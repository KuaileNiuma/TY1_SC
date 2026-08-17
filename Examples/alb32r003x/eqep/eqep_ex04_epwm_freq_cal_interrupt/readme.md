## eqep_ex04_epwm_freq_cal_interrupt

### 1 概述
本例程展示了EPWM产生的方波频率为5 kHz，且eQEP捕获测量出的信号频率为5 kHz

### 2 准备
ALB32R0039_EVM开发板
接线如下：
EQEP1:GPIO0  - GPIO10 
      GPIO1  - GPIO11 
      GPIO30 - GPIO23 
EQEP2:GPIO0  - GPIO14 
      GPIO1  - GPIO15 
      GPIO30 - GPIO26 

### 3 运行步骤
1.配置ePWM1A模块产生5kHz的PWM测试信号，作为eQEP的输入信号源 
2.配置eQEP模块使用单位定时器模式，设置单位定时器周期为10ms（100Hz） 
3.配置eQEP单位定时器超时中断，在每次单位定时器超时（10ms）时自动触发，代替ePWM中断触发测量计算 
4. 每次中断读取eQEP位置计数器的锁存值，计算10ms内的计数变化 

### 4 运行现象
串口会将测试结果直接打印出来，参考如下
```
    eqep_ex4 success.
```
