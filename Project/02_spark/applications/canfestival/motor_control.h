#ifndef __MOTOR_THREAD_H_
#define __MOTOR_THREAD_H_

#include <rtthread.h>
#include "canfestival.h"
#include "nimotion.h"

#define CONSUMER_HEARTBEAT_TIME 1000
#define SYNC_DELAY rt_thread_delay(RT_TICK_PER_SECOND / 50) // 20 tick
#define CONTROL_WORD_DISABLE_VOLTAGE 0x00
#define CONTROL_WORD_SHUTDOWN 0x06
#define CONTROL_WORD_SWITCH_ON 0x07
#define CONTROL_WORD_ENABLE_OPERATION 0x0F
#define CONTROL_WORD_RUNNING_OPERATION 0x1F

#define MOTOR_PRIORITY RT_THREAD_PRIORITY_MAX - 16
#define MOTOR_STACK_SIZE (128 * 24)
#define MOTOR_TIMESLICE 5

#define MOTOR_NODEID 0x02
#define PDO_TRANSMISSION_TYPE 1
#define PRODUCER_HEARTBEAT_TIME 500

#define CONTROL_COMMAND_MUTEX_WAIT_TIME 5000

typedef enum
{
    HOME_PAGE = 1,
    OPERATION_PAGE,
    ZERO_MODE_PAGE,
    POSITION_MODE_PAGE,
    SPEED_MODE_PAGE,
    TORQUE_MODE_PAGE,
    SYNC_MODE_PAGE,
} PageState_t;

typedef enum
{
    NO_DEF0 = 0,
    PP_MOED, /* finish */
    VM_MODE,
    PV_MODE, /* finish */
    PT_MODE,
    NO_DEF5,
    HM_MODE, /* failed */
    IP_MODE,
    CSP_MODE, /* finish */
    CSV_MODE, /* finish */
    CST_MODE
} MotorMode_t;

typedef struct servo_config_state
{
    uint8_t state;
    uint8_t try_cnt;
    struct rt_semaphore finish_sem;
} servo_config_state_t;

void motor_enable(PageState_t cur_page);
void motor_disable(void);
void motor_control_entry(void *parameter);

#endif /* __MOTOR_THREAD_H_ */
