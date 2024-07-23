# [RT-Thread 内核] 硬实时系统+启动流程+任务管理

## 一、实时系统简单介绍

![image-20240723091652763](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723091652763.png)

<img src="https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240723091813333.png" style="zoom: 80%;" />

![image-20240724021857310](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240724021857310.png)

>   Linux资源消耗大，如rootfs，且无法保证实时性，若要保持实时性就会影响到整个系统运行的流畅。

![image-20240723092123656](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723092123656.png)

![image-20240723092427586](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723092427586.png)

![image-20240723092526582](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723092526582.png)

![image-20240723092706349](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723092706349.png)

## 二、RT-Thread启动流程及任务管理

### 线程介绍

![image-20240723093607488](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723093607488.png)

![image-20240723093709303](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723093709303.png)

>   启动流程分析，为什么启动这么快!  MDK是采用`$Sub$$和“$Super$$`机制，该机制常用于修改程序的执行逻辑顺序，但又不想对已经封装好的代码进行太大的改动时使用，再汇编文件启动后，先启动RT-Thead内核再跳转至main函数运行。

![image-20240723093955026](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723093955026.png)

- 关闭中断
- 硬件初始化 ( HAL(NVIC/SYSTICK/MSP)、时钟、RT堆、PIN、串口、板级组件初始化）
- 内核版本打印
- 软件定时器初始化
- 调度器优先级列表初始化
- app线程初始化（malloc rt_thread/stack、状态初始化、挂载到调度器列表进行管理、入口函数、初始化线程栈，这里涉及到ARM寄存器和线程第一次启动当作现场回复的知识、线程超时定时器、启动调度进入就绪态）
- 启动系统定时器（可选） 
- IDLE线程初始化 -> 最低优先级，提供钩子函数擦屁股，可用于功耗管理或者看门狗防宕机
- 系统调度器启动开始运行工作（找到最高优先级线程、触发PendSV异常、打开中断）
  - 开始调度->app线程：main_thread_entry：组件初始化，进入main函数
  - timer、idle、其他线程

![image-20240723094721945](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723094721945.png)

![image-20240723094943204](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723094943204.png)

![image-20240723095331745](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723095331745.png)

>   寄存器以Cortex-M4架构为例（星火一号）

![image-20240723095513802](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723095513802.png)

>   资源不可用时，或主动延时 时任务进入挂起态，不再占用cpu资源。

![image-20240723101703690](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723101703690.png)

![image-20240723102039046](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723102039046.png)

>   与FreeRTOS优先级相反，数值越小优先级越高。
>
>   线程调度算法采用`基于优先级的全抢占式多线程调度算法`，即在系统中除了`中断处理函数`、`调度器上锁`部分的代码和`禁止中断`的代码是不可抢占的之外，系统的其他部分都是可以抢占的，包括线程调度器自身。

![image-20240723102456632](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723102456632.png)

![image-20240723102949024](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723102949024.png)

![image-20240723103540948](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723103540948.png)

>   为什么分配了时间片大小，还要rt_delay让出CPU资源，提高鲁棒性？
>
>   时间片只是对优先级相同的就绪线程有用，确保AB每次执行的时间；
>
>   对于同优先级，但是A rt_delay进入挂起态时，B处于就绪态时，这时候A相等于每隔delay时间执行一次，故A总共花费时间为 A时间片大小+delay时长，在A delay期间，B一直处于就绪可以执行若干轮时间片大小，所以B比A多执行的时间约为（A时间片大小-B时间片大小）+  Adelay时间。
>
>   对于不同优先级时，则是高优先级执行完毕后主动rt_delay控制执行间隔时间，来释放出CPU资源；

### 系统线程

>当系统中没有其他更高优先级的线程时，空闲线程就会被调度执行，因为优先级是最低的，也就是其他任务活都干完了他去`擦屁股`。

![image-20240723104127027](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723104127027.png)

![image-20240723104451995](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723104451995.png)

![image-20240723104739665](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723104739665.png)

>   线程动态创建在栈分配，静态创建编译完就在数据段中

![image-20240723105610846](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240723105610846.png)

![image-20240723105602096](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240723105602096.png)

## 三、解答分享
- MSH实现，本质就是把函数的地址放到了RT-Thread特定的管理段，在终端可以打印段中内容

![image-20240724012418469](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240724012418469.png)

- 嵌入式系统常见问题

![image-20240724015329119](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240724015329119.png) 
![ ](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240724015632865.png)
![image-20240724015834339](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240724015834339.png)
![image-20240724020107551](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240724020107551.png)
![image-20240724020127108](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240724020127108.png)
![image-20240724020205417](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240724020205417.png)

- 调式方法：排除法、注释部分代码、更换硬件、排查编译配置

## 四、参考资料  
[官方文档内核基础](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/basic/basic?id=内核基础)