## xbar_ex07_outputInv

### 1 概述
本例程展示了XBAR输出信号反转功能

### 2 准备
ALB32R0039_EVM开发板
GPIO0连接GPIO1
使用示波器连接GPIO2和GPIO3

### 3 运行步骤
软件执行XBAR输出信号反转测试。
具体流程为：配置GPIO引脚→设置XBAR输入引脚→使能XBAR输出多路复用器→设置XBAR输出多路复用器配置→反转XBAR输出信号→进入无限循环切换GPIO0状态。

### 4 运行现象
程序启动后，GPIO0输出方波信号，XBAR输出信号为GPIO1信号的反转。
