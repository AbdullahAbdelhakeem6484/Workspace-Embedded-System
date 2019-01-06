/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */
#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#define F_CPU 12000000

int main (void)
{
	// low level configuration intrrupt sence ctrl 0
	CLEAR_BIT(MCUCR,1);
	CLEAR_BIT(MCUCR,0);

	//Enable PIE
	SET_BIT(GICR,6);
	//Enable GIE
	SET_BIT(SREG,7);

DIO_voidSetPinDir(PORT_D,PIN_2,INPUT);  //Interrupt 0 input
DIO_voidSetPinValue(PORT_D,PIN_2,HIGH);  //interrupt pin pull up
DIO_voidSetPinDir(PORT_A,PIN_0,OUTPUT); //port A pin 0 output
while(1)
{
	DIO_voidSetPinValue(PORT_A,PIN_0,LOW);  //low led
}

return 0;
}


ISR(INT0_vect)
{
	DIO_voidSetPinValue(PORT_A,PIN_0,HIGH);
}











