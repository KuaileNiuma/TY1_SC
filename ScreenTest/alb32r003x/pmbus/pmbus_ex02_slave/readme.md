# pmbus_ex02_slave

### 1 概述
本例程展示了ALB32R0039作为pmbus slave 的使用，与pmbus_ex01_master例程结合使用

### 2 准备
需要装备两块ALB32R0039_EVM开发板，
其中一块用作pmbus master，GPIO0（SDA），GPIO1（SCL）
其中另一块用作pmbus slave，GPIO0（SDA），GPIO1（SCL）
两块板子的GPIO0对接，GPIO1对接
用作pmbus slave的板子要先运行
debug串口是GPIO_29_SCIA_TX，GPIO_28_SCIA_RX，接上串口工具

### 3 运行步骤
1)系统初始化 
2)I2C GPIO配置 
3)PMBus从设备初始化 
4)中断配置 
5)pmbus命令注册
6)循环等待，pmbus命令的处理在pmbus_isr_handler


### 4 运行现象
收到注册的命令后，则会打印cb:cmd: 0x%05, read:true, pec_check:true, len:1,