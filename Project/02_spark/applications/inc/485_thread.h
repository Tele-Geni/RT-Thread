#ifndef __MODBUS_THREAD_H_
#define __MODBUS_THREAD_H_

#include <rtthread.h>
#include "mb.h"
#include "mb_m.h"
#include "user_mb_app.h"

#define SLAVE_ADDR 0x01

#define USART_PORT 6
#define USART_BAUDRATE 115200
#define USART_PARITY MB_PAR_NONE
#define USART_MODBUS_MODE MB_RTU

#define MODBUS_PRIORITY RT_THREAD_PRIORITY_MAX - 16
#define MODBUS_POLL_PRIORITY RT_THREAD_PRIORITY_MAX - 14
#define MODBUS_SEND_PRIORITY RT_THREAD_PRIORITY_MAX - 10

#define MODBUS_STACK_SIZE (128 * 10)
#define MODBUS_POLL_STACK_SIZE (128 * 4)
#define MODBUS_SEND_STACK_SIZE (128 * 4)

#define MODBUS_TIMESLICE 10

void modbus_entry(void *parameter);

#endif /* __MODBUS_THREAD_H_ */
