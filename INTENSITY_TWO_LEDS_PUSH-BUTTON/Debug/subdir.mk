################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Driver_prog.c \
../DIO_prog.c \
../EX_Interrupt_prog.c \
../KeyPad_prog.c \
../LCD_prog.c \
../Timer_Driver_prog.c \
../main.c 

OBJS += \
./ADC_Driver_prog.o \
./DIO_prog.o \
./EX_Interrupt_prog.o \
./KeyPad_prog.o \
./LCD_prog.o \
./Timer_Driver_prog.o \
./main.o 

C_DEPS += \
./ADC_Driver_prog.d \
./DIO_prog.d \
./EX_Interrupt_prog.d \
./KeyPad_prog.d \
./LCD_prog.d \
./Timer_Driver_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


