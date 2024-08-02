#ifndef __BUTTON_THREAD_H_
#define __BUTTON_THREAD_H_

#include <rtthread.h>
#include <drv_gpio.h>
#include "flexible_button.h"

#define KEY_UP GET_PIN(C, 5)
#define KEY_DOWN GET_PIN(C, 1)
#define KEY_LEFT GET_PIN(C, 0)
#define KEY_RIGHT GET_PIN(C, 4)

#define ENUM_TO_STR(e) (#e)

typedef enum
{
    KEY_UP_0 = 0,
    KEY_DOWN_1,
    KEY_LEFT_2,
    KEY_RIGHT_3,
    BUTTON_MAX
} user_button_t;

#define BUTTON_PRIORITY RT_THREAD_PRIORITY_MAX - 22
#define BUTTON_STACK_SIZE (128 * 8)
#define BUTTON_TIMESLICE 10

void button_entry(void *parameter);

#endif /* __BUTTON_THREAD_H_ */
