## rtos_ex01_ucosll

### 1 概述
本例程展示了UCOSII实时操作系统的基本功能。通过创建多个任务，演示了任务的调度和执行过程，并通过串口输出任务运行状态。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程执行以下操作：
- 初始化系统和板卡
- 打印"Start ucosii..."信息
- 调用prvSetupHardware()函数设置硬件
- 初始化UCOSII操作系统
- 创建start_task任务
- 启动UCOSII操作系统
- start_task任务创建task1、task2、task3三个任务，然后挂起自己
- task1每500ms执行一次，打印任务运行信息
- task2每250ms执行一次，打印任务运行信息
- task3每250ms执行一次，打印任务运行信息

### 4 运行现象
测试现象：
```
1. 串口输出"Start ucosii..."和"create start task success"
2. start_task执行，输出"start all task..."
3. 三个任务周期性执行，输出各自的运行信息
4. task1每500ms输出一次，task2和task3每250ms输出一次
5. 在模拟环境下，task3执行3次后会退出
```
