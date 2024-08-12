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
#include "lv_dclock.h"

int Home_digital_clock_1_min_value = 00;
int Home_digital_clock_1_hour_value = 00;
int Home_digital_clock_1_sec_value = 00;
char Home_digital_clock_1_meridiem[] = "/S";
void setup_scr_Home(lv_ui *ui)
{
	// Write codes Home
	ui->Home = lv_obj_create(NULL);
	lv_obj_set_size(ui->Home, 240, 240);
	lv_obj_set_scrollbar_mode(ui->Home, LV_SCROLLBAR_MODE_OFF);

	// Write style for Home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Home, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_img_1
	ui->Home_img_1 = lv_img_create(ui->Home);
	lv_obj_add_flag(ui->Home_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Home_img_1, &_home_alpha_240x240);
	lv_img_set_pivot(ui->Home_img_1, 50, 50);
	lv_img_set_angle(ui->Home_img_1, 0);
	lv_obj_set_pos(ui->Home_img_1, 0, 0);
	lv_obj_set_size(ui->Home_img_1, 240, 240);

	// Write style for Home_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->Home_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->Home_img_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->Home_img_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_btn_entry
	ui->Home_btn_entry = lv_btn_create(ui->Home);
	ui->Home_btn_entry_label = lv_label_create(ui->Home_btn_entry);
	lv_label_set_text(ui->Home_btn_entry_label, "Entry");
	lv_label_set_long_mode(ui->Home_btn_entry_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Home_btn_entry_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Home_btn_entry, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Home_btn_entry_label, LV_PCT(100));
	lv_obj_set_pos(ui->Home_btn_entry, 70, 180);
	lv_obj_set_size(ui->Home_btn_entry, 100, 50);

	// Write style for Home_btn_entry, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Home_btn_entry, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Home_btn_entry, lv_color_hex(0x2FDA64), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Home_btn_entry, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Home_btn_entry, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_btn_entry, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_btn_entry, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_btn_entry, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_btn_entry, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_btn_entry, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_btn_entry, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_cont_1
	ui->Home_cont_1 = lv_obj_create(ui->Home);
	lv_obj_set_pos(ui->Home_cont_1, 0, 51);
	lv_obj_set_size(ui->Home_cont_1, 240, 120);
	lv_obj_set_scrollbar_mode(ui->Home_cont_1, LV_SCROLLBAR_MODE_OFF);

	// Write style for Home_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_cont_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Home_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Home_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Home_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Home_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Home_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_spangroup_1
	ui->Home_spangroup_1 = lv_spangroup_create(ui->Home);
	lv_spangroup_set_align(ui->Home_spangroup_1, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->Home_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->Home_spangroup_1, LV_SPAN_MODE_BREAK);
	// create span
	ui->Home_spangroup_1_span = lv_spangroup_new_span(ui->Home_spangroup_1);
	lv_span_set_text(ui->Home_spangroup_1_span, "温度");
	lv_style_set_text_color(&ui->Home_spangroup_1_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->Home_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->Home_spangroup_1_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->Home_spangroup_1, 10, 64);
	lv_obj_set_size(ui->Home_spangroup_1, 32, 18);

	// Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_1_main_main_default
	static lv_style_t style_Home_spangroup_1_main_main_default;
	ui_init_style(&style_Home_spangroup_1_main_main_default);

	lv_style_set_border_width(&style_Home_spangroup_1_main_main_default, 0);
	lv_style_set_radius(&style_Home_spangroup_1_main_main_default, 0);
	lv_style_set_bg_opa(&style_Home_spangroup_1_main_main_default, 0);
	lv_style_set_pad_top(&style_Home_spangroup_1_main_main_default, 0);
	lv_style_set_pad_right(&style_Home_spangroup_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_Home_spangroup_1_main_main_default, 0);
	lv_style_set_pad_left(&style_Home_spangroup_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_Home_spangroup_1_main_main_default, 0);
	lv_obj_add_style(ui->Home_spangroup_1, &style_Home_spangroup_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->Home_spangroup_1);

	// Write codes Home_spangroup_2
	ui->Home_spangroup_2 = lv_spangroup_create(ui->Home);
	lv_spangroup_set_align(ui->Home_spangroup_2, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->Home_spangroup_2, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->Home_spangroup_2, LV_SPAN_MODE_BREAK);
	// create span
	ui->Home_spangroup_2_span = lv_spangroup_new_span(ui->Home_spangroup_2);
	lv_span_set_text(ui->Home_spangroup_2_span, "湿度");
	lv_style_set_text_color(&ui->Home_spangroup_2_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->Home_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->Home_spangroup_2_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->Home_spangroup_2, 130, 64);
	lv_obj_set_size(ui->Home_spangroup_2, 32, 18);

	// Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_2_main_main_default
	static lv_style_t style_Home_spangroup_2_main_main_default;
	ui_init_style(&style_Home_spangroup_2_main_main_default);

	lv_style_set_border_width(&style_Home_spangroup_2_main_main_default, 0);
	lv_style_set_radius(&style_Home_spangroup_2_main_main_default, 0);
	lv_style_set_bg_opa(&style_Home_spangroup_2_main_main_default, 0);
	lv_style_set_pad_top(&style_Home_spangroup_2_main_main_default, 0);
	lv_style_set_pad_right(&style_Home_spangroup_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_Home_spangroup_2_main_main_default, 0);
	lv_style_set_pad_left(&style_Home_spangroup_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_Home_spangroup_2_main_main_default, 0);
	lv_obj_add_style(ui->Home_spangroup_2, &style_Home_spangroup_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->Home_spangroup_2);

	// Write codes Home_spangroup_3
	ui->Home_spangroup_3 = lv_spangroup_create(ui->Home);
	lv_spangroup_set_align(ui->Home_spangroup_3, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->Home_spangroup_3, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->Home_spangroup_3, LV_SPAN_MODE_BREAK);
	// create span
	ui->Home_spangroup_3_span = lv_spangroup_new_span(ui->Home_spangroup_3);
	lv_span_set_text(ui->Home_spangroup_3_span, "加速度");
	lv_style_set_text_color(&ui->Home_spangroup_3_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->Home_spangroup_3_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->Home_spangroup_3_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->Home_spangroup_3, 7, 110.5);
	lv_obj_set_size(ui->Home_spangroup_3, 50, 18);

	// Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_3_main_main_default
	static lv_style_t style_Home_spangroup_3_main_main_default;
	ui_init_style(&style_Home_spangroup_3_main_main_default);

	lv_style_set_border_width(&style_Home_spangroup_3_main_main_default, 0);
	lv_style_set_radius(&style_Home_spangroup_3_main_main_default, 0);
	lv_style_set_bg_opa(&style_Home_spangroup_3_main_main_default, 0);
	lv_style_set_pad_top(&style_Home_spangroup_3_main_main_default, 0);
	lv_style_set_pad_right(&style_Home_spangroup_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_Home_spangroup_3_main_main_default, 0);
	lv_style_set_pad_left(&style_Home_spangroup_3_main_main_default, 0);
	lv_style_set_shadow_width(&style_Home_spangroup_3_main_main_default, 0);
	lv_obj_add_style(ui->Home_spangroup_3, &style_Home_spangroup_3_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->Home_spangroup_3);

	// Write codes Home_spangroup_4
	ui->Home_spangroup_4 = lv_spangroup_create(ui->Home);
	lv_spangroup_set_align(ui->Home_spangroup_4, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->Home_spangroup_4, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->Home_spangroup_4, LV_SPAN_MODE_BREAK);
	// create span
	ui->Home_spangroup_4_span = lv_spangroup_new_span(ui->Home_spangroup_4);
	lv_span_set_text(ui->Home_spangroup_4_span, "角速度");
	lv_style_set_text_color(&ui->Home_spangroup_4_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->Home_spangroup_4_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->Home_spangroup_4_span->style, &lv_font_SourceHanSerifSC_Regular_16);
	lv_obj_set_pos(ui->Home_spangroup_4, 7, 139);
	lv_obj_set_size(ui->Home_spangroup_4, 50, 18);

	// Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_4_main_main_default
	static lv_style_t style_Home_spangroup_4_main_main_default;
	ui_init_style(&style_Home_spangroup_4_main_main_default);

	lv_style_set_border_width(&style_Home_spangroup_4_main_main_default, 0);
	lv_style_set_radius(&style_Home_spangroup_4_main_main_default, 0);
	lv_style_set_bg_opa(&style_Home_spangroup_4_main_main_default, 0);
	lv_style_set_pad_top(&style_Home_spangroup_4_main_main_default, 0);
	lv_style_set_pad_right(&style_Home_spangroup_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_Home_spangroup_4_main_main_default, 0);
	lv_style_set_pad_left(&style_Home_spangroup_4_main_main_default, 0);
	lv_style_set_shadow_width(&style_Home_spangroup_4_main_main_default, 0);
	lv_obj_add_style(ui->Home_spangroup_4, &style_Home_spangroup_4_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->Home_spangroup_4);

	// Write codes Home_led_1
	ui->Home_led_1 = lv_led_create(ui->Home);
	lv_led_set_brightness(ui->Home_led_1, 255);
	lv_led_set_color(ui->Home_led_1, lv_color_hex(0x2FDA64));
	lv_obj_set_pos(ui->Home_led_1, 10, 10);
	lv_obj_set_size(ui->Home_led_1, 20, 20);

	// Write codes Home_label_temp
	ui->Home_label_temp = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_temp, "0");
	lv_label_set_long_mode(ui->Home_label_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_temp, 45, 68);
	lv_obj_set_size(ui->Home_label_temp, 40, 12);

	// Write style for Home_label_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_temp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_temp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_temp, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_temp, &lv_font_montserratMedium_10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_temp, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_temp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_temp, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_temp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_temp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_temp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_temp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_temp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_temp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_humi
	ui->Home_label_humi = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_humi, "0");
	lv_label_set_long_mode(ui->Home_label_humi, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_humi, 165, 68);
	lv_obj_set_size(ui->Home_label_humi, 40, 12);

	// Write style for Home_label_humi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_humi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_humi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_humi, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_humi, &lv_font_montserratMedium_10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_humi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_humi, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_humi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_humi, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_humi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_humi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_humi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_humi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_humi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_humi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_1
	ui->Home_label_1 = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_1, "℃");
	lv_label_set_long_mode(ui->Home_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_1, 100, 65);
	lv_obj_set_size(ui->Home_label_1, 17, 16);

	// Write style for Home_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_1, &lv_font_SourceHanSerifSC_Regular_14, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_1, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_2
	ui->Home_label_2 = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_2, "RH");
	lv_label_set_long_mode(ui->Home_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_2, 210, 65);
	lv_obj_set_size(ui->Home_label_2, 25, 16);

	// Write style for Home_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_2, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_acc_x
	ui->Home_label_acc_x = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_acc_x, "0");
	lv_label_set_long_mode(ui->Home_label_acc_x, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_acc_x, 72, 115.5);
	lv_obj_set_size(ui->Home_label_acc_x, 40, 12);

	// Write style for Home_label_acc_x, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_acc_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_acc_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_acc_x, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_acc_x, &lv_font_montserratMedium_10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_acc_x, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_acc_x, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_acc_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_acc_x, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_acc_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_acc_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_acc_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_acc_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_acc_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_acc_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_acc_y
	ui->Home_label_acc_y = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_acc_y, "0");
	lv_label_set_long_mode(ui->Home_label_acc_y, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_acc_y, 131, 115.5);
	lv_obj_set_size(ui->Home_label_acc_y, 40, 12);

	// Write style for Home_label_acc_y, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_acc_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_acc_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_acc_y, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_acc_y, &lv_font_montserratMedium_10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_acc_y, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_acc_y, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_acc_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_acc_y, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_acc_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_acc_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_acc_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_acc_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_acc_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_acc_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_acc_z
	ui->Home_label_acc_z = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_acc_z, "0");
	lv_label_set_long_mode(ui->Home_label_acc_z, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_acc_z, 190, 115.5);
	lv_obj_set_size(ui->Home_label_acc_z, 40, 12);

	// Write style for Home_label_acc_z, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_acc_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_acc_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_acc_z, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_acc_z, &lv_font_montserratMedium_10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_acc_z, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_acc_z, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_acc_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_acc_z, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_acc_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_acc_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_acc_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_acc_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_acc_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_acc_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_gyro_x
	ui->Home_label_gyro_x = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_gyro_x, "0");
	lv_label_set_long_mode(ui->Home_label_gyro_x, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_gyro_x, 72, 144);
	lv_obj_set_size(ui->Home_label_gyro_x, 40, 12);

	// Write style for Home_label_gyro_x, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_gyro_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_gyro_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_gyro_x, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_gyro_x, &lv_font_montserratMedium_10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_gyro_x, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_gyro_x, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_gyro_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_gyro_x, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_gyro_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_gyro_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_gyro_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_gyro_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_gyro_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_gyro_x, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_gyro_y
	ui->Home_label_gyro_y = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_gyro_y, "0");
	lv_label_set_long_mode(ui->Home_label_gyro_y, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_gyro_y, 131, 144);
	lv_obj_set_size(ui->Home_label_gyro_y, 40, 12);

	// Write style for Home_label_gyro_y, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_gyro_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_gyro_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_gyro_y, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_gyro_y, &lv_font_montserratMedium_10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_gyro_y, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_gyro_y, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_gyro_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_gyro_y, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_gyro_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_gyro_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_gyro_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_gyro_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_gyro_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_gyro_y, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_gyro_z
	ui->Home_label_gyro_z = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_gyro_z, "0");
	lv_label_set_long_mode(ui->Home_label_gyro_z, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_gyro_z, 190, 144);
	lv_obj_set_size(ui->Home_label_gyro_z, 40, 12);

	// Write style for Home_label_gyro_z, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_gyro_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_gyro_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_gyro_z, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_gyro_z, &lv_font_montserratMedium_10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_gyro_z, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_gyro_z, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_gyro_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_gyro_z, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_gyro_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_gyro_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_gyro_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_gyro_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_gyro_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_gyro_z, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_9
	ui->Home_label_9 = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_9, "X");
	lv_label_set_long_mode(ui->Home_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_9, 99, 93);
	lv_obj_set_size(ui->Home_label_9, 13, 14);

	// Write style for Home_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_9, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_9, &lv_font_SourceHanSerifSC_Regular_11, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_9, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_9, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_10
	ui->Home_label_10 = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_10, "Y");
	lv_label_set_long_mode(ui->Home_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_10, 157, 93);
	lv_obj_set_size(ui->Home_label_10, 13, 14);

	// Write style for Home_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_10, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_10, &lv_font_SourceHanSerifSC_Regular_11, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_10, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_10, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_label_11
	ui->Home_label_11 = lv_label_create(ui->Home);
	lv_label_set_text(ui->Home_label_11, "Z");
	lv_label_set_long_mode(ui->Home_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Home_label_11, 215, 93);
	lv_obj_set_size(ui->Home_label_11, 13, 14);

	// Write style for Home_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Home_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Home_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_label_11, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_label_11, &lv_font_SourceHanSerifSC_Regular_11, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_label_11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_label_11, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Home_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_label_11, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_line_1
	ui->Home_line_1 = lv_line_create(ui->Home);
	static lv_point_t Home_line_1[] = {
		{0, 0},
		{150, 0},
	};
	lv_line_set_points(ui->Home_line_1, Home_line_1, 2);
	lv_obj_set_pos(ui->Home_line_1, 78, 111);
	lv_obj_set_size(ui->Home_line_1, 150, 1);

	// Write style for Home_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->Home_line_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->Home_line_1, lv_color_hex(0x757575), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->Home_line_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->Home_line_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Home_digital_clock_1
	static bool Home_digital_clock_1_timer_enabled = false;
	ui->Home_digital_clock_1 = lv_dclock_create(ui->Home, "00:00:00/S");
	if (!Home_digital_clock_1_timer_enabled)
	{
		lv_timer_create(Home_digital_clock_1_timer, 1000, NULL);
		Home_digital_clock_1_timer_enabled = true;
	}
	lv_obj_set_pos(ui->Home_digital_clock_1, 120, 5);
	lv_obj_set_size(ui->Home_digital_clock_1, 115, 35);

	// Write style for Home_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Home_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Home_digital_clock_1, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Home_digital_clock_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Home_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Home_digital_clock_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Home_digital_clock_1, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Home_digital_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Home_digital_clock_1, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// The custom code of Home.

	// Update current screen layout.
	lv_obj_update_layout(ui->Home);

	// Init events for screen.
	events_init_Home(ui);
}
