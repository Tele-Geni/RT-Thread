#include "icm20608_thread.h"

#define LOG_TAG "icm.thread"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

static icm20608_device_t g_dev = RT_NULL;
rt_mq_t g_icm20608_mq = RT_NULL;

static void icm20608_entry_init(void)
{
    g_dev = icm20608_init(ICM_DEV_NAME);
    if (RT_NULL == g_dev)
        LOG_E("The sensor initializes failure");
    else
        LOG_D("The sensor initializes success");

    rt_err_t ret;
    ret = icm20608_calib_level(g_dev, 10); // 对 icm20608 进行零值校准：采样 10 次，求取平均值作为零值
    if (ret == RT_EOK)
    {
        LOG_D("The sensor calibrates success");
        LOG_D("accel_offset: X%6d  Y%6d  Z%6d", g_dev->accel_offset.x, g_dev->accel_offset.y, g_dev->accel_offset.z);
        LOG_D("gyro_offset : X%6d  Y%6d  Z%6d", g_dev->gyro_offset.x, g_dev->gyro_offset.y, g_dev->gyro_offset.z);
    }
    else
    {
        LOG_E("The sensor calibrates failure");
        icm20608_deinit(g_dev);
    }
    g_icm20608_mq = rt_mq_create("icm20608", sizeof(rt_int16_t) * 6, 32, RT_IPC_FLAG_PRIO);
}

void icm20608_entry(void *parameter)
{
    rt_int16_t icm_buf[6];
    rt_err_t ret;

    icm20608_entry_init();
    LOG_I("icm20608_entry_init success");

    while (1)
    {
        memset(icm_buf, 0, sizeof(icm_buf));
        /* accel_x 、accel_y 、accel_z */
        ret = icm20608_get_accel(g_dev, &icm_buf[0], &icm_buf[1], &icm_buf[2]);
        if (ret == RT_EOK)
            LOG_D("accel_x : %5d, accel_y : %5d, accel_z : %5d", icm_buf[0], icm_buf[1], icm_buf[2]);
        else
        {
            LOG_E("The sensor does not work");
            break;
        }
        /* gyros_x 、gyros_y 、gyros_z */
        ret = icm20608_get_gyro(g_dev, &icm_buf[3], &icm_buf[4], &icm_buf[5]);
        if (ret == RT_EOK)
            LOG_D("gyros_x : %5d, gyros_y : %5d, gyros_z : %5d", icm_buf[3], icm_buf[4], icm_buf[5]);
        else
        {
            LOG_E("The sensor does not work");
            break;
        }
        ret = rt_mq_send_wait(g_icm20608_mq, icm_buf, sizeof(icm_buf), RT_WAITING_FOREVER);
        if (ret != RT_EOK)
            LOG_W("rt_mq_send_wait failed!");
        rt_thread_mdelay(800); // 队伍满了，生产者可以等，但是不能让消费者等
    }
}

int icm20608_thread(void)
{
    rt_thread_t tid = RT_NULL;
    tid = rt_thread_create("icm20608_thread",
                           icm20608_entry, RT_NULL,
                           ICM20608_STACK_SIZE,
                           ICM20608_PRIORITY, ICM20608_TIMESLICE);
    if (tid != RT_NULL)
        rt_thread_startup(tid);
    return 0;
}
// MSH_CMD_EXPORT(icm20608_thread, icm20608_thread);
INIT_DEVICE_EXPORT(icm20608_thread);
