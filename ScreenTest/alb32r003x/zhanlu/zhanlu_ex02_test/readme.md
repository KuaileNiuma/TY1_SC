## zhanlu_ex02_test

### 1 概述
本例程展示了ZHANLU_NICE指令集的测试功能。通过执行ILM_int()函数初始化ILM内存，并执行zhanlu_cycle_test()函数进行周期测试，同时测试系统定时器的MTIP和MSIP中断功能，验证ZHANLU_NICE指令集的性能。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程执行以下操作：
- 初始化系统和板卡
- 调用zhanlu_cycle_test()函数进行周期测试
- 打印测试完成信息
- 进入无限循环

### 4 运行现象
测试现象：
```
1. 打印输出每条zhanlu指令循环10000次（5*20*100）所消耗的cycle数"
```
