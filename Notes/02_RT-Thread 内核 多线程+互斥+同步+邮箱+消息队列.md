

# [RT-Thread 内核] 多线程+互斥+同步+邮箱+消息队列基本使用

## 一、前言

![image-20240722171831030](https://gitee.com/qq1600845354/picgo_img/raw/main/笔记/image-20240722171831030.png)

> 可维护性功能上的拓展，线程模块代码可重用性，高优先级任务响应的实时性

![image-20240722221027383](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722221027383.png)

![image-20240722221145463](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722221145463.png)

![image-20240722221259228](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722221259228.png)

![image-20240722221504567](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722221504567.png)

![image-20240722221559525](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722221559525.png)

![image-20240722221715245](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722221715245.png)

![image-20240722221810442](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722221810442.png)

![image-20240722221831682](https://gitee.com/qq1600845354/picgo_img/raw/main/%E7%AC%94%E8%AE%B0/image-20240722221831682.png)

## 二、API使用举例

### 多线程：创建两个线程，一个动态线程，一个静态线程。静态线程在运行完毕后自动被系统脱离，动态线程一直打印计数。

```c
#include <rtthread.h>

#define THREAD_STACK_SIZE       512
#define THREAD_PRIORITY         25
#define THREAD_TIMESLICE        5
static rt_thread_t tid1 = RT_NULL;
static void thread1_entry(void *parameter)
{
    rt_uint32_t count = 0;
    while (1)
    {
        /* 线程1采用低优先级运行，一直打印计数值 */
        rt_kprintf("thread1 count: %d\n", count++);
        rt_thread_mdelay(500);
    }
}

static char thread2_stack[1024];
static struct rt_thread thread2;
static void thread2_entry(void *param)
{
    rt_uint32_t count = 0;
    /* 线程2拥有较高的优先级，以抢占线程1而获得执行 */
    for (count = 0; count < 10 ; count++)
    {
        rt_kprintf("thread2 count: %d\n", count);
    }
    rt_kprintf("thread2 exit\n");
    /* 线程2运行结束后也将自动被系统脱离 */
}

int thread_sample(void)
{	
    /* 动态：占用空间小，运行时分配，效率低 */
    tid1 = rt_thread_create("thread1", thread1_entry, RT_NULL, THREAD_STACK_SIZE, 
                            THREAD_PRIORITY, THREAD_TIMESLICE);
    if (tid1 != RT_NULL)
        rt_thread_startup(tid1);
	
    /* 静态：效率高，但占用读写空间段，且运行时无法改变 */
    rt_thread_init(&thread2, "thread2", thread2_entry, RT_NULL, &thread2_stack[0],
                   sizeof(thread2_stack), THREAD_PRIORITY - 1, THREAD_TIMESLICE);
    rt_thread_startup(&thread2);
    
    return 0;
}
/* 将函数导出到msh命令列表中 */
MSH_CMD_EXPORT(thread_sample, thread sample);
```

### 互斥锁：线程1对2个number分别进行加1操作，线程2也会对2个number分别进行加1操作，使用互斥量保证2个number值保持一致。

```c
/* 指向互斥量的指针 */
static rt_mutex_t dynamic_mutex = RT_NULL;
static rt_uint8_t number1, number2 = 0;

static char thread1_stack[1024];
static struct rt_thread thread1;
static void rt_thread_entry1(void *parameter)
{
    while (1)
    {
        /* 线程1获取到互斥量后，先后对number1、number2进行加1操作，然后释放互斥量 */
        rt_mutex_take(dynamic_mutex, RT_WAITING_FOREVER);
        number1++;
        rt_thread_mdelay(10);
        number2++;
        rt_mutex_release(dynamic_mutex);
    }
}

static char thread2_stack[1024];
static struct rt_thread thread2;
static void rt_thread_entry2(void *parameter)
{
    while (1)
    {
	/* 线程2获取到互斥量后，检查number1、number2的值是否相同，相同则表示mutex起到了锁的作用 */
        rt_mutex_take(dynamic_mutex, RT_WAITING_FOREVER);
        if (number1 != number2) {
            rt_kprintf("not protect.number1 = %d, mumber2 = %d \n", number1, number2);
        } else {
            rt_kprintf("mutex protect ,number1 = mumber2 is %d\n", number1);
        }
        number1++;
        number2++;
        rt_mutex_release(dynamic_mutex);

        if (number1 >= 50)
            return;
    }
}

int mutex_sample(void)
{
    dynamic_mutex = rt_mutex_create("dmutex", RT_IPC_FLAG_PRIO);
    if (dynamic_mutex == RT_NULL) {
        rt_kprintf("create dynamic mutex failed.\n");
        return -1;
    }
    //...
}
MSH_CMD_EXPORT(mutex_sample, mutex sample);
```

### 信号量：两个静态线程，一个每10次释放一次信号量，一个永久等待信号量。

```c
/* 指向信号量的指针 */
static rt_sem_t dynamic_sem = RT_NULL;

static char thread1_stack[1024];
static struct rt_thread thread1;
static void rt_thread1_entry(void *parameter)
{
    static rt_uint8_t count = 0;
    while(1) {
        if(count <= 100) {
            count++;
        } else {
            return;
        }
        /* count 每计数 10 次，就释放一次信号量 */
        if(0 == (count % 10))
        {
            rt_kprintf("t1 release a dynamic semaphore.\n");
            rt_sem_release(dynamic_sem);  // 释放信号量
        }
    }
}

static char thread2_stack[1024];
static struct rt_thread thread2;
static void rt_thread2_entry(void *parameter)
{
    static rt_err_t result;
    static rt_uint8_t number = 0;
    while(1)
    {
        /* 永久方式等待信号量，获取到信号量，则执行 number 自加的操作 */
        result = rt_sem_take(dynamic_sem, RT_WAITING_FOREVER);
        if (result != RT_EOK) {
            rt_kprintf("t2 take a dynamic semaphore, failed.\n");
            rt_sem_delete(dynamic_sem);  // 删除信号量
            return;
        } else {
            number++;  // 信号量获取成功，number 自加
            rt_kprintf("t2 take a dynamic semaphore. number = %d\n", number);
        }
    }
}

int semaphore_sample(void)
{
    /* 创建一个动态信号量，初始值是 0 */
    dynamic_sem = rt_sem_create("dsem", 0, RT_IPC_FLAG_PRIO);
    if (dynamic_sem == RT_NULL) {
        rt_kprintf("create dynamic semaphore failed.\n");
        return -1;
    } else {
        rt_kprintf("create done. dynamic semaphore value = 0.\n");
    }
    //...
}
MSH_CMD_EXPORT(semaphore_sample, semaphore sample);
```

### 邮箱：创建2个静态线程，一个静态的邮箱对象，其中一个线程往邮箱中发送邮件，一个线程往邮箱中收取邮件。

```c
/* 邮箱控制块 */
static struct rt_mailbox mb;
/* 用于放邮件的内存池 */
static char mb_pool[128];
static char mb_str1[] = "I'm a mail!";
static char mb_str2[] = "this is another mail!";
static char mb_str3[] = "over";

static char thread1_stack[1024];
static struct rt_thread thread1;
static void thread1_entry(void *parameter)
{
    char *str;
    while (1)
    {
        rt_kprintf("thread1: try to recv a mail\n");
        /* 从邮箱中收取邮件 */
        if (rt_mb_recv(&mb, (rt_ubase_t *)&str, RT_WAITING_FOREVER) == RT_EOK)
        {
            rt_kprintf("thread1: get a mail from mailbox, the content:%s\n", str);
            if (str == mb_str3)
                break;
            rt_thread_mdelay(100);
        }
    }
    /* 执行邮箱对象脱离 */
    rt_mb_detach(&mb);
}

static char thread2_stack[1024];
static struct rt_thread thread2;
static void thread2_entry(void *parameter)
{
    rt_uint8_t count;
    count = 0;
    while (count < 10)
    {
        count ++;
        if (count & 0x1)  // 判断计数器是否为奇数  
        {
            /* 发送mb_str1地址到邮箱中 */
            rt_mb_send(&mb, (rt_uint32_t)&mb_str1);
        }
        else  // 否则，即计数器为偶数
        {
            /* 发送mb_str2地址到邮箱中 */
            rt_mb_send(&mb, (rt_uint32_t)&mb_str2);
        }
        rt_thread_mdelay(200);
    }
    /* 发送邮件告诉线程1，线程2已经运行结束 */
    rt_mb_send(&mb, (rt_uint32_t)&mb_str3);
}

int mailbox_sample(void)
{
    rt_err_t result;
    result = rt_mb_init(&mb, "mbt", &mb_pool[0], 
                        sizeof(mb_pool) / sizeof(rt_ubase_t), RT_IPC_FLAG_PRIO);
    if (result != RT_EOK) {
        rt_kprintf("init mailbox failed.\n");
        return -1;
    }
    //...
}
MSH_CMD_EXPORT(mailbox_sample, mailbox sample);
```

### 消息队列：创建2个静态线程，一个线程会从消息队列中收取消息，一个线程会定时给消息队列发送普通消息和紧急消息。

```c
static struct rt_messagequeue mq;		/* 消息队列控制块 */
static rt_uint8_t msg_pool[2048];		/* 消息队列中用到的放置消息的内存池 */

static char thread1_stack[1024];
static struct rt_thread thread1;
static void thread1_entry(void *parameter)
{
    char buf = 0;
    rt_uint8_t cnt = 0;
    while (1)
    {
        /* 从消息队列中接收消息 */
        if (rt_mq_recv(&mq, &buf, sizeof(buf), RT_WAITING_FOREVER) > 0)
        {
            rt_kprintf("thread1: recv msg from msg queue, the content: %c\n", buf);
            if (cnt == 19)
            {
                break;
            }
        }
        cnt++;
        rt_thread_mdelay(50);
    }
    rt_kprintf("thread1: detach mq \n");
    rt_mq_detach(&mq);  // 脱离消息队列
}

static char thread2_stack[1024];
static struct rt_thread thread2;
static void thread2_entry(void *parameter)
{
    int result;
    char buf = 'A';
    rt_uint8_t cnt = 0;
    while (1)
    {
        if (cnt == 8) {
            /* 发送紧急消息到消息队列中 */
            result = rt_mq_urgent(&mq, &buf, 1);
            if (result != RT_EOK) {
                rt_kprintf("rt_mq_urgent ERR\n");
            } else {
                rt_kprintf("thread2: send urgent message - %c\n", buf);
            }
        }
        else if (cnt >= 20) {
            rt_kprintf("message queue stop send, thread2 quit\n");
            break;
        } else {
            /* 发送消息到消息队列中 */
            result = rt_mq_send(&mq, &buf, 1);
            if (result != RT_EOK) {
                rt_kprintf("rt_mq_send ERR\n");
            }
            rt_kprintf("thread2: send message - %c\n", buf);
        }
        buf++;
        cnt++;
        rt_thread_mdelay(5);
    }
}

int msgq_sample(void)
{
    rt_err_t result;
    result = rt_mq_init(&mq, "mqt", &msg_pool[0], 1, sizeof(msg_pool), RT_IPC_FLAG_PRIO);   
    if (result != RT_EOK) {
        rt_kprintf("init message queue failed.\n");
        return -1;
    }
    //...
}
MSH_CMD_EXPORT(msgq_sample, msgq sample);
```



































