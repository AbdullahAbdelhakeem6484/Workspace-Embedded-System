################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prog.c \
../EX_Interrupt_prog.c \
../IR_Sensor.c \
../MOTOR_prog.c \
../ULTRASONIC.c \
../main.c 

OBJS += \
./DIO_prog.o \
./EX_Interrupt_prog.o \
./IR_Sensor.o \
./MOTOR_prog.o \
./ULTRASONIC.o \
./main.o 

C_DEPS += \
./DIO_prog.d \
./EX_Interrupt_prog.d \
./IR_Sensor.d \
./MOTOR_prog.d \
./ULTRASONIC.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


