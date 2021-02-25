/*
 * EX_Interrupt_prog.c

 *
 *  Created on: Sep 5, 2018
 *      Author: Abdullah Abdelhakeem
 */



#include"STD_Types.h"
#include"macros.h"
#include"DIO_Interface.h"
#include "EX_Interrupt_config.h"
#include"MOTOR.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 12000000
extern u8 flag;

void EX_Interrupt_voidInitINT0(void)
{
	//Enable PIE for INT0
	SET_BIT(GICR,6);


	//Enable GIE
	SET_BIT(SREG,7);


#if SENSE_CONTROL == LOW_LEVEL

	//set Low Level sense control in ISC0
	CLEAR_BIT(MCUCR,ISC00);
	CLEAR_BIT(MCUCR,ISC01);

#elif SENSE_CONTROL == ANY_LOGIC_CHANGE

	SET_BIT(MCUCR,ISC00);
	CLEAR_BIT(MCUCR,ISC01);

#elif SENSE_CONTROL == RISING_EDGE

	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);

#elif SENSE_CONTROL == FALLING_EDGE

	CLEAR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);

#endif
}

void EX_Interrupt_voidSetINT0(void)
{
	// Set PD2"INT0" as input pull-up
	DIO_voidSetPinDir(PORT_D,PIN_2,INPUT);
	DIO_voidSetPinValue(PORT_D,PIN_2,HIGH);
}




void EX_Interrupt_voidInitINT1(void)
{

	//Enable GIE
	SET_BIT(SREG,7);

	//Enable PIE for INT1
	SET_BIT(GICR,7);

#if SENSE_CONTROL == LOW_LEVEL

	//set Low Level sense control in ISC1
	CLEAR_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);

#elif SENSE_CONTROL == ANY_LOGIC_CHANGE

	SET_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);

#elif SENSE_CONTROL == RISING_EDGE

	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);

#elif SENSE_CONTROL == FALLING_EDGE

	CLEAR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);

#endif

}
void EX_Interrupt_voidSetINT1(void)
{
	// Set PD3"INT1" as input pull-up
	DIO_voidSetPinDir(PORT_D,PIN_3,INPUT);
	DIO_voidSetPinValue(PORT_D,PIN_3,HIGH);
}




ISR(INT0_vect)
{
	 Motor_voidStop();
	 //Motor_voidDefault();

}







