## ecap_ex06_intr_phase_shift

### 1 概述
本例程展示了ECAP（增强型捕获模块）的APWM（模拟PWM）模式的中断相位偏移功能。通过配置ECAP模块为APWM模式，生成PWM波形，并通过OUTPUTXBAR输出到GPIO4和GPIO6引脚，同时通过中断动态调整PWM的相位偏移。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程配置两个ECAP模块：
- ECAP1：配置为APWM模式，设置周期为PWM_PRD_VAL，比较值为PWM_CMP_VAL（50%占空比），极性为低电平有效，同步输出为计数器周期时
- ECAP2：配置为APWM模式，设置相同的周期和比较值，极性为低电平有效，启用计数器加载，同步输出为同步输入，启用计数器周期中断

配置OUTPUTXBAR：
- 将ECAP1的输出信号路由到OUTPUTXBAR3（GPIO4）
- 将ECAP2的输出信号路由到OUTPUTXBAR4（GPIO6）

在中断服务程序中：
- 递增相位偏移值（0到4000循环）
- 更新ECAP2的APWM周期和比较值
- 设置新的相位偏移
- 加载计数器
- 清除中断标志

### 4 运行现象
可以通过示波器或逻辑分析仪抓取波形观察
测试现象：
```
1. GPIO4输出PWM波形
2. GPIO6输出与GPIO4同频率但有相位偏移的PWM波形
3. 相位偏移值在0到4000之间动态变化
4. 两个PWM波形的占空比保持在50%
```
