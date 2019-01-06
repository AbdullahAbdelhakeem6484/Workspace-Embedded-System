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
keypad_opt.lss \

FLASH_IMAGE += \
keypad_opt.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: keypad_opt.elf secondary-outputs

# Tool invocations
keypad_opt.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,keypad_opt.map -mmcu=atmega32 -o "keypad_opt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

keypad_opt.lss: keypad_opt.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S keypad_opt.elf  >"keypad_opt.lss"
	@echo 'Finished building: $@'
	@echo ' '

keypad_opt.hex: keypad_opt.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex keypad_opt.elf  "keypad_opt.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: keypad_opt.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 keypad_opt.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) keypad_opt.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
