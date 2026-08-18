## xbar_ex01_clbxbar

### 1 概述
本例程展示了CLBXBAR作为CLB的输入源

### 2 准备
ALB32R0039_EVM开发板
GPIO1连接GPIO0

### 3 运行步骤
使能全局中断 -> 配置中断服务函数 -> 配置GPIO1为输出 -> 初始化INPUTXBAR -> 初始化CLBXBAR -> 初始化CLB -> 等待中断标志 -> 清除中断 

### 4 运行现象
GPIO1和GPIO0互联后可进入CLB1中断。
shu