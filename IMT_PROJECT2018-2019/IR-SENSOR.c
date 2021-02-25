/*
 * IR-SENSOR.c

 *
 *   Created on: 27/11/2018
 *      Author: Abdullah Abdelhakeem
 */
#include"IR-SENSOR.h"
#include "DIO_interface.h"
#include <avr/io.h>
void IR_Right_SENSOR_voidInit(void)
{
	/*BOTH IR sensors pins are declared as input*/
		DIO_voidSetPinDir(PORT_D,PIN_3,INPUT); // RIGHT SENSOR
		DIO_voidSetPinValue(PORT_D,PIN_3,HIGH);


}
void IR_Left_SENSOR_voidInit(void)
{
	DIO_voidSetPinDir(PORT_D,PIN_4,INPUT);//LEFT SENSOR
	DIO_voidSetPinValue(PORT_D,PIN_4,HIGH);
}
