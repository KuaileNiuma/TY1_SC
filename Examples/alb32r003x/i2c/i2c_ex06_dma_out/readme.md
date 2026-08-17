## i2c_ex06_dma_out

### 1 概述
本例程展示了I2C1作为主设备，先按页向eeprom写入数据，使用DMA接收从eeprom（从设备）读取数据，实现数据的收发

### 2 准备
ALB32R0039_EVM开发板
接线如下：
GPIO32 -> SDA
GPIO33 -> SCL

### 3 运行步骤
1.配置为内部回环模式
2.配置为轮询方式自发自收

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
    i2c_ex06_dma_out start
    I2C1_BASE eeprom write read  test OK
    i2c_ex06_dma_out end
```
