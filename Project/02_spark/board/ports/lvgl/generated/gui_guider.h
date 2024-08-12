/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

	typedef struct
	{

		lv_obj_t *Home;
		bool Home_del;
		lv_obj_t *Home_img_1;
		lv_obj_t *Home_btn_entry;
		lv_obj_t *Home_btn_entry_label;
		lv_obj_t *Home_cont_1;
		lv_obj_t *Home_spangroup_1;
		lv_span_t *Home_spangroup_1_span;
		lv_obj_t *Home_spangroup_2;
		lv_span_t *Home_spangroup_2_span;
		lv_obj_t *Home_spangroup_3;
		lv_span_t *Home_spangroup_3_span;
		lv_obj_t *Home_spangroup_4;
		lv_span_t *Home_spangroup_4_span;
		lv_obj_t *Home_led_1;
		lv_obj_t *Home_label_temp;
		lv_obj_t *Home_label_humi;
		lv_obj_t *Home_label_1;
		lv_obj_t *Home_label_2;
		lv_obj_t *Home_label_acc_x;
		lv_obj_t *Home_label_acc_y;
		lv_obj_t *Home_label_acc_z;
		lv_obj_t *Home_label_gyro_x;
		lv_obj_t *Home_label_gyro_y;
		lv_obj_t *Home_label_gyro_z;
		lv_obj_t *Home_label_9;
		lv_obj_t *Home_label_10;
		lv_obj_t *Home_label_11;
		lv_obj_t *Home_line_1;
		lv_obj_t *Home_digital_clock_1;
		lv_obj_t *Operation;
		bool Operation_del;
		lv_obj_t *Operation_btn_zero_mode;
		lv_obj_t *Operation_btn_zero_mode_label;
		lv_obj_t *Operation_btn_position_mode;
		lv_obj_t *Operation_btn_position_mode_label;
		lv_obj_t *Operation_btn_speed_mdoe;
		lv_obj_t *Operation_btn_speed_mdoe_label;
		lv_obj_t *Operation_btn_current_mode;
		lv_obj_t *Operation_btn_current_mode_label;
		lv_obj_t *Operation_btn_control_mode;
		lv_obj_t *Operation_btn_control_mode_label;
		lv_obj_t *Operation_btn_exit;
		lv_obj_t *Operation_btn_exit_label;
		lv_obj_t *Operation_label_1;
		lv_obj_t *Operation_ta_motor_id;
		lv_obj_t *Operation_label_3;
		lv_obj_t *ZeroMode;
		bool ZeroMode_del;
		lv_obj_t *ZeroMode_btn_run;
		lv_obj_t *ZeroMode_btn_run_label;
		lv_obj_t *ZeroMode_label_1;
		lv_obj_t *ZeroMode_cont_1;
		lv_obj_t *ZeroMode_spangroup_1;
		lv_span_t *ZeroMode_spangroup_1_span;
		lv_obj_t *ZeroMode_label_2;
		lv_obj_t *ZeroMode_spangroup_2;
		lv_span_t *ZeroMode_spangroup_2_span;
		lv_obj_t *ZeroMode_label_3;
		lv_obj_t *ZeroMode_spangroup_3;
		lv_span_t *ZeroMode_spangroup_3_span;
		lv_obj_t *ZeroMode_label_4;
		lv_obj_t *ZeroMode_label_5;
		lv_obj_t *ZeroMode_label_6;
		lv_obj_t *ZeroMode_label_7;
		lv_obj_t *ZeroMode_btn_2;
		lv_obj_t *ZeroMode_btn_2_label;
		lv_obj_t *ZeroMode_btn_3;
		lv_obj_t *ZeroMode_btn_3_label;
		lv_obj_t *PositionMode;
		bool PositionMode_del;
		lv_obj_t *PositionMode_cont_1;
		lv_obj_t *PositionMode_btn_back;
		lv_obj_t *PositionMode_btn_back_label;
		lv_obj_t *PositionMode_btn_run;
		lv_obj_t *PositionMode_btn_run_label;
		lv_obj_t *PositionMode_spangroup_3;
		lv_span_t *PositionMode_spangroup_3_span;
		lv_obj_t *PositionMode_spangroup_2;
		lv_span_t *PositionMode_spangroup_2_span;
		lv_obj_t *PositionMode_spangroup_1;
		lv_span_t *PositionMode_spangroup_1_span;
		lv_obj_t *PositionMode_label_6;
		lv_obj_t *PositionMode_label_5;
		lv_obj_t *PositionMode_label_4;
		lv_obj_t *PositionMode_label_3;
		lv_obj_t *PositionMode_label_2;
		lv_obj_t *PositionMode_label_1;
		lv_obj_t *PositionMode_label_7;
		lv_obj_t *PositionMode_btn_1;
		lv_obj_t *PositionMode_btn_1_label;
		lv_obj_t *PositionMode_slider_1;
		lv_obj_t *PositionMode_spangroup_4;
		lv_span_t *PositionMode_spangroup_4_span;
		lv_obj_t *PositionMode_slider_2;
		lv_obj_t *PositionMode_spangroup_5;
		lv_span_t *PositionMode_spangroup_5_span;
		lv_obj_t *SpeedMode;
		bool SpeedMode_del;
		lv_obj_t *SpeedMode_cont_1;
		lv_obj_t *SpeedMode_btn_back;
		lv_obj_t *SpeedMode_btn_back_label;
		lv_obj_t *SpeedMode_btn_run;
		lv_obj_t *SpeedMode_btn_run_label;
		lv_obj_t *SpeedMode_spangroup_3;
		lv_span_t *SpeedMode_spangroup_3_span;
		lv_obj_t *SpeedMode_spangroup_2;
		lv_span_t *SpeedMode_spangroup_2_span;
		lv_obj_t *SpeedMode_spangroup_1;
		lv_span_t *SpeedMode_spangroup_1_span;
		lv_obj_t *SpeedMode_label_6;
		lv_obj_t *SpeedMode_label_5;
		lv_obj_t *SpeedMode_label_4;
		lv_obj_t *SpeedMode_label_3;
		lv_obj_t *SpeedMode_label_2;
		lv_obj_t *SpeedMode_label_1;
		lv_obj_t *SpeedMode_label_7;
		lv_obj_t *SpeedMode_btn_1;
		lv_obj_t *SpeedMode_btn_1_label;
		lv_obj_t *SpeedMode_slider_2;
		lv_obj_t *SpeedMode_spangroup_5;
		lv_span_t *SpeedMode_spangroup_5_span;
		lv_obj_t *SpeedMode_slider_1;
		lv_obj_t *SpeedMode_spangroup_4;
		lv_span_t *SpeedMode_spangroup_4_span;
		lv_obj_t *CurrentMode;
		bool CurrentMode_del;
		lv_obj_t *CurrentMode_cont_1;
		lv_obj_t *CurrentMode_btn_back;
		lv_obj_t *CurrentMode_btn_back_label;
		lv_obj_t *CurrentMode_btn_run;
		lv_obj_t *CurrentMode_btn_run_label;
		lv_obj_t *CurrentMode_spangroup_3;
		lv_span_t *CurrentMode_spangroup_3_span;
		lv_obj_t *CurrentMode_spangroup_2;
		lv_span_t *CurrentMode_spangroup_2_span;
		lv_obj_t *CurrentMode_spangroup_1;
		lv_span_t *CurrentMode_spangroup_1_span;
		lv_obj_t *CurrentMode_label_6;
		lv_obj_t *CurrentMode_label_5;
		lv_obj_t *CurrentMode_label_4;
		lv_obj_t *CurrentMode_label_3;
		lv_obj_t *CurrentMode_label_2;
		lv_obj_t *CurrentMode_label_1;
		lv_obj_t *CurrentMode_label_7;
		lv_obj_t *CurrentMode_btn_1;
		lv_obj_t *CurrentMode_btn_1_label;
		lv_obj_t *CurrentMode_slider_2;
		lv_obj_t *CurrentMode_spangroup_5;
		lv_span_t *CurrentMode_spangroup_5_span;
		lv_obj_t *CurrentMode_slider_1;
		lv_obj_t *CurrentMode_spangroup_4;
		lv_span_t *CurrentMode_spangroup_4_span;
		lv_obj_t *ControlMode;
		bool ControlMode_del;
		lv_obj_t *ControlMode_cont_1;
		lv_obj_t *ControlMode_btn_back;
		lv_obj_t *ControlMode_btn_back_label;
		lv_obj_t *ControlMode_btn_run;
		lv_obj_t *ControlMode_btn_run_label;
		lv_obj_t *ControlMode_spangroup_3;
		lv_span_t *ControlMode_spangroup_3_span;
		lv_obj_t *ControlMode_spangroup_2;
		lv_span_t *ControlMode_spangroup_2_span;
		lv_obj_t *ControlMode_spangroup_1;
		lv_span_t *ControlMode_spangroup_1_span;
		lv_obj_t *ControlMode_label_6;
		lv_obj_t *ControlMode_label_5;
		lv_obj_t *ControlMode_label_4;
		lv_obj_t *ControlMode_label_3;
		lv_obj_t *ControlMode_label_2;
		lv_obj_t *ControlMode_label_1;
		lv_obj_t *ControlMode_label_7;
		lv_obj_t *ControlMode_btn_1;
		lv_obj_t *ControlMode_btn_1_label;
		lv_obj_t *ControlMode_slider_2;
		lv_obj_t *ControlMode_spangroup_5;
		lv_span_t *ControlMode_spangroup_5_span;
		lv_obj_t *ControlMode_slider_1;
		lv_obj_t *ControlMode_spangroup_4;
		lv_span_t *ControlMode_spangroup_4_span;
	} lv_ui;

	typedef void (*ui_setup_scr_t)(lv_ui *ui);

	void ui_init_style(lv_style_t *style);

	void ui_load_scr_animation(lv_ui *ui, lv_obj_t **new_scr, bool new_scr_del, bool *old_scr_del, ui_setup_scr_t setup_scr,
							   lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

	void ui_animation(void *var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
					  uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
					  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

	void init_scr_del_flag(lv_ui *ui);

	void setup_ui(lv_ui *ui);

	extern lv_ui guider_ui;

	void setup_scr_Home(lv_ui *ui);
	void setup_scr_Operation(lv_ui *ui);
	void setup_scr_ZeroMode(lv_ui *ui);
	void setup_scr_PositionMode(lv_ui *ui);
	void setup_scr_SpeedMode(lv_ui *ui);
	void setup_scr_CurrentMode(lv_ui *ui);
	void setup_scr_ControlMode(lv_ui *ui);
	LV_IMG_DECLARE(_home_alpha_240x240);

	LV_FONT_DECLARE(lv_font_montserratMedium_16)
	LV_FONT_DECLARE(lv_font_montserratMedium_12)
	LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
	LV_FONT_DECLARE(lv_font_montserratMedium_10)
	LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_14)
	LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_12)
	LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_11)
	LV_FONT_DECLARE(lv_font_arial_18)
	LV_FONT_DECLARE(lv_font_arial_16)
	LV_FONT_DECLARE(lv_font_montserratMedium_7)

#ifdef __cplusplus
}
#endif
#endif
