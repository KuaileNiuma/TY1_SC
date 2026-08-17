## spi_ex05_polling_flash

### 1 概述
本例程展示了使用SPI对FLASH进行通信功能

### 2 准备
ALB32R0039_EVM开发板
准备一块支持SPI协议的FLASH并按以下进行接线（电源线省略）
GPIO0 ->	CS
GPIO3 ->	CLK
GPIO1 ->	SOMI
GPIO2 ->	SIMO

### 3 运行步骤
软件执行SPI1和FLASH通信，对FLASH进行读取ID号，擦除，写入，读取操作。
具体流程为：开启SPI1→获取FLASH的ID号→对FLASH进行擦除操作→对FLASH进行写入操作→对FLASH进行读取操作→验证读取数据与写入数据是否一致

### 4 运行现象
串口会将测试结果直接打印出来，失败和成功的串口输出参考如下
```
    FLASH communicate with SPI failed!
```  


```
    FLASH communicate with SPI successfully!
```
