## benchmark_ex01_acimotor

### 1 概述
本例程展示了交流感应电机（ACIM）控制的基准测试。通过配置ADC和EPWM模块，实现对交流感应电机的控制，并使用ZHANLU_NICE指令集优化控制算法的性能。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程执行以下操作：
- 初始化系统和板卡
- 启用ADC1、EPWM1、EPWM2、EPWM3的时钟
- 配置中断为CLINT中断模式
- 调用ACI_main()函数执行ACIM控制算法
- 使用ZHANLU_NICE指令集进行数学运算优化

### 4 运行现象
详情见串口打印信息
