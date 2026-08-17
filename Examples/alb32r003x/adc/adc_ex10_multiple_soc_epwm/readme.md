## 1.10 adc_ex10_multiple_soc_epwm

### 1.10.1 概述
本例程展示了使用EPWM触发多个ADC SOC（Start of Conversion）的同步采样功能。通过EPWM1的SOCA信号同时触发多个ADC通道的转换，实现多通道的同步采样。

### 1.10.2 准备
ALB32R0039_EVM开发板

### 1.10.3 运行步骤
1. 板卡初始化：配置ADC、GPIO和中断等模块
2. 配置4个ADC SOC：
   - SOC0：使用EPWM1_SOCA触发，通道为ADC_CH_ADCIN11，采样窗口为500个系统时钟周期
   - SOC1：使用EPWM1_SOCA触发，通道为ADC_CH_ADCIN0，采样窗口为500个系统时钟周期
   - SOC2：使用EPWM1_SOCA触发，通道为ADC_CH_ADCIN1，采样窗口为500个系统时钟周期
   - SOC3：使用EPWM1_SOCA触发，通道为ADC_CH_ADCIN2，采样窗口为500个系统时钟周期
3. 配置ADC中断1：链接到SOC3，启用中断
4. 配置EPWM1：设置EPWM触发ADC转换，比较值1000，周期1999，时钟分频为1
5. 主循环：启动EPWM1，启用SOCA触发，计数器设置为递增模式
6. 当所有SOC转换完成后，在中断服务程序中读取所有SOC的转换结果
7. 主循环检测到缓冲区满标志后，打印所有通道的转换结果

### 1.10.4 运行现象

```
ADC EXT10 SOC EPWM SYNC.
ADC SOC0 CH11 value:2048
ADC SOC1 CH0  value:1024
ADC SOC2 CH1  value:1536
ADC SOC3 CH2  value:512
```