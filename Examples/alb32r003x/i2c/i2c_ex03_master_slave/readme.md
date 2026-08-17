## i2c_ex03_master_slave

### 1 概述
本例程展示i2c在主从模式下，收发数据的功能

### 2 准备
ALB32R0039_EVM开发板
GPIO32 -> GPIO14
GPIO33 -> GPIO15

### 3 运行步骤
1.将I2C配置为主模式，将I2C配置为从模式
2.配置为主模式发送数据，从模式接收数据

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
    i2c_ex03_master_slave start
　　　r 1
　　　r 2
　　　r 3
　　　...
　　　r 254
　　　r 255
　　　r 0
    master i2c0 slave i2c1 write read test OK
    i2c_ex03_master_slave end
```
