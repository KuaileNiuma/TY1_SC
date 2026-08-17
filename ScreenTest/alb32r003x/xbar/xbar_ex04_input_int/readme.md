## xbar_ex04_input_int

### 1 概述
本例程展示了INPUTXBAR作为XIINT1的触发源

### 2 准备
ALB32R0039_EVM开发板
GPIO1连接GPIO0

### 3 运行步骤
使能全局中断 -> 配置中断服务函数 -> 配置GPIO1为输出 -> 初始化inputxbar -> 输出5个测试脉冲（每300ms翻转一次）-> 等待中断标志 -> 清除中断 

### 4 运行现象
GPIO1和GPIO0互联后可进入XINT1中断。
