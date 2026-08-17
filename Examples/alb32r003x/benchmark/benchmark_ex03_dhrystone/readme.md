## benchmark_ex03_dhrystone

### 1 概述
本例程展示了Dhrystone基准测试。通过执行Dhrystone测试套件，评估处理器的整数性能和编译器优化效果。

### 2 准备
ALB32R0039_EVM开发板

### 3 运行步骤

该例程执行以下操作：
- 初始化系统和板卡
- 打印系统信息，包括核心运行频率
- 调用benchmark_dhry_main()函数执行Dhrystone测试，运行5000000次循环
- 测试完成后返回

### 4 运行现象
详情见串口打印信息
