#ifndef __LVGL_THREAD_H_
#define __LVGL_THREAD_H_

#include <lvgl.h>
#include "gui_guider.h"
#include "custom.h"
#include "button_thread.h"

typedef enum
{
    HOME_PAGE = 1,
    OPERATION_PAGE,
    ZERO_MODE_PAGE,
    POSITION_MODE_PAGE,
    SPEED_MODE_PAGE,
    CURRENT_MODE_PAGE,
    CONTROL_MODE_PAGE,
} PageState_t;

static char *page_state_string[] = {
    ENUM_TO_STR(RT_NULL),
    ENUM_TO_STR(HOME_PAGE),
    ENUM_TO_STR(OPERATION_PAGE),
    ENUM_TO_STR(ZERO_MODE_PAGE),
    ENUM_TO_STR(POSITION_MODE_PAGE),
    ENUM_TO_STR(SPEED_MODE_PAGE),
    ENUM_TO_STR(CURRENT_MODE_PAGE),
    ENUM_TO_STR(CONTROL_MODE_PAGE),
};

void handle_key_input(uint32_t act_key);

#endif /* __LVGL_THREAD_H_ */
