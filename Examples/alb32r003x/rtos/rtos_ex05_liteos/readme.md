## rtos_ex05_liteos

### 1 概述
本例程展示了LiteOS实时操作系统的基本功能。通过创建两个不同优先级的任务，演示了任务的调度和执行过程，并通过串口输出任务运行状态。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程执行以下操作：
- 初始化系统和板卡
- 调用RunTaskSample()函数
- RunTaskSample()函数初始化LiteOS内核
- TaskSample()函数创建两个任务：TaskSampleEntry1和TaskSampleEntry2
- 启动LiteOS操作系统
- TaskSampleEntry1每2秒执行一次，打印任务运行信息
- TaskSampleEntry2每10秒执行一次，打印任务运行信息

### 4 运行现象
测试现象：
```
1. 串口输出任务创建信息
2. TaskSampleEntry1每2秒输出一次"TaskSampleEntry1 running..."
3. TaskSampleEntry2每10秒输出一次"TaskSampleEntry2 running..."
4. 由于TaskSampleEntry1的优先级高于TaskSampleEntry2，所以TaskSampleEntry1会先执行
```
