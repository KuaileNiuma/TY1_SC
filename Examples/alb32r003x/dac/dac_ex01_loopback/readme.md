## 8.1 dac_ex01_loopback

### 8.1.1 概述
本例程展示了DAC内部回环模式下，通过ADC采样验证DAC输出波形的功能。DACA输出正弦波，DACB输出锯齿波，通过ADC采样验证输出波形。

### 8.1.2 准备
ALB32R0039_EVM开发板

### 8.1.3 运行步骤
1.配置DACA输出正弦波（f(x)=sin(x)+1.6）
2.配置DACB输出锯齿波（从0到VREFHI，再回到0）
3.配置ADC采样DAC输出
4.循环更新DAC输出值并采样

### 8.1.4 运行现象
DACA输出正弦波，DACB输出锯齿波，ADC采样DAC输出，结果存储在ADCA0_Result和ADCA1_Result数组中。可以通过实时查看这些数组来观察实际的DAC输出信号。