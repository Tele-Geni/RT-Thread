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



void setup_scr_ZeroMode(lv_ui *ui)
{
	//Write codes ZeroMode
	ui->ZeroMode = lv_obj_create(NULL);
	lv_obj_set_size(ui->ZeroMode, 240, 240);
	lv_obj_set_scrollbar_mode(ui->ZeroMode, LV_SCROLLBAR_MODE_OFF);

	//Write style for ZeroMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ZeroMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ZeroMode_btn_1
	ui->ZeroMode_btn_1 = lv_btn_create(ui->ZeroMode);
	ui->ZeroMode_btn_1_label = lv_label_create(ui->ZeroMode_btn_1);
	lv_label_set_text(ui->ZeroMode_btn_1_label, "Back");
	lv_label_set_long_mode(ui->ZeroMode_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ZeroMode_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ZeroMode_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->ZeroMode_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->ZeroMode_btn_1, 135, 190);
	lv_obj_set_size(ui->ZeroMode_btn_1, 90, 40);

	//Write style for ZeroMode_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ZeroMode_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ZeroMode_btn_1, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ZeroMode_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ZeroMode_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZeroMode_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZeroMode_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZeroMode_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZeroMode_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZeroMode_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZeroMode_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ZeroMode_btn_1, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->ZeroMode_btn_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->ZeroMode_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->ZeroMode_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->ZeroMode_btn_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->ZeroMode_btn_1, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->ZeroMode_btn_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->ZeroMode_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->ZeroMode_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->ZeroMode_btn_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//The custom code of ZeroMode.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->ZeroMode);

	//Init events for screen.
	events_init_ZeroMode(ui);
}
