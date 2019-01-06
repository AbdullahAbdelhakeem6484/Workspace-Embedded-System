/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


#include"STD_Types.h"
#include"macros.h"
#include "DIO_interface.h"
#define F_CPU 12000000
#include<util/delay.h>


int main (void)
{
	DIO_voidSetPinDir(PORT_C,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_1,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_2,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_3,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_4,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_5,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_6,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_7,OUTPUT);
	DIO_voidSetPinDir(PORT_A,PIN_0,OUTPUT);
while(1)
{    //pin 0,7
	DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);
	    _delay_ms(100);
	DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_7,LOW);
	//pin 1,6
	DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);
		_delay_ms(100);
	DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_6,LOW);
	//pin 2,5
	DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
		_delay_ms(100);
	DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
	//pin 3,4
	DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH);
	//PUZZER
			DIO_voidSetPinValue(PORT_A,PIN_0,HIGH);
				_delay_ms(50);
			DIO_voidSetPinValue(PORT_A,PIN_0,LOW);
			   _delay_ms(50);
			DIO_voidSetPinValue(PORT_A,PIN_0,HIGH);
				_delay_ms(50);
			DIO_voidSetPinValue(PORT_A,PIN_0,LOW);
			  _delay_ms(50);
			DIO_voidSetPinValue(PORT_A,PIN_0,HIGH);
				_delay_ms(50);
			DIO_voidSetPinValue(PORT_A,PIN_0,LOW);
			_delay_ms(50);
	//_delay_ms(1000);


	DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_4,LOW);


}

return 0;
}
