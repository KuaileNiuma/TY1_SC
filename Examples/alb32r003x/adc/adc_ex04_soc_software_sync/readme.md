## 1.4 adc_ex04_soc_software_sync

### 1.4.1 概述
本例程展示了ADC同步SOC软件强制

### 1.4.2 准备
ALB32R0039_EVM开发板

### 1.4.3 运行步骤
通过配置ePWM模块周期性产生SOCA事件信号触发ADC转换序列。ADC配置转换触发源为ePWM的SOCA事件，在转换结束中断服务程序中将转换结果存储到缓冲区数组。当缓冲区填满后设置标志位，主循环检测到标志位后禁用ePWM模块停止SOC事件信号。
具体流程为：ePWM周期触发ADC转换→中断中存储结果→缓冲区满置标志位→主循环停用ePWM。

### 1.4.4 运行现象
串口打印，参考如下
```
ADC EXT04 SOC EPWM.
-----ADC Sample Value: -----
ADCA11=2244
ADCA11=2244
ADCA11=2242
ADCA11=2243
```
