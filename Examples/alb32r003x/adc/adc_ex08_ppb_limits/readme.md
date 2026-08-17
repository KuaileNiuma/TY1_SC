## adc_ex08_ppb_limit

### 1 概述
本例程展示了ADC后处理模块(PPB)的阈值检测功能。通过设置PPB的阈值，当ADC转换结果超过阈值时，会触发PPB事件和中断，从而实现对ADC转换值的实时监控。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
1. 板卡初始化：配置ADC、GPIO和中断等模块
2. 配置ADC SOC0：使用软件触发，通道为ADC_CH_ADCIN11，采样窗口为500个系统时钟周期
3. 配置PPB1：链接到SOC0，启用PPB上阈值事件和中断，设置阈值为myADC0_PPB_HITRIG
4. 主循环：等待ADC空闲后强制触发SOC0转换
5. 当ADC转换值超过设置的阈值时，PPB会触发事件和中断，在中断服务程序中读取转换结果并设置标志位
6. 主循环检测到标志位后，打印提示信息并重置标志位

### 4 运行现象

```
ADC EXT08 PPB LIMITS.
ADC conversion value reaches the set threshold!
ADC has stopped conversion!
```