# [RT-Thread] 设备驱动开发

## 一、介绍

### 简单介绍

不同厂家的MCU关于硬件API接口的设计都是不同的，硬件平台更换会带来巨大的工作量。

![image-20240730212412894](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730212412894.png)

学习成本高，代码复用率低。

不同厂商的API接口虽然都是不同的，但是它们对于同一硬件设备的操作逻辑都是相似的。

是否能够把驱动代码和驱动设备代码进行分离呢？

![image-20240730212727074](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730212727074.png)

代码层次上虽然复杂了，但是代码的复用率得到了提高，更换硬件平台时，应用层代码也无需再更改。

![image-20240730212819820](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730212819820.png)

I/O层对应Linux的文件IO

![image-20240730213008087](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730213008087.png)

![image-20240730213027148](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730213027148.png)

> 没太懂驱动和BSP的区别?

![image-20240730213114354](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730213114354.png)

> 相比Linux，这里的设备驱动层中就有点像对应不同的设备树也就硬件对应不同的驱动代码，但是Linux用的是设备树匹配，这里RTT我猜测就是用的名称匹配。有点迷糊，感觉设备驱动层框架+设备驱动层 合起来 对应Linux的设备驱动开发，I/O设备管理层就是对应Linux的应用层文件IO。

![image-20240730213231832](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730213231832.png)

![image-20240730213731456](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730213731456.png)

![image-20240730213950708](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730213950708.png)

![image-20240730214030262](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730214030262.png)

字符设备`顺序读取`，不支持随机访问；块设备可以`随机访问`设备数据，不同扇区

![image-20240730214150708](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730214150708.png)

MSH可以重定向到任意的字符设备上，如可以将打印输出到LCD上，将LCD虚拟成字符设备

![image-20240730214402907](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730214402907.png)

### API接口函数

- 创建/销毁

![image-20240730214443962](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730214443962.png)

- 注册/销毁

![image-20240730214525383](../../../AppData/Roaming/Typora/typora-user-images/image-20240730214525383.png)

​	注册设备flags

![image-20240730214608699](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730214608699.png)

![image-20240730215341358](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730215341358.png)

- 查找设备/初始化设备

![image-20240730215415749](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730215415749.png)

- 打开和关闭设备

![image-20240730215504592](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730215504592.png)

![image-20240730215530951](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730215530951.png)

- control

![image-20240730215735801](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730215735801.png)

- 读写

![image-20240730215752922](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730215752922.png)

![image-20240730215817797](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730215817797.png)

![image-20240730215830942](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730215830942.png)

### 应用层访问I/O框架的关系图

![image-20240730215930198](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730215930198.png)



设备驱动开发分层

I/O设备管理层 对应 file_operations

它这里既有rt_device_ops又有rt_pin_ops，而且两者也没有什么继承关系(没找到)，每搞懂两者的区别。

难道说rt_device_ops只是对应Linux中的应用层文件IO？还是说IO设备管理层，不同类型设备都有一个结构体，并没有在上次再做封装？

在rt_pin_ops下又去实现不同硬件的驱动函数

![image-20240729013059671](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240729013059671.png)

完善rt_device_t中的ops操作函数并进行注册，最后通过APP函数进行调用。

![image-20240730233211125](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730233211125.png)

![image-20240730233202064](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730233202064.png)

> 以PIN设备为例，进行学习展开

![image-20240730220645310](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730220645310.png)

- 配置

![image-20240730220724277](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730220724277.png)

![image-20240730221658322](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730221658322.png)

自己追代码后续，没找到它是怎么跳转的。

![image-20240730233239238](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730233239238.png)

![image-20240730222651757](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730222651757.png)

ulog打开

![image-20240729012957564](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240729012957564.png)

- 按键FlexibleButton按键库，通过scon脚本查看哪个是示例demo，然后修改KEY按键引脚定义，包含头文件，解决报错问题

![image-20240730225004817](../../../AppData/Roaming/Typora/typora-user-images/image-20240730225004817.png)

## 二、设备驱动入门I2C、SPI

![image-20240730232830835](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730232830835.png)

![image-20240730232957999](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730232957999.png)

![image-20240730233657277](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730233657277.png)

![image-20240730233706517](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730233706517.png)

![image-20240730233806591](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730233806591.png)

读是先读再写

![image-20240730233820565](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730233820565.png)

![image-20240730234023360](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730234023360.png)

![image-20240730234631650](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730234631650.png)

修改board目录下的Kconfig新增自己的I2C设备

改动1：

![image-20240730235558536](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730235558536.png)

改动2：

![image-20240730235807564](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730235807564.png)改动3：

![image-20240730235840837](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730235840837.png)

效果：

![image-20240730235903943](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240730235903943.png)

![image-20240731000013518](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731000013518.png)

![image-20240731000517475](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731000517475.png)

![image-20240731000624525](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731000624525.png)

![image-20240731000652286](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731000652286.png)

### API接口函数

![image-20240731000757570](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731000757570.png)

![image-20240731000949925](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731000949925.png)

![image-20240731001208885](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731001208885.png)

![image-20240731001227108](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731001227108.png)

![image-20240731002555310](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731002555310.png)

### I2C常见问题

![image-20240731004145328](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731004145328.png)

![image-20240731004739525](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731004739525.png)

![image-20240731005124853](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731005124853.png)

## 三、SPI

常见设备EEPROM、FLASH

![image-20240731010951494](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731010951494.png)

![image-20240731011027911](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731011027911.png)

![image-20240731124122338](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731124122338.png)

- 挂载

![image-20240731011910584](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731011910584.png)

- 第二种方式

![image-20240731012010223](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731012010223.png)

- 相关操作API接口函数

![image-20240731012026179](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731012026179.png)

- 查找SPI设备

![image-20240731124857059](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731124857059.png)

![image-20240731124920564](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731124920564.png)

![image-20240731124932134](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731124932134.png)

## 四、如何从零编写一个自己的驱动

1.在libraries\HAL_Drivers\drivers目录下编写驱动代码

2.Kconfig语法，加入项目构建之中

3.应用测试

I/O设备管理层：rt_device_ops

设备驱动管理层：

设备驱动层：





























