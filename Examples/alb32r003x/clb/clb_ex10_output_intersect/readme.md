## clb_ex10_output_intersect

### 1 概述
本例程展示了EPWM2A和EPWM3A作为CLB输入，CLB内部实现与门逻辑的功能。

### 2 准备
ALB32R0039_EVM开发板
使用示波器连接GPIO22

### 3 运行步骤
板级初始化 -> 初始化CLB -> 初始化epwm2 为主模块 -> 初始化epwm3为从模块 ->将epwm3同步输入源设为epwm2同步输出 -> 使能CLB -> 在主循环中每10ms更新占空比。

### 4 运行现象
GPIO22输出符合AND门真值表输出。捕获到的波形图如图5-15所示。
