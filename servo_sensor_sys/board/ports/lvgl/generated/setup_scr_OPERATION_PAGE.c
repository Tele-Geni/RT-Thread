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



void setup_scr_OPERATION_PAGE(lv_ui *ui)
{
	//Write codes OPERATION_PAGE
	ui->OPERATION_PAGE = lv_obj_create(NULL);
	lv_obj_set_size(ui->OPERATION_PAGE, 240, 240);
	lv_obj_set_scrollbar_mode(ui->OPERATION_PAGE, LV_SCROLLBAR_MODE_OFF);

	//Write style for OPERATION_PAGE, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes OPERATION_PAGE_btn_zero_mode
	ui->OPERATION_PAGE_btn_zero_mode = lv_btn_create(ui->OPERATION_PAGE);
	ui->OPERATION_PAGE_btn_zero_mode_label = lv_label_create(ui->OPERATION_PAGE_btn_zero_mode);
	lv_label_set_text(ui->OPERATION_PAGE_btn_zero_mode_label, "Zero Mode");
	lv_label_set_long_mode(ui->OPERATION_PAGE_btn_zero_mode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->OPERATION_PAGE_btn_zero_mode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->OPERATION_PAGE_btn_zero_mode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->OPERATION_PAGE_btn_zero_mode_label, LV_PCT(100));
	lv_obj_set_pos(ui->OPERATION_PAGE_btn_zero_mode, 15, 90);
	lv_obj_set_size(ui->OPERATION_PAGE_btn_zero_mode, 90, 40);

	//Write style for OPERATION_PAGE_btn_zero_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_zero_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_zero_mode, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_zero_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_zero_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_zero_mode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_zero_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_zero_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_zero_mode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_zero_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->OPERATION_PAGE_btn_zero_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for OPERATION_PAGE_btn_zero_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_zero_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_zero_mode, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_zero_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_zero_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_zero_mode, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_zero_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_zero_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_zero_mode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_zero_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes OPERATION_PAGE_btn_position_mode
	ui->OPERATION_PAGE_btn_position_mode = lv_btn_create(ui->OPERATION_PAGE);
	ui->OPERATION_PAGE_btn_position_mode_label = lv_label_create(ui->OPERATION_PAGE_btn_position_mode);
	lv_label_set_text(ui->OPERATION_PAGE_btn_position_mode_label, "Position Mode");
	lv_label_set_long_mode(ui->OPERATION_PAGE_btn_position_mode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->OPERATION_PAGE_btn_position_mode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->OPERATION_PAGE_btn_position_mode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->OPERATION_PAGE_btn_position_mode_label, LV_PCT(100));
	lv_obj_set_pos(ui->OPERATION_PAGE_btn_position_mode, 135, 90);
	lv_obj_set_size(ui->OPERATION_PAGE_btn_position_mode, 90, 40);

	//Write style for OPERATION_PAGE_btn_position_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_position_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_position_mode, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_position_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_position_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_position_mode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_position_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_position_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_position_mode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_position_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->OPERATION_PAGE_btn_position_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for OPERATION_PAGE_btn_position_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_position_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_position_mode, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_position_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_position_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_position_mode, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_position_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_position_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_position_mode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_position_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes OPERATION_PAGE_btn_speed_mdoe
	ui->OPERATION_PAGE_btn_speed_mdoe = lv_btn_create(ui->OPERATION_PAGE);
	ui->OPERATION_PAGE_btn_speed_mdoe_label = lv_label_create(ui->OPERATION_PAGE_btn_speed_mdoe);
	lv_label_set_text(ui->OPERATION_PAGE_btn_speed_mdoe_label, "Speed Mode");
	lv_label_set_long_mode(ui->OPERATION_PAGE_btn_speed_mdoe_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->OPERATION_PAGE_btn_speed_mdoe_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->OPERATION_PAGE_btn_speed_mdoe, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->OPERATION_PAGE_btn_speed_mdoe_label, LV_PCT(100));
	lv_obj_set_pos(ui->OPERATION_PAGE_btn_speed_mdoe, 15, 140);
	lv_obj_set_size(ui->OPERATION_PAGE_btn_speed_mdoe, 90, 40);

	//Write style for OPERATION_PAGE_btn_speed_mdoe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_speed_mdoe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_speed_mdoe, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_speed_mdoe, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_speed_mdoe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_speed_mdoe, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_speed_mdoe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_speed_mdoe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_speed_mdoe, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_speed_mdoe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->OPERATION_PAGE_btn_speed_mdoe, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for OPERATION_PAGE_btn_speed_mdoe, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_speed_mdoe, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_speed_mdoe, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_speed_mdoe, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_speed_mdoe, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_speed_mdoe, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_speed_mdoe, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_speed_mdoe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_speed_mdoe, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_speed_mdoe, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes OPERATION_PAGE_btn_current_mode
	ui->OPERATION_PAGE_btn_current_mode = lv_btn_create(ui->OPERATION_PAGE);
	ui->OPERATION_PAGE_btn_current_mode_label = lv_label_create(ui->OPERATION_PAGE_btn_current_mode);
	lv_label_set_text(ui->OPERATION_PAGE_btn_current_mode_label, "Torque Mode");
	lv_label_set_long_mode(ui->OPERATION_PAGE_btn_current_mode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->OPERATION_PAGE_btn_current_mode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->OPERATION_PAGE_btn_current_mode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->OPERATION_PAGE_btn_current_mode_label, LV_PCT(100));
	lv_obj_set_pos(ui->OPERATION_PAGE_btn_current_mode, 135, 140);
	lv_obj_set_size(ui->OPERATION_PAGE_btn_current_mode, 90, 40);

	//Write style for OPERATION_PAGE_btn_current_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_current_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_current_mode, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_current_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_current_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_current_mode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_current_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_current_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_current_mode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_current_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->OPERATION_PAGE_btn_current_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for OPERATION_PAGE_btn_current_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_current_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_current_mode, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_current_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_current_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_current_mode, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_current_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_current_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_current_mode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_current_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes OPERATION_PAGE_btn_control_mode
	ui->OPERATION_PAGE_btn_control_mode = lv_btn_create(ui->OPERATION_PAGE);
	ui->OPERATION_PAGE_btn_control_mode_label = lv_label_create(ui->OPERATION_PAGE_btn_control_mode);
	lv_label_set_text(ui->OPERATION_PAGE_btn_control_mode_label, "Sync Mode");
	lv_label_set_long_mode(ui->OPERATION_PAGE_btn_control_mode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->OPERATION_PAGE_btn_control_mode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->OPERATION_PAGE_btn_control_mode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->OPERATION_PAGE_btn_control_mode_label, LV_PCT(100));
	lv_obj_set_pos(ui->OPERATION_PAGE_btn_control_mode, 15, 190);
	lv_obj_set_size(ui->OPERATION_PAGE_btn_control_mode, 90, 40);

	//Write style for OPERATION_PAGE_btn_control_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_control_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_control_mode, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_control_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_control_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_control_mode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_control_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_control_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_control_mode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_control_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->OPERATION_PAGE_btn_control_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for OPERATION_PAGE_btn_control_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_control_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_control_mode, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_control_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_control_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_control_mode, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_control_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_control_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_control_mode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_control_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes OPERATION_PAGE_btn_exit
	ui->OPERATION_PAGE_btn_exit = lv_btn_create(ui->OPERATION_PAGE);
	ui->OPERATION_PAGE_btn_exit_label = lv_label_create(ui->OPERATION_PAGE_btn_exit);
	lv_label_set_text(ui->OPERATION_PAGE_btn_exit_label, "Exit");
	lv_label_set_long_mode(ui->OPERATION_PAGE_btn_exit_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->OPERATION_PAGE_btn_exit_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->OPERATION_PAGE_btn_exit, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->OPERATION_PAGE_btn_exit_label, LV_PCT(100));
	lv_obj_set_pos(ui->OPERATION_PAGE_btn_exit, 135, 190);
	lv_obj_set_size(ui->OPERATION_PAGE_btn_exit, 90, 40);

	//Write style for OPERATION_PAGE_btn_exit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_exit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_exit, lv_color_hex(0x928f77), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_exit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_exit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_exit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_exit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_exit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_exit, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_exit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->OPERATION_PAGE_btn_exit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for OPERATION_PAGE_btn_exit, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_btn_exit, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->OPERATION_PAGE_btn_exit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->OPERATION_PAGE_btn_exit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_btn_exit, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_btn_exit, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_btn_exit, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_btn_exit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_btn_exit, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_btn_exit, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes OPERATION_PAGE_label_1
	ui->OPERATION_PAGE_label_1 = lv_label_create(ui->OPERATION_PAGE);
	lv_label_set_text(ui->OPERATION_PAGE_label_1, "Motor Control System");
	lv_label_set_long_mode(ui->OPERATION_PAGE_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->OPERATION_PAGE_label_1, 11, 8);
	lv_obj_set_size(ui->OPERATION_PAGE_label_1, 220, 20);

	//Write style for OPERATION_PAGE_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_label_1, lv_color_hex(0xffc700), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_label_1, &lv_font_arial_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->OPERATION_PAGE_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->OPERATION_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->OPERATION_PAGE_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->OPERATION_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->OPERATION_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->OPERATION_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->OPERATION_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes OPERATION_PAGE_label_3
	ui->OPERATION_PAGE_label_3 = lv_label_create(ui->OPERATION_PAGE);
	lv_label_set_text(ui->OPERATION_PAGE_label_3, "Device ID");
	lv_label_set_long_mode(ui->OPERATION_PAGE_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->OPERATION_PAGE_label_3, 42, 34);
	lv_obj_set_size(ui->OPERATION_PAGE_label_3, 76, 36);

	//Write style for OPERATION_PAGE_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_label_3, lv_color_hex(0xffc700), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_label_3, &lv_font_arial_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->OPERATION_PAGE_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->OPERATION_PAGE_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->OPERATION_PAGE_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->OPERATION_PAGE_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->OPERATION_PAGE_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->OPERATION_PAGE_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->OPERATION_PAGE_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes OPERATION_PAGE_label_4
	ui->OPERATION_PAGE_label_4 = lv_label_create(ui->OPERATION_PAGE);
	lv_label_set_text(ui->OPERATION_PAGE_label_4, "2");
	lv_label_set_long_mode(ui->OPERATION_PAGE_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->OPERATION_PAGE_label_4, 167, 44);
	lv_obj_set_size(ui->OPERATION_PAGE_label_4, 26, 19);

	//Write style for OPERATION_PAGE_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->OPERATION_PAGE_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->OPERATION_PAGE_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->OPERATION_PAGE_label_4, lv_color_hex(0xffc700), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->OPERATION_PAGE_label_4, &lv_font_arial_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->OPERATION_PAGE_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->OPERATION_PAGE_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->OPERATION_PAGE_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->OPERATION_PAGE_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->OPERATION_PAGE_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->OPERATION_PAGE_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->OPERATION_PAGE_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->OPERATION_PAGE_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->OPERATION_PAGE_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->OPERATION_PAGE_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of OPERATION_PAGE.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->OPERATION_PAGE);

	//Init events for screen.
	events_init_OPERATION_PAGE(ui);
}
