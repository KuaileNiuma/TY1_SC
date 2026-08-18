## xbar_ex06_launch

### 1 概述
本例程展示了INPUTXBAR作为XIINT1的触发源

### 2 准备
ALB32R0039_EVM开发板
GPIO2连接GPIO3

### 3 运行步骤
使能外设时钟 -> 初始化GPIO -> 软件触发LATCH -> 获取锁存态 -> 校验输出是否和锁存一致

### 4 运行现象
串口打印XBAR LATCH PASS。
