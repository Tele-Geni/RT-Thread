#include "lvgl_thread.h"

#define LOG_TAG "lvgl.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

lv_ui guider_ui;

int32_t g_motor_pos = 0;
int32_t g_motor_speed = 0;
int32_t g_motor_torque = 0;
rt_sem_t g_control_command_sem = RT_NULL;
rt_mutex_t g_control_command_mutex = RT_NULL;

static PageState_t g_current_page = HOME_PAGE;

/* lvgl本身就是个伪多线程，也就是说一个函数不被执行完，是不会被抢占的，所以可以不用互斥锁 */
static rt_mutex_t g_page_state_mutex = RT_NULL;
static rt_mutex_t g_fresh_mutex = RT_NULL;
static lv_timer_t *g_aht10_fresh_timer = RT_NULL;
static lv_timer_t *g_icm_fresh_timer = RT_NULL;
static lv_timer_t *g_led_blink_timer = RT_NULL;

extern lv_group_t *keypad_group; // default group
extern rt_mq_t g_aht10_mq;
extern rt_mq_t g_icm20608_mq;
extern rt_sem_t g_led_sem;
extern rt_mq_t g_motor_mq;

#define PAGE_LABEL(page, str) page##_##str

void motor_sync_mode(int32_t pos)
{
    rt_mutex_take(g_page_state_mutex, RT_WAITING_FOREVER);
    if (g_current_page != SYNC_MODE_PAGE)
    {
        rt_mutex_release(g_page_state_mutex);
        return;
    }
    rt_err_t ret = rt_mutex_take(g_control_command_mutex, CONTROL_COMMAND_MUTEX_WAIT_TIME);
    if (RT_EOK == ret)
    {
        g_motor_pos = pos;
        rt_mutex_release(g_control_command_mutex);
        rt_sem_release(g_control_command_sem);
    }
    rt_mutex_release(g_page_state_mutex);
}

void send_motor_pos(lv_obj_t *slider)
{
    rt_err_t ret = rt_mutex_take(g_control_command_mutex, CONTROL_COMMAND_MUTEX_WAIT_TIME);
    if (RT_EOK == ret)
    {
        g_motor_pos = lv_slider_get_value(slider);
        rt_mutex_release(g_control_command_mutex);
        rt_sem_release(g_control_command_sem);
    }
    else
    {
        LOG_W("send_motor_pos rt_mutex_take failed, ret = %d!", ret);
    }
}

void send_motor_speed(lv_obj_t *slider)
{
    rt_err_t ret = rt_mutex_take(g_control_command_mutex, CONTROL_COMMAND_MUTEX_WAIT_TIME);
    if (RT_EOK == ret)
    {
        g_motor_speed = lv_slider_get_value(slider);
        rt_mutex_release(g_control_command_mutex);
        rt_sem_release(g_control_command_sem);
    }
    else
    {
        LOG_W("send_motor_speed rt_mutex_take failed, ret = %d!", ret);
    }
}

void send_motor_torque(lv_obj_t *slider)
{
    rt_err_t ret = rt_mutex_take(g_control_command_mutex, CONTROL_COMMAND_MUTEX_WAIT_TIME);
    if (RT_EOK == ret)
    {
        g_motor_torque = lv_slider_get_value(slider);
        rt_mutex_release(g_control_command_mutex);
        rt_sem_release(g_control_command_sem);
    }
    else
    {
        LOG_W("send_motor_torque rt_mutex_take failed, ret = %d!", ret);
    }
}

static void aht_data_fresh(lv_timer_t *timer)
{
    float recvbuf[2] = {0};
    rt_ssize_t ret = RT_NULL;
    ret = rt_mq_recv(g_aht10_mq, recvbuf, sizeof(recvbuf), 5);
    LOG_D("aht10 rt_mq_recv ret : %d", ret);
    rt_mutex_take(g_page_state_mutex, RT_WAITING_FOREVER);
    if (g_current_page == HOME_PAGE && ret == sizeof(recvbuf))
    {
        rt_mutex_take(g_fresh_mutex, RT_WAITING_FOREVER);
        lv_label_set_text_fmt(guider_ui.PAGE_LABEL(HOME_PAGE, label_temp), "%.2f", recvbuf[0]);
        lv_label_set_text_fmt(guider_ui.PAGE_LABEL(HOME_PAGE, label_humi), "%.2f", recvbuf[0]);
        rt_mutex_release(g_fresh_mutex);
    }
    rt_mutex_release(g_page_state_mutex);
}

static void icm_data_fresh(lv_timer_t *timer)
{
    rt_int16_t recvbuf[6] = {0};
    rt_ssize_t ret = RT_NULL;
    ret = rt_mq_recv(g_icm20608_mq, recvbuf, sizeof(recvbuf), 5);
    LOG_D("icm20680 rt_mq_recv ret : %d", ret);
    rt_mutex_take(g_page_state_mutex, RT_WAITING_FOREVER);
    if (g_current_page == HOME_PAGE && ret == sizeof(recvbuf))
    {
        rt_mutex_take(g_fresh_mutex, RT_WAITING_FOREVER);
        lv_label_set_text_fmt(guider_ui.PAGE_LABEL(HOME_PAGE, label_acc_x), "%6d", recvbuf[0] == 0 ? 0 : recvbuf[0]);
        lv_label_set_text_fmt(guider_ui.PAGE_LABEL(HOME_PAGE, label_acc_y), "%6d", recvbuf[1] == 0 ? 0 : recvbuf[1]);
        lv_label_set_text_fmt(guider_ui.PAGE_LABEL(HOME_PAGE, label_acc_z), "%6d", recvbuf[2] == 0 ? 0 : recvbuf[2]);
        lv_label_set_text_fmt(guider_ui.PAGE_LABEL(HOME_PAGE, label_gyro_x), "%6d", recvbuf[3] == 0 ? 0 : recvbuf[3]);
        lv_label_set_text_fmt(guider_ui.PAGE_LABEL(HOME_PAGE, label_gyro_y), "%6d", recvbuf[4] == 0 ? 0 : recvbuf[4]);
        lv_label_set_text_fmt(guider_ui.PAGE_LABEL(HOME_PAGE, label_gyro_z), "%6d", recvbuf[5] == 0 ? 0 : recvbuf[5]);
        rt_mutex_release(g_fresh_mutex);
    }
    rt_mutex_release(g_page_state_mutex);
}

static void led_blink_fresh(lv_timer_t *timer)
{
    rt_err_t ret = RT_NULL;
    rt_sem_take(g_led_sem, 5);
    if (g_current_page == HOME_PAGE && ret == RT_NULL)
    {
        rt_mutex_take(g_fresh_mutex, RT_WAITING_FOREVER);
        lv_led_toggle(guider_ui.PAGE_LABEL(HOME_PAGE, led_1));
        rt_mutex_release(g_fresh_mutex);
    }
}

static void motor_reback_fresh(lv_timer_t *timer)
{
    rt_int32_t recvbuf[3] = {0};
    rt_ssize_t ret = RT_NULL;
    ret = rt_mq_recv(g_motor_mq, recvbuf, sizeof(recvbuf), 5);
    LOG_D("motor_reback rt_mq_recv ret : %d", ret);
    rt_mutex_take(g_page_state_mutex, RT_WAITING_FOREVER);
    if (g_current_page != HOME_PAGE &&
        g_current_page != OPERATION_PAGE &&
        ret == sizeof(recvbuf))
    {
        rt_mutex_take(g_fresh_mutex, RT_WAITING_FOREVER);
        switch (g_current_page)
        {
        case ZERO_MODE_PAGE:
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(ZERO_MODE_PAGE, label_pos), "%d", recvbuf[0]);
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(ZERO_MODE_PAGE, label_speed), "%d", recvbuf[1]);
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(ZERO_MODE_PAGE, label_torque), "%d", (int16_t)recvbuf[2]);
            break;
        case POSITION_MODE_PAGE:
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(POSITION_MODE_PAGE, label_pos), "%d", recvbuf[0]);
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(POSITION_MODE_PAGE, label_speed), "%d", recvbuf[1]);
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(POSITION_MODE_PAGE, label_torque), "%d", (int16_t)recvbuf[2]);
            break;
        case SPEED_MODE_PAGE:
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(SPEED_MODE_PAGE, label_pos), "%d", recvbuf[0]);
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(SPEED_MODE_PAGE, label_speed), "%d", recvbuf[1]);
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(SPEED_MODE_PAGE, label_torque), "%d", (int16_t)recvbuf[2]);
            break;
        case TORQUE_MODE_PAGE:
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(TORQUE_MODE_PAGE, label_pos), "%d", recvbuf[0]);
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(TORQUE_MODE_PAGE, label_speed), "%d", recvbuf[1]);
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(TORQUE_MODE_PAGE, label_torque), "%d", (int16_t)recvbuf[2]);
        case SYNC_MODE_PAGE:
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(SYNC_MODE_PAGE, label_pos), "%d", recvbuf[0]);
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(SYNC_MODE_PAGE, label_speed), "%d", recvbuf[1]);
            lv_label_set_text_fmt(guider_ui.PAGE_LABEL(SYNC_MODE_PAGE, label_torque), "%d", (int16_t)recvbuf[2]);
            break;
        default:
            break;
        }
        rt_mutex_release(g_fresh_mutex);
    }
    rt_mutex_release(g_page_state_mutex);
}

/* 逻辑混乱，能否用链表进行三级页面管理或者简化为二级 */
void handle_key_input(uint32_t act_key)
{
    lv_obj_t *focused_obj;
    lv_obj_t *focused_obj_label;
    const char *focused_obj_label_text;
    LOG_D("g_current_page previous: %20s", page_state_string[g_current_page]);
    switch (g_current_page)
    {
    case HOME_PAGE:
    {
        switch (act_key)
        {
        case KEY_UP_0:
        case KEY_LEFT_2:
            lv_group_focus_prev(keypad_group);
            goto End;
        case KEY_DOWN_1:
        case KEY_RIGHT_3:
            lv_group_focus_next(keypad_group);
            goto End;
        case KEY_ESC:
        case KEY_ENTER:
            focused_obj = lv_group_get_focused(keypad_group);
            focused_obj_label = lv_obj_get_child(focused_obj, 0);
            if (focused_obj_label && lv_obj_check_type(focused_obj_label, &lv_label_class))
                focused_obj_label_text = lv_label_get_text(focused_obj_label);
            LOG_D("focused_obj_label_text: %s", focused_obj_label_text);
            lv_event_send(lv_group_get_focused(keypad_group), LV_EVENT_CLICKED, RT_NULL);
            rt_mutex_take(g_page_state_mutex, RT_WAITING_FOREVER);
            if (strncmp(focused_obj_label_text, "Entry", strlen("Entry")) == 0)
                g_current_page = OPERATION_PAGE;
            rt_mutex_release(g_page_state_mutex);
            goto End;
        }
    }
    break;
    case OPERATION_PAGE:
    {
        switch (act_key)
        {
        case KEY_UP_0:
            lv_group_focus_prev(keypad_group);
            lv_group_focus_prev(keypad_group);
            goto End;
        case KEY_DOWN_1:
            lv_group_focus_next(keypad_group);
            lv_group_focus_next(keypad_group);
            goto End;
        case KEY_LEFT_2:
            lv_group_focus_prev(keypad_group);
            goto End;
        case KEY_RIGHT_3:
            lv_group_focus_next(keypad_group);
            goto End;
        case KEY_ESC:
        case KEY_ENTER:
            focused_obj = lv_group_get_focused(keypad_group);
            focused_obj_label = lv_obj_get_child(focused_obj, 0);
            if (focused_obj_label && lv_obj_check_type(focused_obj_label, &lv_label_class))
                focused_obj_label_text = lv_label_get_text(focused_obj_label);
            LOG_D("focused_obj_label_text: %s", focused_obj_label_text);

            if (focused_obj_label_text && strncmp(focused_obj_label_text, "DEVICE ID", strlen("DEVICE ID")))
            {
                rt_mutex_take(g_page_state_mutex, RT_WAITING_FOREVER);
                if (strncmp(focused_obj_label_text, "Zero Mode", strlen("Zero Mode")) == 0)
                    g_current_page = ZERO_MODE_PAGE;
                else if (strncmp(focused_obj_label_text, "Position Mode", strlen("Position Mode")) == 0)
                    g_current_page = POSITION_MODE_PAGE;
                else if (strncmp(focused_obj_label_text, "Speed Mode", strlen("Speed Mode")) == 0)
                    g_current_page = SPEED_MODE_PAGE;
                else if (strncmp(focused_obj_label_text, "Torque Mode", strlen("Torque Mode")) == 0)
                    g_current_page = TORQUE_MODE_PAGE;
                else if (strncmp(focused_obj_label_text, "Sync Mode", strlen("Sync Mode")) == 0)
                    g_current_page = SYNC_MODE_PAGE;
                else if (strncmp(focused_obj_label_text, "Exit", strlen("Exit")) == 0)
                    g_current_page = HOME_PAGE;
                rt_mutex_release(g_page_state_mutex);
                /* 先改变状态机，再触发事件 */
                lv_event_send(lv_group_get_focused(keypad_group), LV_EVENT_CLICKED, RT_NULL);
            }
            goto End;
        }
    }
    break;
    case ZERO_MODE_PAGE:
    case POSITION_MODE_PAGE:
    case SPEED_MODE_PAGE:
    case TORQUE_MODE_PAGE:
    case SYNC_MODE_PAGE:
    {
        switch (act_key)
        {
        case KEY_UP_0:
        case KEY_LEFT_2:
            lv_group_focus_next(keypad_group);
            goto End;
        case KEY_DOWN_1:
        case KEY_RIGHT_3:
            lv_group_focus_prev(keypad_group);
            goto End;
        case KEY_ESC:
        case KEY_ENTER:
            focused_obj = lv_group_get_focused(keypad_group);
            focused_obj_label = lv_obj_get_child(focused_obj, 0);
            if (focused_obj_label && lv_obj_check_type(focused_obj_label, &lv_label_class))
                focused_obj_label_text = lv_label_get_text(focused_obj_label);
            LOG_D("focused_obj_label_text: %s", focused_obj_label_text);
            rt_mutex_take(g_page_state_mutex, RT_WAITING_FOREVER);
            if (strncmp(focused_obj_label_text, "Back", strlen("Back")) == 0)
                g_current_page = OPERATION_PAGE;
            else if (strncmp(focused_obj_label_text, "Run", strlen("Run")) == 0)
                motor_enable(g_current_page);
            else if (strncmp(focused_obj_label_text, "Stop", strlen("Stop")) == 0)
                motor_disable();
            rt_mutex_release(g_page_state_mutex);
            lv_event_send(lv_group_get_focused(keypad_group), LV_EVENT_CLICKED, RT_NULL);
            goto End;
        case KEY_ADD:
            lv_event_send(lv_group_get_focused(keypad_group), LV_EVENT_VALUE_CHANGED, (void *)KEY_ADD);
            goto End;
        case KEY_SUB:
            lv_event_send(lv_group_get_focused(keypad_group), LV_EVENT_VALUE_CHANGED, (void *)KEY_SUB);
            goto End;
        }
    }
    break;
    default:
        break;
    }
End:
    LOG_D("g_current_page current: %20s\n", page_state_string[g_current_page]);
}

/* lvgl's lv_user_gui_init function that where `packages\LVGL-v8.3.11\env_support\rt-thread\lv_rt_thread_port.c` will be replace at here */
void lv_user_gui_init(void)
{
    lv_obj_clean(lv_scr_act()); // 清屏
    setup_ui(&guider_ui);       // 布局
    custom_init(&guider_ui);    // 自定义
    g_page_state_mutex = rt_mutex_create("page_state", RT_IPC_FLAG_PRIO);
    g_fresh_mutex = rt_mutex_create("data_fresh", RT_IPC_FLAG_PRIO);
    g_control_command_sem = rt_sem_create("motor_command", 0, RT_IPC_FLAG_PRIO);
    g_control_command_mutex = rt_mutex_create("motor_command", RT_IPC_FLAG_PRIO);
    g_aht10_fresh_timer = lv_timer_create(aht_data_fresh, 1000, RT_NULL);
    g_icm_fresh_timer = lv_timer_create(icm_data_fresh, 1000, RT_NULL);
    g_led_blink_timer = lv_timer_create(led_blink_fresh, 500, RT_NULL);
    g_led_blink_timer = lv_timer_create(motor_reback_fresh, 30, RT_NULL);
}

// static void POSITION_MODE_PAGE_slider_pos_event_handler(lv_event_t *e)
// {
//     lv_event_code_t code = lv_event_get_code(e);
//     lv_obj_t *slider = lv_event_get_target(e);
//     user_button_t key_type = (user_button_t)lv_event_get_user_data(e);
//     switch (code)
//     {
//     case LV_EVENT_VALUE_CHANGED:
//     {
//         int32_t value = lv_slider_get_value(slider);
//         if (KEY_ADD == key_type)
//             lv_slider_set_value(slider, value + 1, LV_ANIM_OFF);
//         else if (KEY_SUB == key_type)
//             lv_slider_set_value(slider, value - 1, LV_ANIM_OFF);
//         send_motor_pos(slider);
//         break;
//     }
//     default:
//         break;
//     }
// }