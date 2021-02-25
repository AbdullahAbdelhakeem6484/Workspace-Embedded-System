/*
 * ULTRASONIC.c

 *
 *   Created on: 27/11/2018
 *      Author: Abdullah Abdelhakeem
 */
#include"ULTRASONIC.h"
#include"TIMER1_interface.h"
#include"DIO_interface.h"
#include <avr/io.h>
#include "../lib/std_types.h"

f64 distance=0; //volatile f64 distance=0;
u32 count;

void ULTRASONIC_voidInit(void)
{
	/*ULTRASONIC*/
	DIO_voidSetPinDir(PORT_D,PIN_1,OUTPUT); /*trigger as output */
	DIO_voidSetPinDir(PORT_D,PIN_6,INPUT); /*echo as input*/
	DIO_voidSetPinValue(PORT_D,PIN_6,HIGH);/*PULL UP*/

}

void ULTRASONIC_voidTrigger(void)
{
	PORTD |= (1 << 1);/* Give 10us trigger pulse on trig. pin to HC-SR04 */
	_delay_us(10);
	PORTD &= (~(1 << 1));

}

void ULTRASONIC_voidCalculation(void)
{
	TIMER1_voidSet();
	count = ICR1 + (65535 * TimerOverflow);	/* Take value of capture register */
	/* 12MHz Timer freq, sound speed =343 m/s, calculation mentioned in doc. */
	distance = (double)count / 466.47;



}
