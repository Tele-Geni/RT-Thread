#ifndef __LVGL_THREAD_H_
#define __LVGL_THREAD_H_

#include <rtthread.h>
#include <lvgl.h>
#include "gui_guider.h"
#include "custom.h"
#include "button_thread.h"
#include <stdlib.h>
#include "motor_control.h"

#ifndef ENUM_TO_STR
#define ENUM_TO_STR(e) (#e)
#endif

// typedef enum
// {
//     HOME_PAGE = 1,
//     OPERATION_PAGE,
//     ZERO_MODE_PAGE,
//     POSITION_MODE_PAGE,
//     SPEED_MODE_PAGE,
//     TORQUE_MODE_PAGE,
//     SYNC_MODE_PAGE,
// } PageState_t;

static char *page_state_string[] = {
    ENUM_TO_STR(RT_NULL),
    ENUM_TO_STR(HOME_PAGE),
    ENUM_TO_STR(OPERATION_PAGE),
    ENUM_TO_STR(ZERO_MODE_PAGE),
    ENUM_TO_STR(POSITION_MODE_PAGE),
    ENUM_TO_STR(SPEED_MODE_PAGE),
    ENUM_TO_STR(TORQUE_MODE_PAGE),
    ENUM_TO_STR(SYNC_MODE_PAGE),
};

void motor_sync_mode(int32_t pos);
void send_motor_pos(lv_obj_t *slider);
void send_motor_speed(lv_obj_t *slider);
void send_motor_torque(lv_obj_t *slider);
void handle_key_input(uint32_t act_key);

/* lvgl_thread prio 21 */

#endif /* __LVGL_THREAD_H_ */
