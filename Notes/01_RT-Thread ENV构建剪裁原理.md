# [RT-Thread ENV构建剪裁原理] Kconfig+.config+Scons

## 一、介绍

> 秉承着Linux可裁剪的传统，RT-Thread除了像FreeRTOS基本的内核功能外，还可以通过配置.config文件来加载编译不同源码和网络上的第三方组件包。
>
> 与Linux最大的不同在于，其构建工具做了改变，RT-Thread官方不再采取Makefile，而是采用Scons（python脚本）的方式，通过Scons脚本来读取加载.config配置文件生成的对应宏文件rtconfig.h，来进行项目源码编译构建；Linux则是直接通过Makefile来加载读取.config文件，编译构建项目源码生成镜像。
>
> 从 RT-Thread 0.3.0 开始，RT-Thread 开发团队逐渐引入了 SCons 构建系统，引入 SCons 唯一的目的是：使大家从复杂的 Makefile 配置、IDE 配置中脱离出来，把精力集中在 RT-Thread 功能开发上。

![image-20240722161301121](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722161301121.png)

后续有时间再出一篇Kconfig语言笔记，本文重点在RT-Thread的ENV使用和Scons命令上。

## 二、ENV使用

> 一个项目一般由一个SConstruct和多个SConscript文件来组织进行构建。

- RT-Thread ENV所支持的Scons命令：

```python
# 1.修改ENV编译器，默认为ARM GCC支持ARM平台芯片
    set RTT_CC=gcc
    set RTT_EXEC_PATH=D:/software/RaspberryPi-Pico/gcc/2020-q4-major/bin

    set RTT_CC=keil
    set RTT_EXEC_PATH=C:/Keilv5
# 2.设置工程开发平台
    scons --target=XXX -s
-------------------------------------------------------------------------------
# 如果使用 MDK/IAR 来进行项目开发，在生成 MDK 或者 IAR 工程前，需要检查 rtconfig.py 文件中 EXEC_PATH 变量所保存的对应 IDE 的安装路径是否正确。
# 当修改了 rtconfig.h 打开或者关闭某些组件时，需要使用以下命令中的其中一种重新生成对应的定制化的工程，然后在 MDK/IAR 进行编译下载。
    scons --target=iar
    scons --target=mdk4
    scons --target=mdk5
-------------------------------------------------------------------------------
# 对于习惯 CMake 或者 Makefile 的用户，可以通过以下两个命令来分别生成 CMake 和 Makefile 脚本。
	scons --target=cmake
	Scons --target=makefile
-------------------------------------------------------------------------------
# 在 bsp/simulator 下，可以使用下面的命令生成 vs2012、vs2005 或者 vscode 的工程。
    scons --target=vs2012
    scons --target=vs2005
    scons --target=vsc
-------------------------------------------------------------------------------
# 3.其他重要命令
    scons --dist	# 在bsp目录下的dist文件夹中生成独立的project
    scons -jN		# 开始编译
    scons -c		# 清除编译目标
    pkgs --upgrade	# 升级软件包列表
    pkgs --update	# 更新软件包
    menuconfig -s	# 命令进入 Env 配置界面
```

- 如何在项目编译构建中添加自己的驱动，如在工程下创建了hello文件夹，其中包含了hello.c、hello.h

```python
# 我们需要在hello文件夹中编写SConscript脚本，来将源码加入工程构建
from building import *
import os

cwd     = GetCurrentDir()
CPPPATH = [cwd]
src = ['hello.c']

group = DefineGroup('Hello_Test', src, depend = [''], CPPPATH = CPPPATH)

Return('group')
```

- 如何将自己编写的驱动以模块的方式进行加载 -> 在工程根目录Kconfig文件中最后添加如下内容：

Kconfig -> Menuconfig -> .config -> rtconfig.h -> 工程构建

```shell
menu "hello module"										# 菜单 hello module

    config RT_USING_HELLO   							# RT_USING_HELLO配置选项
        bool "Enable hello module"						# RT_USING_HELLO类型为bool，选中值为y，不选中值为n
        default y										# 默认选中
        help											# 菜单选中help后显示的提示信息，解释配置选项的含义
        this hello module only used for test

    config RT_HELLO_NAME								# RT_HELLO_NAME配置选项
        string "hello name"								# RT_HELLO_NAME类型为字符串
        default "hello"									# 默认值为"hello"

    config RT_HELLO_VALUE								# RT_HELLO_VALUE配置选项
        int "hello value"								# RT_HELLO_VALUE类型为 int
        default 8										# 默认值为8
endmenu

```

![image-20240722203757431](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722203757431.png)

```python
# SConscript脚本作如下内容修改
    src = []
    if GetDepend(['RT_USING_HELLO']):
        src += ['hello.c']
```

## 三、Kconfig、Scons语法

## 四、参考内容

[RT-Thread 文档中心](https://www.rt-thread.org/document/site/#/?id=rt-thread-文档中心)



