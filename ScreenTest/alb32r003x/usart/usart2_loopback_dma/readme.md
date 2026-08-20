## usart2_loopback_dma

### 1 概述
本例程展示了使用USART2以DMA方式收发数据并启用了FIFO模式的功能。

### 2 准备
ALB32R0039_EVM开发板

GPIO22 -> 串口RX
GPIO23 -> 串口TX

### 3 运行步骤
软件执行USART2以DMA的方式收发数据，并启用FIFO功能。
具体流程为：初始化发送数据→开启USART2→配置GPIO引脚→启用FIFO→设置FIFO中断级别→配置DMA发送通道→配置DMA接收通道→进入无限循环等待DMA传输完成。

### 4 运行现象
程序通过DMA自动将128字节的发送数据发送到串口，同时通过DMA自动接收串口数据到接收缓冲区。
