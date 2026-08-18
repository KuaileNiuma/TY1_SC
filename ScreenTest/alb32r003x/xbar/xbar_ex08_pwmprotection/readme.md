## xbar_ex08_pwmprotection

### 1 概述
本例程展示了
GPIO16 --> INPUTXBAR1 --> EPWM保护
GPIO17 --> INPUTXBAR2 --> EPWM保护
GPIO22 --> INPUTXBAR3 --> EPWM保护

GPIO23 --> INPUTXBAR4 --> EPWMXBAR_TRIP4 --> EPWM保护
GPIO33 --> INPUTXBAR5 --> EPWMXBAR_TRIP4 --> EPWM保护

### 2 准备
ALB32R0039_EVM开发板
测试引脚连接GPIO1

### 3 运行步骤
使能外设时钟 -> XBAR初始化 -> EPWM初始化 -> 清除TZFLAG -> 拉低GPIO1 -> 校验TZFLAG是否置位-> 拉高GPIO1 -> 清除TZFLAG 

### 4 运行现象
串口打印INPUTXBAR PWM Protection Done。
