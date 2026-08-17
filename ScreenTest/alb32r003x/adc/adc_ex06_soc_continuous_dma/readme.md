## adc_ex06_soc_continuous_dma

### 1 概述
本例程展示了DMA读取的ADC连续转换

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
通过强制触发ADC转换启动ADCA的连续采样。ADC转换完成时产生中断（adcALISR），该中断信号同时触发DMA传输。DMA（myDMAInit配置）自动将ADCA结果寄存器（ADCARESULT_BASE）中的128个16位转换数据搬运至目标数组（myADCGResults）。

### 4 运行现象
串口打印，参考如下：
```
ADC EXT06 SOC CONTINUOUS DMA.

-----ADCA Sample Value: -----
sampleValue=4095
sampleValue=4095
sampleValue=4095
```