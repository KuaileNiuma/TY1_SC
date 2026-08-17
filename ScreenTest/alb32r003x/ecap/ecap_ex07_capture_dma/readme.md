## ecap_ex07_capture_dma

### 1 概述
本例程展示了ECAP（增强型捕获模块）的捕获模式与DMA（直接内存访问）功能的结合使用。通过配置ECAP模块为捕获模式，捕获PWM波形的时间戳，并通过DMA自动将捕获数据传输到内存，无需CPU干预。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程配置ECAP1为捕获模式：
- 设置事件极性：事件1为下降沿，事件2为上升沿，事件3为下降沿，事件4为上升沿
- 配置计数器在每个事件时重置
- 选择ECAP输入为INPUTXBAR3
- 配置DMA源为事件4

配置INPUTXBAR：
- 将GPIO1的信号路由到INPUTXBAR3

配置EPWM1：
- 工作在递增计数模式
- 设置周期为PWM_PRD_VAL，比较值为PWM_CMP_VAL（30%占空比）
- 启用同步输出脉冲

配置DMA：
- 初始化DMA控制器
- 配置DMA通道，将ECAP1的CAP3和CAP4寄存器数据传输到ecapData数组
- 启用DMA中断
- 启动DMA通道

在主函数中：
- 初始化系统和板卡
- 配置EPWM和DMA
- 等待DMA传输完成
- 读取ECAP的捕获数据

### 4 运行现象
可以通过示波器或逻辑分析仪抓取波形观察
测试现象：
```
1. EPWM1_A输出PWM波形
2. ECAP1成功捕获PWM波形的时间戳
3. DMA自动将捕获数据传输到内存
4. 捕获数据存储在ecapData数组中
```
