## 1.5 adc_ex05_soc_continuous

### 1.5.1 概述
本例程展示了ADC连续触发进行电压采样的功能

### 1.5.2 准备
ALB32R0039_EVM开发板

### 1.5.3 运行步骤
通过软件强制触发ADC转换序列，配置ADC的最后一个转换序列产生中断。在中断服务程序adcAIISR中，CPU读取ADC转换结果并清除中断标志位。
具体流程为：主循环中软件触发ADC转换→中断服务程序读取结果→清除中断和溢出标志→返回主循环持续触发新转换。

### 1.5.4 运行现象
串口打印，参考如下：
```
ADC EXT05 SOC CONTINUOUS.
-----ADC Sample Value: -----
sampleValue=2136
sampleValue=2135
sampleValue=2134
sampleValue=2135
sampleValue=2134
```