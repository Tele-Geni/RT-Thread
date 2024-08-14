/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "button_thread.h"
#include "lvgl_thread.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

static void HOME_PAGE_btn_entry_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.OPERATION_PAGE, guider_ui.OPERATION_PAGE_del, &guider_ui.HOME_PAGE_del, setup_scr_OPERATION_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void HOME_PAGE_led_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		break;
	}
	default:
		break;
	}
}

void events_init_HOME_PAGE(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->HOME_PAGE_btn_entry, HOME_PAGE_btn_entry_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->HOME_PAGE_led_1, HOME_PAGE_led_1_event_handler, LV_EVENT_ALL, ui);
}

static void OPERATION_PAGE_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_SCREEN_LOADED:
	{
		break;
	}
	default:
		break;
	}
}

static void OPERATION_PAGE_btn_zero_mode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.ZERO_MODE_PAGE, guider_ui.ZERO_MODE_PAGE_del, &guider_ui.OPERATION_PAGE_del, setup_scr_ZERO_MODE_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void OPERATION_PAGE_btn_position_mode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.POSITION_MODE_PAGE, guider_ui.POSITION_MODE_PAGE_del, &guider_ui.OPERATION_PAGE_del, setup_scr_POSITION_MODE_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void OPERATION_PAGE_btn_speed_mdoe_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.SPEED_MODE_PAGE, guider_ui.SPEED_MODE_PAGE_del, &guider_ui.OPERATION_PAGE_del, setup_scr_SPEED_MODE_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void OPERATION_PAGE_btn_current_mode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.TORQUE_MODE_PAGE, guider_ui.TORQUE_MODE_PAGE_del, &guider_ui.OPERATION_PAGE_del, setup_scr_TORQUE_MODE_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void OPERATION_PAGE_btn_control_mode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.SYNC_MODE_PAGE, guider_ui.SYNC_MODE_PAGE_del, &guider_ui.OPERATION_PAGE_del, setup_scr_SYNC_MODE_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void OPERATION_PAGE_btn_exit_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.HOME_PAGE, guider_ui.HOME_PAGE_del, &guider_ui.OPERATION_PAGE_del, setup_scr_HOME_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

void events_init_OPERATION_PAGE(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->OPERATION_PAGE, OPERATION_PAGE_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->OPERATION_PAGE_btn_zero_mode, OPERATION_PAGE_btn_zero_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->OPERATION_PAGE_btn_position_mode, OPERATION_PAGE_btn_position_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->OPERATION_PAGE_btn_speed_mdoe, OPERATION_PAGE_btn_speed_mdoe_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->OPERATION_PAGE_btn_current_mode, OPERATION_PAGE_btn_current_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->OPERATION_PAGE_btn_control_mode, OPERATION_PAGE_btn_control_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->OPERATION_PAGE_btn_exit, OPERATION_PAGE_btn_exit_event_handler, LV_EVENT_ALL, ui);
}

static void ZERO_MODE_PAGE_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.OPERATION_PAGE, guider_ui.OPERATION_PAGE_del, &guider_ui.ZERO_MODE_PAGE_del, setup_scr_OPERATION_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void ZERO_MODE_PAGE_btn_stop_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		break;
	}
	default:
		break;
	}
}

static void ZERO_MODE_PAGE_btn_run_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		break;
	}
	default:
		break;
	}
}

void events_init_ZERO_MODE_PAGE(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ZERO_MODE_PAGE_btn_back, ZERO_MODE_PAGE_btn_back_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ZERO_MODE_PAGE_btn_stop, ZERO_MODE_PAGE_btn_stop_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ZERO_MODE_PAGE_btn_run, ZERO_MODE_PAGE_btn_run_event_handler, LV_EVENT_ALL, ui);
}

static void POSITION_MODE_PAGE_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.OPERATION_PAGE, guider_ui.OPERATION_PAGE_del, &guider_ui.POSITION_MODE_PAGE_del, setup_scr_OPERATION_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void POSITION_MODE_PAGE_btn_stop_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		break;
	}
	default:
		break;
	}
}

static void POSITION_MODE_PAGE_btn_run_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		break;
	}
	default:
		break;
	}
}

static void POSITION_MODE_PAGE_slider_pos_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *slider = lv_event_get_target(e);
	user_button_t key_type = (user_button_t)lv_event_get_param(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		int32_t value = lv_slider_get_value(slider);
		if (KEY_ADD == key_type)
			lv_slider_set_value(slider, value + 1, LV_ANIM_OFF);
		else if (KEY_SUB == key_type)
			lv_slider_set_value(slider, value - 1, LV_ANIM_OFF);
		send_motor_pos(slider);
		break;
	}
	default:
		break;
	}
}

static void POSITION_MODE_PAGE_slider_speed_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *slider = lv_event_get_target(e);
	user_button_t key_type = (user_button_t)lv_event_get_param(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		int32_t value = lv_slider_get_value(slider);
		if (KEY_ADD == key_type)
			lv_slider_set_value(slider, value + 1, LV_ANIM_OFF);
		else if (KEY_SUB == key_type)
			lv_slider_set_value(slider, value - 1, LV_ANIM_OFF);
		send_motor_speed(slider);
		break;
	}
	default:
		break;
	}
}

void events_init_POSITION_MODE_PAGE(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->POSITION_MODE_PAGE_btn_back, POSITION_MODE_PAGE_btn_back_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->POSITION_MODE_PAGE_btn_stop, POSITION_MODE_PAGE_btn_stop_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->POSITION_MODE_PAGE_btn_run, POSITION_MODE_PAGE_btn_run_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->POSITION_MODE_PAGE_slider_pos, POSITION_MODE_PAGE_slider_pos_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->POSITION_MODE_PAGE_slider_speed, POSITION_MODE_PAGE_slider_speed_event_handler, LV_EVENT_ALL, ui);
}

static void SPEED_MODE_PAGE_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.OPERATION_PAGE, guider_ui.OPERATION_PAGE_del, &guider_ui.SPEED_MODE_PAGE_del, setup_scr_OPERATION_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void SPEED_MODE_PAGE_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.OPERATION_PAGE, guider_ui.OPERATION_PAGE_del, &guider_ui.SPEED_MODE_PAGE_del, setup_scr_OPERATION_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void SPEED_MODE_PAGE_btn_stop_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		break;
	}
	default:
		break;
	}
}

static void SPEED_MODE_PAGE_btn_run_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		break;
	}
	default:
		break;
	}
}

static void SPEED_MODE_PAGE_slider_pos_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *slider = lv_event_get_target(e);
	user_button_t key_type = (user_button_t)lv_event_get_param(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		int32_t value = lv_slider_get_value(slider);
		if (KEY_ADD == key_type)
			lv_slider_set_value(slider, value + 1, LV_ANIM_OFF);
		else if (KEY_SUB == key_type)
			lv_slider_set_value(slider, value - 1, LV_ANIM_OFF);
		send_motor_pos(slider);
		break;
	}
	default:
		break;
	}
}

static void SPEED_MODE_PAGE_slider_speed_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *slider = lv_event_get_target(e);
	user_button_t key_type = (user_button_t)lv_event_get_param(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		int32_t value = lv_slider_get_value(slider);
		if (KEY_ADD == key_type)
			lv_slider_set_value(slider, value + 1, LV_ANIM_OFF);
		else if (KEY_SUB == key_type)
			lv_slider_set_value(slider, value - 1, LV_ANIM_OFF);
		send_motor_speed(slider);
		break;
	}
	default:
		break;
	}
}

void events_init_SPEED_MODE_PAGE(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->SPEED_MODE_PAGE, SPEED_MODE_PAGE_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SPEED_MODE_PAGE_btn_back, SPEED_MODE_PAGE_btn_back_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SPEED_MODE_PAGE_btn_stop, SPEED_MODE_PAGE_btn_stop_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SPEED_MODE_PAGE_btn_run, SPEED_MODE_PAGE_btn_run_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SPEED_MODE_PAGE_slider_pos, SPEED_MODE_PAGE_slider_pos_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SPEED_MODE_PAGE_slider_speed, SPEED_MODE_PAGE_slider_speed_event_handler, LV_EVENT_ALL, ui);
}

static void TORQUE_MODE_PAGE_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.OPERATION_PAGE, guider_ui.OPERATION_PAGE_del, &guider_ui.TORQUE_MODE_PAGE_del, setup_scr_OPERATION_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void TORQUE_MODE_PAGE_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.OPERATION_PAGE, guider_ui.OPERATION_PAGE_del, &guider_ui.TORQUE_MODE_PAGE_del, setup_scr_OPERATION_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void TORQUE_MODE_PAGE_btn_stop_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		break;
	}
	default:
		break;
	}
}

static void TORQUE_MODE_PAGE_btn_run_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		break;
	}
	default:
		break;
	}
}

static void TORQUE_MODE_PAGE_slider_torque_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *slider = lv_event_get_target(e);
	user_button_t key_type = (user_button_t)lv_event_get_param(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		int32_t value = lv_slider_get_value(slider);
		if (KEY_ADD == key_type)
			lv_slider_set_value(slider, value + 1, LV_ANIM_OFF);
		else if (KEY_SUB == key_type)
			lv_slider_set_value(slider, value - 1, LV_ANIM_OFF);
		send_motor_torque(slider);
		break;
	}
	default:
		break;
	}
}

static void TORQUE_MODE_PAGE_slider_speed_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *slider = lv_event_get_target(e);
	user_button_t key_type = (user_button_t)lv_event_get_param(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		int32_t value = lv_slider_get_value(slider);
		if (KEY_ADD == key_type)
			lv_slider_set_value(slider, value + 1, LV_ANIM_OFF);
		else if (KEY_SUB == key_type)
			lv_slider_set_value(slider, value - 1, LV_ANIM_OFF);
		send_motor_speed(slider);
		break;
	}
	default:
		break;
	}
}

void events_init_TORQUE_MODE_PAGE(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->TORQUE_MODE_PAGE, TORQUE_MODE_PAGE_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TORQUE_MODE_PAGE_btn_back, TORQUE_MODE_PAGE_btn_back_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TORQUE_MODE_PAGE_btn_stop, TORQUE_MODE_PAGE_btn_stop_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TORQUE_MODE_PAGE_btn_run, TORQUE_MODE_PAGE_btn_run_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TORQUE_MODE_PAGE_slider_torque, TORQUE_MODE_PAGE_slider_torque_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TORQUE_MODE_PAGE_slider_speed, TORQUE_MODE_PAGE_slider_speed_event_handler, LV_EVENT_ALL, ui);
}

static void SYNC_MODE_PAGE_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.OPERATION_PAGE, guider_ui.OPERATION_PAGE_del, &guider_ui.SYNC_MODE_PAGE_del, setup_scr_OPERATION_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void SYNC_MODE_PAGE_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.OPERATION_PAGE, guider_ui.OPERATION_PAGE_del, &guider_ui.SYNC_MODE_PAGE_del, setup_scr_OPERATION_PAGE, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void SYNC_MODE_PAGE_btn_stop_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		break;
	}
	default:
		break;
	}
}

static void SYNC_MODE_PAGE_btn_run_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		break;
	}
	default:
		break;
	}
}

void events_init_SYNC_MODE_PAGE(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->SYNC_MODE_PAGE, SYNC_MODE_PAGE_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SYNC_MODE_PAGE_btn_back, SYNC_MODE_PAGE_btn_back_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SYNC_MODE_PAGE_btn_stop, SYNC_MODE_PAGE_btn_stop_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SYNC_MODE_PAGE_btn_run, SYNC_MODE_PAGE_btn_run_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{
}
