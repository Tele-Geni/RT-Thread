#include "lvgl_thread.h"

#define LOG_TAG "lvgl.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

lv_ui guider_ui;

PageState_t g_current_page = HOME_PAGE;
rt_mutex_t g_page_state_mutex = RT_NULL;
rt_mutex_t g_fresh_mutex = RT_NULL;

extern lv_group_t *keypad_group; // default group

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
        switch (act_key)
        {
        case KEY_LEFT_2:
            lv_group_focus_prev(keypad_group);
            goto End;
        case KEY_RIGHT_3:
            lv_group_focus_next(keypad_group);
            goto End;
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
        break;
    case OPERATION_PAGE:
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
                else if (strncmp(focused_obj_label_text, "Current Mode", strlen("Current Mode")) == 0)
                    g_current_page = CURRENT_MODE_PAGE;
                else if (strncmp(focused_obj_label_text, "Control Mode", strlen("Control Mode")) == 0)
                    g_current_page = CONTROL_MODE_PAGE;
                else if (strncmp(focused_obj_label_text, "Exit", strlen("Exit")) == 0)
                    g_current_page = HOME_PAGE;
                rt_mutex_release(g_page_state_mutex);
                /* 先改变状态机，再触发事件 */
                lv_event_send(lv_group_get_focused(keypad_group), LV_EVENT_CLICKED, RT_NULL);
            }
            goto End;
        case KEY_ESC:
            rt_mutex_take(g_page_state_mutex, RT_WAITING_FOREVER);
            g_current_page = HOME_PAGE;
            rt_mutex_release(g_page_state_mutex);
            lv_event_send(guider_ui.Operation_btn_exit, LV_EVENT_CLICKED, RT_NULL);
            goto End;
        }
        break;
    case ZERO_MODE_PAGE:
    case POSITION_MODE_PAGE:
    case SPEED_MODE_PAGE:
    case CURRENT_MODE_PAGE:
    case CONTROL_MODE_PAGE:
        switch (act_key)
        {
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
            rt_mutex_take(g_page_state_mutex, RT_WAITING_FOREVER);
            if (strncmp(focused_obj_label_text, "Back", strlen("Back")) == 0)
                g_current_page = OPERATION_PAGE;
            rt_mutex_release(g_page_state_mutex);
            lv_event_send(lv_group_get_focused(keypad_group), LV_EVENT_CLICKED, RT_NULL);
            goto End;
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
}
