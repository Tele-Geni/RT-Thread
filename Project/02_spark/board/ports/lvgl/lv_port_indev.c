
/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/

#if 1
#include <lvgl.h>
#include "lv_conf.h"
#include "lv_port_indev.h"
#include "button_thread.h"
#include "lvgl_thread.h"

#define LOG_TAG "lvgl.indev"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

static void keypad_init(void);
static void keypad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static int8_t keypad_get_key(void);
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
lv_group_t *keypad_group = RT_NULL;

static void keypad_init(void)
{
    keypad_group = lv_group_create();
    lv_indev_set_group(indev_keypad, keypad_group);
    lv_group_set_default(keypad_group);
}

static void keypad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    static int8_t last_key = -1;
    int8_t act_key = keypad_get_key();
    if (act_key != -1)
    {
        data->state = LV_INDEV_STATE_PR;
        switch (act_key)
        {
        case KEY_UP_0:
            LOG_D("recv act_key value :        %d!\n", act_key);
            // act_key = LV_KEY_UP;
            act_key = KEY_UP_0;
            handle_key_input(act_key);
            break;
        case KEY_DOWN_1:
            LOG_D("recv act_key value :        %d!\n", act_key);
            // act_key = LV_KEY_DOWN;
            act_key = KEY_DOWN_1;
            handle_key_input(act_key);
            break;
        case KEY_LEFT_2:
            LOG_D("recv act_key value :        %d!\n", act_key);
            // act_key = LV_KEY_LEFT;
            act_key = KEY_LEFT_2;
            handle_key_input(act_key);
            break;
        case KEY_RIGHT_3:
            LOG_D("recv act_key value :        %d!\n", act_key);
            // act_key = LV_KEY_RIGHT;
            act_key = KEY_RIGHT_3;
            handle_key_input(act_key);
            break;
        case BUTTON_MAX:
            LOG_D("recv act_key value :        %d!\n", act_key);
            LOG_E("entry illegal BUTTON_MAX path");
            break; /* BUTTON_MAX */
        case KEY_ENTER:
            LOG_D("recv act_key value :        %d!\n", act_key);
            // act_key = LV_KEY_ENTER; /* double click to entry */
            act_key = KEY_ENTER; /* double click to entry */
            handle_key_input(act_key);
            break;
        case KEY_ESC:
            LOG_D("recv act_key value :        %d!\n", act_key);
            // act_key = LV_KEY_ESC; /* short press to exit/back */
            act_key = KEY_ESC; /* short press to exit/back */
            handle_key_input(act_key);
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

static int8_t keypad_get_key(void)
{
    int8_t temp = g_cur_dummy_key;
    g_cur_dummy_key = -1;
    return temp;
}

#else /*Enable this file at the top*/

#endif
