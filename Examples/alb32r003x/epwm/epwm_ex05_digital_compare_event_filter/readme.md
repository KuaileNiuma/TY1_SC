## epwm_ex05_digital_compare_event_filter

### 1 概述
本例程展示了使用epwm的功能。

### 2 准备
ALB32R0039_EVM开发板
EPWM1A -> GPIO0
EPWM1B -> GPIO1

### 3 运行步骤
1.开启EPWM1

### 4 运行现象
1.通过GPIO生成DC事件，直接应用于TZ模块，将A端波形拉低；通过DC-blank window模块，将B端波形拉低
