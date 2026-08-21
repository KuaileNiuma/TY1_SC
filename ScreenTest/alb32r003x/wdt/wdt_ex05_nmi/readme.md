## wdt_ex05_nmi

### 1 概述
本例程展示了看门狗定时器NMI（不可屏蔽中断）喂狗功能

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
软件执行看门狗定时器NMI喂狗测试。
具体流程为：初始化CLB模块→配置NMI→启动看门狗→进入无限循环→NMI中断中喂狗。

### 4 运行现象
CLB 逻辑触发 NMI，NMI 处理器禁用 CLB NMI 源（防止反复触发打断打印）并喂狗、置位标志。main 检测到标志后关闭系统 NMI，打印 `WDT NMI test OK` 并返回 SC_PASS。
若超时未触发 NMI，打印 `WDT NMI test FAIL` 并返回 SC_FAIL。
