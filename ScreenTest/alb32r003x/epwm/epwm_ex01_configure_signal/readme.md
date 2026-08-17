## epwm_ex01_configure_signal

### 1 概述
本例程展示了使用epwm的功能。 

### 2 准备
ALB32R0039_EVM开发板
EPWM1A -> GPIO0
EPWM1B -> GPIO1
EPWM2A -> GPIO2
EPWM2B -> GPIO3
EPWM3A -> GPIO4
EPWM3B -> GPIO5
EPWM4A -> GPIO6
EPWM4B -> GPIO7

### 3 运行步骤
1.开启EPWM1/2/3/4,一段时间后拉低EPWM4

### 4 运行现象
1.EPWM1/2/3间保持120度的相位差
2.EPWM4在输出一段事件波形后，通过软件强制持续拉低
