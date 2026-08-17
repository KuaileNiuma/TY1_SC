## i2c_ex02_loopback_interrupt

### 1 概述
本例程展示了I2C内部回环模式下，通过中断方式完成I2C数据的自发自收。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
1.配置为内部回环模式
2.配置为中断方式自发自收

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
    i2c_ex02_loopback_irq start
    i2c1 loopback test ok
    i2c_ex02_loopback_irq end
```
