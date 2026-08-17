## gpio_ex03_interrupt

### 1 概述
本例程展示了EVM开发板中LED和KEY功能。

### 2 准备
1.ALB32R0039_EVM开发板
2.跳线帽连接 GPIO50 - KEY1,GPIO54 - KEY2
3.跳线帽连接 GPIO44 - LED1,GPIO49 - LED2

### 3 运行步骤
1.初始化LED KEY
2.循环交替闪烁LED1和LED2，闪烁等待时间由KEY1 KEY输入决定

### 4 运行现象
LED1、LED2交替闪缩
当按键KEY1或KEY2任意一个按下时，LED1、LED2交替闪烁频率变快
