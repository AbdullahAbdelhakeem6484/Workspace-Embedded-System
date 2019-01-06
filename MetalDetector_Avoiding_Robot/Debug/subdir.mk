################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prog.c \
../Timer_Driver_prog.c \
../bluetooth_HCSR04.c \
../main.c \
../metalDetector.c 

OBJS += \
./DIO_prog.o \
./Timer_Driver_prog.o \
./bluetooth_HCSR04.o \
./main.o \
./metalDetector.o 

C_DEPS += \
./DIO_prog.d \
./Timer_Driver_prog.d \
./bluetooth_HCSR04.d \
./main.d \
./metalDetector.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


