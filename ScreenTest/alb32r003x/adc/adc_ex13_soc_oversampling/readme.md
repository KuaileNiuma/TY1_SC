## 1.13 adc_ex13_soc_oversampling

### 1.13.1 概述
本例程展示了ADC的过采样功能。通过配置多个SOC使用相同的通道，然后对多个转换结果取平均值，实现过采样，提高ADC的分辨率和噪声性能。

### 1.13.2 准备
ALB32R0039_EVM开发板

### 1.13.3 运行步骤
1. 板卡初始化：配置ADC、GPIO和中断等模块
2. 配置4个ADC SOC：
   - SOC0：使用EPWM1_SOCA触发，通道为myADC0_CH，采样窗口为1个系统时钟周期
   - SOC1：使用EPWM1_SOCA触发，通道为myADC0_CH，采样窗口为1个系统时钟周期
   - SOC2：使用EPWM1_SOCA触发，通道为myADC0_CH，采样窗口为1个系统时钟周期
   - SOC3：使用EPWM1_SOCA触发，通道为myADC0_CH，采样窗口为1个系统时钟周期
3. 配置ADC中断1：链接到SOC3，启用连续模式
4. 配置EPWM1：设置EPWM触发ADC转换，比较值为myEPWM_Cmp，周期为myEPWM_Prd，时钟分频为1
5. 主循环：启动EPWM1，启用SOCA触发，计数器设置为递增模式
6. 当所有SOC转换完成后，在中断服务程序中读取所有SOC的转换结果，并计算平均值作为过采样结果
7. 主循环检测到缓冲区满标志后，打印所有通道的转换结果和过采样值

### 1.13.4 运行现象

```
ADC EXT13 SOC EOVERSAMPLING.
ADC SOC0 CH11 value:2048
ADC SOC1 CH11 value:2050
ADC SOC2 CH11 value:2046
ADC SOC3 CH11 value:2049
oversample value: 2048
```