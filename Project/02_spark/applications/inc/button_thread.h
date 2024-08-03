#ifndef __BUTTON_THREAD_H_
#define __BUTTON_THREAD_H_

#include <rtthread.h>
#include <drv_gpio.h>
#include "flexible_button.h"

#define KEY_UP GET_PIN(C, 5)
#define KEY_DOWN GET_PIN(C, 1)
#define KEY_LEFT GET_PIN(C, 0)
#define KEY_RIGHT GET_PIN(C, 4)

typedef enum
{
    KEY_UP_0 = 0,
    KEY_DOWN_1,
    KEY_LEFT_2,
    KEY_RIGHT_3,
    BUTTON_MAX
} user_button_t;

#define ENUM_TO_STR(e) (#e)

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

#define BUTTON_PRIORITY RT_THREAD_PRIORITY_MAX - 22
#define BUTTON_STACK_SIZE (128 * 8)
#define BUTTON_TIMESLICE 10

void button_entry(void *parameter);

#endif /* __BUTTON_THREAD_H_ */
