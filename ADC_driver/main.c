/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


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
#define F_CPU 12000000

int main(void)
{    //voltage divider
	u16 digital,analog;
	DIO_voidSetPinDir(PORT_D,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_D,PIN_1,OUTPUT);
	ADC_voidInit();
	while(1)
	{
		ADC_voidSelectChannel(0);
		ADC_voidStartConversion();
		digital=ADC_u16GetCurrentValue();
		analog=(digital*5)/1024; //to be compatability
		if(analog>2)
		{	DIO_voidSetPinValue(PORT_D,PIN_0,HIGH);
			DIO_voidSetPinValue(PORT_D,PIN_1,LOW);
		}
		else
		{	DIO_voidSetPinValue(PORT_D,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_D,PIN_1,HIGH);

		}




	}




return 0;
}































/*int main(void)
{    //voltage divider
	u16 digital,analog;
	DIO_voidSetPinDir(PORT_D,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_D,PIN_1,OUTPUT);
	ADC_voidInit();
	while(1)
	{
		digital=ADC_u16GetValue(0);
		analog=(digital*5)/1024; //to be compatability
		if(analog>2)
		{	DIO_voidSetPinValue(PORT_D,PIN_0,HIGH);
			DIO_voidSetPinValue(PORT_D,PIN_1,LOW);
		}
		else
		{	DIO_voidSetPinValue(PORT_D,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_D,PIN_1,HIGH);

		}




	}














return 0;
}
 */
