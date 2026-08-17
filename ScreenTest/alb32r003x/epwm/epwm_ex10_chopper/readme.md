## epwm_ex10_chopper

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
1.开启EPWM1/2/3/4,使能载波模块，配置载波不同的参数 
EPWM1：PRD=500(UD），16分频，125，0，uAh，dAl，uAh，dAl 
EPWM2：PRD=500(UD），16分频，125，0，uAh，dAl，uAh，dAl；使能载波，占空比1/8，频率EPWMCLK/8/(1+3)，首次脉冲宽度为0。 
EPWM3：PRD=500(UD），16分频，125，0，uAh，dAl，uAh，dAl；使能载波，占空比6/8，频率EPWMCLK/8/(1+3)，首次脉冲宽度为0。 
EPWM4：PRD=500(UD），16分频，125，0，uAh，dAl，uAh，dAl；使能载波，占空比4/8，频率EPWMCLK/8/(1+3)，首次脉冲宽度为10。 

### 4 运行现象
1.EPWM1/2/3/4产生特定方波
