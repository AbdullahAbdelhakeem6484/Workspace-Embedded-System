/*
 * IR_Sensor.c
 *
 *  Created on: 23/11/208
 *      Author: Abdullah Abdelhakeem
 */

#include "STD_Types.h"
#include "macros.h"
#include "DIO_interface.h"
#include "IR_Sensor.h"


void IRSensor_voidInit(void)
{
	/*BOTH IR sensors pins are declared as input*/
	DIO_voidSetPinDir(PORT_D,PIN_3,INPUT); // RIGHT SENSOR
	DIO_voidSetPinValue(PORT_D,PIN_3,HIGH);
	DIO_voidSetPinDir(PORT_D,PIN_4,INPUT);//LEFT SENSOR
	DIO_voidSetPinValue(PORT_D,PIN_4,HIGH);
}
