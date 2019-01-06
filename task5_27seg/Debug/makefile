################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
task5_27seg.lss \

FLASH_IMAGE += \
task5_27seg.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: task5_27seg.elf secondary-outputs

# Tool invocations
task5_27seg.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,task5_27seg.map -mmcu=atmega32 -o "task5_27seg.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

task5_27seg.lss: task5_27seg.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S task5_27seg.elf  >"task5_27seg.lss"
	@echo 'Finished building: $@'
	@echo ' '

task5_27seg.hex: task5_27seg.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex task5_27seg.elf  "task5_27seg.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: task5_27seg.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 task5_27seg.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) task5_27seg.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
