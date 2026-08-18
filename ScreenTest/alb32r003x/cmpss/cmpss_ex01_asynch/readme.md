## cmpss_ex01_asynch

### 1 概述
本例程展示了CMPSS 输出信号到 OutputXBAR， 或者输出信号到EPWMXbar 用于 EPWM Trip 封波功能

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程使能比较器 CMPSS1_COMPH ， 比较器 CMPSS1_COMPH 中外部电压 CMPIN1P 用于提供正输入，内部 DAC 用于提供负输入， 并且内部 DAC 配置为 VDD/2
配置 EPWM7 生成 EPWM 波形， 输出在 GPIO13 引脚
当接入外部电压， 向 CMPIN1P 提供高输入（高于 VDD/2） 时， 比较器 CMPSS1_COMPH 将异步 CTRIPH 信号发送到 EPWM X-BAR 作为TRIP4 输入到 EPWM 的 DC 模块， 从而从生成跳闸信号作用于 EPWMB

当向 CMPIN1P 提供低输入（VSS） 时， EPWM7B(GPIO13)给出 PWM 信号

当接入外部电压， 向 CMPIN1P 提供高输入（高于 VDD/2） 时，EPWM7B(GPIO13) 跳闸并输出高电平,EPWM1A(GPIO0)为默认高阻态

### 4 运行现象
可以通过示波器或逻辑分析仪抓取波形观察
测试现象：
```
1. gpio13输出3.05kHz方波
2. A2/B6 引脚输入高电平，gpio13输出高电平
3. A2/B6 引脚输入低电平，gpio13输出方波
```
