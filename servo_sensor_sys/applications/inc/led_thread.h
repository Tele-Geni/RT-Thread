#ifndef __BUTTON_THREAD_H_
#define __BUTTON_THREAD_H_

#include <rtthread.h>
#include <drv_gpio.h>
#include "lvgl_thread.h"

#define LED_BULE GET_PIN(F, 11)
#define LED_RED GET_PIN(F, 12)

#define LED_ON (PIN_LOW)
#define LED_OFF (PIN_HIGH)

#define LED_BULE_ON() rt_pin_write(LED_BULE, LED_ON)
#define LED_BULE_OFF() rt_pin_write(LED_BULE, LED_OFF)
#define LED_BULE_BLINK()       \
    do                         \
    {                          \
        LED_BULE_OFF();        \
        rt_thread_mdelay(500); \
        LED_BULE_ON();         \
        rt_thread_mdelay(500); \
    } while (0)

#define LED_RED_ON() rt_pin_write(LED_RED, LED_ON)
#define LED_RED_OFF() rt_pin_write(LED_RED, LED_OFF)
#define LED_RED_BLINK()        \
    do                         \
    {                          \
        LED_RED_OFF();         \
        rt_thread_mdelay(500); \
        LED_RED_ON();          \
        rt_thread_mdelay(500); \
    } while (0)

#define LED_BLUE_RED_BLINK()   \
    do                         \
    {                          \
        LED_RED_OFF();         \
        LED_BULE_ON();         \
        rt_thread_mdelay(500); \
        LED_RED_ON();          \
        LED_BULE_OFF();        \
        rt_thread_mdelay(500); \
    } while (0)

#define LED_PRIORITY RT_THREAD_PRIORITY_MAX - 9
#define LED_STACK_SIZE (128 * 4)
#define LED_TIMESLICE 5

void led_entry(void *parameter);

#endif /* __BUTTON_THREAD_H_ */
