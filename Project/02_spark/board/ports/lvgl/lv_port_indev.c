
/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/

#if 1
#include <lv_conf.h>
#include "lv_port_indev.h"
#include <lvgl.h>
// #include <rtdevice.h>
// #include <board.h>
// #include <stdbool.h>

static void keypad_init(void);
static void keypad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static uint32_t keypad_get_key(void);
lv_indev_t *indev_keypad;

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;
    /*------------------ Keypad -----------------*/
    keypad_init();
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv.read_cb = keypad_read;
    indev_keypad = lv_indev_drv_register(&indev_drv);
}

/*------------------ Keypad -----------------*/
volatile int8_t g_cur_dummy_key = -1;

static void keypad_init(void)
{
    lv_group_t *keypad_group = lv_group_create();
    lv_indev_set_group(indev_keypad, keypad_group);
    lv_group_set_default(keypad_group);
}

static void keypad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    static uint32_t last_key = 0;
    uint32_t act_key = keypad_get_key();
    if (act_key != 0)
    {
        data->state = LV_INDEV_STATE_PR;
        switch (act_key)
        {
        case 0:
            act_key = LV_KEY_UP;
            break;
        case 1:
            act_key = LV_KEY_DOWN;
            break;
        case 2:
            act_key = LV_KEY_LEFT;
            break;
        case 3:
            act_key = LV_KEY_RIGHT;
            break;
        case 4:
            break; /* BUTTON_MAX */
        case 5:
            act_key = LV_KEY_ENTER; /* short press */
            break;
        case 6:
            act_key = LV_KEY_ESC; /* double click */
            break;
        default:
            break;
        }
        last_key = act_key;
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
    data->key = last_key;
}

static uint32_t keypad_get_key(void)
{
    int8_t temp = g_cur_dummy_key;
    if (g_cur_dummy_key != -1)
        rt_kprintf("g_cur_dummy_key: %d!\n", g_cur_dummy_key);
    g_cur_dummy_key = -1;
    return temp;
}

#else /*Enable this file at the top*/

#endif
