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

	//Write codes CurrentMode_cont_1
	ui->CurrentMode_cont_1 = lv_obj_create(ui->CurrentMode);
	lv_obj_set_pos(ui->CurrentMode_cont_1, 30, 35);
	lv_obj_set_size(ui->CurrentMode_cont_1, 180, 80);
	lv_obj_set_scrollbar_mode(ui->CurrentMode_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for CurrentMode_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->CurrentMode_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->CurrentMode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->CurrentMode_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->CurrentMode_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->CurrentMode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->CurrentMode_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->CurrentMode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->CurrentMode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->CurrentMode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->CurrentMode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes CurrentMode_btn_back
	ui->CurrentMode_btn_back = lv_btn_create(ui->CurrentMode);
	ui->CurrentMode_btn_back_label = lv_label_create(ui->CurrentMode_btn_back);
	lv_label_set_text(ui->CurrentMode_btn_back_label, "Back");
	lv_label_set_long_mode(ui->CurrentMode_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->CurrentMode_btn_back_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->CurrentMode_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->CurrentMode_btn_back_label, LV_PCT(100));
	lv_obj_set_pos(ui->CurrentMode_btn_back, 165, 190);
	lv_obj_set_size(ui->CurrentMode_btn_back, 60, 40);

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
	lv_obj_set_size(ui->CurrentMode_btn_run, 60, 40);

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

	//Write codes CurrentMode_spangroup_3
	ui->CurrentMode_spangroup_3 = lv_spangroup_create(ui->CurrentMode);
	lv_spangroup_set_align(ui->CurrentMode_spangroup_3, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->CurrentMode_spangroup_3, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->CurrentMode_spangroup_3, LV_SPAN_MODE_BREAK);
	//create span 
	ui->CurrentMode_spangroup_3_span = lv_spangroup_new_span(ui->CurrentMode_spangroup_3);
	lv_span_set_text(ui->CurrentMode_spangroup_3_span, "扭矩：");
	lv_style_set_text_color(&ui->CurrentMode_spangroup_3_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->CurrentMode_spangroup_3_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->CurrentMode_spangroup_3_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->CurrentMode_spangroup_3, 41, 90);
	lv_obj_set_size(ui->CurrentMode_spangroup_3, 50, 18);

	//Write style state: LV_STATE_DEFAULT for &style_CurrentMode_spangroup_3_main_main_default
	static lv_style_t style_CurrentMode_spangroup_3_main_main_default;
	ui_init_style(&style_CurrentMode_spangroup_3_main_main_default);
	
	lv_style_set_border_width(&style_CurrentMode_spangroup_3_main_main_default, 0);
	lv_style_set_radius(&style_CurrentMode_spangroup_3_main_main_default, 0);
	lv_style_set_bg_opa(&style_CurrentMode_spangroup_3_main_main_default, 0);
	lv_style_set_pad_top(&style_CurrentMode_spangroup_3_main_main_default, 0);
	lv_style_set_pad_right(&style_CurrentMode_spangroup_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_CurrentMode_spangroup_3_main_main_default, 0);
	lv_style_set_pad_left(&style_CurrentMode_spangroup_3_main_main_default, 0);
	lv_style_set_shadow_width(&style_CurrentMode_spangroup_3_main_main_default, 0);
	lv_obj_add_style(ui->CurrentMode_spangroup_3, &style_CurrentMode_spangroup_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->CurrentMode_spangroup_3);

	//Write codes CurrentMode_spangroup_2
	ui->CurrentMode_spangroup_2 = lv_spangroup_create(ui->CurrentMode);
	lv_spangroup_set_align(ui->CurrentMode_spangroup_2, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->CurrentMode_spangroup_2, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->CurrentMode_spangroup_2, LV_SPAN_MODE_BREAK);
	//create span 
	ui->CurrentMode_spangroup_2_span = lv_spangroup_new_span(ui->CurrentMode_spangroup_2);
	lv_span_set_text(ui->CurrentMode_spangroup_2_span, "速度：");
	lv_style_set_text_color(&ui->CurrentMode_spangroup_2_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->CurrentMode_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->CurrentMode_spangroup_2_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->CurrentMode_spangroup_2, 41, 66);
	lv_obj_set_size(ui->CurrentMode_spangroup_2, 50, 18);

	//Write style state: LV_STATE_DEFAULT for &style_CurrentMode_spangroup_2_main_main_default
	static lv_style_t style_CurrentMode_spangroup_2_main_main_default;
	ui_init_style(&style_CurrentMode_spangroup_2_main_main_default);
	
	lv_style_set_border_width(&style_CurrentMode_spangroup_2_main_main_default, 0);
	lv_style_set_radius(&style_CurrentMode_spangroup_2_main_main_default, 0);
	lv_style_set_bg_opa(&style_CurrentMode_spangroup_2_main_main_default, 0);
	lv_style_set_pad_top(&style_CurrentMode_spangroup_2_main_main_default, 0);
	lv_style_set_pad_right(&style_CurrentMode_spangroup_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_CurrentMode_spangroup_2_main_main_default, 0);
	lv_style_set_pad_left(&style_CurrentMode_spangroup_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_CurrentMode_spangroup_2_main_main_default, 0);
	lv_obj_add_style(ui->CurrentMode_spangroup_2, &style_CurrentMode_spangroup_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->CurrentMode_spangroup_2);

	//Write codes CurrentMode_spangroup_1
	ui->CurrentMode_spangroup_1 = lv_spangroup_create(ui->CurrentMode);
	lv_spangroup_set_align(ui->CurrentMode_spangroup_1, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->CurrentMode_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->CurrentMode_spangroup_1, LV_SPAN_MODE_BREAK);
	//create span 
	ui->CurrentMode_spangroup_1_span = lv_spangroup_new_span(ui->CurrentMode_spangroup_1);
	lv_span_set_text(ui->CurrentMode_spangroup_1_span, "位置：");
	lv_style_set_text_color(&ui->CurrentMode_spangroup_1_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->CurrentMode_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->CurrentMode_spangroup_1_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->CurrentMode_spangroup_1, 41, 42);
	lv_obj_set_size(ui->CurrentMode_spangroup_1, 50, 18);

	//Write style state: LV_STATE_DEFAULT for &style_CurrentMode_spangroup_1_main_main_default
	static lv_style_t style_CurrentMode_spangroup_1_main_main_default;
	ui_init_style(&style_CurrentMode_spangroup_1_main_main_default);
	
	lv_style_set_border_width(&style_CurrentMode_spangroup_1_main_main_default, 0);
	lv_style_set_radius(&style_CurrentMode_spangroup_1_main_main_default, 0);
	lv_style_set_bg_opa(&style_CurrentMode_spangroup_1_main_main_default, 0);
	lv_style_set_pad_top(&style_CurrentMode_spangroup_1_main_main_default, 0);
	lv_style_set_pad_right(&style_CurrentMode_spangroup_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_CurrentMode_spangroup_1_main_main_default, 0);
	lv_style_set_pad_left(&style_CurrentMode_spangroup_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_CurrentMode_spangroup_1_main_main_default, 0);
	lv_obj_add_style(ui->CurrentMode_spangroup_1, &style_CurrentMode_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->CurrentMode_spangroup_1);

	//Write codes CurrentMode_label_6
	ui->CurrentMode_label_6 = lv_label_create(ui->CurrentMode);
	lv_label_set_text(ui->CurrentMode_label_6, "0");
	lv_label_set_long_mode(ui->CurrentMode_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->CurrentMode_label_6, 91, 93);
	lv_obj_set_size(ui->CurrentMode_label_6, 50, 12);

	//Write style for CurrentMode_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->CurrentMode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->CurrentMode_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CurrentMode_label_6, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->CurrentMode_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->CurrentMode_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->CurrentMode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->CurrentMode_label_6, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->CurrentMode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->CurrentMode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->CurrentMode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->CurrentMode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->CurrentMode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes CurrentMode_label_5
	ui->CurrentMode_label_5 = lv_label_create(ui->CurrentMode);
	lv_label_set_text(ui->CurrentMode_label_5, "0");
	lv_label_set_long_mode(ui->CurrentMode_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->CurrentMode_label_5, 91, 69);
	lv_obj_set_size(ui->CurrentMode_label_5, 50, 12);

	//Write style for CurrentMode_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->CurrentMode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->CurrentMode_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CurrentMode_label_5, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->CurrentMode_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->CurrentMode_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->CurrentMode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->CurrentMode_label_5, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->CurrentMode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->CurrentMode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->CurrentMode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->CurrentMode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->CurrentMode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes CurrentMode_label_4
	ui->CurrentMode_label_4 = lv_label_create(ui->CurrentMode);
	lv_label_set_text(ui->CurrentMode_label_4, "0");
	lv_label_set_long_mode(ui->CurrentMode_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->CurrentMode_label_4, 91, 45);
	lv_obj_set_size(ui->CurrentMode_label_4, 50, 12);

	//Write style for CurrentMode_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->CurrentMode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->CurrentMode_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CurrentMode_label_4, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->CurrentMode_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->CurrentMode_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->CurrentMode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->CurrentMode_label_4, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->CurrentMode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->CurrentMode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->CurrentMode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->CurrentMode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->CurrentMode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes CurrentMode_label_3
	ui->CurrentMode_label_3 = lv_label_create(ui->CurrentMode);
	lv_label_set_text(ui->CurrentMode_label_3, "N*m");
	lv_label_set_long_mode(ui->CurrentMode_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->CurrentMode_label_3, 170, 94.5);
	lv_obj_set_size(ui->CurrentMode_label_3, 30, 9);

	//Write style for CurrentMode_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->CurrentMode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->CurrentMode_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CurrentMode_label_3, &lv_font_montserratMedium_7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->CurrentMode_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->CurrentMode_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->CurrentMode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->CurrentMode_label_3, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->CurrentMode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->CurrentMode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->CurrentMode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->CurrentMode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->CurrentMode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes CurrentMode_label_2
	ui->CurrentMode_label_2 = lv_label_create(ui->CurrentMode);
	lv_label_set_text(ui->CurrentMode_label_2, "RPM");
	lv_label_set_long_mode(ui->CurrentMode_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->CurrentMode_label_2, 170, 70.5);
	lv_obj_set_size(ui->CurrentMode_label_2, 30, 9);

	//Write style for CurrentMode_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->CurrentMode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->CurrentMode_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CurrentMode_label_2, &lv_font_montserratMedium_7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->CurrentMode_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->CurrentMode_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->CurrentMode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->CurrentMode_label_2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->CurrentMode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->CurrentMode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->CurrentMode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->CurrentMode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->CurrentMode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes CurrentMode_label_1
	ui->CurrentMode_label_1 = lv_label_create(ui->CurrentMode);
	lv_label_set_text(ui->CurrentMode_label_1, "Pluse");
	lv_label_set_long_mode(ui->CurrentMode_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->CurrentMode_label_1, 176, 46.5);
	lv_obj_set_size(ui->CurrentMode_label_1, 30, 9);

	//Write style for CurrentMode_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->CurrentMode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->CurrentMode_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CurrentMode_label_1, &lv_font_montserratMedium_7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->CurrentMode_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->CurrentMode_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->CurrentMode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->CurrentMode_label_1, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->CurrentMode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->CurrentMode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->CurrentMode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->CurrentMode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->CurrentMode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes CurrentMode_label_7
	ui->CurrentMode_label_7 = lv_label_create(ui->CurrentMode);
	lv_label_set_text(ui->CurrentMode_label_7, "Current Mode");
	lv_label_set_long_mode(ui->CurrentMode_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->CurrentMode_label_7, 11, 10);
	lv_obj_set_size(ui->CurrentMode_label_7, 220, 20);

	//Write style for CurrentMode_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->CurrentMode_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->CurrentMode_label_7, lv_color_hex(0xffc700), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CurrentMode_label_7, &lv_font_arial_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->CurrentMode_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->CurrentMode_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->CurrentMode_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->CurrentMode_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->CurrentMode_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->CurrentMode_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->CurrentMode_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->CurrentMode_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->CurrentMode_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes CurrentMode_btn_1
	ui->CurrentMode_btn_1 = lv_btn_create(ui->CurrentMode);
	ui->CurrentMode_btn_1_label = lv_label_create(ui->CurrentMode_btn_1);
	lv_label_set_text(ui->CurrentMode_btn_1_label, "Back");
	lv_label_set_long_mode(ui->CurrentMode_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->CurrentMode_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->CurrentMode_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->CurrentMode_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->CurrentMode_btn_1, 90, 190);
	lv_obj_set_size(ui->CurrentMode_btn_1, 60, 40);

	//Write style for CurrentMode_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->CurrentMode_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->CurrentMode_btn_1, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->CurrentMode_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->CurrentMode_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CurrentMode_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->CurrentMode_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->CurrentMode_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for CurrentMode_btn_1, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->CurrentMode_btn_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->CurrentMode_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->CurrentMode_btn_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->CurrentMode_btn_1, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->CurrentMode_btn_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->CurrentMode_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->CurrentMode_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->CurrentMode_btn_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes CurrentMode_slider_2
	ui->CurrentMode_slider_2 = lv_slider_create(ui->CurrentMode);
	lv_slider_set_range(ui->CurrentMode_slider_2, 0, 1000);
	lv_slider_set_mode(ui->CurrentMode_slider_2, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->CurrentMode_slider_2, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->CurrentMode_slider_2, 54, 162);
	lv_obj_set_size(ui->CurrentMode_slider_2, 180, 8);

	//Write style for CurrentMode_slider_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->CurrentMode_slider_2, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->CurrentMode_slider_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_slider_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_slider_2, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->CurrentMode_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for CurrentMode_slider_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->CurrentMode_slider_2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->CurrentMode_slider_2, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_slider_2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_slider_2, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for CurrentMode_slider_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->CurrentMode_slider_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->CurrentMode_slider_2, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_slider_2, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_slider_2, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes CurrentMode_spangroup_5
	ui->CurrentMode_spangroup_5 = lv_spangroup_create(ui->CurrentMode);
	lv_spangroup_set_align(ui->CurrentMode_spangroup_5, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->CurrentMode_spangroup_5, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->CurrentMode_spangroup_5, LV_SPAN_MODE_BREAK);
	//create span 
	ui->CurrentMode_spangroup_5_span = lv_spangroup_new_span(ui->CurrentMode_spangroup_5);
	lv_span_set_text(ui->CurrentMode_spangroup_5_span, "位置：");
	lv_style_set_text_color(&ui->CurrentMode_spangroup_5_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->CurrentMode_spangroup_5_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->CurrentMode_spangroup_5_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->CurrentMode_spangroup_5, 3, 157);
	lv_obj_set_size(ui->CurrentMode_spangroup_5, 55, 18);

	//Write style state: LV_STATE_DEFAULT for &style_CurrentMode_spangroup_5_main_main_default
	static lv_style_t style_CurrentMode_spangroup_5_main_main_default;
	ui_init_style(&style_CurrentMode_spangroup_5_main_main_default);
	
	lv_style_set_border_width(&style_CurrentMode_spangroup_5_main_main_default, 0);
	lv_style_set_radius(&style_CurrentMode_spangroup_5_main_main_default, 0);
	lv_style_set_bg_opa(&style_CurrentMode_spangroup_5_main_main_default, 0);
	lv_style_set_pad_top(&style_CurrentMode_spangroup_5_main_main_default, 0);
	lv_style_set_pad_right(&style_CurrentMode_spangroup_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_CurrentMode_spangroup_5_main_main_default, 0);
	lv_style_set_pad_left(&style_CurrentMode_spangroup_5_main_main_default, 0);
	lv_style_set_shadow_width(&style_CurrentMode_spangroup_5_main_main_default, 0);
	lv_obj_add_style(ui->CurrentMode_spangroup_5, &style_CurrentMode_spangroup_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->CurrentMode_spangroup_5);

	//Write codes CurrentMode_slider_1
	ui->CurrentMode_slider_1 = lv_slider_create(ui->CurrentMode);
	lv_slider_set_range(ui->CurrentMode_slider_1, 0, 1000);
	lv_slider_set_mode(ui->CurrentMode_slider_1, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->CurrentMode_slider_1, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->CurrentMode_slider_1, 54, 131);
	lv_obj_set_size(ui->CurrentMode_slider_1, 180, 8);

	//Write style for CurrentMode_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->CurrentMode_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->CurrentMode_slider_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_slider_1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->CurrentMode_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->CurrentMode_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for CurrentMode_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->CurrentMode_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->CurrentMode_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for CurrentMode_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->CurrentMode_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->CurrentMode_slider_1, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->CurrentMode_slider_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->CurrentMode_slider_1, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes CurrentMode_spangroup_4
	ui->CurrentMode_spangroup_4 = lv_spangroup_create(ui->CurrentMode);
	lv_spangroup_set_align(ui->CurrentMode_spangroup_4, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->CurrentMode_spangroup_4, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->CurrentMode_spangroup_4, LV_SPAN_MODE_BREAK);
	//create span 
	ui->CurrentMode_spangroup_4_span = lv_spangroup_new_span(ui->CurrentMode_spangroup_4);
	lv_span_set_text(ui->CurrentMode_spangroup_4_span, "速度：");
	lv_style_set_text_color(&ui->CurrentMode_spangroup_4_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->CurrentMode_spangroup_4_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->CurrentMode_spangroup_4_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->CurrentMode_spangroup_4, 3, 126);
	lv_obj_set_size(ui->CurrentMode_spangroup_4, 55, 18);

	//Write style state: LV_STATE_DEFAULT for &style_CurrentMode_spangroup_4_main_main_default
	static lv_style_t style_CurrentMode_spangroup_4_main_main_default;
	ui_init_style(&style_CurrentMode_spangroup_4_main_main_default);
	
	lv_style_set_border_width(&style_CurrentMode_spangroup_4_main_main_default, 0);
	lv_style_set_radius(&style_CurrentMode_spangroup_4_main_main_default, 0);
	lv_style_set_bg_opa(&style_CurrentMode_spangroup_4_main_main_default, 0);
	lv_style_set_pad_top(&style_CurrentMode_spangroup_4_main_main_default, 0);
	lv_style_set_pad_right(&style_CurrentMode_spangroup_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_CurrentMode_spangroup_4_main_main_default, 0);
	lv_style_set_pad_left(&style_CurrentMode_spangroup_4_main_main_default, 0);
	lv_style_set_shadow_width(&style_CurrentMode_spangroup_4_main_main_default, 0);
	lv_obj_add_style(ui->CurrentMode_spangroup_4, &style_CurrentMode_spangroup_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->CurrentMode_spangroup_4);

	//The custom code of CurrentMode.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->CurrentMode);

	//Init events for screen.
	events_init_CurrentMode(ui);
}
