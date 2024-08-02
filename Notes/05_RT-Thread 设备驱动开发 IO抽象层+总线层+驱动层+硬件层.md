# [RT-Thread 设备驱动开发] I/O抽象层+总线层+驱动层+硬件层

> 总结型笔记，内容会不断扩充。

## 一、框架介绍

### 问题提出

> 实际项目开发中，我们往往会进行不同的硬件尝试来看是否满足业务功能需求，如WIFI、FLASH等芯片的更换甚至可能是主控MCU的更换。但由于同一功能不同品牌的硬件之间使用差异性较大，需要查阅用户使用手册进行重新编码实现相关接口，同时应用层业务代码也需要进行接口修改。
>
> 当你终于更改完了，操蛋的leader说还是换回原有硬件方案吧，但此时你又在此基础上开发了新的业务代码。于是你又要吭哧吭哧的把新硬件平台上的新业务代码拷贝到旧硬件平台上并做一些接口的修改，捣腾两次这种无趣且又需要仔细的工作后，好了你人没了 ! ! !

基于以上问题，提出几个想法：

1. 更换新硬件平台时，可不可以不用去查阅用户使用手册实现接口？ -> `事先有人提你实现好 `
2. 更换新硬件平台时，可不可以不做应用层业务代码的修改？           -> `调用统一的抽象接口`
3. 更换回旧硬件平台时，可不可以一键进行切换？                            -> `引入"总线"替我们进行管理`

思考一下上面几个问题，我们可以发现本质上是因为我们的业务代码和底层硬件代码是直接依赖的、强耦合的，在程序设计中我们常用的解耦方法有：使用抽象层(抽象数据结构和函数接口、模块化编程)、模块间通信(回调函数、消息传递)、依赖注入(通过参数传递所需的依赖)、接口设计(避免直接访问对方的内部实现)等。

### 解决方案

- 问题1解决方案，`设备驱动代码`以模块化的方式进行开发，使用者则不需要对内部实现进行探究。

- 问题3解决方案，引入"总线"（在RT-Thread中称为`设备驱动框架层`）将程序分离为设备驱动抽象层(DAL)与硬件抽象层(HAL)，使用不同硬件平台时，只需要注册不同硬件平台(STM32、LPC)来与某一设备驱动代码进行匹配。

  ![image-20240801220558378](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801220558378.png)

至此前面三个问题其实都能得到解决了，在总线这一`抽象层`可以提供`统一的接口`来对硬件进行操作。但是还不够优雅，除了spi还有iic、uart、can等系列总线，对于大型项目只开发应用层代码的人，他学起来还是很困难太多了，再给我抽象一下也就是RT-Thread中的`I/O设备管理层`。

需要注意的是，对于简单设备会省略设备驱动框架层这一步骤，而是直接向上层I/O设备管理层进行注册，这样的坏处是不利于统一管理，对应Linux就是不使用platform框架进行字符设备开发。

![image-20240801223947677](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801223947677.png)

![image-20240801225032355](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801225032355.png)

![image-20240730213950708](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240730213950708.png)



## 二、设备驱动开发

### API接口函数

- **以看门狗设备开发为例，下图为实际开发序列图：**

![image-20240801225859601](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801225859601.png)

> 底层部分

- **设备节点创建、销毁**

```c
rt_device_t rt_device_create(int type, int attach_size); // attach_size 用户数据大小
void rt_device_destroy(rt_device_t device);
/*--------------------------------------type-----------------------------------------*/
RT_Device_Class_Char             /* 字符设备       */
RT_Device_Class_Block            /* 块设备         */
RT_Device_Class_NetIf            /* 网络接口设备    */
RT_Device_Class_MTD              /* 内存设备       */
RT_Device_Class_RTC              /* RTC 设备        */
RT_Device_Class_Sound            /* 声音设备        */
RT_Device_Class_Graphic          /* 图形设备        */
RT_Device_Class_I2CBUS           /* I2C 总线设备     */
RT_Device_Class_USBDevice        /* USB device 设备  */
RT_Device_Class_USBHost          /* USB host 设备   */
RT_Device_Class_SPIBUS           /* SPI 总线设备     */
RT_Device_Class_SPIDevice        /* SPI 设备        */
RT_Device_Class_SDIO             /* SDIO 设备       */
RT_Device_Class_Miscellaneous    /* 杂类设备        */
/*-----------------------------------------------------------------------------------*/
typedef struct rt_device *rt_device_t;
struct rt_device {...
#ifdef RT_USING_DEVICE_OPS 
    const struct rt_device_ops *ops;
#else
    rt_err_t (*init)(rt_device_t dev);
    rt_err_t (*open)(rt_device_t dev, rt_uint16_t oflag);
    rt_err_t (*close)(rt_device_t dev);
    rt_ssize_t (*read)(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size);
    rt_ssize_t (*write)(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size);
    rt_err_t (*control)(rt_device_t dev, int cmd, void *args); 
#endif 
...};
```

![image-20240730214150708](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240730214150708.png)

- **设备驱动代码注册与取消**

```c
rt_err_t rt_device_register(rt_device_t dev, const char* name, rt_uint8_t flags);
rt_err_t rt_device_unregister(rt_device_t dev);
/*--------------------------------------flags-----------------------------------------*/
#define RT_DEVICE_FLAG_RDONLY       0x001 /* 只读 */
#define RT_DEVICE_FLAG_WRONLY       0x002 /* 只写  */
#define RT_DEVICE_FLAG_RDWR         0x003 /* 读写  */
#define RT_DEVICE_FLAG_REMOVABLE    0x004 /* 可移除  */
#define RT_DEVICE_FLAG_STANDALONE   0x008 /* 独立   */
#define RT_DEVICE_FLAG_SUSPENDED    0x020 /* 挂起  */
#define RT_DEVICE_FLAG_STREAM       0x040 /* 流模式  */
#define RT_DEVICE_FLAG_INT_RX       0x100 /* 中断接收 */
#define RT_DEVICE_FLAG_DMA_RX       0x200 /* DMA 接收 */
#define RT_DEVICE_FLAG_INT_TX       0x400 /* 中断发送 */
#define RT_DEVICE_FLAG_DMA_TX       0x800 /* DMA 发送 */
/*---------------------------------rt_device_t->ops------------------------------------*/
struct rt_device_ops {
    rt_err_t (*init)(rt_device_t dev);
    rt_err_t (*open)(rt_device_t dev, rt_uint16_t oflag);
    rt_err_t (*close)(rt_device_t dev);
    rt_size_t (*read)(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size);
    rt_size_t (*write)(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size);
    rt_err_t (*control)(rt_device_t dev, int cmd, void *args);
};
```

> 应用层部分

- **访问I/O设备与数据收发回调**

![image-20240801233137590](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801233137590.png)

```c
rt_device_t rt_device_find(const char* name); // 名称匹配
rt_err_t rt_device_init(rt_device_t dev);
rt_err_t rt_device_open(rt_device_t dev, rt_uint16_t oflags); // 检查初始化
rt_err_t rt_device_close(rt_device_t dev);
rt_err_t rt_device_control(rt_device_t dev, rt_uint8_t cmd, void* arg);
rt_size_t rt_device_read(rt_device_t dev, rt_off_t pos,void* buffer, rt_size_t size);
rt_size_t rt_device_write(rt_device_t dev, rt_off_t pos,const void* buffer, rt_size_t size);
rt_err_t rt_device_set_rx_indicate(rt_device_t dev, rt_err_t (*rx_ind)(rt_device_t dev,rt_size_t size));
/*-------------------------------------oflags----------------------------------------*/
#define RT_DEVICE_OFLAG_CLOSE 0x000   /* 设备已经关闭（内部使用）*/
#define RT_DEVICE_OFLAG_RDONLY 0x001  /* 以只读方式打开设备 */
#define RT_DEVICE_OFLAG_WRONLY 0x002  /* 以只写方式打开设备 */
#define RT_DEVICE_OFLAG_RDWR 0x003    /* 以读写方式打开设备 */
#define RT_DEVICE_OFLAG_OPEN 0x008    /* 设备已经打开（内部使用）*/
#define RT_DEVICE_FLAG_STREAM 0x040   /* 设备以流模式打开 */
#define RT_DEVICE_FLAG_INT_RX 0x100   /* 设备以中断接收模式打开 */
#define RT_DEVICE_FLAG_DMA_RX 0x200   /* 设备以 DMA 接收模式打开 */
#define RT_DEVICE_FLAG_INT_TX 0x400   /* 设备以中断发送模式打开 */
#define RT_DEVICE_FLAG_DMA_TX 0x800   /* 设备以 DMA 发送模式打开 */
/*--------------------------------------cmd------------------------------------------*/
#define RT_DEVICE_CTRL_RESUME           0x01   /* 恢复设备 */
#define RT_DEVICE_CTRL_SUSPEND          0x02   /* 挂起设备 */
#define RT_DEVICE_CTRL_CONFIG           0x03   /* 配置设备 */
#define RT_DEVICE_CTRL_SET_INT          0x10   /* 设置中断 */
#define RT_DEVICE_CTRL_CLR_INT          0x11   /* 清中断 */
#define RT_DEVICE_CTRL_GET_INT          0x12   /* 获取中断状态 */
```

```c
/* 当硬件设备收到数据时，可以通过如下函数回调另一个函数来设置数据接收指示，通知上层应用线程有数据到达。 */
rt_err_t rt_device_set_rx_indicate(rt_device_t dev, rt_err_t (*rx_ind)(rt_device_t dev,rt_size_t size));
```

### 驱动快速使用

![image-20240802000742203](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802000742203.png)

> 如何从零编写一个自己的驱动？

- 打开ulog组件

![image-20240729012957564](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240729012957564.png)

- 新建`libraries\HAL_Drivers\drivers\drv_test.c` ，相当于Linux中的module_init

```c
#include <rtthread.h>
#include <rtdevice.h>

// #define DRV_DEBUG
#define LOG_TAG "drv.test"
#include <drv_log.h>

static rt_err_t dev_test_init(rt_device_t dev) {
    LOG_I("test dev init");
    return RT_EOK;
}
static rt_err_t dev_test_open(rt_device_t dev, rt_uint16_t oflag) {
    LOG_I("test dev open flag = %d", oflag);
    return RT_EOK;
}
static rt_err_t dev_test_close(rt_device_t dev) {
    LOG_I("test dev close");
    return RT_EOK;
}
static rt_ssize_t dev_test_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size) {
    LOG_I("tese dev read pos = %d, size = %d", pos, size);
    return RT_EOK;
}
static rt_ssize_t drv_test_write(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size) {
    LOG_I("tese dev write pos = %d, size = %d", pos, size);
    return RT_EOK;
}
static rt_err_t drv_test_control(rt_device_t dev, int cmd, void *args) {
    LOG_I("test dev control cmd %d", cmd);
    return RT_EOK;
}
int rt_drv_test_init(void)
{
    rt_device_t test_dev = rt_device_create(RT_Device_Class_Char, 0);
    if (!test_dev) {
        LOG_E("test dev create failed.");
        return -RT_ERROR;
    }
    test_dev->init = dev_test_init;
    test_dev->open = dev_test_open;
    test_dev->close = dev_test_close;
    test_dev->read = dev_test_read;
    test_dev->write = drv_test_write;
    test_dev->control = drv_test_control;
    if (rt_device_register(test_dev, "test_dev", RT_DEVICE_FLAG_RDWR) != RT_EOK) {
        LOG_E("test dev register failed.");
        return -RT_ERROR;
    }
    return RT_EOK;
}
INIT_BOARD_EXPORT(rt_drv_test_init); // 内核启动前进行组件初始化
```

- 加入Kconfig菜单（可省），另一篇博客[【RT-Thread ENV构建剪裁原理】](https://blog.csdn.net/telegeni/article/details/140686715?spm=1001.2014.3001.5501)中有相关介绍

  修改`libraries\HAL_Drivers\drivers\SConscript`文件，新增如下内容：

```shell
if GetDepend(['BSP_USING_TEST']):
    src += ['drv_test.c']
#    path += [os.path.join(cwd, 'drv_test')] # 用于添加头文件
```

​	修改`libraries\HAL_Drivers\drivers\drv_test.c` ，使用宏定义包含所以代码内容：

```c
#if defined(BSP_USING_TEST)
...
#endif /* BSP_USING_TEST */
```

​	作者选择将驱动添加到Hardware Drivers Config->Board extend module Drivers菜单界面中，故修改`board\Kconfig`文件，在`menu "Board extended module Drivers"`下新增如下内容：

```shell
menu "Board extended module Drivers"
    config BSP_USING_TEST
        bool "Enable test driver"
        default  n
    ...
endmenu
```

​	空格开启TEST驱动模块，即在rtconfig.h中定义BSP_USING_TEST宏。

![image-20240802004729147](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802004729147.png)

- 在应用层代码中调用设备驱动

新增`applications\drv_test_app.c`文件，内容如下：

```c
#include <rtthread.h>
#include <rtdevice.h>

#define LOG_TAG "drv.test"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

static int dev_test_app(void)
{
    rt_device_t test_dev = rt_device_find("test_dev");
    if (test_dev == RT_NULL)
    {
        LOG_E("can't find test dev.");
        return -RT_ERROR;
    }
    rt_device_open(test_dev, RT_DEVICE_OFLAG_RDWR);
    rt_device_control(test_dev, RT_DEVICE_CTRL_CONFIG, RT_NULL);
    rt_device_write(test_dev, 100, RT_NULL, 1024);
    rt_device_read(test_dev, 20, RT_NULL, 128);
    rt_device_close(test_dev);
    return RT_EOK;
}
MSH_CMD_EXPORT(dev_test_app, dev_test_app);
```

- 实验现象如下，可以发现成功注册了自己的test_dev设备并访问调用了相关ops接口。

![image-20240802010816594](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802010816594.png)

> 官方提供了很多芯片以及开发板的BSP支持，即使自己进行设备驱动开发，也不用从头进行代码编写，可以参考类似的硬件平台，接下来以星火一号的BSP为例，进行一个PIN、I2C、SPI的快速使用与分析，以便后续能根据自己的开发板进行二次开发。

### PIN设备

芯片上的引脚一般分为4类：电源、时钟、控制与I/O，其中I/O口在使用模式上又分为`通用I/O`与`功能复用I/O`(如I2C/SPI/UART等)。需要注意的是大多数MCU的引脚都不止一个功能，可以通过对总线矩阵的配置来切换实际功能。

- 应用层相关API，相关宏定义查看pin.h

```c
rt_base_t rt_pin_get(const char *name); // rt_pin_get("PF.9"); or GET_PIN(F,  9)
void rt_pin_mode(rt_base_t pin, rt_base_t mode);
void rt_pin_write(rt_base_t pin, rt_base_t value);
int rt_pin_read(rt_base_t pin);
rt_err_t rt_pin_attach_irq(rt_int32_t pin, rt_uint32_t mode, void (*hdr)(void *args), void *args);
rt_err_t rt_pin_irq_enable(rt_base_t pin, rt_uint32_t enabled);
rt_err_t rt_pin_detach_irq(rt_int32_t pin);
```

- 调用对比

这里的rt_pin_xx()就相当于前面应用部分`I/O设备管理层`的rt_device_xx()，其会调用pin.c下的全局变量static struct `rt_device_pin` _hw_pin中的`设备驱动框架层`const struct `rt_pin_ops` *ops，最终调用`设备驱动层`所提供的ops具体内容，如 _stm32_pin_ops。

```c
rt_pin_xx                                               // 接口函数         应用层
    struct rt_device_pin                                // I/O设备管理层    内核层
        struct rt_pin_ops                               // 设备驱动框架层   总线层
            stm32、gd32 driver，such as _stm32_pin_ops  // 设备驱动层       驱动层
            										//                 硬件层
-----------------------------------------------------------------------------------------
rt_device_xxx                  // 接口函数                          应用层
	rt_device_t               // struct rt_device*,I/O设备管理层    内核层
		rt_device_ops        // 设备驱动框架层                      总线层
    		my_drvier        // 设备驱动层                          驱动层
           					//                 				     硬件层
```

由于BSP官方已经帮我们适配好了，我们只需创建`applications\pin_irq.c`文件，通过接口函数简单调用I/O设备管理层的内容即可。

- 应用层开发示例

```c
#include <rtthread.h>
#include <rtdevice.h>
#define LOG_TAG "pin.irq"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>
#include <drv_gpio.h>

#define KEY_UP GET_PIN(C, 5)
#define KEY_DOWN GET_PIN(C, 1)
#define KEY_LEFT GET_PIN(C, 0)
#define KEY_RIGHT GET_PIN(C, 4)

void key_up_callback(void *args) {
    int value = rt_pin_read(KEY_UP);
    LOG_I("key up! %d", value);
}
void key_down_callback(void *args) {
    int value = rt_pin_read(KEY_DOWN);
    LOG_I("key down! %d", value);
}
void key_left_callback(void *args) {
    int value = rt_pin_read(KEY_LEFT);
    LOG_I("key left! %d", value);
}
void key_right_callback(void *args) {
    int value = rt_pin_read(KEY_RIGHT);
    LOG_I("key right! %d", value);
}
static int rt_pin_irq_example(void) {
    rt_pin_mode(KEY_UP, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_DOWN, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_LEFT, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_RIGHT, PIN_MODE_INPUT_PULLUP);
    
    rt_pin_attach_irq(KEY_UP, PIN_IRQ_MODE_FALLING, key_up_callback, RT_NULL);
    rt_pin_attach_irq(KEY_DOWN, PIN_IRQ_MODE_FALLING, key_down_callback, RT_NULL);
    rt_pin_attach_irq(KEY_LEFT, PIN_IRQ_MODE_FALLING, key_left_callback, RT_NULL);
    rt_pin_attach_irq(KEY_RIGHT, PIN_IRQ_MODE_FALLING, key_right_callback, RT_NULL);
    
    rt_pin_irq_enable(KEY_UP, PIN_IRQ_ENABLE);
    rt_pin_irq_enable(KEY_DOWN, PIN_IRQ_ENABLE);
    rt_pin_irq_enable(KEY_LEFT, PIN_IRQ_ENABLE);
    rt_pin_irq_enable(KEY_RIGHT, PIN_IRQ_ENABLE);
    
    return RT_EOK;
}
MSH_CMD_EXPORT(rt_pin_irq_example, rt_pin_irq_example);
```

![image-20240802112522679](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802112522679.png)

### I2C设备

> I2C相关内容不做过多介绍， 需要注意的是在传输期间`如果从机来不及处理主机发送过来的数据，从机设备会保持SCL时钟线为低电平`，待处理完后才会释放SCL时钟线为高电平，这也恰恰说明I2C传输过程中是在SCL高电平期间进行SDA数据读取，SCL低电平期间进行SDA数据变化。
>
> 死锁问题：主机从机之间为客户端服务器通信方式，每发送完8位后需要进行一个应答将SDA拉低，等待下一个时钟时再将SDA拉高。但是这期间如果主机刚好复位，SCL被打断直接跳过当前时钟，那么从机将会一直拉低SDA等待SCL变低，而主机复位后发现SDA为低被占用故一直等待，此时主机和从机就都进入了一个相互等待的死锁状态。
>
> 从机等待主机拉低SCL才肯释放SDA，主机等待SDA变高才会去控制SCL时钟线。
>
> 解决方案：I2C主机启动传输前，先控制I2C中的SCL时钟线产生脉冲，这样I2C从机就可以完成被挂起的读操作，从死锁状态中回复过来。 `stm32_i2c_bus_unlock`

![image-20240802113424938](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802113424938.png)

![image-20240730233820565](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240730233820565.png)

> 正式开始前，我们需要对以下三类驱动有一定概念：

**板载外设驱动**：指 MCU 之外，开发板上外设，例如 TF 卡、以太网和 LCD 等

**片上外设驱动**：指 MCU 芯片上的外设，例如硬件定时器、ADC 和看门狗等

**扩展模块驱动**：指可以通过扩展接口或者杜邦线连接的开发板的模块，例如 ESP8266 模块

> 简单使用与二次开发

- 打开`片上外设驱动`I2C1，SCL引脚号计算：端口A+24/16，引脚24%16 ---> PB8

![image-20240802114615974](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802114615974.png)

- 如何修改menuconfig菜单并新增自己的I2C6

  Kconfig修改，重点！！！

![image-20240730235558536](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240730235558536.png)

​	片上外设驱动代码修改，其实就是根据Kconfig进行代码构建和引脚信息获取

![image-20240730235807564](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240730235807564.png)

![image-20240730235840837](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240730235840837.png)

- 最终效果如下，出现了自带的i2c1与我们自己添加的i2c6

![image-20240730235903943](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240730235903943.png)

- 打开`板载外设驱动`并使用、下载i2c-tools工具并使用

![image-20240802121532122](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802121532122.png)

![image-20240802121715707](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802121715707.png)

![image-20240802121653901](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802121653901.png)

- icm20608主函数传递参数简单使用，相关代码在packages\icm20608-latest\icm20608.c中

![image-20240802122455512](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802122455512.png)

- 创建`applications\icm_20608_app.c`文件，使用现成的板载外设驱动`icm20608_xxxx`进行应用层开发

```c
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <icm20608.h>
#define LOG_TAG "icm.app"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

static void icm_thread_entry(void *parameter) {
    icm20608_device_t dev = RT_NULL;
    const char *i2c_bus_name = "i2c2";
    int count = 0;
    rt_err_t result;
    /* 初始化 icm20608 传感器 */
    dev = icm20608_init(i2c_bus_name);
    if (dev == RT_NULL) {
        LOG_E("The sensor initializes failure");
    } else {
        LOG_D("The sensor initializes success");
    }
    /* 对 icm20608 进行零值校准：采样 10 次，求取平均值作为零值 */
    result = icm20608_calib_level(dev, 10);
    if (result == RT_EOK) {
        LOG_D("The sensor calibrates success");
        LOG_D("accel_offset: X%6d  Y%6d  Z%6d", dev->accel_offset.x, dev->accel_offset.y, dev->accel_offset.z);
        LOG_D("gyro_offset : X%6d  Y%6d  Z%6d", dev->gyro_offset.x, dev->gyro_offset.y, dev->gyro_offset.z);
    } else {
        LOG_E("The sensor calibrates failure");
        icm20608_deinit(dev);
    }

    while (count++ < 100) {
        rt_int16_t accel_x, accel_y, accel_z;
        rt_int16_t gyros_x, gyros_y, gyros_z;
        /* 读取三轴加速度 */
        result = icm20608_get_accel(dev, &accel_x, &accel_y, &accel_z);
        if (result == RT_EOK) {
            LOG_D("current accelerometer: accel_x%6d, accel_y%6d, accel_z%6d", accel_x, accel_y, accel_z);
        } else {
            LOG_E("The sensor does not work");
        }
        /* 读取三轴陀螺仪 */
        result = icm20608_get_gyro(dev, &gyros_x, &gyros_y, &gyros_z);
        if (result == RT_EOK) {
            LOG_D("current gyroscope    : gyros_x%6d, gyros_y%6d, gyros_z%6d", gyros_x, gyros_y, gyros_z);
        } else {
            LOG_E("The sensor does not work");
            break;
        }
        rt_thread_mdelay(1000);
    }
}

static int icm_app(void)
{
    rt_thread_t res = rt_thread_create("icm", icm_thread_entry, RT_NULL, 1024, 20, 50);
    if (res == RT_NULL) {
        return -RT_ERROR;
    }
    rt_thread_startup(res);
    return RT_EOK;
}
MSH_CMD_EXPORT(icm_app, icm_app);
```

![image-20240802122311690](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802122311690.png)

-  如何编写自己的板载外设驱动

  相关API接口

```c
rt_device_t rt_device_find(const char* name);
// 此函数会调用rt_mutex_take，不能在中断服务程序里面调用，会导致assertion断言错误
rt_size_t rt_i2c_transfer(struct rt_i2c_bus_device *bus,
                          struct rt_i2c_msg         msgs[],
                          rt_uint32_t               num); // 消息数组的元素个数
// 由rt_i2c_transfer()封装而来,更加简单易用，推荐使用。
rt_size_t rt_i2c_master_send(struct rt_i2c_bus_device *bus,
                             rt_uint16_t               addr,
                             rt_uint16_t               flags,
                             const rt_uint8_t         *buf,
                             rt_uint32_t               count);
rt_size_t rt_i2c_master_recv(struct rt_i2c_bus_device *bus,
                             rt_uint16_t               addr,
                             rt_uint16_t               flags,
                             rt_uint8_t               *buf,
                             rt_uint32_t               count);
struct rt_i2c_msg
{
    rt_uint16_t addr;    /* 从机地址 */
    rt_uint16_t flags;   /* 读、写标志等 */
    rt_uint16_t len;     /* 读写数据字节数 */
    rt_uint8_t  *buf;    /* 读写数据缓冲区指针　*/
}
/*--------------------------------------flags----------------------------------*/
#define RT_I2C_WR              0x0000        /* 写标志，不可以和读标志进行“|”操作 */
#define RT_I2C_RD              (1u << 0)     /* 读标志，不可以和写标志进行“|”操作 */
#define RT_I2C_ADDR_10BIT      (1u << 2)     /* 10 位地址模式 */
#define RT_I2C_NO_START        (1u << 4)     /* 无开始条件 */
#define RT_I2C_IGNORE_NACK     (1u << 5)     /* 忽视 NACK */
#define RT_I2C_NO_READ_ACK     (1u << 6)     /* 读的时候不发送 ACK */
#define RT_I2C_NO_STOP         (1u << 7)     /* 不发送结束位 */
```

​	简单使用示例

```c
#include <rtthread.h>
#include <rtdevice.h>
#define LOG_TAG "i2c.drv"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>
/*--------------------------------------写操作----------------------------------*/
void i2c_single_byte_write()
{
    struct rt_i2c_bus_device *i2c_bus;
    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c2");
    if (i2c_bus == RT_NULL)
    {
        LOG_E("can't find %s device!\n", "i2c2");
    }

    struct rt_i2c_msg msgs;
    rt_uint8_t buf = 0x68;
    msgs.addr = 0x68;
    msgs.flags = RT_I2C_WR;
    msgs.buf = &buf;
    msgs.len = 1;
    if (rt_i2c_transfer(i2c_bus, &msgs, 1) == 1)
    {
        LOG_I("single byte write success!");
    }
    else
    {
        LOG_E("single byte write failed!");
    }
}
MSH_CMD_EXPORT(i2c_single_byte_write, i2c_single_byte_write);
void i2c_mult_byte_write()
{
    struct rt_i2c_bus_device *i2c_bus;
    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c2");
    if (i2c_bus == RT_NULL)
    {
        LOG_E("can't find %s device!\n", "i2c2");
    }

    struct rt_i2c_msg msgs;
    rt_uint8_t buf[3] = {0x01, 0x02, 0x03};
    msgs.addr = 0x68;
    msgs.flags = RT_I2C_WR;
    msgs.buf = buf;
    msgs.len = 3;
    if (rt_i2c_transfer(i2c_bus, &msgs, 1) == 1)
        LOG_I("mult byte write success!");
    else
        LOG_E("mult byte write failed!");
}
MSH_CMD_EXPORT(i2c_mult_byte_write, i2c_mult_byte_write);
/*--------------------------------------读操作----------------------------------*/
void i2c_single_byte_read()
{
    struct rt_i2c_bus_device *i2c_bus;
    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c2");
    if (i2c_bus == RT_NULL)
    {
        LOG_E("can't find %s device!\n", "i2c2");
    }

    struct rt_i2c_msg msgs[2];
    rt_uint8_t send_buf[1] = {0x6B};
    rt_uint8_t recv_buf[1] = {0};

    msgs[0].addr = 0x68;
    msgs[0].flags = RT_I2C_WR;
    msgs[0].buf = send_buf;
    msgs[0].len = 1;

    msgs[1].addr = 0x68;
    msgs[1].flags = RT_I2C_RD;
    msgs[1].len = 1;
    msgs[1].buf = recv_buf;

    if (rt_i2c_transfer(i2c_bus, msgs, 2) == 2)
    {
        LOG_I("single byte read success!");
    }
    else
    {
        LOG_E("single byte read failed!");
    }
}
MSH_CMD_EXPORT(i2c_single_byte_read, i2c_single_byte_read);
void i2c_mult_byte_read()
{
    struct rt_i2c_bus_device *i2c_bus;
    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c2");
    if (i2c_bus == RT_NULL)
    {
        LOG_E("can't find %s device!\n", "i2c2");
    }

    struct rt_i2c_msg msgs[2];
    rt_uint8_t send_buf[1] = {0x68};
    rt_uint8_t recv_buf[2] = {0};

    msgs[0].addr = 0x68;
    msgs[0].flags = RT_I2C_WR;
    msgs[0].buf = send_buf;
    msgs[0].len = 1;

    msgs[1].addr = 0x68;
    msgs[1].flags = RT_I2C_RD;
    msgs[1].buf = recv_buf;
    msgs[1].len = 2;

    if (rt_i2c_transfer(i2c_bus, msgs, 2) == 2)
    {
        LOG_I("mult byte read success!");
    }
    else
    {
        LOG_E("mult byte read failed");
    }
}
MSH_CMD_EXPORT(i2c_mult_byte_read, i2c_mult_byte_read);
```

​	调用关系及分层对比（个人理解）

```c
--------------------------------------RT-Thread------------------------------------------
icm_20608_app.c                                       // 应用层     
    icm20608_xx                                       // 应用层    
        write_regs、read_regs                         // 应用层  
            rt_i2c_transfer                           // 接口函数		  应用层
                struct rt_i2c_bus_device              // I/O设备管理层     内核层
                    struct rt_i2c_bus_device_ops      // 设备驱动框架层	总线层
                            stm32_i2c_master_xfer     // 设备驱动层        驱动层
                                                      //                  硬件层
----------------------------------------Linux-------------------------------------------
icm_20608_app.c                                     // 应用层              
    icm20608_xx                                     // 驱动层 		      
        write_regs、read_regs                       // 驱动层		
            rt_i2c_transfer						  // Core核心层，提供接口函数 
                struct rt_i2c_bus_device            // 适配器设备管理层
                    struct rt_i2c_bus_device_ops    // 适配器驱动框架层
                            stm32_i2c_master_xfer   // 适配器驱动层
                        						  // 硬件层
```

软件I2C，调用流程没搞懂，后续用到再仔细看。

```c
struct stm32_i2c 
	struct rt_i2c_bit_ops 
```

### SPI设备

![image-20240731010951494](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240731010951494.png)

![image-20240731011027911](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240731011027911.png)

- 打开片上外设spi2总线，并挂载自己的spi20设备

![image-20240802172840922](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802172840922.png)

​	新建`applications\spi_example.c`文件，添加如下内容

```c
#include <rtthread.h>
#include <rtdevice.h>
#include <drv_spi.h>
#include <drv_gpio.h>
static int spi_attach(void)
{
    //挂载SPI设备
    return rt_hw_spi_device_attach("spi2", "spi20", GET_PIN(B, 12), RT_NULL);
    //struct rt_spi_device *spi_device = RT_NULL;
  	//rt_spi_bus_attach_device_cspin(spi_device, "spi20", "spi2",GET_PIN(B, 12), RT_NULL));
}
INIT_DEVICE_EXPORT(spi_attach);
```

可以发现spi2总线已打开，相应的spi20设备也已挂载成功

![image-20240802175159885](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802175159885.png)

- 如何编写自己的板载外设驱动

  相关API接口函数

![image-20240731012026179](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731012026179.png)

​	简单示例，补充`applications\spi_example.c`内容如下：

```c
static int spi_transfer_one_data(void) 
{
    rt_err_t ret = RT_EOK;
    struct rt_spi_device *spi20 = (struct rt_spi_device *)rt_device_find("spi20");

    struct rt_spi_configuration cfg;
    cfg.data_width = 8;
    cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
    cfg.max_hz = 1 * 1000 * 1000;
    rt_spi_configure(spi20, &cfg);

    rt_uint8_t sendBuff = 0xDA;
    rt_uint8_t recvBuff = 0;
    ret = rt_spi_transfer(spi20, &sendBuff, &recvBuff, 1); // 来回
    rt_kprintf("ret = %d\n", ret);
    return RT_EOK;
}
MSH_CMD_EXPORT(spi_transfer_one_data, spi_transfer_one_data);

static int spi_send_one_data(void) 
{
    rt_err_t ret = RT_EOK;
    struct rt_spi_device *spi20 = (struct rt_spi_device *)rt_device_find("spi20");

    struct rt_spi_configuration cfg;
    cfg.data_width = 8;
    cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
    cfg.max_hz = 1 * 1000 * 1000;
    rt_spi_configure(spi20, &cfg);

    rt_uint8_t sendBuff = 0x1A;
    ret = rt_spi_send(spi20, &sendBuff, 1); // 单独发
    rt_kprintf("ret = %d\n", ret);
    return RT_EOK;
}
MSH_CMD_EXPORT(spi_send_one_data, spi_send_one_data);

static int spi_recv_one_data(void)
{
    rt_err_t ret = RT_EOK;
    struct rt_spi_device *spi20 = (struct rt_spi_device *)rt_device_find("spi20");

    struct rt_spi_configuration cfg;
    cfg.data_width = 8;
    cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
    cfg.max_hz = 1 * 1000 * 1000;
    rt_spi_configure(spi20, &cfg);

    rt_uint8_t recvBuff = 0;
    ret = rt_spi_recv(spi20, &recvBuff, 1); //单独接
    rt_kprintf("ret = %d\n", ret);

    return RT_EOK;
}
MSH_CMD_EXPORT(spi_recv_one_data, spi_recv_one_data);

static int spi_send_then_send_data(void)
{
    rt_err_t ret = RT_EOK;
    struct rt_spi_device *spi20 = (struct rt_spi_device *)rt_device_find("spi20");

    struct rt_spi_configuration cfg;
    cfg.data_width = 8;
    cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
    cfg.max_hz = 1 * 1000 * 1000;
    rt_spi_configure(spi20, &cfg);

    rt_uint8_t sendBuff1[2] = {0x1A, 0x99};
    rt_uint8_t sendBuff2[2] = {0x12, 0x22};
    ret = rt_spi_send_then_send(spi20, &sendBuff1, 2, &sendBuff2, 2); // 多字节多次发送
    rt_kprintf("ret = %d\n", ret);

    return RT_EOK;
}
MSH_CMD_EXPORT(spi_send_then_send_data, spi_send_then_send_data);

static int spi_send_then_recv_data(void)
{
    rt_err_t ret = RT_EOK;
    struct rt_spi_device *spi20 = (struct rt_spi_device *)rt_device_find("spi20");

    struct rt_spi_configuration cfg;
    cfg.data_width = 8;
    cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
    cfg.max_hz = 1 * 1000 * 1000;
    rt_spi_configure(spi20, &cfg);

    rt_uint8_t sendBuff1[2] = {0x1A, 0x99};
    rt_uint8_t recvBuff2[2] = {0};

    ret = rt_spi_send_then_recv(spi20, &sendBuff1, 2, &recvBuff2, 2); // 多字节来回
    rt_kprintf("ret = %d\n", ret);

    return RT_EOK;
}
MSH_CMD_EXPORT(spi_send_then_recv_data, spi_send_then_recv_data);
```

![image-20240802182347715](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802182347715.png)

- 打开`板载外设`Rw007 WLAN，记得取消上面的挂载INIT_DEVICE_EXPORT(spi_attach);

![image-20240802182256351](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802182256351.png)

硬件版本有变，修改默认引脚

![image-20240731194812211](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240731194812211.png)

成功上网

![image-20240802185442735](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240802185442735.png)





​			     



































