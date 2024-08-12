#include "485_thread.h"

#define LOG_TAG "485.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

extern USHORT usMRegHoldBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_HOLDING_NREGS];

static eMBMasterReqErrCode write_485rtu_sensor(void *parameter)
{
    RT_UNUSED(parameter);
    USHORT usRegAddr = 0;
    USHORT usRegData = 0;
    eMBMasterReqErrCode error_code = MB_MRE_NO_ERR;
    switch (RT_NULL)
    {
    default:
        /* set baud: 0x02-9600 0x03-19200 0x04-115200
         * send cmd: 01 06 00 0C 00 04 48 0A
         * ack cmd is the same as send cmd */
        // usRegAddr = 0x03; // test
        usRegAddr = 0x0C; // baud
        usRegData = 0x03; // 19200
        error_code = eMBMasterReqWriteHoldingRegister(SLAVE_ADDR, usRegAddr, usRegData, RT_WAITING_FOREVER);
        if (error_code == MB_MRE_NO_ERR)
            LOG_D("usMRegHoldBuf[SLAVE_ADDR - 1][usRegAddr] write data: %d!", usMRegHoldBuf[SLAVE_ADDR - 1][usRegAddr]); // 如usMRegHoldBuf[2][1]为从机3寄存器1的数据
        else
            LOG_W("write_485rtu_sensor failed!");
        break;
    }
    return error_code;
}
MSH_CMD_EXPORT(write_485rtu_sensor, write_485rtu_sensor);

static eMBMasterReqErrCode read_485rtu_sensor(void *parameter)
{
    RT_UNUSED(parameter);
    USHORT usRegAddr = 0;
    USHORT usRegData = 0;
    eMBMasterReqErrCode error_code = MB_MRE_NO_ERR;
    switch (RT_NULL)
    {
    default:
        /* read angle: 0°~180°, 0~5v
         * send cmd: 01 03 00 01 00 01 D5 CA
         * ack cmd，such as: 01 03 02 (4F 75) 4D 93
         *              --> 4F 75 = 20341,no need to convert endianism */
        usRegAddr = 0x01;
        usRegData = 0x01;
        error_code = eMBMasterReqReadHoldingRegister(SLAVE_ADDR, usRegAddr, usRegData, RT_WAITING_FOREVER);
        if (error_code == MB_MRE_NO_ERR)
            LOG_D("usMRegHoldBuf[SLAVE_ADDR - 1][usRegAddr] read data: %d!", usMRegHoldBuf[SLAVE_ADDR - 1][usRegAddr]); // 如usMRegHoldBuf[2][1]为从机3寄存器1的数据
        else
            LOG_W("read_485rtu_sensor failed!");
    }
    return error_code;
}
MSH_CMD_EXPORT(read_485rtu_sensor, read_485rtu_sensor);

static void md_send_entry(void *parameter)
{
    while (1)
    {
        read_485rtu_sensor(RT_NULL);
        write_485rtu_sensor(RT_NULL);
        rt_thread_mdelay(1000);
    }
}

static void md_poll_entry(void *parameter)
{
    eMBMasterInit(USART_MODBUS_MODE, USART_PORT, USART_BAUDRATE, USART_PARITY);
    eMBMasterEnable();
    while (1)
    {
        /* 1:检查协议栈状态是否使能，eMBState初值为STATE_NOT_INITIALIZED，在eMBMasterInit()函数中被赋值为STATE_DISABLED,在eMBMasterEnable函数中被赋值为STATE_ENABLED;
         * 2:轮询EV_MASTER_FRAME_RECEIVED事件发生，若EV_MASTER_FRAME_RECEIVED事件发生，接收一帧报文数据，上报EV_MASTER_EXECUTE事件，解析一帧报文;                    */
        eMBMasterPoll();
        rt_thread_mdelay(100);
    }
}

void modbus_entry(void *parameter)
{
    rt_thread_t tid1 = RT_NULL, tid2 = RT_NULL;
    tid1 = rt_thread_create("md_poll", md_poll_entry, RT_NULL, MODBUS_POLL_STACK_SIZE, MODBUS_POLL_PRIORITY, MODBUS_TIMESLICE);
    if (tid1 != RT_NULL)
        rt_thread_startup(tid1);
    tid2 = rt_thread_create("md_send", md_send_entry, RT_NULL, MODBUS_SEND_STACK_SIZE, MODBUS_SEND_PRIORITY, MODBUS_TIMESLICE);
    if (tid2 != RT_NULL)
        rt_thread_startup(tid2);
}

int modbus_thread(void)
{
    static rt_uint8_t is_init = 0;

    if (is_init > 0)
    {
        LOG_W("modbus_thread is running\n");
        return -RT_ERROR;
    }

    rt_thread_t tid = RT_NULL;
    tid = rt_thread_create("modbus_thread",
                           modbus_entry, RT_NULL,
                           MODBUS_STACK_SIZE,
                           MODBUS_PRIORITY, MODBUS_TIMESLICE);
    if (tid != RT_NULL)
        rt_thread_startup(tid);

    is_init = 1;
    return RT_EOK;
}
// MSH_CMD_EXPORT(modbus_thread, modbus_thread);
INIT_DEVICE_EXPORT(modbus_thread);