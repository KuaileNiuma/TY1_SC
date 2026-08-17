## adc_ex01_soc_software

### 1 概述
本例程展示了使用软件来触发ADC进行电压采样的功能

### 2 准备
ALB32R0039_EVM开发板
使用板载滑动变阻器调整ADC的输入电压，测试时需将JP11的1和2引脚通过跳线帽短接

### 3 运行步骤
软件强制触发ADC转换序列，CPU通过轮询标志位检测转换完成状态，最后读取并存储转换结果。
具体流程为：软件触发ADC转换→循环等待完成标志→清除中断标志→读取转换结果。

### 4 运行现象
串口会将采样结果直接打印出来，参考如下
```
    -----ADCA Sample Value: -----
    sampleValue = 2018
    sampleValue = 1977
    sampleValue = 1942
    sampleValue = 1916
    sampleValue = 1898
    sampleValue = 1883
    sampleValue = 1872
    sampleValue = 1863
```  