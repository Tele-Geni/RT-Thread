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



void setup_scr_CurrentMode(lv_ui *ui)
{
	//Write codes CurrentMode
	ui->CurrentMode = lv_obj_create(NULL);
	lv_obj_set_size(ui->CurrentMode, 240, 240);
	lv_obj_set_scrollbar_mode(ui->CurrentMode, LV_SCROLLBAR_MODE_OFF);

	//Write style for CurrentMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->CurrentMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes CurrentMode_btn_back
	ui->CurrentMode_btn_back = lv_btn_create(ui->CurrentMode);
	ui->CurrentMode_btn_back_label = lv_label_create(ui->CurrentMode_btn_back);
	lv_label_set_text(ui->CurrentMode_btn_back_label, "Back");
	lv_label_set_long_mode(ui->CurrentMode_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->CurrentMode_btn_back_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->CurrentMode_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->CurrentMode_btn_back_label, LV_PCT(100));
	lv_obj_set_pos(ui->CurrentMode_btn_back, 135, 189);
	lv_obj_set_size(ui->CurrentMode_btn_back, 90, 40);

	//Write style for CurrentMode_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->CurrentMode_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->CurrentMode_btn_back, lv_color_hex(0x928f77), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_btn_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->CurrentMode_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_btn_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->CurrentMode_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CurrentMode_btn_back, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->CurrentMode_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->CurrentMode_btn_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for CurrentMode_btn_back, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->CurrentMode_btn_back, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->CurrentMode_btn_back, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_btn_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->CurrentMode_btn_back, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->CurrentMode_btn_back, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->CurrentMode_btn_back, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->CurrentMode_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->CurrentMode_btn_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->CurrentMode_btn_back, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes CurrentMode_btn_run
	ui->CurrentMode_btn_run = lv_btn_create(ui->CurrentMode);
	ui->CurrentMode_btn_run_label = lv_label_create(ui->CurrentMode_btn_run);
	lv_label_set_text(ui->CurrentMode_btn_run_label, "Run");
	lv_label_set_long_mode(ui->CurrentMode_btn_run_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->CurrentMode_btn_run_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->CurrentMode_btn_run, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->CurrentMode_btn_run_label, LV_PCT(100));
	lv_obj_set_pos(ui->CurrentMode_btn_run, 15, 190);
	lv_obj_set_size(ui->CurrentMode_btn_run, 90, 40);

	//Write style for CurrentMode_btn_run, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->CurrentMode_btn_run, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->CurrentMode_btn_run, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_btn_run, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->CurrentMode_btn_run, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_btn_run, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_btn_run, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->CurrentMode_btn_run, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CurrentMode_btn_run, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->CurrentMode_btn_run, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->CurrentMode_btn_run, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for CurrentMode_btn_run, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->CurrentMode_btn_run, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->CurrentMode_btn_run, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_btn_run, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->CurrentMode_btn_run, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->CurrentMode_btn_run, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->CurrentMode_btn_run, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->CurrentMode_btn_run, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->CurrentMode_btn_run, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->CurrentMode_btn_run, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//The custom code of CurrentMode.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->CurrentMode);

	//Init events for screen.
	events_init_CurrentMode(ui);
}
