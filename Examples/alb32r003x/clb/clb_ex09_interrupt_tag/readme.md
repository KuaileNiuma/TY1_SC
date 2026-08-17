## 5.9 clb_ex09__interrupt_tag

### 5.9.1 概述
本例程展示了CLB 计数器的 match1 事件和 match2 事件生成的中断的功能。

### 5.9.2 准备
ALB32R0039_EVM开发板
使用示波器连接GPIO0和GPIO1

### 5.9.3 运行步骤
板级初始化 -> 初始化CLB -> 使能CLB逻辑块 -> 使能中断 —> 配置中断函数
  
### 5.9.4 运行现象
捕获GPIO0,GPIO1引脚波形，由于设置COUNTER的MATCH1,MATCH2值不同可以看到GPIO0,GPIO1, 引脚翻转频率不一致。如图5-14所示。 