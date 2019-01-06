/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"

#include<util/delay.h>
#define F_CPU 12000000

int main(void)
{

	DIO_voidSetPinDir(PORT_C,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_1,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_2,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_3,OUTPUT);

while(1)
{
	DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
	_delay_ms(2);

	DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
	_delay_ms(2);
	DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
	_delay_ms(2);
	DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);
	_delay_ms(2);



}

}
