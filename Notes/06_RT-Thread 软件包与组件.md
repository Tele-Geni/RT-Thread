# [RT-Thread] 软件包与组件

## 一、软件包（Software Package）

![image-20240731184847327](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731184847327.png)

### AHT10软件包简单使用

![image-20240731184921109](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731184921109.png)开启AHT21

![image-20240731185814894](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731185814894.png)

后，自动勾选在线软件包

![image-20240731185918364](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731185918364.png)

### MQTT协议软件包使用

三种消息等级，容易拓展

![image-20240731192055058](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731192055058.png)

![image-20240731192218410](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731192218410.png)

> MQTT对比TCP来说，最大的优点就是说TCP/IP加入一个设备需要获取对方的IP地址信息才能做一个消息转发，消息一旦多起来，存储空间数量会比较庞大；而MQTT的话只需要把数据交给服务器，让服务器去做转发就好了，不需要考虑那么多。

![image-20240731192344652](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731192344652.png)

https://www.aliyun.com/product/iot/iot_instc_public_cn

![image-20240731192810219](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731192810219.png)

点击管理控制台进行服务开通以及公共实例，随后创建产品以及设备进行测试。

接着meuconfig 配置RW007软件包并修改引脚，用于连接云平台。

![image-20240731194812211](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731194812211.png)

开启阿里云，并适配云平台的产品密钥、设备名字、设备密码以及开启sample样例。

![image-20240731194940544](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731194940544.png)

![image-20240731195213352](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731195213352.png)

![image-20240731205450841](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731205450841.png)

模拟查看消息格式

![image-20240731211049361](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731211049361.png)

![image-20240731231604001](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731231604001.png)

## 二、组件 （Component）

定义：指的是一个可以独立开发、测试、部署和维护的软件单元

![image-20240731232229269](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731232229269.png)

![image-20240731232322456](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731232322456.png)

![image-20240731232752414](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731232752414.png)

![image-20240731232809800](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731232809800.png)

![image-20240731235449633](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240731235449633.png)

![image-20240801000035270](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801000035270.png)

![image-20240801000248633](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801000248633.png)

![image-20240801000330065](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801000330065.png)

![image-20240801000428208](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801000428208.png)

![image-20240801000721581](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801000721581.png)

![image-20240801003317736](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801003317736.png)

![image-20240801003329612](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801003329612.png)

![image-20240801003354037](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801003354037.png)

![image-20240801003413450](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801003413450.png)

![image-20240801012801497](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801012801497.png)

![image-20240801012746531](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240801012746531.png)

 

 

 















