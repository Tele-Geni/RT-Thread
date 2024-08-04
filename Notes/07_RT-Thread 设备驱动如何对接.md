# [RT-Thread 设备驱动如何对接] PIN+UART+II2+SPI

## 设备

### PIN Control系统
结构体
![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-2.png)
结构体实现
![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-1.png)
结构体注册
![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-3.png)

![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-14.png)

### uart系统
![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-4.png)

![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-13.png)

## 总线
>总线管理与上面的具体设备作区分，总线注册完成后，在总线下方还可以注册不同的设备。需要做区分的是，SPI设备需要attach挂载，而I2C则不需要。因为I2C每个设备都有不同的地址，可以在`软件程序`中做区分，而SPI设备靠的是不同的`物理引脚`CS来进行操作控制的。
### i2c总线系统
![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-5.png)

#### STM32
![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-12.png)

#### HC32
![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-11.png)

### spi总线系统
![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-6.png)

#### STM32
![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-9.png)

#### HC32
![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-10.png)

![alt text](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-7.png)
