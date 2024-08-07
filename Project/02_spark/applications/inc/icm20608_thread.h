#ifndef __ICM20608_THREAD_H_
#define __ICM20608_THREAD_H_

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <icm20608.h>
#include "lvgl_thread.h"

#define ICM_DEV_NAME "i2c2"

#define ICM20608_PRIORITY RT_THREAD_PRIORITY_MAX - 10
#define ICM20608_STACK_SIZE (128 * 8)
#define ICM20608_TIMESLICE 10

void icm20608_entry(void *parameter);

#endif /* __ICM20608_THREAD_H_ */
