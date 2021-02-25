/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


#include"macros.h"
#include"STD_Types.h"
#include"ADC_interface.h"
#include"DIO_interface.h"
#include<avr/interrupt.h>
#include<util/delay.h>
#include<avr/io.h>
#define F_CPU 12000000

int main(void)
{
	//Enable PIE
	SET_BIT(GICR,6);
	//Enable GIE
	SET_BIT(SREG,7);

	//RISING EDGE   EXTERNAL interrupt
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	//Special FunctionIO Register
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
	CLEAR_BIT(SFIOR,7);

	DIO_voidSetPinDir(PORT_D,PIN_2,INPUT);  //Interrupt 0 input
	DIO_voidSetPinValue(PORT_D,PIN_2,HIGH);  //interrupt pin pull up


	//voltage divider
	u16 digital,analog;
	DIO_voidSetPinDir(PORT_C,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_1,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_2,OUTPUT);
	ADC_voidInit();
	ADC_voidSelectChannel(0);
	ADC_voidStartConversion();
	while(1)
	{


		digital=ADC_u16GetCurrentValue();
		analog=(digital*500)/1024; //to be compatability
		if(analog>30)
		{
			DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);
			DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);
			DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);

		}
		else
		{	DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);

		}
	}
return 0;
}

//EXTERNAL INTERRUPT
ISR(INT0_vect)
{}
