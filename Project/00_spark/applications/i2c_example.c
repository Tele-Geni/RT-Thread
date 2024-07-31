#include <rtthread.h>
#include <rtdevice.h>
#define LOG_TAG "i2c.app"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>
void i2c_sample_single_byte_write()
{
    struct rt_i2c_bus_device *i2c_bus;
    struct rt_i2c_msg msgs;
    rt_uint8_t buf[2];

    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c2");
    if (i2c_bus == RT_NULL)
    {
        LOG_E("can't find %s device!\n", "i2c2");
    }

    buf[0] = 0x68;

    msgs.addr = 0x68;
    msgs.flags = RT_I2C_WR;
    msgs.len = 1;
    msgs.buf = buf;

    if (rt_i2c_transfer(i2c_bus, &msgs, 1) == 1)
        LOG_I("single byte write success!");
    else
        LOG_E("single byte write failed!");
}
MSH_CMD_EXPORT(i2c_sample_single_byte_write, i2c_sample_single_byte_write);
void i2c_sample_mult_byte_write()
{
    struct rt_i2c_bus_device *i2c_bus;
    struct rt_i2c_msg msgs;
    rt_uint8_t buf[3];

    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c2");
    if (i2c_bus == RT_NULL)
    {
        LOG_E("can't find %s device!\n", "i2c2");
    }

    buf[0] = 0x01;
    buf[1] = 0x02;
    buf[2] = 0x03;

    msgs.addr = 0x68;
    msgs.flags = RT_I2C_WR;
    msgs.len = 3;
    msgs.buf = buf;

    if (rt_i2c_transfer(i2c_bus, &msgs, 1) == 1)
        LOG_I("mult byte write success!");
    else
        LOG_E("mult byte write failed!");
}
MSH_CMD_EXPORT(i2c_sample_mult_byte_write, i2c_sample_mult_byte_write);
void i2c_sample_single_byte_read()
{
    struct rt_i2c_bus_device *i2c_bus;
    struct rt_i2c_msg msgs[2];
    rt_uint8_t send_buf[1], recv_buf[1];
    rt_err_t ret = RT_EOK;

    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c2");
    if (i2c_bus == RT_NULL)
    {
        LOG_E("can't find %s device!\n", "i2c2");
    }

    send_buf[0] = 0x6B;
    recv_buf[0] = 0x6A;

    msgs[0].addr = 0x32;
    msgs[0].flags = RT_I2C_WR;
    msgs[0].len = 1;
    msgs[0].buf = send_buf;

    msgs[1].addr = 0x31;
    msgs[1].flags = RT_I2C_WR;
    msgs[1].len = 1;
    msgs[1].buf = recv_buf;

    ret = rt_i2c_transfer(i2c_bus, msgs, 2);
    if (ret == 2)
        LOG_I("single byte read success!");
    else
        LOG_E("single byte read failed %d!", ret);
}
MSH_CMD_EXPORT(i2c_sample_single_byte_read, i2c_sample_single_byte_read);
void i2c_sample_mult_byte_read()
{
    struct rt_i2c_bus_device *i2c_bus;
    struct rt_i2c_msg msgs[2];
    rt_uint8_t send_buf[1], recv_buf[1];

    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c2");
    if (i2c_bus == RT_NULL)
    {
        LOG_E("can't find %s device!\n", "i2c2");
    }

    send_buf[0] = 0x88;
    recv_buf[0] = 0x6A;

    msgs[0].addr = 0x68;
    msgs[0].flags = RT_I2C_WR;
    msgs[0].len = 1;
    msgs[0].buf = send_buf;

    msgs[1].addr = 0x68;
    msgs[1].flags = RT_I2C_WR;
    msgs[1].len = 1;
    msgs[1].buf = recv_buf;

    if (rt_i2c_transfer(i2c_bus, msgs, 2) == 2)
        LOG_I("mult byte read success!");
    else
        LOG_E("mult byte read failed");
}
MSH_CMD_EXPORT(i2c_sample_mult_byte_read, i2c_sample_mult_byte_read);
