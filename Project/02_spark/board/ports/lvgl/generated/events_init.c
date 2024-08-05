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
#include <rtthread.h>
#include "lvgl_thread.h"

#define LOG_TAG "lvglevent.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

extern PageState_t g_current_page;
extern rt_mutex_t g_fresh_mutex;

static void Home_btn_entry_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.Home_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void Home_led_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	rt_err_t ret = RT_NULL;
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		extern rt_sem_t g_led_sem;
		rt_sem_take(g_led_sem, 5);
		if (HOME_PAGE == g_current_page &&
			RT_NULL == ret)
		{
			rt_mutex_take(g_fresh_mutex, RT_WAITING_FOREVER);
			lv_led_toggle(guider_ui.Home_led_1);
			rt_mutex_release(g_fresh_mutex);
		}
		break;
	}
	default:
		break;
	}
}

static void Home_label_temp_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	float recvbuf[2] = {0};
	rt_ssize_t ret = RT_NULL;
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		extern rt_mq_t g_aht10_mq;
		ret = rt_mq_recv(g_aht10_mq, recvbuf, sizeof(recvbuf), 5);
		LOG_D("aht10 rt_mq_recv ret : %d", ret);
		if (HOME_PAGE == g_current_page &&
			sizeof(recvbuf) == ret)
		{
			rt_mutex_take(g_fresh_mutex, RT_WAITING_FOREVER);
			lv_label_set_text_fmt(guider_ui.Home_label_temp, "%.2f", recvbuf[0]);
			lv_label_set_text_fmt(guider_ui.Home_label_humi, "%.2f", recvbuf[1]);
			rt_mutex_release(g_fresh_mutex);
		}
		break;
	}
	default:
		break;
	}
}

static void Home_label_humi_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		/* in Home_label_temp_event_handler function process */
		break;
	}
	default:
		break;
	}
}

static void Home_label_acc_x_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	rt_int16_t g_icm_recvbuf[6] = {0};
	rt_ssize_t ret = RT_NULL;
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		extern rt_mq_t g_icm20608_mq;
		ret = rt_mq_recv(g_icm20608_mq, g_icm_recvbuf, sizeof(g_icm_recvbuf), 5);
		LOG_D("icm20680 rt_mq_recv ret : %d", ret);
		if (HOME_PAGE == g_current_page &&
			sizeof(g_icm_recvbuf) == ret)
		{
			rt_mutex_take(g_fresh_mutex, RT_WAITING_FOREVER);
			lv_label_set_text_fmt(guider_ui.Home_label_acc_x, "%5d", g_icm_recvbuf[0]);
			lv_label_set_text_fmt(guider_ui.Home_label_acc_y, "%5d", g_icm_recvbuf[1]);
			lv_label_set_text_fmt(guider_ui.Home_label_acc_z, "%5d", g_icm_recvbuf[2]);
			lv_label_set_text_fmt(guider_ui.Home_label_gyro_x, "%5d", g_icm_recvbuf[3]);
			lv_label_set_text_fmt(guider_ui.Home_label_gyro_y, "%5d", g_icm_recvbuf[4]);
			lv_label_set_text_fmt(guider_ui.Home_label_gyro_z, "%5d", g_icm_recvbuf[5]);
			rt_mutex_release(g_fresh_mutex);
		}
		break;
	}
	default:
		break;
	}
}

static void Home_label_acc_y_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		/* in Home_label_acc_x_event_handler function process */
		break;
	}
	default:
		break;
	}
}

static void Home_label_acc_z_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		/* in Home_label_acc_x_event_handler function process */
		break;
	}
	default:
		break;
	}
}

static void Home_label_gyro_x_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		/* in Home_label_acc_x_event_handler function process */
		break;
	}
	default:
		break;
	}
}

static void Home_label_gyro_y_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		/* in Home_label_acc_x_event_handler function process */
		break;
	}
	default:
		break;
	}
}

static void Home_label_gyro_z_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		/* in Home_label_acc_x_event_handler function process */
		break;
	}
	default:
		break;
	}
}

void events_init_Home(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Home_btn_entry, Home_btn_entry_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_led_1, Home_led_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_label_temp, Home_label_temp_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_label_humi, Home_label_humi_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_label_acc_x, Home_label_acc_x_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_label_acc_y, Home_label_acc_y_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_label_acc_z, Home_label_acc_z_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_label_gyro_x, Home_label_gyro_x_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_label_gyro_y, Home_label_gyro_y_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_label_gyro_z, Home_label_gyro_z_event_handler, LV_EVENT_ALL, ui);
}

static void Operation_event_handler(lv_event_t *e)
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

static void Operation_btn_zero_mode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.ZeroMode, guider_ui.ZeroMode_del, &guider_ui.Operation_del, setup_scr_ZeroMode, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void Operation_btn_position_mode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.PositionMode, guider_ui.PositionMode_del, &guider_ui.Operation_del, setup_scr_PositionMode, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void Operation_btn_speed_mdoe_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.SpeedMode, guider_ui.SpeedMode_del, &guider_ui.Operation_del, setup_scr_SpeedMode, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void Operation_btn_current_mode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.CurrentMode, guider_ui.CurrentMode_del, &guider_ui.Operation_del, setup_scr_CurrentMode, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void Operation_btn_control_mode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.ControlMode, guider_ui.ControlMode_del, &guider_ui.Operation_del, setup_scr_ControlMode, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void Operation_btn_exit_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.Operation_del, setup_scr_Home, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

void events_init_Operation(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Operation, Operation_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_zero_mode, Operation_btn_zero_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_position_mode, Operation_btn_position_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_speed_mdoe, Operation_btn_speed_mdoe_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_current_mode, Operation_btn_current_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_control_mode, Operation_btn_control_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Operation_btn_exit, Operation_btn_exit_event_handler, LV_EVENT_ALL, ui);
}

static void ZeroMode_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.ZeroMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}

void events_init_ZeroMode(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ZeroMode_btn_back, ZeroMode_btn_back_event_handler, LV_EVENT_ALL, ui);
}

static void PositionMode_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.PositionMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}

void events_init_PositionMode(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->PositionMode_btn_back, PositionMode_btn_back_event_handler, LV_EVENT_ALL, ui);
}

static void SpeedMode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.SpeedMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void SpeedMode_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.SpeedMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}

void events_init_SpeedMode(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->SpeedMode, SpeedMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SpeedMode_btn_back, SpeedMode_btn_back_event_handler, LV_EVENT_ALL, ui);
}

static void CurrentMode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.CurrentMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void CurrentMode_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.CurrentMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}

void events_init_CurrentMode(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->CurrentMode, CurrentMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->CurrentMode_btn_back, CurrentMode_btn_back_event_handler, LV_EVENT_ALL, ui);
}

static void ControlMode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.ControlMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void ControlMode_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Operation, guider_ui.Operation_del, &guider_ui.ControlMode_del, setup_scr_Operation, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}

void events_init_ControlMode(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ControlMode, ControlMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ControlMode_btn_back, ControlMode_btn_back_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{
}
