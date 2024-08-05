#ifndef __CAN_THREAD_H_
#define __CAN_THREAD_H_

#include <rtthread.h>
#include <drv_can.h>

#define CAN_DEV_NAME "can1"

#define CAN_PRIORITY RT_THREAD_PRIORITY_MAX - 16
#define CAN_STACK_SIZE (128 * 8)
#define CAN_TIMESLICE 10

int can_send(rt_uint8_t *txbuf);
void can_entry(void *parameter);

#endif /* __CAN_THREAD_H_ */
