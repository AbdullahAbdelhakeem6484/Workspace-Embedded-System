/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
//traffic light

#include"STD_Types.h"
#include"macros.h"
#include "DIO_interface.h"
#define F_CPU 12000000
#include<util/delay.h>


int main (void)
{
	DIO_voidSetPinDir(PORT_A,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_A,PIN_1,OUTPUT);
	DIO_voidSetPinDir(PORT_A,PIN_2,OUTPUT);
while(1)
{
	DIO_voidSetPinValue(PORT_A,PIN_0,HIGH);
	   _delay_ms(10000);
	DIO_voidSetPinValue(PORT_A,PIN_0,LOW);

	DIO_voidSetPinValue(PORT_A,PIN_1,HIGH);
		_delay_ms(3000);
	DIO_voidSetPinValue(PORT_A,PIN_1,LOW);

	DIO_voidSetPinValue(PORT_A,PIN_2,HIGH);
		_delay_ms(1000);
	DIO_voidSetPinValue(PORT_A,PIN_2,LOW);

	DIO_voidSetPinValue(PORT_A,PIN_1,HIGH);
		_delay_ms(3000);
	DIO_voidSetPinValue(PORT_A,PIN_1,LOW);

	DIO_voidSetPinValue(PORT_A,PIN_0,HIGH);
	   _delay_ms(10000);
	DIO_voidSetPinValue(PORT_A,PIN_0,LOW);

}

return 0;
}
