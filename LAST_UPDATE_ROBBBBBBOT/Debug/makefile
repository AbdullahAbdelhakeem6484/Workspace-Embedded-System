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
LAST_UPDATE_ROBBBBBBOT.lss \

FLASH_IMAGE += \
LAST_UPDATE_ROBBBBBBOT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: LAST_UPDATE_ROBBBBBBOT.elf secondary-outputs

# Tool invocations
LAST_UPDATE_ROBBBBBBOT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LAST_UPDATE_ROBBBBBBOT.map -mmcu=atmega32 -o "LAST_UPDATE_ROBBBBBBOT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LAST_UPDATE_ROBBBBBBOT.lss: LAST_UPDATE_ROBBBBBBOT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LAST_UPDATE_ROBBBBBBOT.elf  >"LAST_UPDATE_ROBBBBBBOT.lss"
	@echo 'Finished building: $@'
	@echo ' '

LAST_UPDATE_ROBBBBBBOT.hex: LAST_UPDATE_ROBBBBBBOT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LAST_UPDATE_ROBBBBBBOT.elf  "LAST_UPDATE_ROBBBBBBOT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LAST_UPDATE_ROBBBBBBOT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LAST_UPDATE_ROBBBBBBOT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LAST_UPDATE_ROBBBBBBOT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
