## lpm_ex01_test

### 1 概述
本例程展示了控制CPU分别进入sleep模式和deepsleep模式，用外部中断唤醒

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤
1.配置GPIO3为外部中断模式
2.进入sleep模式后，通过定时器唤醒
3.随后进入deepsleep模式，通过对GPIO3输入下降沿唤醒

### 4 运行现象
CPU被唤醒并打印串口信息
