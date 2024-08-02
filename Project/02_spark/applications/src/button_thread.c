#include "button_thread.h"

#define LOG_TAG "button.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

static flex_button_t button[BUTTON_MAX];

static char *enum_event_string[] = {
    ENUM_TO_STR(FLEX_BTN_PRESS_DOWN),
    ENUM_TO_STR(FLEX_BTN_PRESS_CLICK),
    ENUM_TO_STR(FLEX_BTN_PRESS_DOUBLE_CLICK),
    ENUM_TO_STR(FLEX_BTN_PRESS_REPEAT_CLICK),
    ENUM_TO_STR(FLEX_BTN_PRESS_SHORT_START),
    ENUM_TO_STR(FLEX_BTN_PRESS_SHORT_UP),
    ENUM_TO_STR(FLEX_BTN_PRESS_LONG_START),
    ENUM_TO_STR(FLEX_BTN_PRESS_LONG_UP),
    ENUM_TO_STR(FLEX_BTN_PRESS_LONG_HOLD),
    ENUM_TO_STR(FLEX_BTN_PRESS_LONG_HOLD_UP),
    ENUM_TO_STR(FLEX_BTN_PRESS_MAX),
    ENUM_TO_STR(FLEX_BTN_PRESS_NONE),
};

static char *enum_btn_id_string[] = {
    ENUM_TO_STR(KEY_UP),
    ENUM_TO_STR(KEY_DOWN),
    ENUM_TO_STR(KEY_LEFT),
    ENUM_TO_STR(KEY_RIGHT),
    ENUM_TO_STR(BUTTON_MAX),
};

void key_up_callback(void *args)
{
    int value = rt_pin_read(KEY_UP);
    LOG_I("key up! %d", value);
}

void key_down_callback(void *args)
{
    int value = rt_pin_read(KEY_DOWN);
    LOG_I("key down! %d", value);
}

void key_left_callback(void *args)
{
    int value = rt_pin_read(KEY_LEFT);
    LOG_I("key left! %d", value);
}

void key_right_callback(void *args)
{
    int value = rt_pin_read(KEY_RIGHT);
    LOG_I("key right! %d", value);
}

/* 按键引脚电平读取函数 */
static uint8_t common_btn_read(void *arg)
{
    uint8_t value = 0;
    flex_button_t *btn = (flex_button_t *)arg;
    switch (btn->id)
    {
    case KEY_UP_0:
        value = rt_pin_read(KEY_UP);
        break;
    case KEY_DOWN_1:
        value = rt_pin_read(KEY_DOWN);
        break;
    case KEY_LEFT_2:
        value = rt_pin_read(KEY_LEFT);
        break;
    case KEY_RIGHT_3:
        value = rt_pin_read(KEY_RIGHT);
        break;
    default:
        RT_ASSERT(0);
    }
    return value;
}

/* 按键事件回调 */
static void common_btn_evt_cb(void *arg)
{
    flex_button_t *btn = (flex_button_t *)arg;
    // rt_kprintf("id: [%d - %s]  event: [%d - %30s]  repeat: %d\n",
    //            btn->id, enum_btn_id_string[btn->id],
    //            btn->event, enum_event_string[btn->event],
    //            btn->click_cnt);
    switch (btn->id)
    {
    case KEY_UP_0:
        key_up_callback(btn->event);
        break;
    case KEY_DOWN_1:
        key_down_callback(btn->event);
        break;
    case KEY_LEFT_2:
        key_left_callback(btn->event);
        break;
    case KEY_RIGHT_3:
        key_right_callback(btn->event);
        break;
    default:
        RT_ASSERT(0);
    }
}

static void button_init(void)
{
    rt_memset(&button[0], 0x0, sizeof(button));

    rt_pin_mode(KEY_UP, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_DOWN, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_LEFT, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_RIGHT, PIN_MODE_INPUT_PULLUP);

    for (int i = 0; i < BUTTON_MAX; i++)
    {
        button[i].id = i;
        button[i].usr_button_read = common_btn_read;
        button[i].cb = common_btn_evt_cb;
        button[i].pressed_logic_level = 0;
        button[i].short_press_start_tick = FLEX_MS_TO_SCAN_CNT(1500);
        button[i].long_press_start_tick = FLEX_MS_TO_SCAN_CNT(3000);
        button[i].long_hold_start_tick = FLEX_MS_TO_SCAN_CNT(4500);
        flex_button_register(&button[i]);
    }
}

void button_entry(void *parameter)
{
    button_init();
    LOG_I("button_init success!");
    while (1)
    {
        flex_button_scan();
        rt_thread_mdelay(20);
    }
}

int button_thread(void)
{
    rt_thread_t tid = RT_NULL;
    tid = rt_thread_create("button_thread",
                           button_entry, RT_NULL,
                           BUTTON_STACK_SIZE,
                           BUTTON_PRIORITY, BUTTON_TIMESLICE);

    if (tid != RT_NULL)
        rt_thread_startup(tid);
    return 0;
}
MSH_CMD_EXPORT(button_thread, button_thread);
