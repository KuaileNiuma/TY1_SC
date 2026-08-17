## clb_ex06_external_signal_and_gate

### 1 概述
本例程展示了CLB实现AND逻辑的功能。

### 2 准备
ALB32R0039_EVM开发板
使用示波器连接GPIO24

### 3 运行步骤
板级初始化 -> 使能CLB   
在GPIO0,GPIO1输入真值表输入，观察GPIO24引脚输出是否符合真值表输出。 

### 4 运行现象
将GPIO0接低、GPIO1接高/GPIO0接高、GPIO1接低，捕获到的波形图如图所示图5-8所示。
将GPIO0和GPIO1均接低，捕获到的波形图如图5-8所示。
将GPIO0和GPIO1均接高，捕获到的波形图如图5-9所示。
