

# [RSOC] RT-Thread Summer Of Code

## 简介

​		本分支主要是为了记录2024 RT-Thread暑期夏立营期间的学习笔记及工程代码。

## 硬件介绍

​		星火一号 STM32F407 是RT-Thread推出的一款基于 ARM Cortex-M4 内核的开发板，最高主频为 168Mhz，开发板外观如下图所示：

![image-20240723204920204](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723204920204.png)

## 目录组成

- Documents
  - RT-Thread 内核基础+线程.pdf
  - RT-Thread IPC.pdf
  - RT-Thread 驱动框架.pdf
  - RT-Thread 软件包与组件.pdf
  - 星火1号用户手册_V1.1.0.pdf
  - RT-Thread BSP移植思路分享.pdf
  - ARM Cortex-M3与Cortex-M4权威指南.pdf
  - PR提交流程图.png
  - CANopen轻松入门（周立功）.pdf
  - 硬石YS-H7Multi开发手册.pdf
- Notes
  - 00_RT-Thread 开发环境搭建.md
  - 01_RT-Thread ENV构建剪裁原理.md
  - 02-04_RT-Thread 内核.md
  - 05_RT-Thread 设备驱动开发.md
  - 06_RT-Thread 软件包与组件.md
  - 07_RT-Thread 设备驱动如何对接.md
  - 08_硬件异常报错分析.md
  - 09_sdo_pdo_map_transfer_debug.xlsx
- Project
  - 00_spark——Day1-Day4环境搭建、内核基础、IPC、设备驱动学习
  - 01_spark——Day5组件与软件包学习
  - 02_spark——项目学习：拟采用lvgl+flexible_button+canopen+freemodbus搭建一个伺服电机模式控制及传感器采集显示系统
  - 03_f103-blue-pill——驱动对接学习
  - 04_ev_hc32f460——驱动对接学习
- Tools
  - lcd_font
    
    - 取字模软件.EXE
    
  - lcd_image
    - Image2Lcd_2.9
      - Img2Lcd.exe
    
  - can_analyzer

    - USB_CAN+TOOLSetup(V9.12).exe
    - USB驱动安装工具Setup(V1.40).exe

  - modbus_poll_slave

    - ModbusSlaveSetupxxBit.exe
    - ModbusPollSetupxxBit.exe

  - canfestival_ports
    
    - canfestival_ports_files
    - Mongo-canfestival-3
    - canfestival_manual_en.pdf
    - python-2.7.10.amd64.msi
    - wxPython2.8*.exe
    
    

