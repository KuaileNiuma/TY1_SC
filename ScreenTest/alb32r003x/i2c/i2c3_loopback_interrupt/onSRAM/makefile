################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include Drivers/DriverLib/cpu/startup/subdir.mk
-include Drivers/DriverLib/cpu/subdir.mk
-include Drivers/DriverLib/subdir.mk
-include Drivers/Common/subdir.mk
-include Boards/alb32r003x_evb/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := i2c3_loopback_interrupt
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
i2c3_loopback_interrupt.bin \

SECONDARY_LIST += \
i2c3_loopback_interrupt.lst \

SECONDARY_SIZE += \
i2c3_loopback_interrupt.siz \


# All Target
all: main-build

# Main-build Target
main-build: i2c3_loopback_interrupt.elf secondary-outputs

# Tool invocations
i2c3_loopback_interrupt.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU RISC-V Cross C++ Linker'
	alb32-riscv-elf-g++ -march=rv32imafc_zba_zbb_zbc_zbs_xalbxf_xxldsp -mabi=ilp32f -mcmodel=medlow -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common -g -gdwarf-2 -T "D:\Programs\ALBStudio_20260331_V1.0\ALBStudio\Packages\ALB32RT_SDK\Drivers\Devices\alb32r003x\gcc_alb32r003x_sram.ld" -nostartfiles -nodefaultlibs -Xlinker --gc-sections -Wl,-Map,"i2c3_loopback_interrupt.map" -u _printf_float -u _scanf_float -Wl,--check-sections -Wl,--no-warn-rwx-segments -u _isatty -u _write -u _sbrk -u _read -u _close -u _fstat -u _lseek -u errno -o "i2c3_loopback_interrupt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

i2c3_loopback_interrupt.bin: i2c3_loopback_interrupt.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	alb32-riscv-elf-objcopy -O binary "i2c3_loopback_interrupt.elf"  "i2c3_loopback_interrupt.bin"
	@echo 'Finished building: $@'
	@echo ' '

i2c3_loopback_interrupt.lst: i2c3_loopback_interrupt.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Create Listing'
	alb32-riscv-elf-objdump --source --all-headers --demangle --disassemble --line-numbers --wide "i2c3_loopback_interrupt.elf" > "i2c3_loopback_interrupt.lst"
	@echo 'Finished building: $@'
	@echo ' '

i2c3_loopback_interrupt.siz: i2c3_loopback_interrupt.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	alb32-riscv-elf-size --format=berkeley "i2c3_loopback_interrupt.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CCM_DEPS)$(C_UPPER_DEPS)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(CXXM_DEPS)$(C_DEPS)$(CC_DEPS)$(SX_DEPS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(SECONDARY_FLASH)$(ASM_DEPS)$(S_UPPER_DEPS)$(C++M_DEPS)$(CPP_DEPS) i2c3_loopback_interrupt.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
