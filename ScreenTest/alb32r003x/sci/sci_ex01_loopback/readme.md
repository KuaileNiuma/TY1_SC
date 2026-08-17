## sci_ex01_loopback

### 1 概述
本例程展示了使用UART内部回环轮询收发数据功能

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
软件执行SPI1内部以轮询的方式发送并接收0~15，共计16个数据。
具体流程为：开启UART1→轮询发送数据→轮询接收数据→判断接收数据是否与发送数据相等。

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
    SCI_ex01_loopback start
    SCI_ex01_loopback test ok
    SCI_ex01_loopback end
```
