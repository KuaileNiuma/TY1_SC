## adc_ex14_cput

### 1 概述
本例程展示了使用CPU定时器(CPUT)触发ADC转换的功能。通过配置TIMER1产生定时中断，触发ADC的SOC0转换，实现定时采样。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
1. 板卡初始化：配置ADC、GPIO和模拟参考电压
2. 配置ADC SOC0：使用CPU1_TINT0（CPU定时器1中断）触发，通道为ADC_CH_ADCIN11，采样窗口为500个系统时钟周期
3. 配置ADC中断1：链接到SOC0，启用中断
4. 初始化TIMER1：设置为用户定义模式，启用中断，频率为2MHz
5. 主循环：等待ADC中断，读取转换结果并打印

### 4 运行现象

```
ADC EXT14 SOC CPUT.
ADC value:2048
ADC value:2049
ADC value:2047
```