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
Task4_leds.lss \

FLASH_IMAGE += \
Task4_leds.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Task4_leds.elf secondary-outputs

# Tool invocations
Task4_leds.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Task4_leds.map -mmcu=atmega32 -o "Task4_leds.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Task4_leds.lss: Task4_leds.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Task4_leds.elf  >"Task4_leds.lss"
	@echo 'Finished building: $@'
	@echo ' '

Task4_leds.hex: Task4_leds.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Task4_leds.elf  "Task4_leds.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Task4_leds.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Task4_leds.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Task4_leds.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
