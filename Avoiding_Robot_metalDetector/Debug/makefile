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
Avoiding_Robot_metalDetector.lss \

FLASH_IMAGE += \
Avoiding_Robot_metalDetector.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Avoiding_Robot_metalDetector.elf secondary-outputs

# Tool invocations
Avoiding_Robot_metalDetector.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Avoiding_Robot_metalDetector.map -mmcu=atmega32 -o "Avoiding_Robot_metalDetector.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Avoiding_Robot_metalDetector.lss: Avoiding_Robot_metalDetector.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Avoiding_Robot_metalDetector.elf  >"Avoiding_Robot_metalDetector.lss"
	@echo 'Finished building: $@'
	@echo ' '

Avoiding_Robot_metalDetector.hex: Avoiding_Robot_metalDetector.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Avoiding_Robot_metalDetector.elf  "Avoiding_Robot_metalDetector.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Avoiding_Robot_metalDetector.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Avoiding_Robot_metalDetector.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Avoiding_Robot_metalDetector.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
