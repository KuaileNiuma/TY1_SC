## pmbus_ex01_master

### 1 概述
本例程展示了ALB32R0039作为pmbus master的使用，与pmbus_ex02_slave例程结合使用

### 2 准备
需要装备两块ALB32R0039_EVM开发板，
其中一块用作pmbus master，GPIO0（SDA），GPIO1（SCL）
其中另一块用作pmbus slave，GPIO0（SDA），GPIO1（SCL）
两块板子的GPIO0对接，GPIO1对接
用作pmbus slave的板子要先运行

### 3 运行步骤
1) 系统初始化 
2) I2C GPIO配置 
3) I2C主模式初始化 
4) pmbus命令注册
5) 发送PMBus写命令 
6) 接收PMBus读命令 
7)循环测试 回到5）

### 4 运行现象
观察打印，pmbus的命令是执行打印success还是fail，
例如如果是pmbus写命令，失败则打印输出pmbus(cmd:0x05) master write failed, err_code:1
例如如果是pmbus读命令，成功则打印输出pmbus(cmd:0x00) master read len:1，失败则打印输出pmbus(cmd:0x00) master read failed, err_code:0