## usart_ex03_lin

### 1 概述
本例程展示了USART1在Lin模式下，发送Break字符的功能。

### 2 准备
ALB32R0039_EVM开发板

GPIO22 -> 串口RX
GPIO23 -> 串口TX

### 3 运行步骤
具体流程为：开启USART1→配置GPIO引脚→配置USART为lin模式→发送Break字符。

### 4 运行现象
使用示波器 观察到产生持续的低电平。
