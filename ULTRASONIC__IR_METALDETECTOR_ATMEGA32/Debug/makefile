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
ULTRASONIC__IR_METALDETECTOR_ATMEGA32.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ULTRASONIC__IR_METALDETECTOR_ATMEGA32.elf secondary-outputs

# Tool invocations
ULTRASONIC__IR_METALDETECTOR_ATMEGA32.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ULTRASONIC__IR_METALDETECTOR_ATMEGA32.map -mmcu=atmega32 -o "ULTRASONIC__IR_METALDETECTOR_ATMEGA32.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ULTRASONIC__IR_METALDETECTOR_ATMEGA32.lss: ULTRASONIC__IR_METALDETECTOR_ATMEGA32.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ULTRASONIC__IR_METALDETECTOR_ATMEGA32.elf  >"ULTRASONIC__IR_METALDETECTOR_ATMEGA32.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ULTRASONIC__IR_METALDETECTOR_ATMEGA32.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ULTRASONIC__IR_METALDETECTOR_ATMEGA32.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ULTRASONIC__IR_METALDETECTOR_ATMEGA32.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
