################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

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
libADC_driver.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: libADC_driver.a secondary-outputs

# Tool invocations
libADC_driver.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR Archiver'
	avr-ar -r  "libADC_driver.a" $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

libADC_driver.lss: libADC_driver.a
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S libADC_driver.a  >"libADC_driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: libADC_driver.a
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 libADC_driver.a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(ARCHIVES)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) libADC_driver.a
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
