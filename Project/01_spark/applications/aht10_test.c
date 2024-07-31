#include <rtthread.h>
#include "aht10.h"
#define ATH10_I2C_BUS "i2c3"

rt_thread_t ath10 = RT_NULL;
rt_mq_t g_mq = RT_NULL;

void ath10_test(void *parameter)
{
    aht10_device_t dev = RT_NULL;
    float humi, temp;
    float buf[2];
    rt_err_t ret;

    g_mq = rt_mq_create("ath10", sizeof(float) * 2, 32, RT_IPC_FLAG_PRIO);

    dev = aht10_init(ATH10_I2C_BUS);
    if (RT_NULL == dev)
    {
        rt_kprintf("ath10_init failed!\n");
        return;
    }

    while (1)
    {
        // humi = aht10_read_temperature(dev);
        // temp = aht10_read_humidity(dev);
        buf[0] = aht10_read_temperature(dev);
        buf[1] = aht10_read_humidity(dev);

        // rt_kprintf("humi: %d.%d ", (int)humi, (int)(humi * 10) % 10);
        // rt_kprintf("temp: %d.%d\n", (int)temp, (int)(humi * 10) % 10);

        // 需要开启rt_vsnprintf_full才能支持浮点数输出
        // rt_kprintf("humi: %.2f, temp: %f\n", humi, temp);
        ret = rt_mq_send_wait(g_mq, buf, sizeof(buf), RT_WAITING_FOREVER);

        rt_thread_mdelay(2000);
    }
}

void ath10_create_thread(void)
{
    ath10 = rt_thread_create("ath10", ath10_test, RT_NULL, 2048, 25, 5);
    if (RT_NULL != ath10)
    {
        rt_thread_startup(ath10);
    }
    else
    {
        rt_kprintf("ath10_thread create failed!\n");
    }
}
MSH_CMD_EXPORT(ath10_create_thread, ath10_create_thread);
