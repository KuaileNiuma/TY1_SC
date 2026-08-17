## 1.12 adc_ex12_burst_mode_oversampling

### 1.12.1 概述
本例程展示了ADC的burst模式和过采样功能。通过burst模式一次触发执行多个SOC的转换，然后对多个转换结果取平均值，实现过采样，提高ADC的分辨率和噪声性能。

### 1.12.2 准备
ALB32R0039_EVM开发板

### 1.12.3 运行步骤
1. 板卡初始化：配置ADC、GPIO和中断等模块
2. 配置ADC为burst模式：使用EPWM1_SOCA触发，burst长度为3（即一次触发执行4个SOC）
3. 配置4个ADC SOC：
   - SOC0：使用EPWM1_SOCA触发，通道为ADC_CH_ADCIN11，采样窗口为500个系统时钟周期
   - SOC13：使用SW_ONLY触发，通道为ADC_CH_ADCIN11，采样窗口为500个系统时钟周期
   - SOC14：使用SW_ONLY触发，通道为ADC_CH_ADCIN11，采样窗口为500个系统时钟周期
   - SOC15：使用SW_ONLY触发，通道为ADC_CH_ADCIN11，采样窗口为500个系统时钟周期
4. 配置ADC中断1：链接到SOC15，启用中断
5. 配置EPWM1：设置EPWM触发ADC转换，比较值1000，周期1999，时钟分频为1
6. 主循环：启动EPWM1，启用SOCA触发，计数器设置为递增模式
7. 当burst模式执行完成后，在中断服务程序中读取所有SOC的转换结果
8. 主循环检测到缓冲区满标志后，计算4个转换结果的平均值，实现过采样功能

### 1.12.4 运行现象

```
ADC EXT12 SOC EPWM.
ADC SOC0   CH11 value:2048
ADC SOC13  CH11 value:2050
ADC SOC14  CH11 value:2046
ADC SOC15  CH11 value:2049
oversample value: 2048
```