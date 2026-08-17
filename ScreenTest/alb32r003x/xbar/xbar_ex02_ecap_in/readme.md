## xbar_ex02_ecap_in

### 1 概述
本例程展示了INPUTXBAR作为ECAP的输入源

### 2 准备
ALB32R0039_EVM开发板
GPIO34连接GPIO0

### 3 运行步骤
使能各外设时钟 -> 初始化ECAP -> 初始化XBAR -> 检验捕获值和预期值是否相符 

### 4 运行现象
GPIO34和GPIO0互联后使用串口工具可看到测试PASS的log信息。
