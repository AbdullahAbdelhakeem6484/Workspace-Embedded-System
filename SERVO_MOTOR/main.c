/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */
#include"macros.h"
#include"STD_Types.h"
#include<avr/io.h>
#include"DIO_interface.h"


#include<util/delay.h>
#define F_CPU 12000000


int main(void)
{
	u32 i;

	DIO_voidSetPinDir(PORT_B,PIN_3,OUTPUT);
while(1)
{

for( i=0;i<250;i++)
{
		DIO_voidSetPinValue(PORT_B,PIN_3,HIGH);
		_delay_us(60);
		DIO_voidSetPinValue(PORT_B,PIN_3,LOW);
		_delay_us(19940);

}
for( i=0;i<250;i++)
{
		DIO_voidSetPinValue(PORT_B,PIN_3,HIGH);
		_delay_us(600);
		DIO_voidSetPinValue(PORT_B,PIN_3,LOW);
		_delay_us(19400);

}
for(i=0;i<250;i++)
{
		DIO_voidSetPinValue(PORT_B,PIN_3,HIGH);
		_delay_us(1800);
		DIO_voidSetPinValue(PORT_B,PIN_3,LOW);
		_delay_us(18200);

}
for( i=0;i<250;i++)
{
		DIO_voidSetPinValue(PORT_B,PIN_3,HIGH);
		_delay_us(500);
		DIO_voidSetPinValue(PORT_B,PIN_3,LOW);
		_delay_us(19500);

}

}



return 0;
}

