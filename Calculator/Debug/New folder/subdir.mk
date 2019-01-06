################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../New\ folder/LCD_prog.c \
../New\ folder/keypad_prog.c 

OBJS += \
./New\ folder/LCD_prog.o \
./New\ folder/keypad_prog.o 

C_DEPS += \
./New\ folder/LCD_prog.d \
./New\ folder/keypad_prog.d 


# Each subdirectory must supply rules for building sources it contributes
New\ folder/LCD_prog.o: ../New\ folder/LCD_prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"New folder/LCD_prog.d" -MT"New\ folder/LCD_prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

New\ folder/keypad_prog.o: ../New\ folder/keypad_prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"New folder/keypad_prog.d" -MT"New\ folder/keypad_prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


