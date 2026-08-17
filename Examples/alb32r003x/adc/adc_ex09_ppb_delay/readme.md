## 1.9 adc_ex09_ppb_delay

### 1.9.1 概述
本例程展示了ADC后处理模块(PPB)的延迟时间戳功能。通过配置PPB链接到SOC，可以在ADC转换完成后获取转换的延迟时间戳，用于测量ADC转换的精确时间。

### 1.9.2 准备
ALB32R0039_EVM开发板

### 1.9.3 运行步骤
1. 板卡初始化：配置ADC、GPIO和中断等模块
2. 配置ADC SOC0：使用EPWM1_SOCA触发，通道为ADC_CH_ADCIN11，采样窗口为500个系统时钟周期
3. 配置ADC中断1：链接到SOC0，启用中断
4. 配置PPB1：链接到SOC0
5. 配置EPWM1：设置EPWM触发ADC转换，比较值1000，周期1999，时钟分频为1
6. 主循环：启动EPWM1，启用SOCA触发，计数器设置为递增模式
7. 在中断服务程序中读取ADC转换结果和PPB延迟时间戳
8. 停止EPWM1，打印延迟时间

### 1.9.4 运行现象

```
ADC EXT09 PPB DELAY.
ADC conversion delay time: 1000
```