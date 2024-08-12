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

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void Home_btn_entry_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.Home_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void Home_led_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		break;
	}
    default:
        break;
    }
}

void events_init_Home (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Home_btn_entry, Home_btn_entry_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_led_1, Home_led_1_event_handler, LV_EVENT_ALL, ui);
}

static void Operation_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		break;
	}
    default:
        break;
    }
}

static void Operation_btn_zero_mode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.ZeroMode, guider_ui.ZeroMode_del, &guider_ui.Operation_del, setup_scr_ZeroMode, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void Operation_btn_position_mode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.PositionMode, guider_ui.PositionMode_del, &guider_ui.Operation_del, setup_scr_PositionMode, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void Operation_btn_speed_mdoe_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.SpeedMode, guider_ui.SpeedMode_del, &guider_ui.Operation_del, setup_scr_SpeedMode, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void Operation_btn_current_mode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.CurrentMode, guider_ui.CurrentMode_del, &guider_ui.Operation_del, setup_scr_CurrentMode, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void Operation_btn_control_mode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.ControlMode, guider_ui.ControlMode_del, &guider_ui.Operation_del, setup_scr_ControlMode, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void Operation_btn_exit_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.Operation_del, setup_scr_Home, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

void events_init_Operation (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Operation, Operation_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_zero_mode, Operation_btn_zero_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_position_mode, Operation_btn_position_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_speed_mdoe, Operation_btn_speed_mdoe_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_current_mode, Operation_btn_current_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_control_mode, Operation_btn_control_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_exit, Operation_btn_exit_event_handler, LV_EVENT_ALL, ui);
}

static void ZeroMode_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.ZeroMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

void events_init_ZeroMode (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ZeroMode_btn_3, ZeroMode_btn_3_event_handler, LV_EVENT_ALL, ui);
}

static void PositionMode_btn_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.PositionMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void PositionMode_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		break;
	}
    default:
        break;
    }
}

static void PositionMode_slider_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		break;
	}
    default:
        break;
    }
}

void events_init_PositionMode (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->PositionMode_btn_back, PositionMode_btn_back_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->PositionMode_slider_1, PositionMode_slider_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->PositionMode_slider_2, PositionMode_slider_2_event_handler, LV_EVENT_ALL, ui);
}

static void SpeedMode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.SpeedMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void SpeedMode_btn_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.SpeedMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void SpeedMode_slider_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		break;
	}
    default:
        break;
    }
}

static void SpeedMode_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		break;
	}
    default:
        break;
    }
}

void events_init_SpeedMode (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->SpeedMode, SpeedMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SpeedMode_btn_back, SpeedMode_btn_back_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SpeedMode_slider_2, SpeedMode_slider_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SpeedMode_slider_1, SpeedMode_slider_1_event_handler, LV_EVENT_ALL, ui);
}

static void CurrentMode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.CurrentMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void CurrentMode_btn_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.CurrentMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void CurrentMode_slider_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		break;
	}
    default:
        break;
    }
}

static void CurrentMode_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		break;
	}
    default:
        break;
    }
}

void events_init_CurrentMode (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->CurrentMode, CurrentMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->CurrentMode_btn_back, CurrentMode_btn_back_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->CurrentMode_slider_2, CurrentMode_slider_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->CurrentMode_slider_1, CurrentMode_slider_1_event_handler, LV_EVENT_ALL, ui);
}

static void ControlMode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.ControlMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void ControlMode_btn_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.ControlMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void ControlMode_slider_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		break;
	}
    default:
        break;
    }
}

static void ControlMode_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		break;
	}
    default:
        break;
    }
}

void events_init_ControlMode (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ControlMode, ControlMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ControlMode_btn_back, ControlMode_btn_back_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ControlMode_slider_2, ControlMode_slider_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ControlMode_slider_1, ControlMode_slider_1_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
