/*
 * Copyright (c) 2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-07-06     Supperthomas first version
 * 2023-12-03     Meco Man     support nano version
 */

#include <board.h>
#include <rtthread.h>
#include <drv_gpio.h>
#ifndef RT_USING_NANO
#include <rtdevice.h>
#endif /* RT_USING_NANO */
#include "hello_driver.h"
#include "drv_lcd.h"

#define PIN_KEY0 GET_PIN(C, 0)

#define GPIO_LED_B GET_PIN(F, 11)
#define GPIO_LED_R GET_PIN(F, 12)

#define THREAD_PRIORITY 25
#define THREAD_STACK_SIZE 1024
#define THREAD_TIMESLICE 5

static rt_thread_t tid1 = RT_NULL;
static rt_thread_t tid2 = RT_NULL;
static rt_sem_t dynamic_sem = RT_NULL;

static void key_name_thread(void *parameter);
static void led_name_thread(void *parameter);

int main(void)
{
    rt_pin_mode(GPIO_LED_R, PIN_MODE_OUTPUT);
    rt_pin_mode(PIN_KEY0, PIN_MODE_INPUT_PULLUP);

    dynamic_sem = rt_sem_create("dsem", 0, RT_IPC_FLAG_PRIO);
    if (dynamic_sem == RT_NULL)
    {
        rt_kprintf("create dynamic semaphore failed.\n");
        return -1;
    }

    tid1 = rt_thread_create("key_thread",
                            key_name_thread, RT_NULL,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY, THREAD_TIMESLICE);
    // if (tid1 != RT_NULL)
    //     rt_thread_startup(tid1);

    tid2 = rt_thread_create("led_thread",
                            led_name_thread, RT_NULL,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY, THREAD_TIMESLICE);
    // if (tid2 != RT_NULL)
    // rt_thread_startup(tid2);

    lcd_clear(WHITE);
    lcd_set_color(WHITE, BLACK);
    lcd_show_string(10, 69, 16, "Hello RT-Thread!");

    while (1)
    {
        // hello_driver();
        // rt_pin_write(GPIO_LED_R, PIN_HIGH);
        // rt_thread_mdelay(500);
        // rt_pin_write(GPIO_LED_R, PIN_LOW);
        rt_thread_mdelay(1000);
    }
}

static void key_name_thread(void *parameter)
{
    while (1)
    {
        if (rt_pin_read(PIN_KEY0) == PIN_LOW)
        {
            rt_thread_mdelay(50);
            if (rt_pin_read(PIN_KEY0) == PIN_LOW)
            {
                rt_kprintf("KEY0 pressed!\n");
                rt_sem_release(dynamic_sem);
            }
        }
        rt_thread_mdelay(10);
    }
}

static void led_name_thread(void *parameter)
{
    while (1)
    {
        rt_sem_take(dynamic_sem, RT_WAITING_FOREVER);
        rt_kprintf("LED_R blink!\n");
        rt_pin_write(GPIO_LED_R, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(GPIO_LED_R, PIN_LOW);
        rt_thread_mdelay(500);
    }
}

int user_name_sample(void)
{
    rt_kprintf("hello world\n");
}
MSH_CMD_EXPORT(user_name_sample, user name sample);
