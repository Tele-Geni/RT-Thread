#include "button_thread.h"

#define LOG_TAG "button.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

#define KEY_UP GET_PIN(C, 5)
#define KEY_DOWN GET_PIN(C, 1)
#define KEY_LEFT GET_PIN(C, 0)
#define KEY_RIGHT GET_PIN(C, 4)

#define THREAD_PRIORITY 25
#define THREAD_STACK_SIZE 512
#define THREAD_TIMESLICE 5

static rt_thread_t tid = RT_NULL;

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

void button_init(void)
{
    rt_pin_mode(KEY_UP, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_DOWN, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_LEFT, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_RIGHT, PIN_MODE_INPUT_PULLUP);

    rt_pin_attach_irq(KEY_UP, PIN_IRQ_MODE_FALLING, key_up_callback, RT_NULL);
    rt_pin_attach_irq(KEY_DOWN, PIN_IRQ_MODE_FALLING, key_down_callback, RT_NULL);
    rt_pin_attach_irq(KEY_LEFT, PIN_IRQ_MODE_FALLING, key_left_callback, RT_NULL);
    rt_pin_attach_irq(KEY_RIGHT, PIN_IRQ_MODE_FALLING, key_right_callback, RT_NULL);

    rt_pin_irq_enable(KEY_UP, PIN_IRQ_ENABLE);
    rt_pin_irq_enable(KEY_DOWN, PIN_IRQ_ENABLE);
    rt_pin_irq_enable(KEY_LEFT, PIN_IRQ_ENABLE);
    rt_pin_irq_enable(KEY_RIGHT, PIN_IRQ_ENABLE);
}

void button_entry(void *parameter)
{
    button_init();
    while (1)
    {
        rt_thread_mdelay(1000);
    }
}

int button_thread(void)
{
    tid = rt_thread_create("button_thread",
                           button_entry, RT_NULL,
                           THREAD_STACK_SIZE,
                           THREAD_PRIORITY, THREAD_TIMESLICE);

    if (tid != RT_NULL)
        rt_thread_startup(tid);
    return 0;
}
MSH_CMD_EXPORT(button_thread, thread button_thread);
