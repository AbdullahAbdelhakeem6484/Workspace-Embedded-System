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
TASK_LEDintensity_LCD_KEYPAD.lss \

FLASH_IMAGE += \
TASK_LEDintensity_LCD_KEYPAD.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TASK_LEDintensity_LCD_KEYPAD.elf secondary-outputs

# Tool invocations
TASK_LEDintensity_LCD_KEYPAD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TASK_LEDintensity_LCD_KEYPAD.map -mmcu=atmega32 -o "TASK_LEDintensity_LCD_KEYPAD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TASK_LEDintensity_LCD_KEYPAD.lss: TASK_LEDintensity_LCD_KEYPAD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TASK_LEDintensity_LCD_KEYPAD.elf  >"TASK_LEDintensity_LCD_KEYPAD.lss"
	@echo 'Finished building: $@'
	@echo ' '

TASK_LEDintensity_LCD_KEYPAD.hex: TASK_LEDintensity_LCD_KEYPAD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TASK_LEDintensity_LCD_KEYPAD.elf  "TASK_LEDintensity_LCD_KEYPAD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TASK_LEDintensity_LCD_KEYPAD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TASK_LEDintensity_LCD_KEYPAD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TASK_LEDintensity_LCD_KEYPAD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
