## spi2_loopback_int

### 1 概述
本例程展示了使用SPI内部回环中断收发通信功能

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
软件执行SPI1内部以中断的方式发送并接收数据，数据从0，1开始累加，一次发送两个数据。
具体流程为：开启SPI1→中断发送数据→中断接收数据→判断接收数据是否与发送数据相等。

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
    SPI transmit and receive successfully!
    rData[0]: 0
    SPI transmit and receive successfully!
    rData[1]: 1
    SPI transmit and receive successfully!
    rData[0]: 1
    SPI transmit and receive successfully!
    rData[1]: 2
    SPI transmit and receive successfully!
    rData[0]: 2
    SPI transmit and receive successfully!
    rData[1]: 3
    SPI transmit and receive successfully!
    rData[0]: 3
    SPI transmit and receive successfully!
    rData[1]: 4

```
