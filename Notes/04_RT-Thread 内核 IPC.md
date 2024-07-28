# [RT-Thread 内核] IPC 线程同步与通信

> 在Linux中IPC一般是指进程间通讯机制，但是标准版RT-Thread仅支持单核MCU，故没有进程的概念，所以这里的IPC也就是常说的线程间同步、互斥以及通讯机制。

![image-20240725145758243](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240725145758243.png)

## 一、概念介绍

> 问题引出、临界区、阻塞/非阻塞、挂起、死锁

- 问题引出

![image-20240725150249098](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240725150249098.png)

- 什么是临界区？ 有限资源

![image-20240725150549101](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240725150549101.png)

- 什么是阻塞？

![image-20240725150852171](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240725150852171.png)

- 什么是挂起？线程执行任务做到一半时，获取不到所期望的资源，选择暂时不做了，等到别人通知我有资源再去做，挂起后任务栈仍在内存中。

![image-20240725151925000](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240725151925000.png)

- 什么是死锁？简单来说就是线程之间因为资源竞争，但是需要的资源又都无法释放时，导致线程无法进行下一步工作。

![image-20240725152029947](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240725152029947.png)

## 二、线程同步互斥

### 信号量

- 为什么互斥信号量会引起优先级反转？why?

低优先级线程拿到资源时，高优先级没法打断只能等待，但是低优先级任务由于优先级过低一直轮不到执行（被不需要资源的中优先级任务抢占）或者执行的时间很少，一直持有着锁，此时高优先级线程不能得到及时执行，系统不再实时。

在中断中，我们一般不使用互斥锁，就是因为优先级反转问题不好处理，一般会断言卡死。

![image-20240725152722068](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240725152722068.png)

- 三种策略：一直等待、等一会儿不来就做别的事情、不等直接做别的事情

![image-20240725234653330](../../../AppData/Roaming/Typora/typora-user-images/image-20240725234653330.png)

- 为什么不使用全局变量？要搞信号量、互斥锁、事件集来进行同步互斥

同步事件过多时，全局变量的修改很容易导致出现`一些错误和不可预料的结果`。此外操作系统中获取不到资源时线程会进入`挂起态`，这是不会占用cpu资源的，但是像裸机一直`轮询`去判断全局变量的状态是十分消耗CPU的资源的，影响实时性。

- 二值信号量

![image-20240726000001972](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726000001972.png)

![image-20240726000026643](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726000026643.png)

![image-20240726000105865](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726000105865.png)

- 计数信号量

![image-20240726000239788](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726000239788.png)

![image-20240726000335606](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726000335606.png)

- API接口函数

> 一般只使用RT_IPC_FLAG_PRIO，因为FIFO的机制很容易影响系统实时性，高优先级的任务无法第一时间得到CPU资源的使用。

![image-20240726000904021](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726000904021.png)

![image-20240726001704164](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726001704164.png)

![image-20240726001730633](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726001730633.png)

![image-20240726002318447](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726002318447.png)

![image-20240726002721163](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726002721163.png)

![image-20240726003140689](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726003140689.png)

![image-20240726003353622](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726003353622.png)

### 互斥量

> 互斥量是从信号量上面引申出来的东西，`解决信号量无法对临界资源进行保护的问题`。why?

互斥量具有所有权，只能被一个线程所持有，其进行释放后才能被别人获取，但是二值信号量/计数信号量产生时，多个线程都可以获取。支持递归访问，解决了优先级翻转问题，也是互斥量引出的原因。

![image-20240726004241113](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726004241113.png)

![image-20240726005039211](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726005039211.png)

系统不实时了，最紧要的高优先级任务A未能最先拿到CPU资源的执行权，反而因为锁的原因，让B线程已经C线程执行完了，才到A。

![image-20240726005639959](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726005639959.png)

![image-20240726010109862](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726010109862.png)

- API接口函数

少了赋初值的操作，因为互斥量具有所有权，拿到了以后不再允许别人来拿，赋初值也没意义

![image-20240726010510644](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726010510644.png)

![image-20240726010755116](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726010755116.png)

![image-20240726010929192](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726010929192.png)

![image-20240726011012161](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726011012161.png)

![image-20240726011237216](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726011237216.png)

![image-20240726011503717](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726011503717.png)

### 事件集

> 相当于多元信号量，可以传递过来很多事件信号。

![image-20240726012205620](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726012205620.png)

![image-20240726012421151](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726012421151.png)

![image-20240726013050751](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726013050751.png)

- API接口函数

![image-20240726013212426](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726013212426.png)

![image-20240726013253696](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726013253696.png)

![image-20240726013422182](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726013422182.png)

![image-20240726013442604](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726013442604.png)

![image-20240726013512988](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726013512988.png)

![image-20240726013952155](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726013952155.png)

![image-20240726014156695](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726014156695.png)

>不可以，当我在上厕所时，某一个人虽然不想上厕所，但是他有钥匙开门进来打断我上厕所，显然就保证不了互斥了。相当于不需要资源的中优先级任务打断了低优先级任务，主要是因为信号量不具有所有权，所以无法解决优先级反转问题，但是互斥量则必须由持有者进行释放。

![image-20240726020025758](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726020025758.png)

## 三、线程通信

> 并不是说消息邮箱和消息队列不能用作同步，只是同步我们不需要这么复杂的结构，不会这么去做。

### 消息邮箱

![image-20240726020648980](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726020648980.png)

- API接口函数

![image-20240726020939938](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726020939938.png)

![image-20240726020725097](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726020725097.png)

![image-20240726020740733](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726020740733.png)

![image-20240726020749969](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726020749969.png)

![image-20240726020806802](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726020806802.png)

wait不可以在中断中使用，因为中断上下文不允许被阻塞。

![image-20240726020817172](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726020817172.png)

![image-20240726020847095](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726020847095.png)

![image-20240726021333123](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240726021333123.png)

### 消息队列

> 读超时机制、等待发送机制、允许不定长任意类型消息、支持发送紧急消息

![image-20240727161409672](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240727161409672.png)

![image-20240727161714906](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240727161714906.png)

- API接口函数

> 消息队列比较特殊，没有init静态创建方式
>
> 与消息邮箱对比，可以发现消息队列每条消息的大小可以自定义且是复制传值，而消息邮箱仅支持四个字节，传递大块内容时只能传地址。

![image-20240727162043133](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240727162043133.png)

![image-20240727162325363](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240727162325363.png)

![image-20240727162650248](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240727162650248.png)

![image-20240727162743017](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240727162743017.png)![image-20240727162908592](../../../AppData/Roaming/Typora/typora-user-images/image-20240727162908592.png)

![image-20240727163035057](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240727163035057.png)



 



























