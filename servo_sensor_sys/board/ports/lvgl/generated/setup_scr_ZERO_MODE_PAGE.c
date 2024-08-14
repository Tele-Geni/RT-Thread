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



void setup_scr_ZERO_MODE_PAGE(lv_ui *ui)
{
	//Write codes ZERO_MODE_PAGE
	ui->ZERO_MODE_PAGE = lv_obj_create(NULL);
	lv_obj_set_size(ui->ZERO_MODE_PAGE, 240, 240);
	lv_obj_set_scrollbar_mode(ui->ZERO_MODE_PAGE, LV_SCROLLBAR_MODE_OFF);

	//Write style for ZERO_MODE_PAGE, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ZERO_MODE_PAGE_btn_back
	ui->ZERO_MODE_PAGE_btn_back = lv_btn_create(ui->ZERO_MODE_PAGE);
	ui->ZERO_MODE_PAGE_btn_back_label = lv_label_create(ui->ZERO_MODE_PAGE_btn_back);
	lv_label_set_text(ui->ZERO_MODE_PAGE_btn_back_label, "Back");
	lv_label_set_long_mode(ui->ZERO_MODE_PAGE_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ZERO_MODE_PAGE_btn_back_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ZERO_MODE_PAGE_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->ZERO_MODE_PAGE_btn_back_label, LV_PCT(100));
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_btn_back, 165, 190);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_btn_back, 60, 40);

	//Write style for ZERO_MODE_PAGE_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ZERO_MODE_PAGE_btn_back, lv_color_hex(0x928f77), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ZERO_MODE_PAGE_btn_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_btn_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_btn_back, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZERO_MODE_PAGE_btn_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ZERO_MODE_PAGE_btn_back, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_btn_back, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->ZERO_MODE_PAGE_btn_back, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->ZERO_MODE_PAGE_btn_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_btn_back, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_btn_back, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_btn_back, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_btn_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_btn_back, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes ZERO_MODE_PAGE_btn_stop
	ui->ZERO_MODE_PAGE_btn_stop = lv_btn_create(ui->ZERO_MODE_PAGE);
	ui->ZERO_MODE_PAGE_btn_stop_label = lv_label_create(ui->ZERO_MODE_PAGE_btn_stop);
	lv_label_set_text(ui->ZERO_MODE_PAGE_btn_stop_label, "Stop");
	lv_label_set_long_mode(ui->ZERO_MODE_PAGE_btn_stop_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ZERO_MODE_PAGE_btn_stop_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ZERO_MODE_PAGE_btn_stop, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->ZERO_MODE_PAGE_btn_stop_label, LV_PCT(100));
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_btn_stop, 90, 190);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_btn_stop, 60, 40);

	//Write style for ZERO_MODE_PAGE_btn_stop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_btn_stop, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ZERO_MODE_PAGE_btn_stop, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ZERO_MODE_PAGE_btn_stop, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_btn_stop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_btn_stop, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_btn_stop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_btn_stop, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_btn_stop, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_btn_stop, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZERO_MODE_PAGE_btn_stop, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ZERO_MODE_PAGE_btn_stop, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_btn_stop, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->ZERO_MODE_PAGE_btn_stop, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->ZERO_MODE_PAGE_btn_stop, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_btn_stop, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_btn_stop, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_btn_stop, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_btn_stop, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_btn_stop, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_btn_stop, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes ZERO_MODE_PAGE_btn_run
	ui->ZERO_MODE_PAGE_btn_run = lv_btn_create(ui->ZERO_MODE_PAGE);
	ui->ZERO_MODE_PAGE_btn_run_label = lv_label_create(ui->ZERO_MODE_PAGE_btn_run);
	lv_label_set_text(ui->ZERO_MODE_PAGE_btn_run_label, "Run");
	lv_label_set_long_mode(ui->ZERO_MODE_PAGE_btn_run_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ZERO_MODE_PAGE_btn_run_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ZERO_MODE_PAGE_btn_run, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->ZERO_MODE_PAGE_btn_run_label, LV_PCT(100));
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_btn_run, 15, 190);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_btn_run, 60, 40);

	//Write style for ZERO_MODE_PAGE_btn_run, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_btn_run, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ZERO_MODE_PAGE_btn_run, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ZERO_MODE_PAGE_btn_run, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_btn_run, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_btn_run, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_btn_run, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_btn_run, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_btn_run, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_btn_run, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZERO_MODE_PAGE_btn_run, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ZERO_MODE_PAGE_btn_run, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_btn_run, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->ZERO_MODE_PAGE_btn_run, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->ZERO_MODE_PAGE_btn_run, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_btn_run, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_btn_run, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_btn_run, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_btn_run, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_btn_run, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_btn_run, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes ZERO_MODE_PAGE_label_1
	ui->ZERO_MODE_PAGE_label_1 = lv_label_create(ui->ZERO_MODE_PAGE);
	lv_label_set_text(ui->ZERO_MODE_PAGE_label_1, "Zero Mode");
	lv_label_set_long_mode(ui->ZERO_MODE_PAGE_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_label_1, 11, 10);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_label_1, 220, 20);

	//Write style for ZERO_MODE_PAGE_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_label_1, lv_color_hex(0xffc700), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_label_1, &lv_font_arial_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ZERO_MODE_PAGE_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ZERO_MODE_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZERO_MODE_PAGE_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ZERO_MODE_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ZERO_MODE_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ZERO_MODE_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ZERO_MODE_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ZERO_MODE_PAGE_cont_1
	ui->ZERO_MODE_PAGE_cont_1 = lv_obj_create(ui->ZERO_MODE_PAGE);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_cont_1, 30, 55);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_cont_1, 180, 80);
	lv_obj_set_scrollbar_mode(ui->ZERO_MODE_PAGE_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ZERO_MODE_PAGE_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ZERO_MODE_PAGE_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ZERO_MODE_PAGE_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->ZERO_MODE_PAGE_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ZERO_MODE_PAGE_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ZERO_MODE_PAGE_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ZERO_MODE_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ZERO_MODE_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ZERO_MODE_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ZERO_MODE_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ZERO_MODE_PAGE_spangroup_1
	ui->ZERO_MODE_PAGE_spangroup_1 = lv_spangroup_create(ui->ZERO_MODE_PAGE);
	lv_spangroup_set_align(ui->ZERO_MODE_PAGE_spangroup_1, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->ZERO_MODE_PAGE_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->ZERO_MODE_PAGE_spangroup_1, LV_SPAN_MODE_BREAK);
	//create span 
	ui->ZERO_MODE_PAGE_spangroup_1_span = lv_spangroup_new_span(ui->ZERO_MODE_PAGE_spangroup_1);
	lv_span_set_text(ui->ZERO_MODE_PAGE_spangroup_1_span, "位置：");
	lv_style_set_text_color(&ui->ZERO_MODE_PAGE_spangroup_1_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->ZERO_MODE_PAGE_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->ZERO_MODE_PAGE_spangroup_1_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_spangroup_1, 41, 62);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_spangroup_1, 50, 18);

	//Write style state: LV_STATE_DEFAULT for &style_ZERO_MODE_PAGE_spangroup_1_main_main_default
	static lv_style_t style_ZERO_MODE_PAGE_spangroup_1_main_main_default;
	ui_init_style(&style_ZERO_MODE_PAGE_spangroup_1_main_main_default);
	
	lv_style_set_border_width(&style_ZERO_MODE_PAGE_spangroup_1_main_main_default, 0);
	lv_style_set_radius(&style_ZERO_MODE_PAGE_spangroup_1_main_main_default, 0);
	lv_style_set_bg_opa(&style_ZERO_MODE_PAGE_spangroup_1_main_main_default, 0);
	lv_style_set_pad_top(&style_ZERO_MODE_PAGE_spangroup_1_main_main_default, 0);
	lv_style_set_pad_right(&style_ZERO_MODE_PAGE_spangroup_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ZERO_MODE_PAGE_spangroup_1_main_main_default, 0);
	lv_style_set_pad_left(&style_ZERO_MODE_PAGE_spangroup_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_ZERO_MODE_PAGE_spangroup_1_main_main_default, 0);
	lv_obj_add_style(ui->ZERO_MODE_PAGE_spangroup_1, &style_ZERO_MODE_PAGE_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->ZERO_MODE_PAGE_spangroup_1);

	//Write codes ZERO_MODE_PAGE_label_pos
	ui->ZERO_MODE_PAGE_label_pos = lv_label_create(ui->ZERO_MODE_PAGE);
	lv_label_set_text(ui->ZERO_MODE_PAGE_label_pos, "0");
	lv_label_set_long_mode(ui->ZERO_MODE_PAGE_label_pos, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_label_pos, 107, 65);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_label_pos, 50, 12);

	//Write style for ZERO_MODE_PAGE_label_pos, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_label_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_label_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_label_pos, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_label_pos, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_label_pos, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ZERO_MODE_PAGE_label_pos, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ZERO_MODE_PAGE_label_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZERO_MODE_PAGE_label_pos, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_label_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ZERO_MODE_PAGE_label_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ZERO_MODE_PAGE_label_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ZERO_MODE_PAGE_label_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ZERO_MODE_PAGE_label_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_label_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ZERO_MODE_PAGE_spangroup_2
	ui->ZERO_MODE_PAGE_spangroup_2 = lv_spangroup_create(ui->ZERO_MODE_PAGE);
	lv_spangroup_set_align(ui->ZERO_MODE_PAGE_spangroup_2, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->ZERO_MODE_PAGE_spangroup_2, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->ZERO_MODE_PAGE_spangroup_2, LV_SPAN_MODE_BREAK);
	//create span 
	ui->ZERO_MODE_PAGE_spangroup_2_span = lv_spangroup_new_span(ui->ZERO_MODE_PAGE_spangroup_2);
	lv_span_set_text(ui->ZERO_MODE_PAGE_spangroup_2_span, "速度：");
	lv_style_set_text_color(&ui->ZERO_MODE_PAGE_spangroup_2_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->ZERO_MODE_PAGE_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->ZERO_MODE_PAGE_spangroup_2_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_spangroup_2, 41, 86);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_spangroup_2, 50, 18);

	//Write style state: LV_STATE_DEFAULT for &style_ZERO_MODE_PAGE_spangroup_2_main_main_default
	static lv_style_t style_ZERO_MODE_PAGE_spangroup_2_main_main_default;
	ui_init_style(&style_ZERO_MODE_PAGE_spangroup_2_main_main_default);
	
	lv_style_set_border_width(&style_ZERO_MODE_PAGE_spangroup_2_main_main_default, 0);
	lv_style_set_radius(&style_ZERO_MODE_PAGE_spangroup_2_main_main_default, 0);
	lv_style_set_bg_opa(&style_ZERO_MODE_PAGE_spangroup_2_main_main_default, 0);
	lv_style_set_pad_top(&style_ZERO_MODE_PAGE_spangroup_2_main_main_default, 0);
	lv_style_set_pad_right(&style_ZERO_MODE_PAGE_spangroup_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ZERO_MODE_PAGE_spangroup_2_main_main_default, 0);
	lv_style_set_pad_left(&style_ZERO_MODE_PAGE_spangroup_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_ZERO_MODE_PAGE_spangroup_2_main_main_default, 0);
	lv_obj_add_style(ui->ZERO_MODE_PAGE_spangroup_2, &style_ZERO_MODE_PAGE_spangroup_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->ZERO_MODE_PAGE_spangroup_2);

	//Write codes ZERO_MODE_PAGE_label_speed
	ui->ZERO_MODE_PAGE_label_speed = lv_label_create(ui->ZERO_MODE_PAGE);
	lv_label_set_text(ui->ZERO_MODE_PAGE_label_speed, "0");
	lv_label_set_long_mode(ui->ZERO_MODE_PAGE_label_speed, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_label_speed, 107, 89);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_label_speed, 50, 12);

	//Write style for ZERO_MODE_PAGE_label_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_label_speed, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_label_speed, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_label_speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ZERO_MODE_PAGE_label_speed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ZERO_MODE_PAGE_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZERO_MODE_PAGE_label_speed, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ZERO_MODE_PAGE_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ZERO_MODE_PAGE_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ZERO_MODE_PAGE_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ZERO_MODE_PAGE_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ZERO_MODE_PAGE_spangroup_3
	ui->ZERO_MODE_PAGE_spangroup_3 = lv_spangroup_create(ui->ZERO_MODE_PAGE);
	lv_spangroup_set_align(ui->ZERO_MODE_PAGE_spangroup_3, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->ZERO_MODE_PAGE_spangroup_3, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->ZERO_MODE_PAGE_spangroup_3, LV_SPAN_MODE_BREAK);
	//create span 
	ui->ZERO_MODE_PAGE_spangroup_3_span = lv_spangroup_new_span(ui->ZERO_MODE_PAGE_spangroup_3);
	lv_span_set_text(ui->ZERO_MODE_PAGE_spangroup_3_span, "扭矩：");
	lv_style_set_text_color(&ui->ZERO_MODE_PAGE_spangroup_3_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->ZERO_MODE_PAGE_spangroup_3_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->ZERO_MODE_PAGE_spangroup_3_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_spangroup_3, 41, 110);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_spangroup_3, 50, 18);

	//Write style state: LV_STATE_DEFAULT for &style_ZERO_MODE_PAGE_spangroup_3_main_main_default
	static lv_style_t style_ZERO_MODE_PAGE_spangroup_3_main_main_default;
	ui_init_style(&style_ZERO_MODE_PAGE_spangroup_3_main_main_default);
	
	lv_style_set_border_width(&style_ZERO_MODE_PAGE_spangroup_3_main_main_default, 0);
	lv_style_set_radius(&style_ZERO_MODE_PAGE_spangroup_3_main_main_default, 0);
	lv_style_set_bg_opa(&style_ZERO_MODE_PAGE_spangroup_3_main_main_default, 0);
	lv_style_set_pad_top(&style_ZERO_MODE_PAGE_spangroup_3_main_main_default, 0);
	lv_style_set_pad_right(&style_ZERO_MODE_PAGE_spangroup_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ZERO_MODE_PAGE_spangroup_3_main_main_default, 0);
	lv_style_set_pad_left(&style_ZERO_MODE_PAGE_spangroup_3_main_main_default, 0);
	lv_style_set_shadow_width(&style_ZERO_MODE_PAGE_spangroup_3_main_main_default, 0);
	lv_obj_add_style(ui->ZERO_MODE_PAGE_spangroup_3, &style_ZERO_MODE_PAGE_spangroup_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->ZERO_MODE_PAGE_spangroup_3);

	//Write codes ZERO_MODE_PAGE_label_torque
	ui->ZERO_MODE_PAGE_label_torque = lv_label_create(ui->ZERO_MODE_PAGE);
	lv_label_set_text(ui->ZERO_MODE_PAGE_label_torque, "0");
	lv_label_set_long_mode(ui->ZERO_MODE_PAGE_label_torque, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_label_torque, 107, 113);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_label_torque, 50, 12);

	//Write style for ZERO_MODE_PAGE_label_torque, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_label_torque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_label_torque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_label_torque, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_label_torque, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_label_torque, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ZERO_MODE_PAGE_label_torque, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ZERO_MODE_PAGE_label_torque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZERO_MODE_PAGE_label_torque, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_label_torque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ZERO_MODE_PAGE_label_torque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ZERO_MODE_PAGE_label_torque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ZERO_MODE_PAGE_label_torque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ZERO_MODE_PAGE_label_torque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_label_torque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ZERO_MODE_PAGE_label_5
	ui->ZERO_MODE_PAGE_label_5 = lv_label_create(ui->ZERO_MODE_PAGE);
	lv_label_set_text(ui->ZERO_MODE_PAGE_label_5, "Pluse");
	lv_label_set_long_mode(ui->ZERO_MODE_PAGE_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_label_5, 176, 66.5);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_label_5, 30, 9);

	//Write style for ZERO_MODE_PAGE_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_label_5, &lv_font_montserratMedium_7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ZERO_MODE_PAGE_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ZERO_MODE_PAGE_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZERO_MODE_PAGE_label_5, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ZERO_MODE_PAGE_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ZERO_MODE_PAGE_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ZERO_MODE_PAGE_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ZERO_MODE_PAGE_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ZERO_MODE_PAGE_label_6
	ui->ZERO_MODE_PAGE_label_6 = lv_label_create(ui->ZERO_MODE_PAGE);
	lv_label_set_text(ui->ZERO_MODE_PAGE_label_6, "RPM");
	lv_label_set_long_mode(ui->ZERO_MODE_PAGE_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_label_6, 170, 90.5);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_label_6, 30, 9);

	//Write style for ZERO_MODE_PAGE_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_label_6, &lv_font_montserratMedium_7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ZERO_MODE_PAGE_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ZERO_MODE_PAGE_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZERO_MODE_PAGE_label_6, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ZERO_MODE_PAGE_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ZERO_MODE_PAGE_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ZERO_MODE_PAGE_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ZERO_MODE_PAGE_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ZERO_MODE_PAGE_label_7
	ui->ZERO_MODE_PAGE_label_7 = lv_label_create(ui->ZERO_MODE_PAGE);
	lv_label_set_text(ui->ZERO_MODE_PAGE_label_7, "N*m");
	lv_label_set_long_mode(ui->ZERO_MODE_PAGE_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ZERO_MODE_PAGE_label_7, 170, 114.5);
	lv_obj_set_size(ui->ZERO_MODE_PAGE_label_7, 30, 9);

	//Write style for ZERO_MODE_PAGE_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ZERO_MODE_PAGE_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ZERO_MODE_PAGE_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ZERO_MODE_PAGE_label_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ZERO_MODE_PAGE_label_7, &lv_font_montserratMedium_7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ZERO_MODE_PAGE_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ZERO_MODE_PAGE_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ZERO_MODE_PAGE_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ZERO_MODE_PAGE_label_7, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ZERO_MODE_PAGE_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ZERO_MODE_PAGE_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ZERO_MODE_PAGE_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ZERO_MODE_PAGE_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ZERO_MODE_PAGE_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ZERO_MODE_PAGE_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of ZERO_MODE_PAGE.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->ZERO_MODE_PAGE);

	//Init events for screen.
	events_init_ZERO_MODE_PAGE(ui);
}
