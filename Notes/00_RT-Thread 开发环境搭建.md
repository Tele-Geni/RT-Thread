# [RT-Thread开发环境搭建] ENV+VSCode+OPENDOCD

## 一、RT-Thread环境

### 项目构建方式

RT-Thread常见的开发方式主要有通过RT-Thread Studio和ENV两种方式，本文选用ENV构建方式以通过VSCode打开源码项目进行开发。

-   官方下载ENV：https://www.rt-thread.org/download.html

点击网站下载最新版`env-windows-v2.0.0`并解压

<img src="https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722130411438.png" alt="image-20240722130411438"  />

确保网络正常，双击打开文件夹中的 env.exe or env.bat，首次打开会有如下界面：

![image-20240722130911171](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722130911171.png)

为方便使用，将env可执行文件注册到环境变量

![image-20240722131052372](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722131052372.png)

![image-20240722131103776](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722131103776.png)

至此我们就可以在系统的任意目录下使用右键打开env了

![image-20240722131122679](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722131122679.png)

### 项目源码下载并切换到稳定分支

```shell
git clone https://github.com/RT-Thread/rt-thread.git
cd rt-thread
git branch -a
git checkout XXX
```

### ENV构建项目

进入源码目录下bsp文件夹，选择对应所支持的板级文件，作者手中开发板为官方配套星火一号，故进入bsp\stm32\stm32f407-rt-spark目录，右键空白在此处打开ENV（ConEmu Here）。若在bsp文件夹中没有对应支持板级文件，需要自行编写bsp，可以选择bsp目录下与手中开发板相接近的型号进行修改移植，具体内容作者还未涉及。

在命令行窗口输入 scons --target=vsc 生成VSCode工程

![image-20240722132123715](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722132123715.png)

>   备注：使用scons --dist可以在dist目录下构建出独立的工程，可拷贝至任意地方进行编写运行。vscode若出现`代码无法提示`现象，是c_cpp_properties.json出现了问题，通过scons --target=vsc重新生成，即可解决。

## 二、VSCode环境搭建

由于不使用RT-Thread Studio环境和scons --target=mdk5进行开发，需要给VSCode搭建仿真调试下载功能：

1.  VSCode下载插件`Cortex-Debug`

    <img src="https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722132448299.png" alt="image-20240722132448299" style="zoom: 67%;" />

2.  下载openocd-20231002.7z开发工具，解压放到非中文、无空格目录下。

    ![image-20240722132732415](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722132732415.png)

3.  打开VSCode，Ctrl+Shift+p输入settings.json，在{}中最后添加如下内容：

    ```json
    "cortex-debug.openocdPath": "D:/此处为自己的文件目录/OpenOCD-20231002-0.12.0/bin/openocd.exe"
    ```

至此基本配置已经完成，通过VSCode打开之前scons构建项目文件夹，并点击运行和调试按钮为项目添加launch.json文件，内容如下：

![image-20240722133321102](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722133321102.png)

`executable`、`targetId`、`armToolchainPath`、`gdbPath`字段视情况修改。

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "rt-spark-openocd",
            "executable": "${workspaceRoot}/rt-thread.elf",
            "request": "launch",
            "type": "cortex-debug",
            "runToEntryPoint": "main",
            "targetId": "STM32F407ZG",
            "servertype": "openocd",
            "configFiles": [
                "interface/stlink-v2.cfg",
                "target/stm32f4x.cfg"
            ],
            "armToolchainPath": "D:/workspace_work/env-windows/tools/gnu_gcc/arm_gcc/mingw/bin", // ！！！需要修改为自己的GCC 工具链路径 ！！！
            "gdbPath": "D:/workspace_work/env-windows/tools/gnu_gcc/arm_gcc/mingw/bin/arm-none-eabi-gdb.exe" // ！！！需要修改为自己的GDB 路径 ！！！
        }
    ]
}
```

## 三、烧录调试

在vscode终端中输入 scons -j12 编译工程生成固件

![image-20240722134132338](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722134132338.png)

![image-20240722134146548](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722134146548.png)

连接硬件烧录工具，在VSCode下按下F5开始调试，此时顶侧出现如下按钮：

![image-20240722134001342](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722134001342.png)

按下第一个按钮程序全速运行，按下最后一个按钮断开调试。

> 备注：vscode Ctrl+P 输入"> 打开反汇编视图"，可以进入反汇编调试界面

## 四、参考资源与安装包

RT-Thread官方文档与2024 RT-Thread夏立营文档

`OpenOCD-20231002-0.12.0`

链接：https://pan.baidu.com/s/1cQPzX30rjVH8cRByU4MFPg 提取码：ikzh

`fastgithub_win-x64`

链接：https://pan.baidu.com/s/1VtdgNHqtTllJeQKiUGW01Q 提取码：v3xz







