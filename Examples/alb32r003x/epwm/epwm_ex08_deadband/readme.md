## epwm_ex08_deadband

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
EPWM5A -> GPIO4
EPWM5B -> GPIO5
EPWM6A -> GPIO6
EPWM6B -> GPIO7

### 3 运行步骤
1.开启EPWM1/2/3/4/5/6

### 4 运行现象
1.各种死区信号 
EPWM1：PRD=2000（UD)，16分频，500，1500，uAh，dAl，uBh，dBl 
EPWM2：PDRD=2000（UD)，16分频，500，1500，uAh，dAl，uBh，dBl；A端：A源，RED=400，不取反，B端，A源，FED=200,不取反 
EPWM3：PRD=2000（UD),16分频，500，1500，uAh，dAl，uBh，dBl；A端：A源，RED=400，不取反，B端，A源，FED=200，不取反；交换A/B端波形 
EPWM4：PRD=2000（UD),16分频，500，1500，uAh，dAl，uBh，dBl；A端：A源，RED=400，不取反，B端，A源，FED=200，取反 
EPWM5：PRD=2000（UD),16分频，500，1500，uAh，dAl，uBh，dBl；A端：A源，RED=400，取反，B端，A源，FED=200，不取反，交换A/B端波形 
EPWM6：PRD=2000（UD),16分频，500，1500，uAh，dAl，uBh，dBl，交换A/B端波形
