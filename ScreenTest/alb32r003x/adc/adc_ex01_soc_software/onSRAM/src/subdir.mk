################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adc_ex01_board.c \
../src/adc_ex01_soc_software.c 

C_DEPS += \
./src/adc_ex01_board.d \
./src/adc_ex01_soc_software.d 

OBJS += \
./src/adc_ex01_board.o \
./src/adc_ex01_soc_software.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	alb32-riscv-elf-gcc -march=rv32imafc_zba_zbb_zbc_zbs_xalbxf_xxldsp -mabi=ilp32f -mcmodel=medlow -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common -g -gdwarf-2 -DIS_ALB32R003X -D__IDE_RV_CORE=R3 -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Common" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices\alb32r003x" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu\NMSIS_Core\Include" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc\hw_regs" -I"D:\ALBStudio_20260416_V1.0\ALBStudio\Packages\ALB32RT_SDK\Boards\alb32r003x_evb" -isystem=/include/newlib-nano -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


