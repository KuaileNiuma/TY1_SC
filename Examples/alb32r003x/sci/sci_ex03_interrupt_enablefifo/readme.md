## sci\_ex03\_interrupt_enablefifo

### 1 概述

本例程展示了使用UART中断接收数据功能，并启用了FIFO模式

### 2 准备

ALB32R0039\_EVM开发板

GPIO10 -> 串口的TX
GPIO11 -> 串口的RX

### 3 运行步骤

软件执行UART2以中断的方式接收数据，并启用FIFO功能。
具体流程为：开启UART2→配置GPIO引脚→配置UART中断→启用FIFO→设置FIFO中断级别→注册中断处理函数→等待接收数据。

### 4 运行现象

使用串口给UART2发送数据，程序可以接收数据并进入中断，且发送和接收的数据一致。

