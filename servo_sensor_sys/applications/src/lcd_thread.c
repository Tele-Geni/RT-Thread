#include "lcd_thread.h"

#define LOG_TAG "lcd.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

static void led_init(void)
{
    lcd_clear(BLACK);
    lcd_show_image(0, 0, 240, 240, image_home);
    // lcd_set_color(WHITE, BLACK); // 白底黑字
    // lcd_show_string(10, 69, 16, "Hello, RT-Thread!");
    // lcd_show_string(10, 69 + 16, 24, "RT-Thread");
    // lcd_show_string(10, 69 + 16 + 24, 32, "RT-Thread");
    // lcd_draw_line(0, 69 + 16 + 24 + 32, 240, 69 + 16 + 24 + 32);
    // lcd_draw_point(120, 194);
    // for (int i = 0; i < 46; i += 4)
    // {
    //     lcd_draw_circle(120, 194, i);
    // }
}

void lcd_entry(void *parameter)
{
    led_init();
    LOG_I("lcd_entry success!");
    while (1)
    {
        rt_thread_mdelay(1000);
    }
}

int lcd_thread(void)
{
    rt_thread_t tid = RT_NULL;
    tid = rt_thread_create("lcd_thread",
                           lcd_entry, RT_NULL,
                           LCD_STACK_SIZE,
                           LCD_PRIORITY, LCD_TIMESLICE);

    if (tid != RT_NULL)
        rt_thread_startup(tid);
    return 0;
}
MSH_CMD_EXPORT(lcd_thread, lcd_thread);