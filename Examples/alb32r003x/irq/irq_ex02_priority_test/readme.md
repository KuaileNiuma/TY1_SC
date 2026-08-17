## irq_ex02_priority_test

### 1 概述
本例程验证中断抢占优先级调度逻辑，使用两路定时器实现高低优先级中断嵌套抢占测试，通过串口打印输出抢占时序，直观验证高优先级中断可打断正在执行的低优先级中断。

### 2 准备
ALB32R0039_EVM开发板，串口参数 115200 8N1。

### 3 运行步骤
打开串口工具查看打印日志；
硬件自动初始化：TIMER1 为低优先级周期中断（抢占优先级 5），TIMER2 为高优先级周期中断（抢占优先级 1）；
TIMER1 中断内执行长循环模拟耗时业务，运行过程中 TIMER2 定时触发，产生中断抢占；
持续观察串口输出日志判断抢占是否生效。

### 4 运行现象
测试通过现象：串口交替打印低优先级任务日志，中途插入高优先级中断打印，完整时序如下：
[LOW_IRQ] Enter low priority long task, waiting possible preempt...
[HIGH_IRQ] Real-time urgent task execute, preempt flag ++
[LOW_IRQ] Detected high priority preempt during my execution!
[LOW_IRQ] Low priority task finished
高优先级打印穿插在低优先级任务执行中间，代表发生中断抢占嵌套。