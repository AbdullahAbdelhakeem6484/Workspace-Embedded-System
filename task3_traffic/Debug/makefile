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
task3_traffic.lss \

FLASH_IMAGE += \
task3_traffic.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: task3_traffic.elf secondary-outputs

# Tool invocations
task3_traffic.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,task3_traffic.map -mmcu=atmega32 -o "task3_traffic.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

task3_traffic.lss: task3_traffic.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S task3_traffic.elf  >"task3_traffic.lss"
	@echo 'Finished building: $@'
	@echo ' '

task3_traffic.hex: task3_traffic.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex task3_traffic.elf  "task3_traffic.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: task3_traffic.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 task3_traffic.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) task3_traffic.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
