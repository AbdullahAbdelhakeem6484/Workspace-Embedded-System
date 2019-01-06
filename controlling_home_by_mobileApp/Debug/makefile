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
controlling_home_by_mobileApp.lss \

FLASH_IMAGE += \
controlling_home_by_mobileApp.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: controlling_home_by_mobileApp.elf secondary-outputs

# Tool invocations
controlling_home_by_mobileApp.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,controlling_home_by_mobileApp.map -mmcu=atmega32 -o "controlling_home_by_mobileApp.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

controlling_home_by_mobileApp.lss: controlling_home_by_mobileApp.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S controlling_home_by_mobileApp.elf  >"controlling_home_by_mobileApp.lss"
	@echo 'Finished building: $@'
	@echo ' '

controlling_home_by_mobileApp.hex: controlling_home_by_mobileApp.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex controlling_home_by_mobileApp.elf  "controlling_home_by_mobileApp.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: controlling_home_by_mobileApp.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 controlling_home_by_mobileApp.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) controlling_home_by_mobileApp.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
