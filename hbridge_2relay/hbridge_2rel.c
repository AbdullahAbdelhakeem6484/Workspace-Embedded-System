/*
 * hbridge_2rel.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


/*
 * hbridge_4trans.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"
#include<avr/io.h>

#include<util/delay.h>
#define F_CPU 12000000

int main (void)
{
	DIO_voidSetPinDir(PORT_A,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_A,PIN_1,OUTPUT);
while(1)
{


	DIO_voidSetPinValue(PORT_A,PIN_0,HIGH);
	_delay_ms(3000);
	DIO_voidSetPinValue(PORT_A,PIN_0,LOW);
	_delay_ms(2000);

	DIO_voidSetPinValue(PORT_A,PIN_1,HIGH);
	_delay_ms(3000);
	DIO_voidSetPinValue(PORT_A,PIN_1,LOW);
	_delay_ms(2000);

}

return 0;
}

