#ifndef __LCD_THREAD_H_
#define __LCD_THREAD_H_

#include <rtthread.h>
#include <drv_lcd.h>
#include <disp_image.h>

#define LCD_PRIORITY RT_THREAD_PRIORITY_MAX - 11
#define LCD_STACK_SIZE (128 * 12)
#define LCD_TIMESLICE 10

void lcd_entry(void *parameter);

#endif /* __LCD_THREAD_H_ */