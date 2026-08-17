## gpio_ex01_input

### 1 概述
本例程展示了对gpio输入功能。

### 2 准备
ALB32R0039_EVM开发板
跳线帽连接 GPIO50 - KEY1,GPIO54 - KEY2

### 3 运行步骤
1.GPIOx设置为输入模式，将GPIOx接高/接低，读取相应电平

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
    GPIO EX01 INPUT.
    KEY1 DOWN,GPIO50 SET LOW.      ----当KEY1按键按下时
    KEY1 UP,GPIO50 SET HIGH.      ----当KEY1按键没有按下时
    KEY2 DOWN,GPIO54 SET LOW.      ----当KEY2按键按下时
    KEY2 UP,GPIO50 SET HIGH.      ----当KEY2按键没有按下时

```
