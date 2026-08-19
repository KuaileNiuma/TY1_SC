## spi1_2_external_int

### 1 概述
本例程展示了使用SPI2与SPI3使用中断收发进行通信功能

### 2 准备
ALB32R0039_EVM开发板
准备一块支持SPI协议的FLASH并按以下进行接线（电源线省略）
GPIO0 ->	GPIO15 
GPIO3 ->	GPIO14 
GPIO1 ->	GPIO6 
GPIO2 ->	GPIO7

### 3 运行步骤
软件执行配置SPI3为从机，配置SPI2为主机，进行数据传输。
具体流程为：配置SPI3和SPI2→SPI2中断发送数据→SPI3中断接收数据→验证读取数据与发送数据是否一致

### 4 运行现象
串口会将测试结果直接打印出来，失败和成功的串口输出参考如下
```
    SPI2  communicate with SPI3 by interrupt failed!
```  


```
    SPI2  communicate with SPI3 by interrupt failed successfully!
```
