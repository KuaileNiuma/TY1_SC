## wwdt_ex04_interrupt_feed

### 1 概述
本例程展示了窗口看门狗定时器中断喂狗功能

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
软件执行窗口看门狗定时器中断喂狗测试。
具体流程为：初始化窗口看门狗定时器→配置窗口看门狗参数→注册中断处理函数→使能窗口看门狗中断→进入无限循环。

### 4 运行现象
程序启动窗口看门狗定时器后，Early Wakeup 中断中喂狗，系统不会复位。当中断喂狗次数达到 WWDT_FEED_TARGET 次后，打印 `WWDT interrupt feed test OK` 并返回 SC_PASS。
若超时未达到目标次数，打印 `WWDT interrupt feed test FAIL` 并返回 SC_FAIL。
