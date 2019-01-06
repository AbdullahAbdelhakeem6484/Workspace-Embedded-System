################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD\ 8.c 

OBJS += \
./LCD\ 8.o 

C_DEPS += \
./LCD\ 8.d 


# Each subdirectory must supply rules for building sources it contributes
LCD\ 8.o: ../LCD\ 8.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"LCD 8.d" -MT"LCD\ 8.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


