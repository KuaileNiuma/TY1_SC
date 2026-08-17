## flash_ex01_operation

### 1 概述
本例程展示了对flash的读、擦、写功能。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
1.解锁Flash寄存器锁定位，并将读保护降级为0 
2.对主扇区的扇区8-11执行擦除操作
3.从主扇区起始位置0xff70000开始，对每块扇区执行编程操作 
4.在CDC模式下对OTP区域执行擦除操作 
5. 同样对OTP区域每块地址执行编程操作 

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
    FLASH EX01 Operation.
    FLASH EX01 Operation success.
```  
