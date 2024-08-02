#ifndef __BUTTON_THREAD_H_
#define __BUTTON_THREAD_H_

#include <rtthread.h>
#include <drv_gpio.h>

#define KEY_UP GET_PIN(C, 5)
#define KEY_DOWN GET_PIN(C, 1)
#define KEY_LEFT GET_PIN(C, 0)
#define KEY_RIGHT GET_PIN(C, 4)

#define BUTTON_PRIORITY RT_THREAD_PRIORITY_MAX - 10
#define BUTTON_STACK_SIZE (128 * 4)
#define BUTTON_TIMESLICE 5

void button_entry(void *parameter);

#endif /* __BUTTON_THREAD_H_ */
