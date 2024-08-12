#include "button_thread.h"

#define LOG_TAG "button.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

extern volatile int8_t g_cur_dummy_key;

static flex_button_t g_button[BUTTON_MAX];

static void key_up_callback(void *args)
{
    flex_button_t *btn = (flex_button_t *)args;
    LOG_D("event: %25s", enum_event_string[btn->event]);
    switch (btn->event)
    {
    case FLEX_BTN_PRESS_CLICK:
        g_cur_dummy_key = KEY_UP_0;
        break;
    default:
        break;
    }
}

static void key_down_callback(void *args)
{
    flex_button_t *btn = (flex_button_t *)args;
    LOG_D("event: %25s", enum_event_string[btn->event]);
    switch (btn->event)
    {
    case FLEX_BTN_PRESS_CLICK:
        g_cur_dummy_key = KEY_DOWN_1;
        break;
    case FLEX_BTN_PRESS_DOUBLE_CLICK:
        g_cur_dummy_key = KEY_ENTER; /* double click to entry */
        break;
    case FLEX_BTN_PRESS_SHORT_START:
        g_cur_dummy_key = KEY_ESC; /* short press to exit/back */
        break;
    default:
        break;
    }
}

static void key_left_callback(void *args)
{
    flex_button_t *btn = (flex_button_t *)args;
    LOG_D("event: %25s", enum_event_string[btn->event]);
    switch (btn->event)
    {
    case FLEX_BTN_PRESS_CLICK:
        g_cur_dummy_key = KEY_LEFT_2;
        break;
    case FLEX_BTN_PRESS_SHORT_START:
        g_cur_dummy_key = KEY_SUB; /* short press to sub */
        break;
    default:
        break;
    }
}

static void key_right_callback(void *args)
{
    flex_button_t *btn = (flex_button_t *)args;
    LOG_D("event: %25s", enum_event_string[btn->event]);
    switch (btn->event)
    {
    case FLEX_BTN_PRESS_CLICK:
        g_cur_dummy_key = KEY_RIGHT_3;
        break;
    case FLEX_BTN_PRESS_SHORT_START:
        g_cur_dummy_key = KEY_ADD; /* short press to add */
        break;
    default:
        break;
    }
}
//...

static void common_btn_evt_cb(void *arg)
{
    flex_button_t *btn = (flex_button_t *)arg;
    switch (btn->id)
    {
    case KEY_UP_0:
        key_up_callback((void *)btn);
        break;
    case KEY_DOWN_1:
        key_down_callback((void *)btn);
        break;
    case KEY_LEFT_2:
        key_left_callback((void *)btn);
        break;
    case KEY_RIGHT_3:
        key_right_callback((void *)btn);
        break;
    //...
    default:
        RT_ASSERT(0);
    }
}

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
    //...
    default:
        RT_ASSERT(0);
    }
    return value;
}

static void button_init(void)
{
    rt_memset(&g_button[0], 0x0, sizeof(g_button));

    rt_pin_mode(KEY_UP, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_DOWN, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_LEFT, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_RIGHT, PIN_MODE_INPUT_PULLUP);
    //...

    for (int i = 0; i < BUTTON_MAX; i++)
    {
        g_button[i].id = i;
        g_button[i].usr_button_read = common_btn_read;                      // 按键引脚电平读取函数
        g_button[i].cb = common_btn_evt_cb;                                 // 按键事件回调
        g_button[i].pressed_logic_level = 0;                                // 按下时引脚电平
        g_button[i].short_press_start_tick = FLEX_MS_TO_SCAN_CNT(1500 / 4); // 单位为tick, 1/RT_TICK_PER_SECOND秒，默认为1ms
        g_button[i].long_press_start_tick = FLEX_MS_TO_SCAN_CNT(3000 / 4);
        g_button[i].long_hold_start_tick = FLEX_MS_TO_SCAN_CNT(4500 / 4);
        flex_button_register(&g_button[i]);
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
// MSH_CMD_EXPORT(button_thread, button_thread);
INIT_DEVICE_EXPORT(button_thread);
