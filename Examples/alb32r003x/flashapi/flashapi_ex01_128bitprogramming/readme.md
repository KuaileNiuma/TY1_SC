## flashapi_ex01_128bitprogramming

### 1 概述
本例程展示如何使用flashapi的函数，涉及初始化，擦除，读写等

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
1) Flash API 初始化，
2) 设置活动Flash Bank，
3) 等待Flash控制器就绪，
4) 擦除扇区，
5) 编程Flash（使用AutoECC）

### 4 运行现象
观察各函数的返回值情况，返回0--成功，其他值--失败