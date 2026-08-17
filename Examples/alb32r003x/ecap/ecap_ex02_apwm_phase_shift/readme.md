## ecap_ex02_apwm_phase_shift

### 1 概述
本例程展示了ECAP（增强型捕获模块）的APWM（模拟PWM）模式的相位偏移功能。通过配置两个ECAP模块为APWM模式，并使用同步信号实现两个PWM波形之间的相位偏移，同时通过OUTPUTXBAR输出到GPIO5和GPIO6引脚。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程配置两个ECAP模块：
- ECAP1：配置为APWM模式，设置周期为PWM_PRD_VAL，比较值为PWM_CMP_VAL，极性为低电平有效，同步输出为计数器周期时
- ECAP2：配置为APWM模式，设置相同的周期和比较值，极性为低电平有效，设置相位偏移为PWM_PHASE_VAL，启用计数器加载相位偏移值，同步输入为ECAP1的同步输出

配置OUTPUTXBAR：
- 将ECAP1的输出信号路由到OUTPUTXBAR3（GPIO5）
- 将ECAP2的输出信号路由到OUTPUTXBAR4（GPIO6）

### 4 运行现象
可以通过示波器或逻辑分析仪抓取波形观察
测试现象：
```
1. GPIO5输出PWM波形
2. GPIO6输出与GPIO5同频率、同占空比但有相位偏移的PWM波形
3. 两个PWM波形之间的相位差为PWM_PHASE_VAL对应的角度
```
