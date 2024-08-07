#include "aht10_thread.h"

#define LOG_TAG "aht.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

static aht10_device_t g_dev = RT_NULL;
rt_mq_t g_aht10_mq = RT_NULL;

void aht10_entry_init(void)
{
    g_dev = aht10_init(ATH10_I2C_BUS);
    if (RT_NULL == g_dev)
        LOG_E("aht10_init failed!");
    g_aht10_mq = rt_mq_create("aht10", sizeof(float) * 2, 32, RT_IPC_FLAG_PRIO);
}

void aht10_entry(void *parameter)
{
    float ath10_buf[2];
    rt_err_t ret;

    aht10_entry_init();
    LOG_I("aht10_entry_init success");

    while (1)
    {
        memset(ath10_buf, 0, sizeof(ath10_buf));
        ath10_buf[0] = aht10_read_temperature(g_dev);
        ath10_buf[1] = aht10_read_humidity(g_dev);
        LOG_D("humi: %.2f, temp: %.2f", ath10_buf[0], ath10_buf[1]);
        ret = rt_mq_send_wait(g_aht10_mq, ath10_buf, sizeof(ath10_buf), RT_WAITING_FOREVER);
        if (ret != RT_EOK)
            LOG_W("rt_mq_send_wait failed!");
        rt_thread_mdelay(800); // 队伍满了，生产者可以等，但是不能让消费者等
    }
}

int aht10_thread(void)
{
    rt_thread_t tid = RT_NULL;
    tid = rt_thread_create("aht10_thread",
                           aht10_entry, RT_NULL,
                           AHT10_STACK_SIZE,
                           AHT10_PRIORITY, AHT10_TIMESLICE);
    if (tid != RT_NULL)
        rt_thread_startup(tid);
    return 0;
}
// MSH_CMD_EXPORT(aht10_thread, aht10_thread);
INIT_DEVICE_EXPORT(aht10_thread);
