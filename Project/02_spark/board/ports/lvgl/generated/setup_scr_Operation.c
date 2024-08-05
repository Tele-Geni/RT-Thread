/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_Operation(lv_ui *ui)
{
	//Write codes Operation
	ui->Operation = lv_obj_create(NULL);
	lv_obj_set_size(ui->Operation, 240, 240);
	lv_obj_set_scrollbar_mode(ui->Operation, LV_SCROLLBAR_MODE_OFF);

	//Write style for Operation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Operation_btn_zero_mode
	ui->Operation_btn_zero_mode = lv_btn_create(ui->Operation);
	ui->Operation_btn_zero_mode_label = lv_label_create(ui->Operation_btn_zero_mode);
	lv_label_set_text(ui->Operation_btn_zero_mode_label, "Zero Mode");
	lv_label_set_long_mode(ui->Operation_btn_zero_mode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Operation_btn_zero_mode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Operation_btn_zero_mode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Operation_btn_zero_mode_label, LV_PCT(100));
	lv_obj_set_pos(ui->Operation_btn_zero_mode, 15, 90);
	lv_obj_set_size(ui->Operation_btn_zero_mode, 90, 40);

	//Write style for Operation_btn_zero_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Operation_btn_zero_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Operation_btn_zero_mode, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_zero_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Operation_btn_zero_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Operation_btn_zero_mode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Operation_btn_zero_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Operation_btn_zero_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Operation_btn_zero_mode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Operation_btn_zero_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Operation_btn_zero_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Operation_btn_zero_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->Operation_btn_zero_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->Operation_btn_zero_mode, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_zero_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->Operation_btn_zero_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->Operation_btn_zero_mode, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->Operation_btn_zero_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->Operation_btn_zero_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->Operation_btn_zero_mode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->Operation_btn_zero_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes Operation_btn_position_mode
	ui->Operation_btn_position_mode = lv_btn_create(ui->Operation);
	ui->Operation_btn_position_mode_label = lv_label_create(ui->Operation_btn_position_mode);
	lv_label_set_text(ui->Operation_btn_position_mode_label, "Position Mode");
	lv_label_set_long_mode(ui->Operation_btn_position_mode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Operation_btn_position_mode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Operation_btn_position_mode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Operation_btn_position_mode_label, LV_PCT(100));
	lv_obj_set_pos(ui->Operation_btn_position_mode, 135, 90);
	lv_obj_set_size(ui->Operation_btn_position_mode, 90, 40);

	//Write style for Operation_btn_position_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Operation_btn_position_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Operation_btn_position_mode, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_position_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Operation_btn_position_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Operation_btn_position_mode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Operation_btn_position_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Operation_btn_position_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Operation_btn_position_mode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Operation_btn_position_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Operation_btn_position_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Operation_btn_position_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->Operation_btn_position_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->Operation_btn_position_mode, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_position_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->Operation_btn_position_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->Operation_btn_position_mode, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->Operation_btn_position_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->Operation_btn_position_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->Operation_btn_position_mode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->Operation_btn_position_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes Operation_btn_speed_mdoe
	ui->Operation_btn_speed_mdoe = lv_btn_create(ui->Operation);
	ui->Operation_btn_speed_mdoe_label = lv_label_create(ui->Operation_btn_speed_mdoe);
	lv_label_set_text(ui->Operation_btn_speed_mdoe_label, "Speed Mode");
	lv_label_set_long_mode(ui->Operation_btn_speed_mdoe_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Operation_btn_speed_mdoe_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Operation_btn_speed_mdoe, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Operation_btn_speed_mdoe_label, LV_PCT(100));
	lv_obj_set_pos(ui->Operation_btn_speed_mdoe, 15, 140);
	lv_obj_set_size(ui->Operation_btn_speed_mdoe, 90, 40);

	//Write style for Operation_btn_speed_mdoe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Operation_btn_speed_mdoe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Operation_btn_speed_mdoe, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_speed_mdoe, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Operation_btn_speed_mdoe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Operation_btn_speed_mdoe, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Operation_btn_speed_mdoe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Operation_btn_speed_mdoe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Operation_btn_speed_mdoe, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Operation_btn_speed_mdoe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Operation_btn_speed_mdoe, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Operation_btn_speed_mdoe, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->Operation_btn_speed_mdoe, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->Operation_btn_speed_mdoe, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_speed_mdoe, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->Operation_btn_speed_mdoe, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->Operation_btn_speed_mdoe, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->Operation_btn_speed_mdoe, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->Operation_btn_speed_mdoe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->Operation_btn_speed_mdoe, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->Operation_btn_speed_mdoe, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes Operation_btn_current_mode
	ui->Operation_btn_current_mode = lv_btn_create(ui->Operation);
	ui->Operation_btn_current_mode_label = lv_label_create(ui->Operation_btn_current_mode);
	lv_label_set_text(ui->Operation_btn_current_mode_label, "Current Mode");
	lv_label_set_long_mode(ui->Operation_btn_current_mode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Operation_btn_current_mode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Operation_btn_current_mode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Operation_btn_current_mode_label, LV_PCT(100));
	lv_obj_set_pos(ui->Operation_btn_current_mode, 135, 140);
	lv_obj_set_size(ui->Operation_btn_current_mode, 90, 40);

	//Write style for Operation_btn_current_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Operation_btn_current_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Operation_btn_current_mode, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_current_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Operation_btn_current_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Operation_btn_current_mode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Operation_btn_current_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Operation_btn_current_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Operation_btn_current_mode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Operation_btn_current_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Operation_btn_current_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Operation_btn_current_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->Operation_btn_current_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->Operation_btn_current_mode, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_current_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->Operation_btn_current_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->Operation_btn_current_mode, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->Operation_btn_current_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->Operation_btn_current_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->Operation_btn_current_mode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->Operation_btn_current_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes Operation_btn_control_mode
	ui->Operation_btn_control_mode = lv_btn_create(ui->Operation);
	ui->Operation_btn_control_mode_label = lv_label_create(ui->Operation_btn_control_mode);
	lv_label_set_text(ui->Operation_btn_control_mode_label, "Control Mode");
	lv_label_set_long_mode(ui->Operation_btn_control_mode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Operation_btn_control_mode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Operation_btn_control_mode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Operation_btn_control_mode_label, LV_PCT(100));
	lv_obj_set_pos(ui->Operation_btn_control_mode, 15, 190);
	lv_obj_set_size(ui->Operation_btn_control_mode, 90, 40);

	//Write style for Operation_btn_control_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Operation_btn_control_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Operation_btn_control_mode, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_control_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Operation_btn_control_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Operation_btn_control_mode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Operation_btn_control_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Operation_btn_control_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Operation_btn_control_mode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Operation_btn_control_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Operation_btn_control_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Operation_btn_control_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->Operation_btn_control_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->Operation_btn_control_mode, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_control_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->Operation_btn_control_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->Operation_btn_control_mode, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->Operation_btn_control_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->Operation_btn_control_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->Operation_btn_control_mode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->Operation_btn_control_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes Operation_btn_exit
	ui->Operation_btn_exit = lv_btn_create(ui->Operation);
	ui->Operation_btn_exit_label = lv_label_create(ui->Operation_btn_exit);
	lv_label_set_text(ui->Operation_btn_exit_label, "Exit");
	lv_label_set_long_mode(ui->Operation_btn_exit_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Operation_btn_exit_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Operation_btn_exit, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Operation_btn_exit_label, LV_PCT(100));
	lv_obj_set_pos(ui->Operation_btn_exit, 135, 190);
	lv_obj_set_size(ui->Operation_btn_exit, 90, 40);

	//Write style for Operation_btn_exit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Operation_btn_exit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Operation_btn_exit, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_exit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Operation_btn_exit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Operation_btn_exit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Operation_btn_exit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Operation_btn_exit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Operation_btn_exit, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Operation_btn_exit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Operation_btn_exit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Operation_btn_exit, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->Operation_btn_exit, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->Operation_btn_exit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->Operation_btn_exit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->Operation_btn_exit, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->Operation_btn_exit, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->Operation_btn_exit, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->Operation_btn_exit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->Operation_btn_exit, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->Operation_btn_exit, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes Operation_label_1
	ui->Operation_label_1 = lv_label_create(ui->Operation);
	lv_label_set_text(ui->Operation_label_1, "Motor Control System");
	lv_label_set_long_mode(ui->Operation_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Operation_label_1, 11, 12);
	lv_obj_set_size(ui->Operation_label_1, 220, 20);

	//Write style for Operation_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Operation_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Operation_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Operation_label_1, lv_color_hex(0xffc700), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Operation_label_1, &lv_font_arial_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Operation_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Operation_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Operation_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Operation_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Operation_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Operation_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Operation_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Operation_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Operation_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Operation_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Operation_ta_motor_id
	ui->Operation_ta_motor_id = lv_textarea_create(ui->Operation);
	lv_textarea_set_text(ui->Operation_ta_motor_id, "");
	lv_textarea_set_placeholder_text(ui->Operation_ta_motor_id, "");
	lv_textarea_set_password_bullet(ui->Operation_ta_motor_id, "*");
	lv_textarea_set_password_mode(ui->Operation_ta_motor_id, false);
	lv_textarea_set_one_line(ui->Operation_ta_motor_id, false);
	lv_textarea_set_accepted_chars(ui->Operation_ta_motor_id, "");
	lv_textarea_set_max_length(ui->Operation_ta_motor_id, 32);
	lv_obj_set_pos(ui->Operation_ta_motor_id, 93, 46);
	lv_obj_set_size(ui->Operation_ta_motor_id, 130, 30);

	//Write style for Operation_ta_motor_id, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Operation_ta_motor_id, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Operation_ta_motor_id, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Operation_ta_motor_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Operation_ta_motor_id, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Operation_ta_motor_id, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Operation_ta_motor_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Operation_ta_motor_id, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Operation_ta_motor_id, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Operation_ta_motor_id, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Operation_ta_motor_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Operation_ta_motor_id, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Operation_ta_motor_id, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Operation_ta_motor_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Operation_ta_motor_id, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Operation_ta_motor_id, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Operation_ta_motor_id, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Operation_ta_motor_id, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Operation_ta_motor_id, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Operation_ta_motor_id, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Operation_ta_motor_id, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Operation_ta_motor_id, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Operation_ta_motor_id, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes Operation_label_3
	ui->Operation_label_3 = lv_label_create(ui->Operation);
	lv_label_set_text(ui->Operation_label_3, "Device ID");
	lv_label_set_long_mode(ui->Operation_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Operation_label_3, 16, 48);
	lv_obj_set_size(ui->Operation_label_3, 76, 29);

	//Write style for Operation_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Operation_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Operation_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Operation_label_3, lv_color_hex(0xffc700), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Operation_label_3, &lv_font_arial_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Operation_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Operation_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Operation_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Operation_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Operation_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Operation_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Operation_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Operation_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Operation_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Operation_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of Operation.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->Operation);

	//Init events for screen.
	events_init_Operation(ui);
}
