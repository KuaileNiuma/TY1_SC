## 1.7 adc_ex07_ppb_offset

### 1.7.1 概述
本例程展示了ADC后处理模块offset

### 1.7.2 准备
ALB32R0039_EVM开发板

### 1.7.3 运行步骤
通过软件强制触发启动ADCA的SOC0转换序列。CPU在主循环轮询ADC忙状态标志（ADC_isBusy），转换完成后产生中断。在中断服务程序（adcAllSR）中，读取链接到SOC0的PPB2/3/4后处理块结果（分别设置256/512/1024参考偏移量）。通过对比不同PPB的转换结果（myADCOResults[1]-[3]），可观察到PPB对原始ADC值的偏移修正效果。

### 1.7.4 运行现象

```
ADC EXT07 SOC PPB OFFSET.
ADCPPB1 = 2113
ADCPPB1 = 2119
ADCPPB1 = 2114
```