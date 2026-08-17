## i2c_ex04_eeprom_polling

### 1 概述
本例程展示了I2C1作为主设备与eeprom（从设备）通信，实现数据的收发 。

### 2 准备
ALB32R0039_EVM开发板
接线如下：
GPIO32 -> SDA
GPIO33 -> SCL

### 3 运行步骤
1.配置I2C1作为主设备

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
    i2c_ex04_eeprom_polling start
    I2C1_BASE eeprom write read  test OK
    i2c_ex04_eeprom_polling end
```
