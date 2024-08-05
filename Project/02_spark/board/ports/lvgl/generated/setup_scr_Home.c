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



void setup_scr_Home(lv_ui *ui)
{
	//Write codes Home
	ui->Home = lv_obj_create(NULL);
	lv_obj_set_size(ui->Home, 240, 240);
	lv_obj_set_scrollbar_mode(ui->Home, LV_SCROLLBAR_MODE_OFF);

	//Write style for Home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Home_img_1
	ui->Home_img_1 = lv_img_create(ui->Home);
	lv_obj_add_flag(ui->Home_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Home_img_1, &_home_alpha_240x240);
	lv_img_set_pivot(ui->Home_img_1, 50,50);
	lv_img_set_angle(ui->Home_img_1, 0);
	lv_obj_set_pos(ui->Home_img_1, 0, 0);
	lv_obj_set_size(ui->Home_img_1, 240, 240);

	//Write style for Home_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->Home_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->Home_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->Home_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Home_btn_entry
	ui->Home_btn_entry = lv_btn_create(ui->Home);
	ui->Home_btn_entry_label = lv_label_create(ui->Home_btn_entry);
	lv_label_set_text(ui->Home_btn_entry_label, "进入");
	lv_label_set_long_mode(ui->Home_btn_entry_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Home_btn_entry_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Home_btn_entry, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Home_btn_entry_label, LV_PCT(100));
	lv_obj_set_pos(ui->Home_btn_entry, 70, 95);
	lv_obj_set_size(ui->Home_btn_entry, 100, 50);

	//Write style for Home_btn_entry, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Home_btn_entry, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Home_btn_entry, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Home_btn_entry, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Home_btn_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_btn_entry, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_btn_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_btn_entry, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_btn_entry, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_btn_entry, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_btn_entry, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of Home.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->Home);

	//Init events for screen.
	events_init_Home(ui);
}
