## 1.11 adc_ex11_burst_mode_epwm

### 1.11.1 概述
本例程展示了ADC的burst模式功能。通过EPWM1的SOCA信号触发一次burst模式，同时执行多个SOC的转换，提高了ADC采样的效率和同步性。

### 1.11.2 准备
ALB32R0039_EVM开发板

### 1.11.3 运行步骤
1. 板卡初始化：配置ADC、GPIO和中断等模块
2. 配置ADC为burst模式：使用EPWM1_SOCA触发，burst长度为3（即一次触发执行4个SOC）
3. 配置4个ADC SOC：
   - SOC0：使用EPWM1_SOCA触发，通道为ADC_CH_ADCIN11，采样窗口为500个系统时钟周期
   - SOC13：使用SW_ONLY触发，通道为ADC_CH_ADCIN0，采样窗口为500个系统时钟周期
   - SOC14：使用SW_ONLY触发，通道为ADC_CH_ADCIN1，采样窗口为500个系统时钟周期
   - SOC15：使用SW_ONLY触发，通道为ADC_CH_ADCIN2，采样窗口为500个系统时钟周期
4. 配置ADC中断1：链接到SOC15，启用中断
5. 配置EPWM1：设置EPWM触发ADC转换，比较值1000，周期1999，时钟分频为1
6. 主循环：启动EPWM1，启用SOCA触发，计数器设置为递增模式
7. 当burst模式执行完成后，在中断服务程序中读取所有SOC的转换结果
8. 主循环检测到缓冲区满标志后，打印所有通道的转换结果

### 1.11.4 运行现象

```
ADC EXT11 SOC EPWM.
ADC SOC0   CH11 value:2048
ADC SOC13  CH0  value:1024
ADC SOC14  CH1  value:1536
ADC SOC15  CH2  value:512
```