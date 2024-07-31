#include <rtthread.h>
#include <rtdevice.h>
#define LOG_TAG "drv.irq"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

rt_device_t g_test_dev = RT_NULL;

static rt_err_t test_drv_init(rt_device_t dev)
{
    LOG_I("test drv init!");
    return RT_EOK;
}
static rt_err_t test_drv_open(rt_device_t dev, rt_uint16_t oflag)
{
    LOG_I("test drv open flag - %d!", oflag);
    return RT_EOK;
}
static rt_err_t test_drv_close(rt_device_t dev)
{
    LOG_I("test drv close!");
    return RT_EOK;
}
static rt_ssize_t test_drv_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    LOG_I("test drv read pos = %d, size = %d!", pos, size);
    return RT_EOK;
}
static rt_ssize_t test_drv_write(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size)
{
    LOG_I("test drv write pos = %d, size = %d!", pos, size);
    return RT_EOK;
}
static rt_err_t test_drv_control(rt_device_t dev, int cmd, void *args)
{
    LOG_I("test drv control cmd = %d!", cmd);
    return RT_EOK;
}
static int rt_device_test_init(void)
{
    rt_device_t test_dev = rt_device_create(RT_Device_Class_Char, 0);
    if (!test_dev)
    {
        LOG_E("test_dev create failed!");
        return -RT_ERROR;
    }

    test_dev->init = test_drv_init;
    test_dev->open = test_drv_open;
    test_dev->close = test_drv_close;
    test_dev->read = test_drv_read;
    test_dev->write = test_drv_write;
    test_dev->control = test_drv_control;

    if (RT_EOK != rt_device_register(test_dev, "test_dev", RT_DEVICE_FLAG_RDONLY))
    {
        LOG_E("test_dev register failed!");
        return -RT_ERROR;
    }
}
MSH_CMD_EXPORT(rt_device_test_init, rt_device_test_init);
// INIT_BOARD_EXPORT(rt_device_test_init);

// static int rt_device_test_exit(void)
// {
//     if (RT_EOK != rt_device_unregister(g_test_dev))
//     {
//         rt_kprintf("test_dev unregister failed!\n");
//         return -RT_ERROR;
//     }

//     rt_device_destroy(g_test_dev);
//     return RT_EOK;
// }
// MSH_CMD_EXPORT(rt_device_test_exit, rt_device_test_exit);

static int drv_test_app(void)
{
    rt_device_t test_dev = rt_device_find("test_dev");
    if (test_dev == RT_NULL)
    {
        LOG_E("can not find test drv!");
        return -RT_ERROR;
    }
    LOG_I("fin drv_test_app!");
    rt_device_open(test_dev, RT_DEVICE_OFLAG_RDWR);
    rt_device_control(test_dev, RT_DEVICE_CTRL_CONFIG, RT_NULL);
    rt_device_write(test_dev, 100, RT_NULL, 1024);
    rt_device_read(test_dev, 20, RT_NULL, 128);

    rt_device_close(test_dev);
    return RT_EOK;
}
// MSH_CMD_EXPORT(drv_test_app, enable test drv app);
