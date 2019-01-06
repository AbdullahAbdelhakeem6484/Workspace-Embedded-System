/*
 * ULTRASONIC.c
 *
 *  Created on: 23/11/208
 *      Author: Abdullah Abdelhakeem
 */
#include "STD_Types.h"
#include "macros.h"
#include "DIO_interface.h"
#include"ULTRASONIC.h"

#include <util/delay.h>
#define F_CPU 12000000
#include <avr/io.h>
void ULTRASONIC_voidInit(void)
{
	DIO_voidSetPinDir(PORT_D,PIN_1,OUTPUT); /*trigger as output */
	//DIO_voidSetPinDir(PORT_D,PIN_6,INPUT); /*echo as input*/
	DIO_voidSetPinValue(PORT_D,PIN_6,HIGH);/*PULL UP*/

}
void ULTRASONIC_voidTrigger(void)
{
	PORTD |= (1 << 1);/* Give 10us trigger pulse on trig. pin to HC-SR04 */
	_delay_us(10);
	PORTD &= (~(1 << 1));
}
