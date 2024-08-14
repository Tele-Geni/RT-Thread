#include "motor_control.h"

#define LOG_TAG "motor.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

rt_mq_t g_motor_mq = RT_NULL;

static CO_Data *g_pCO_Data = &nimotion_Data;
static servo_config_state_t servo_conf[4];

/* 若写在config_motor_param函数中则不够灵活，因为pdo map映射相对固定，该部分内容可根据用户需要进行删减配置 */
// uint16_t motor_limit_para_sdo[][8] = {
//     // {0x2F, 0x98, 0x60, 0x00, 0x11, 0x00, 0x00, 0x00}, // 发送：2F 98 60 00 11 00 00 00(设置回零方式为 17)
//     // {0x23, 0x80, 0x60, 0x00, 0xE8, 0x03, 0x00, 0x00}, // 最大转速：6080,00:3E8=4000rpm/4, 23
//     // {0x23, 0x7F, 0x60, 0x00, 0xE8, 0x03, 0x00, 0x00}, // 最大轮廓转速：607F,00:2710=500000/50, 23
//     // {0x2B, 0x72, 0x60, 0x00, 0xF4, 0x01, 0x00, 0x00}, // 最大转矩：6072,00:1F4=1000/2, 2B
//     // {0x2B, 0x73, 0x60, 0x00, 0xF4, 0x01, 0x00, 0x00}, // 最大电流：6073,00:1F4=1500/3, 2B
// };
// #define MOTOR_LIMIT_PARA_SDO_LENGTH (sizeof(motor_limit_para_sdo) / sizeof(motor_limit_para_sdo[0]))

extern int32_t g_motor_pos;
extern int32_t g_motor_speed;
extern int32_t g_motor_torque;
extern rt_sem_t g_control_command_sem;
extern rt_mutex_t g_control_command_mutex;

extern void EnterMutex(void);
extern void LeaveMutex(void);

static void config_motor(uint8_t nodeId);
static void config_motor_param(uint8_t nodeId, struct servo_config_state *conf);
static void motor_info(void);
/*********************************************************** mater init ***********************************************************/

static void config_single_motor(void *parameter)
{
    uint32_t nodeId;
    nodeId = (uint32_t)parameter;
    config_motor(nodeId);
    masterSendNMTstateChange(g_pCO_Data, nodeId, NMT_Start_Node);
}
static void slaveBootupHdl(CO_Data *d, UNS8 nodeId)
{
    rt_thread_t tid;
    tid = rt_thread_create("pdo_map_online", config_single_motor, (void *)(int)nodeId, 1024, 12 + nodeId, 2);
    if (tid == RT_NULL)
        LOG_E("canopen slave pdo map thread start failed!");
    else
        rt_thread_startup(tid);
}
static void config_motor(uint8_t nodeId)
{
    servo_conf[nodeId - 2].state = 0;
    servo_conf[nodeId - 2].try_cnt = 0;
    rt_sem_init(&(servo_conf[nodeId - 2].finish_sem), "servocnf", 0, RT_IPC_FLAG_FIFO);

    EnterMutex();
    config_motor_param(nodeId, &servo_conf[nodeId - 2]);
    LeaveMutex();
    rt_sem_take(&(servo_conf[nodeId - 2].finish_sem), RT_WAITING_FOREVER);
    rt_sem_detach(&(servo_conf[nodeId - 2].finish_sem));
}
void canopen_send_sdo(uint16_t *message_sdo, UNS8 nodeId) // or displays-the-size-of-the-formula `uint16_t message_sdo[8]`
{
    if (message_sdo[0] == 0)
        return;
    uint16_t index = (uint16_t)(message_sdo[2] << 8 | message_sdo[1]);
    uint8_t subIndex = (uint8_t)(message_sdo[3]);
    uint32_t count = 0;
    uint8_t dataType = 0;
    uint8_t data[4] = {0};
    unsigned long abortCode = 0;
    uint8_t cnt = 0;

    switch (message_sdo[0] & 0x0F)
    {
    case 0x0F:
        count = 1;
        dataType = uint8;
        break;
    case 0x0B:
        count = 2;
        dataType = uint16;
        break;
    case 0x07:
        count = 3;
        dataType = uint24;
        break;
    case 0x03:
        count = 4;
        dataType = uint32;
        break;
    default:
        count = 4;
        dataType = uint32;
        break;
    }

    for (int i = 0; i < 4; i++)
        data[i] = (uint8_t)message_sdo[4 + i];

    // d; nodeId; index; subIndex; count; dataType; data[4]; useBlockMode;
    writeNetworkDict(g_pCO_Data, nodeId, index, subIndex, count, dataType, &data, 0);
    while (getWriteResultNetworkDict(g_pCO_Data, nodeId, &abortCode) != SDO_FINISHED)
    {
        if (++cnt > 3)
        {
            LOG_E("canopen_send_sdo writeNetworkDict failed %d times, abortCode = %lu!", cnt, abortCode);
            break;
        }
        writeNetworkDict(g_pCO_Data, nodeId, index, subIndex, count, dataType, &data, 0);
    }
}
/* auto cite while motor entry preOperational state */
void canopen_start_thread_entry(void *parameter)
{
    UNS32 sync_id, size;
    UNS8 data_type, sub_cnt;
    UNS32 consumer_heartbeat_time;

    rt_thread_delay(200); // 200tick

    /* bug: only send odd message */
    // for (int i = 0; i < MOTOR_LIMIT_PARA_SDO_LENGTH; i++)
    // {
    //     EnterMutex();
    //     canopen_send_sdo(motor_limit_para_sdo[i], MOTOR_NODEID);
    //     LeaveMutex();
    //     rt_thread_mdelay(10);
    // }

    config_motor(MOTOR_NODEID);                    // offline map slave pdo
    g_pCO_Data->post_SlaveBootup = slaveBootupHdl; // online map slave pdo

    // 1015h    VAR    变量     Inhibit time emergency      紧急报文禁止时间（单位 100us）
    // 1016h    ARRAY  数组     Consumer heartbeat time     消费者心跳时间间隔(单位 ms)
    // 1017h    VAR    变量     Producer heartbeat time     生产者心跳时间间隔（单位 ms）

    /* 主机作为客户端消费数据, 设置主机心跳报文0x70x周期, 不过对象字典中SYNC并未打开心跳, 需将nimotion_obj1005设未0x4000 0080则打开心跳 */
    consumer_heartbeat_time = (2 << 16) | CONSUMER_HEARTBEAT_TIME;
    size = 4;
    writeLocalDict(g_pCO_Data, 0x1016, 0x01, &consumer_heartbeat_time, &size, 0);
    consumer_heartbeat_time = (3 << 16) | CONSUMER_HEARTBEAT_TIME;
    writeLocalDict(g_pCO_Data, 0x1016, 0x02, &consumer_heartbeat_time, &size, 0);
    sub_cnt = 2;
    size = 1;
    writeLocalDict(g_pCO_Data, 0x1016, 0x00, &sub_cnt, &size, 0);

    /* master entry oper and make motor entry oper */
    setState(g_pCO_Data, Operational);
    masterSendNMTstateChange(g_pCO_Data, MOTOR_NODEID, NMT_Start_Node);

    data_type = uint32;
    size = 4;
    readLocalDict(g_pCO_Data, 0x1005, 0, &sync_id, &size, &data_type, 0);
    sync_id |= (1 << 30);
    writeLocalDict(g_pCO_Data, 0x1005, 0, &sync_id, &size, 0);
}

static void InitNodes(CO_Data *d, UNS32 id)
{
    setNodeId(g_pCO_Data, 0x7f); // master address
    setState(g_pCO_Data, Initialisation);
}
void nimotion_heartbeatError(CO_Data *d, UNS8 heartbeatID)
{
    LOG_D("heartbeatError %d", heartbeatID);
}

void nimotion_initialisation(CO_Data *d)
{
    LOG_D("canfestival enter initialisation state");
}

void nimotion_preOperational(CO_Data *d)
{
    rt_thread_t tid;
    LOG_D("canfestival enter preOperational state");
    tid = rt_thread_create("pdo_map", canopen_start_thread_entry, RT_NULL, 1024, MOTOR_PRIORITY + 4, 2);
    if (tid == RT_NULL)
        LOG_E("canfestival config thread start failed!");
    else
        rt_thread_startup(tid);
}

void nimotion_operational(CO_Data *d)
{
    LOG_D("canfestival enter operational state");
}

void nimotion_stopped(CO_Data *d)
{
    LOG_D("canfestival enter stop state");
}

void nimotion_post_sync(CO_Data *d)
{
}

void nimotion_post_TPDO(CO_Data *d)
{
}

void nimotion_storeODSubIndex(CO_Data *d, UNS16 wIndex, UNS8 bSubindex)
{
    LOG_D("storeODSubIndex : %4.4x %2.2x", wIndex, bSubindex);
}

void nimotion_post_emcy(CO_Data *d, UNS8 nodeID, UNS16 errCode, UNS8 errReg, const UNS8 errSpec[5])
{
    LOG_D("received EMCY message. Node: %2.2x  ErrorCode: %4.4x  ErrorRegister: %2.2x", nodeID, errCode, errReg);
}

void motor_control_init(void)
{
    g_pCO_Data->heartbeatError = nimotion_heartbeatError;
    g_pCO_Data->initialisation = nimotion_initialisation;
    g_pCO_Data->preOperational = nimotion_preOperational;
    g_pCO_Data->operational = nimotion_operational;
    g_pCO_Data->stopped = nimotion_stopped;
    g_pCO_Data->post_sync = nimotion_post_sync;
    g_pCO_Data->post_TPDO = nimotion_post_TPDO;
    g_pCO_Data->storeODSubIndex = (storeODSubIndex_t)nimotion_storeODSubIndex;
    g_pCO_Data->post_emcy = (post_emcy_t)nimotion_post_emcy;
    canOpen(RT_NULL, g_pCO_Data);
    initTimer();

    g_motor_mq = rt_mq_create("motor_reback", sizeof(rt_int32_t) * 3, 32, RT_IPC_FLAG_PRIO);

    StartTimerLoop(&InitNodes); // set soft timer to entry initialisation state, after entry preOperational state
}
/*********************************************************** mater init ***********************************************************/

/*********************************************************** slave pdo map ***********************************************************/
static void config_servo_param_cb(CO_Data *d, UNS8 nodeId)
{
    UNS32 abortCode;
    UNS8 res;
    struct servo_config_state *conf;

    conf = &servo_conf[nodeId - 2];
    res = getWriteResultNetworkDict(g_pCO_Data, nodeId, &abortCode);
    closeSDOtransfer(g_pCO_Data, nodeId, SDO_CLIENT);
    if (res != SDO_FINISHED)
    {
        conf->try_cnt++;
        LOG_W("write SDO failed!  nodeId = %d, abortCode = 0x%08X", nodeId, abortCode);
        if (conf->try_cnt < 3)
        {
            config_motor_param(nodeId, conf);
        }
        else
        {
            rt_sem_release(&(conf->finish_sem));
            conf->state = 0;
            conf->try_cnt = 0;
            LOG_E("SDO config try count > 3, config failed!");
        }
    }
    else
    {
        conf->state++;
        conf->try_cnt = 0;
        config_motor_param(nodeId, conf);
    }
}

/* state-machine: cross-reference-mapping-based-on-the-host-object-dictionary */
static void config_motor_param(uint8_t nodeId, struct servo_config_state *conf)
{
    switch (conf->state)
    {
    /* TPDO1 */
    case 0: /* disable Slave TPDO1 */
    {
        UNS32 TPDO_COBId = 0x80000180 + nodeId;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1800, 1,
                                 4, uint32, &TPDO_COBId, config_servo_param_cb, 0);
    }
    break;
    case 1: /* 1SYNC synchronous */
    {
        UNS8 trans_type = PDO_TRANSMISSION_TYPE;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1800, 2,
                                 1, uint8, &trans_type, config_servo_param_cb, 0);
    }
    break;
    case 2: /* clear map */
    {
        UNS8 pdo_map_cnt = 0;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1A00, 0,
                                 1, uint8, &pdo_map_cnt, config_servo_param_cb, 0);
    }
    break;
    case 3: /* map xxx */
    {
        UNS32 pdo_map_val = 0x60410010; /* uint16 */
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1A00, 1,
                                 4, uint32, &pdo_map_val, config_servo_param_cb, 0);
    }
    break;
    case 4: /* map xxx */
    {
        UNS32 pdo_map_val = 0x60640020; /* int32 */
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1A00, 2,
                                 4, uint32, &pdo_map_val, config_servo_param_cb, 0);
    }
    break;
    case 5: /* map count */
    {
        UNS8 pdo_map_cnt = 2;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1A00, 0,
                                 1, uint8, &pdo_map_cnt, config_servo_param_cb, 0);
    }
    break;
    case 6: /* enable Slave's TPDO */
    {
        UNS32 TPDO_COBId = 0x00000180 + nodeId;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1800, 1,
                                 4, uint32, &TPDO_COBId, config_servo_param_cb, 0);
    }
    break;
    /* TPDO2 */
    case 7:
    {
        UNS32 TPDO_COBId = 0x80000280 + nodeId;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1801, 1,
                                 4, uint32, &TPDO_COBId, config_servo_param_cb, 0);
    }
    break;
    case 8:
    {
        UNS8 trans_type = PDO_TRANSMISSION_TYPE;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1801, 2,
                                 1, uint8, &trans_type, config_servo_param_cb, 0);
    }
    break;
    case 9:
    {
        UNS8 pdo_map_cnt = 0;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1A01, 0,
                                 1, uint8, &pdo_map_cnt, config_servo_param_cb, 0);
    }
    break;
    case 10: /* map xxx */
    {
        UNS32 pdo_map_val = 0x606c0020; /* int32 */
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1A01, 1,
                                 4, uint32, &pdo_map_val, config_servo_param_cb, 0);
    }
    break;
    case 11: /* map xxx */
    {
        UNS32 pdo_map_val = 0x60770010; /* int16 */
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1A01, 2,
                                 4, uint32, &pdo_map_val, config_servo_param_cb, 0);
    }
    break;
    case 12:
    {
        UNS8 pdo_map_cnt = 2;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1A01, 0,
                                 1, uint8, &pdo_map_cnt, config_servo_param_cb, 0);
    }
    break;
    case 13:
    {
        UNS32 TPDO_COBId = 0x00000280 + nodeId;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1801, 1,
                                 4, uint32, &TPDO_COBId, config_servo_param_cb, 0);
    }
    break;
    /* RPDO1 */
    case 14:
    {
        UNS32 RPDO_COBId = 0x80000200 + nodeId;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1400, 1,
                                 4, uint32, &RPDO_COBId, config_servo_param_cb, 0);
    }
    break;
    case 15:
    {
        UNS8 trans_type = PDO_TRANSMISSION_TYPE;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1400, 2,
                                 1, uint8, &trans_type, config_servo_param_cb, 0);
    }
    break;
    case 16:
    {
        UNS8 pdo_map_cnt = 0;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1600, 0,
                                 1, uint8, &pdo_map_cnt, config_servo_param_cb, 0);
    }
    break;
    case 17: /* map xxx */
    {
        UNS32 pdo_map_val = 0x60400010; /* uint16*/
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1600, 1,
                                 4, uint32, &pdo_map_val, config_servo_param_cb, 0);
    }
    break;
    case 18: /* map xxx */
    {
        UNS32 pdo_map_val = 0x60600008; /* int8 */
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1600, 2,
                                 4, uint32, &pdo_map_val, config_servo_param_cb, 0);
    }
    break;
    case 19:
    {
        UNS8 pdo_map_cnt = 2;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1600, 0,
                                 1, uint8, &pdo_map_cnt, config_servo_param_cb, 0);
    }
    break;
    case 20:
    {
        UNS32 RPDO_COBId = 0x00000200 + nodeId;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1400, 1,
                                 4, uint32, &RPDO_COBId, config_servo_param_cb, 0);
    }
    break;
    /* RPDO2 */
    case 21:
    {
        UNS32 RPDO_COBId = 0x80000300 + nodeId;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1401, 1,
                                 4, uint32, &RPDO_COBId, config_servo_param_cb, 0);
    }
    break;
    case 22:
    {
        UNS8 trans_type = PDO_TRANSMISSION_TYPE;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1401, 2,
                                 1, uint8, &trans_type, config_servo_param_cb, 0);
    }
    break;
    case 23:
    {
        UNS8 pdo_map_cnt = 0;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1601, 0,
                                 1, uint8, &pdo_map_cnt, config_servo_param_cb, 0);
    }
    break;
    case 24: /* map xxx */
    {
        UNS32 pdo_map_val = 0x607a0020; /* int32 */
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1601, 1,
                                 4, uint32, &pdo_map_val, config_servo_param_cb, 0);
    }
    break;
    case 25: /* map xxx */
    {
        UNS32 pdo_map_val = 0x60ff0020; /* int32 */
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1601, 2,
                                 4, uint32, &pdo_map_val, config_servo_param_cb, 0);
    }
    break;
    case 26:
    {
        UNS8 pdo_map_cnt = 2;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1601, 0,
                                 1, uint8, &pdo_map_cnt, config_servo_param_cb, 0);
    }
    break;
    case 27:
    {
        UNS32 TPDO_COBId = 0x00000300 + nodeId;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1401, 1,
                                 4, uint32, &TPDO_COBId, config_servo_param_cb, 0);
    }
    break;
    /* RPDO3 */
    case 28:
    {
        UNS32 RPDO_COBId = 0x80000400 + nodeId;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1402, 1,
                                 4, uint32, &RPDO_COBId, config_servo_param_cb, 0);
    }
    break;
    case 29:
    {
        UNS8 trans_type = PDO_TRANSMISSION_TYPE;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1402, 2,
                                 1, uint8, &trans_type, config_servo_param_cb, 0);
    }
    break;
    case 30:
    {
        UNS8 pdo_map_cnt = 0;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1602, 0,
                                 1, uint8, &pdo_map_cnt, config_servo_param_cb, 0);
    }
    break;
    case 31: /* map xxx */
    {
        UNS32 pdo_map_val = 0x60710010; /* int16 */
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1602, 1,
                                 4, uint32, &pdo_map_val, config_servo_param_cb, 0);
    }
    break;
    case 32: /* map xxx */
    {
        UNS32 pdo_map_val = 0x60800020; /* uint32 */
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1602, 2,
                                 4, uint32, &pdo_map_val, config_servo_param_cb, 0);
    }
    break;
    case 33:
    {
        UNS8 pdo_map_cnt = 2;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1602, 0,
                                 1, uint8, &pdo_map_cnt, config_servo_param_cb, 0);
    }
    break;
    case 34:
    {
        UNS32 TPDO_COBId = 0x00000400 + nodeId;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1402, 1,
                                 4, uint32, &TPDO_COBId, config_servo_param_cb, 0);
    }
    break;
    /* 1017h 生产者电机心跳时间间隔(ms) */
    case 35:
    {
        UNS16 producer_heartbeat_time = PRODUCER_HEARTBEAT_TIME;
        writeNetworkDictCallBack(g_pCO_Data, nodeId, 0x1017, 0,
                                 2, uint16, &producer_heartbeat_time, config_servo_param_cb, 0);
    }
    break;
    /* finised map */
    case 36:
        rt_sem_release(&(conf->finish_sem));
        break;
    default:
        break;
    }
}
/*********************************************************** slave pdo map ***********************************************************/

/*********************************************************** entry function ***********************************************************/
void motor_control_entry(void *parameter)
{
    rt_err_t ret;
    motor_control_init();
    LOG_I("motor_control_init finised!");
    while (1)
    {
        /* user app code */
        int32_t motor_reback[3] = {0};
        motor_reback[0] = Position_actual_value;
        motor_reback[1] = Velocity_actual_value;
        motor_reback[2] = torque_actual_value_6077;
        ret = rt_mq_send_wait(g_motor_mq, motor_reback, sizeof(motor_reback), 5);
        if (-RT_ERROR == ret)
            LOG_E("rt_mq_send_wait failed, send message exceed max length!");

        if (g_control_command_sem != RT_NULL)
        {
            ret = rt_sem_take(g_control_command_sem, 5);
            if (RT_EOK == ret)
            {
                rt_mutex_take(g_control_command_mutex, CONTROL_COMMAND_MUTEX_WAIT_TIME);
                rt_kprintf("g_motor_pos: %d\n", g_motor_pos * 10000);
                rt_kprintf("g_motor_speed: %d\n", g_motor_speed * 10000);
                rt_kprintf("g_motor_torque: %d\n", g_motor_torque);
                Target_position = g_motor_pos * 10000;
                Target_velocity = g_motor_speed * 10000;
                torque_actual_value_6077 = g_motor_torque;
                rt_mutex_release(g_control_command_mutex);
            }
        }
        rt_thread_mdelay(10);
    }
}

int motor_control_thread(void)
{
    rt_thread_t tid = RT_NULL;
    tid = rt_thread_create("motor_control_thread", motor_control_entry,
                           RT_NULL, MOTOR_STACK_SIZE,
                           MOTOR_PRIORITY, MOTOR_TIMESLICE);
    if (tid != RT_NULL)
        rt_thread_startup(tid);
    return 0;
}
// MSH_CMD_EXPORT(motor_control_thread, motor_control_thread);
INIT_DEVICE_EXPORT(motor_control_thread);
/*********************************************************** entry function ***********************************************************/

/*********************************************************** debug cmd ***********************************************************/
static void cmd_motor_info(void)
{
    rt_kprintf("Controlword 0x%0X\n", (uint16_t)Controlword);
    rt_kprintf("Statusword 0x%0X\n", (int8_t)Statusword);
    rt_kprintf("Modes_of_operation 0x%0X\n", (uint16_t)Modes_of_operation);
    rt_kprintf("Position_actual_value %d\n", (int32_t)Position_actual_value);
    rt_kprintf("Velocity_actual_value %d\n", (int32_t)Velocity_actual_value);
    rt_kprintf("torque_actual_value %d\n", (int16_t)torque_actual_value_6077);
}
MSH_CMD_EXPORT(cmd_motor_info, cmd_motor_info);

static void cmd_motor_enable(int argc, char *argv[])
{
    if (argc < 2)
    {
        rt_kprintf("Usage: cmd_motor_on [Modes_of_operation]\n");
        return;
    }
    uint8_t operationMode = atoi(argv[1]);
    Modes_of_operation = operationMode;
    Target_position = Position_actual_value; /* avoid dithering */
    Target_velocity = 0;                     /* avoid dithering */
    target_torque_6071 = 0;                  /* avoid dithering */
    Controlword = CONTROL_WORD_SHUTDOWN;
    SYNC_DELAY;
    Controlword = CONTROL_WORD_SWITCH_ON;
    SYNC_DELAY;
    Controlword = CONTROL_WORD_ENABLE_OPERATION;
}
MSH_CMD_EXPORT(cmd_motor_enable, cmd_motor_enable);

static void cmd_motor_disable(int argc, char *argv[])
{
    Controlword = CONTROL_WORD_SHUTDOWN;
    SYNC_DELAY;
    Controlword = CONTROL_WORD_DISABLE_VOLTAGE;
}
MSH_CMD_EXPORT(cmd_motor_disable, cmd_motor_disable);

static void cmd_motor_position_set(int argc, char *argv[])
{
    if (argc < 2)
    {
        rt_kprintf("Usage: motor_relmove [Target_position]\n");
        return;
    }
    int32_t position = atoi(argv[1]);
    LOG_I("Target_position: %d\n", position);
    Target_position = position;
    target_torque_6071 = 10;
}
MSH_CMD_EXPORT(cmd_motor_position_set, cmd_motor_position_set);

static void cmd_motor_velocity_set(int argc, char *argv[])
{
    if (argc < 2)
    {
        rt_kprintf("Usage: motor_relmove [Target_velocity]\n");
        return;
    }
    int32_t velocity = atoi(argv[1]);
    rt_kprintf("Target_velocity: %d\n", velocity);
    Target_velocity = velocity;
    target_torque_6071 = 10;
}
MSH_CMD_EXPORT(cmd_motor_velocity_set, cmd_motor_velocity_set);

static void cmd_motor_torque_set(int argc, char *argv[])
{
    if (argc < 2)
    {
        rt_kprintf("Usage: motor_relmove [Target_torque]\n");
        return;
    }
    int32_t torque = atoi(argv[1]);
    rt_kprintf("Target_torque: %d\n", torque);
    target_torque_6071 = torque;
    max_velocity_6080 = 10; // rpm
}
MSH_CMD_EXPORT(cmd_motor_torque_set, cmd_motor_torque_set);

static void cmd_motor_zero_run(int argc, char *argv[])
{
    rt_kprintf("Position_actual_value: %d\n", Position_actual_value);
    Controlword = CONTROL_WORD_RUNNING_OPERATION;
}
MSH_CMD_EXPORT(cmd_motor_zero_run, cmd_motor_zero_run);
/*********************************************************** debug cmd ***********************************************************/

/*********************************************************** external-interfaces ***********************************************************/
void motor_enable(PageState_t cur_page)
{
    switch (cur_page)
    {
    case ZERO_MODE_PAGE:
        Modes_of_operation = CSP_MODE;
        Target_position = 0;
        break;
    case POSITION_MODE_PAGE:
        Modes_of_operation = CSP_MODE;
        Target_position = Position_actual_value;
        break;
    case SPEED_MODE_PAGE:
        Modes_of_operation = CSV_MODE;
        Target_position = Position_actual_value;
        break;
    case TORQUE_MODE_PAGE:
        Modes_of_operation = CST_MODE;
        Target_position = Position_actual_value;
        break;
    case SYNC_MODE_PAGE:
        Modes_of_operation = CSP_MODE;
        Target_position = Position_actual_value;
        break;
    default:
        LOG_E("motor_enable recv illegal page status");
        break;
    }
    Target_velocity = 0;
    target_torque_6071 = 0;
    Controlword = CONTROL_WORD_SHUTDOWN;
    SYNC_DELAY;
    Controlword = CONTROL_WORD_SWITCH_ON;
    SYNC_DELAY;
    Controlword = CONTROL_WORD_ENABLE_OPERATION;
}

void motor_disable(void)
{
    Target_position = Position_actual_value;
    Target_velocity = 0;
    target_torque_6071 = 0;
    Controlword = CONTROL_WORD_SHUTDOWN;
    Modes_of_operation = NO_DEF0;
    SYNC_DELAY;
    Controlword = CONTROL_WORD_DISABLE_VOLTAGE;
}
/*********************************************************** external-interfaces ***********************************************************/