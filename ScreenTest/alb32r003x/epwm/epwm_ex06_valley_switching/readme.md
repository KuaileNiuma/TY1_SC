## epwm_ex06_valley_switching

### 1 概述
本例程展示了使用epwm的功能。

### 2 准备
ALB32R0039_EVM开发板
EPWM1A -> GPIO0
EPWM1B -> GPIO1

### 3 运行步骤
1.开启EPWM1

### 4 运行现象
1.通过GPIO生成DC事件，直接应用于TZ模块，将A端波形拉低；通过DC-valley switch模块后作为TZ-OST源，将B端波形拉低
