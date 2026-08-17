## flash_ex02_opt_operation

### 1 概述
本例程展示了对flash的用户选项字节的配置。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

1.解锁Flash寄存器锁定位，并将读保护降级为0 
2.检测扇区的写保护是否开启，若开启，则配置为关闭状态；若写保护关闭，则配置为开启状态 
3.配置用户选项区域功能，例如 RDP, BOR, CPU reset等，并检测是否配置成功 
4. 软件复位Flash，并检测用户选项字节区域配置是否回到复位后的状态 

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
FLASH EX02 option operation.
<<-FLASH-INFO->> WRP protect success.......
<<-FLASH-INFO->> 

<<-FLASH-INFO->> REG:OPTCR=0FFFAA03
<<-FLASH-INFO->> 

<<-FLASH-INFO->> -------------RDP LEVEL-------------
<<-FLASH-INFO->> FLASH RDP is LEVEL0
<<-FLASH-INFO->> 

<<-FLASH-INFO->> -------------WRP sector-------------
<<-FLASH-INFO->> WRP=0xfff
<<-FLASH-INFO->> 

<<-FLASH-INFO->> hard wdg

<<-FLASH-INFO->> cpu reset when suspend mode

<<-FLASH-INFO->> 

<<-FLASH-INFO->> cpu reset when standby mode

<<-FLASH-INFO->> BOR Voltage is from 2.70 to  3.60 V

<<-FLASH-INFO->> 

<<-FLASH-INFO->> Set RDP LEVEL1.....

<<-FLASH-INFO->> 

<<-FLASH-INFO->> Set RDP LEVEL0.....
```
