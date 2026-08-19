################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/ALBStudio_20260416_V1.0/ALBStudio/Packages/ALB32RT_SDK/Drivers/DriverLib/cpu/cpu_common.c \
D:/ALBStudio_20260416_V1.0/ALBStudio/Packages/ALB32RT_SDK/Drivers/DriverLib/cpu/system_cpu.c 

C_DEPS += \
./Drivers/DriverLib/cpu/cpu_common.d \
./Drivers/DriverLib/cpu/system_cpu.d 

OBJS += \
./Drivers/DriverLib/cpu/cpu_common.o \
./Drivers/DriverLib/cpu/system_cpu.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DriverLib/cpu/cpu_common.o: D:/ALBStudio_20260416_V1.0/ALBStudio/Packages/ALB32RT_SDK/Drivers/DriverLib/cpu/cpu_common.c Drivers/DriverLib/cpu/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	alb32-riscv-elf-gcc -march=rv32imafc_zba_zbb_zbc_zbs_xalbxf_xxldsp -mabi=ilp32f -mcmodel=medlow -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common -g -gdwarf-2 -DIS_ALB32R003X -D__IDE_RV_CORE=R3 -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Common" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices\alb32r003x" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu\NMSIS_Core\Include" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc\hw_regs" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Boards\alb32r003x_evb" -isystem=/include/newlib-nano -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/DriverLib/cpu/system_cpu.o: D:/ALBStudio_20260416_V1.0/ALBStudio/Packages/ALB32RT_SDK/Drivers/DriverLib/cpu/system_cpu.c Drivers/DriverLib/cpu/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	alb32-riscv-elf-gcc -march=rv32imafc_zba_zbb_zbc_zbs_xalbxf_xxldsp -mabi=ilp32f -mcmodel=medlow -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common -g -gdwarf-2 -DIS_ALB32R003X -D__IDE_RV_CORE=R3 -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Common" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices\alb32r003x" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu\NMSIS_Core\Include" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc\hw_regs" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Boards\alb32r003x_evb" -isystem=/include/newlib-nano -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


