## spi_ex03_external_loopback

### 1 概述
本例程展示了使用从机SPI1和主机SPI2进行通信功能,

### 2 准备
ALB32R0039_EVM开发板，并连接J13跳线帽（引脚BP -----引脚Q2）

GPIO0 ->	GPIO15 
GPIO3 ->	GPIO14 
GPIO1 ->	GPIO6 
GPIO2 ->	GPIO7 

### 3 运行步骤
软件执行配置SPI1为从机，配置SPI2为主机，进行数据传输。
具体流程为：配置SPI1和SPI2→准备好传输的数据→数据互传→验证读取数据与发送数据是否一致

### 4 运行现象
串口会将测试结果直接打印出来，失败和成功的结果参考如下
```
    SPI1  communicate with SPI2 failed!
```  


```
    SPI1 communicate with SPI2 successfully!
```
