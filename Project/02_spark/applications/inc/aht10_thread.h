#ifndef __AHT10_THREAD_H_
#define __AHT10_THREAD_H_

#include <rtthread.h>
#include "aht10.h"
#include "lvgl_thread.h"

#define ATH10_I2C_BUS "i2c3"

#define AHT10_PRIORITY RT_THREAD_PRIORITY_MAX - 10
#define AHT10_STACK_SIZE (128 * 12)
#define AHT10_TIMESLICE 10

void aht10_entry(void *parameter);

#endif /* __AHT10_THREAD_H_ */
