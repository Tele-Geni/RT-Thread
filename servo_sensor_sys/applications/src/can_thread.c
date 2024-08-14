#include "can_thread.h"

#define LOG_TAG "can.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

static rt_device_t g_can_dev;
static struct rt_semaphore g_rx_sem;
static struct rt_can_msg g_rxmsg = {0};
static struct rt_can_msg g_txmsg = {0};

int can_send(unsigned char id, rt_uint8_t *txbuf)
{
    rt_ssize_t size = 0;
    rt_ubase_t count = 0;

    if (!txbuf)
        LOG_W("can_send buf is null!");

    g_txmsg.id = id; // uint_8
    g_txmsg.ide = RT_CAN_STDID;
    g_txmsg.rtr = RT_CAN_DTR;
    g_txmsg.len = 8;

    // rt_strncpy(g_txmsg.data, txbuf, sizeof(txbuf));
    if (sizeof(txbuf) > sizeof(g_txmsg.data))
        count = sizeof(g_txmsg.data);
    else
        count = sizeof(txbuf);
    rt_memcpy(g_txmsg.data, txbuf, count);

    size = rt_device_write(g_can_dev, 0, &g_txmsg, sizeof(g_txmsg));
    if (size == 0)
    {
        LOG_I("rt_device_write failed!");
        return RT_ERROR;
    }
    return size;
}

static rt_err_t can_rx_call(rt_device_t dev, rt_size_t size)
{
    rt_sem_release(&g_rx_sem);
    return RT_EOK;
}

static int can_init(void)
{
    rt_err_t ret;

    g_can_dev = rt_device_find(CAN_DEV_NAME);
    if (!g_can_dev)
    {
        LOG_I("find %s failed!", CAN_DEV_NAME);
        return RT_ERROR;
    }
    ret = rt_device_open(g_can_dev, RT_DEVICE_FLAG_INT_TX | RT_DEVICE_FLAG_INT_RX); // 以中断接收及发送方式打开CAN设备
    RT_ASSERT(ret == RT_EOK);

    rt_sem_init(&g_rx_sem, "g_rx_sem", 0, RT_IPC_FLAG_PRIO);

    rt_device_set_rx_indicate(g_can_dev, can_rx_call);
}

void can_entry(void *parameter)
{
    can_init();
    LOG_I("can_init success!");
    while (1)
    {
        g_rxmsg.hdr_index = -1; // 使用默认过滤表???
        rt_sem_take(&g_rx_sem, RT_WAITING_FOREVER);
        rt_device_read(g_can_dev, 0, &g_rxmsg, sizeof(g_rxmsg));
        rt_kprintf("ID:%03x, RECV DATA:", g_rxmsg.id);
        for (int i = 0; i < 8; i++)
        {
            rt_kprintf("%02x ", g_rxmsg.data[i]);
        }
        rt_kprintf("\n");
        can_send(0x01, g_rxmsg.data);
        rt_thread_mdelay(20);
    }
}

int can_thread(void)
{
    rt_thread_t tid = RT_NULL;
    tid = rt_thread_create("can_thread",
                           can_entry, RT_NULL,
                           CAN_STACK_SIZE,
                           CAN_PRIORITY, CAN_TIMESLICE);

    if (tid != RT_NULL)
        rt_thread_startup(tid);
    return 0;
}
MSH_CMD_EXPORT(can_thread, can_thread);
// INIT_DEVICE_EXPORT(can_thread);