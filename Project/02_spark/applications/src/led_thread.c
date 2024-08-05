#include "led_thread.h"

#define LOG_TAG "led.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

rt_sem_t g_led_sem = RT_NULL;

static void led_init(void)
{
    rt_pin_mode(LED_BULE, PIN_MODE_OUTPUT);
    rt_pin_mode(LED_RED, PIN_MODE_OUTPUT);
    rt_pin_write(LED_BULE, LED_OFF);
    rt_pin_write(LED_RED, LED_OFF);
    g_led_sem = rt_sem_create("led", 0, RT_IPC_FLAG_PRIO);
}

void led_entry(void *parameter)
{
    led_init();
    LOG_I("led_init success!");
    while (1)
    {
        // LED_BLUE_RED_BLINK();
        LED_RED_ON();
        rt_sem_release(g_led_sem);
        lv_event_send(guider_ui.Home_led_1, LV_EVENT_VALUE_CHANGED, RT_NULL);
        rt_thread_mdelay(500);
        LED_RED_OFF();
        rt_sem_release(g_led_sem);
        lv_event_send(guider_ui.Home_led_1, LV_EVENT_VALUE_CHANGED, RT_NULL);
        rt_thread_mdelay(500);
    }
}

int led_thread(void)
{
    rt_thread_t tid = RT_NULL;
    tid = rt_thread_create("led_thread",
                           led_entry, RT_NULL,
                           LED_STACK_SIZE,
                           LED_PRIORITY, LED_TIMESLICE);

    if (tid != RT_NULL)
        rt_thread_startup(tid);
    return 0;
}
// MSH_CMD_EXPORT(led_thread, led_thread);
INIT_DEVICE_EXPORT(led_thread);
