## rtos_ex02_free_rtos

### 1 概述
本例程展示了FreeRTOS实时操作系统的基本功能。通过创建多个任务和软件定时器，演示了任务的调度和执行过程，并通过串口输出任务运行状态。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程执行以下操作：
- 初始化系统和板卡
- 调用prvSetupHardware()函数设置硬件
- 创建一个队列
- 创建start_task1和start_task2两个任务
- 创建并启动一个软件定时器，周期为500ms
- 启动FreeRTOS操作系统
- start_task1每100ms执行一次，打印任务运行信息
- start_task2每100ms执行一次，打印任务运行信息
- 软件定时器每500ms执行一次回调函数，打印定时器信息

### 4 运行现象
测试现象：
```
1. 串口输出"Before StartScheduler"
2. start_task1执行，输出"Enter to task_1"
3. start_task2执行，输出"Enter to task_2"
4. 两个任务周期性执行，每100ms输出一次各自的运行信息
5. 软件定时器每500ms输出一次回调信息
6. 在模拟环境下，软件定时器执行3次后会退出
```
