/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#include"macros.h"
#include"STD_Types.h"
#include"DIO_interface.h"
#include"SERVO_interface.h"

int main(void)
{
	DIO_voidSetPinDir(PORT_C,PIN_2,OUTPUT);

while(1)
{
	SERVO_voidAngle(0);
	_delay_ms(1000);
	SERVO_voidAngle(45);
	_delay_ms(1000);
	SERVO_voidAngle(90);
	_delay_ms(1000);
	SERVO_voidAngle(135);
	_delay_ms(1000);
	SERVO_voidAngle(180);
	_delay_ms(1000);

}





return 0;
}
