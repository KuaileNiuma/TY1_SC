################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
D:/Programs/ALBStudio_20260331_V1.0/ALBStudio/Packages/ALB32RT_SDK/Drivers/DriverLib/cpu/startup/intexc.S \
D:/Programs/ALBStudio_20260331_V1.0/ALBStudio/Packages/ALB32RT_SDK/Drivers/DriverLib/cpu/startup/intexc_s.S \
D:/Programs/ALBStudio_20260331_V1.0/ALBStudio/Packages/ALB32RT_SDK/Drivers/DriverLib/cpu/startup/startup.S 

OBJS += \
./Drivers/DriverLib/cpu/startup/intexc.o \
./Drivers/DriverLib/cpu/startup/intexc_s.o \
./Drivers/DriverLib/cpu/startup/startup.o 

S_UPPER_DEPS += \
./Drivers/DriverLib/cpu/startup/intexc.d \
./Drivers/DriverLib/cpu/startup/intexc_s.d \
./Drivers/DriverLib/cpu/startup/startup.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DriverLib/cpu/startup/intexc.o: D:/Programs/ALBStudio_20260331_V1.0/ALBStudio/Packages/ALB32RT_SDK/Drivers/DriverLib/cpu/startup/intexc.S Drivers/DriverLib/cpu/startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	alb32-riscv-elf-gcc -march=rv32imafc_zba_zbb_zbc_zbs_xalbxf_xxldsp -mabi=ilp32f -mcmodel=medlow -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common -g -gdwarf-2 -x assembler-with-cpp -DIS_ALB32R003X -D__IDE_RV_CORE=R3 -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\ScreenTest\scTest_drivers" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Common" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices\alb32r003x" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu\NMSIS_Core\Include" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc\hw_regs" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Boards\alb32r003x_evb" -isystem=/include/newlib-nano -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/DriverLib/cpu/startup/intexc_s.o: D:/Programs/ALBStudio_20260331_V1.0/ALBStudio/Packages/ALB32RT_SDK/Drivers/DriverLib/cpu/startup/intexc_s.S Drivers/DriverLib/cpu/startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	alb32-riscv-elf-gcc -march=rv32imafc_zba_zbb_zbc_zbs_xalbxf_xxldsp -mabi=ilp32f -mcmodel=medlow -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common -g -gdwarf-2 -x assembler-with-cpp -DIS_ALB32R003X -D__IDE_RV_CORE=R3 -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\ScreenTest\scTest_drivers" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Common" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices\alb32r003x" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu\NMSIS_Core\Include" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc\hw_regs" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Boards\alb32r003x_evb" -isystem=/include/newlib-nano -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/DriverLib/cpu/startup/startup.o: D:/Programs/ALBStudio_20260331_V1.0/ALBStudio/Packages/ALB32RT_SDK/Drivers/DriverLib/cpu/startup/startup.S Drivers/DriverLib/cpu/startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	alb32-riscv-elf-gcc -march=rv32imafc_zba_zbb_zbc_zbs_xalbxf_xxldsp -mabi=ilp32f -mcmodel=medlow -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common -g -gdwarf-2 -x assembler-with-cpp -DIS_ALB32R003X -D__IDE_RV_CORE=R3 -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\ScreenTest\scTest_drivers" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Common" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices\alb32r003x" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\cpu\NMSIS_Core\Include" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\DriverLib\inc\hw_regs" -I"D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Boards\alb32r003x_evb" -isystem=/include/newlib-nano -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


