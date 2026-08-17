## i2c_ex05_dma_in

### 1 概述
本例程展示了I2C1作为主设备，使用DMA发送向eeprom写入数据，并从eeprom读取数据

### 2 准备
ALB32R0039_EVM开发板
接线如下：
GPIO32 -> SDA
GPIO33 -> SCL

### 3 运行步骤
1.配置I2C1作为主设备
2.配置为DMA模式发送

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
    i2c_ex05_dma_in start
    I2C1_BASE eeprom write read  test OK
    i2c_ex05_dma_in end
```
