## ecap_ex05_apwm_pwm_sync

### 1 概述
本例程展示了ECAP（增强型捕获模块）的APWM（模拟PWM）模式与EPWM（增强型PWM）模块的同步功能。通过配置ECAP模块为APWM模式，并与EPWM模块进行同步，生成同步的PWM波形，并通过OUTPUTXBAR输出到GPIO4和GPIO15引脚。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程配置两个ECAP模块：
- ECAP1：配置为APWM模式，设置周期为2000，比较值为1000（50%占空比），极性为低电平有效，同步输出为计数器周期时，禁用同步输入
- ECAP2：配置为APWM模式，设置相同的周期和比较值，极性为低电平有效，禁用同步输出，同步输入为ECAP1的同步输出

配置OUTPUTXBAR：
- 将ECAP1的输出信号路由到OUTPUTXBAR3（GPIO4）
- 将ECAP2的输出信号路由到OUTPUTXBAR4（GPIO15）

配置EPWM1：
- 工作在递增计数模式
- 设置周期为PWM_PRD_VAL，比较值为PWM_CMP_VAL（50%占空比）
- 启用同步输出脉冲

### 4 运行现象
可以通过示波器或逻辑分析仪抓取波形观察
测试现象：
```
1. GPIO4输出PWM波形
2. GPIO15输出与GPIO4同步的PWM波形
3. 两个PWM波形的频率和占空比相同
4. ECAP模块与EPWM模块保持同步
```
