################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/canfd_ex03_loopback.c 

C_DEPS += \
./src/canfd_ex03_loopback.d 

OBJS += \
./src/canfd_ex03_loopback.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	alb32-riscv-elf-gcc -march=rv32imafc_zba_zbb_zbc_zbs_xalbxf_xxldsp -mabi=ilp32f -mcmodel=medlow -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common -g -gdwarf-2 -DIS_ALB32R003X -D__IDE_RV_CORE=R3 -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\ScreenTest\scTest_drivers" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Common" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices\alb32r003x" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu\NMSIS_Core\Include" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc\hw_regs" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Boards\alb32r003x_evb" -isystem=/include/newlib-nano -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


