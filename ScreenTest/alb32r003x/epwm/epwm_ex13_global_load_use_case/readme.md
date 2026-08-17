## epwm_ex13_global_load_use_case

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

### 3 运行步骤
1.EPWM2/3的CMPA/CMPB/GLDCTL2链接到EPWM1，都使能global和global的单次模式，global的装载源是CTR=0。写入EPWM1中CMP值时，同时改变EPWM2/3，启动EPWM1的单次global时，同时启动EPWM2/3。 EPWM1每3个周期产生一次中断，当产生300000中断时，修改CMP值，启动单次global。所以EPWM2/3会占空比会始终和EPWM1相同。 
2.EPWM1在CTR=0时，产生同步波形给EPWM2/3。使得三个EPWM波形间保持120度相移。 
3.CMPSS生成信号，进入EPWM2的TZ-CBC模块，用于将EPWM2的AB端波形拉低 4.GPIO6通过INPUTXBAR，进入EPWM3的TZ-OST模块，用于将EPWM3的AB端波形拉低

### 4 运行现象
1.EPWM1/2/3产生特定波形
