/*

 * motor.c
 *
 *  Created on: 23/11/208
 *      Author: Abdullah Abdelhakeem
 */
#include "STD_Types.h"
#include "macros.h"
#include "DIO_interface.h"
#include <util/delay.h>

#include "MOTOR_interface.h"
#define F_CPU 12000000


void Motor_voidInit(void)
{
	/*motor one*/
	DIO_voidSetPinDir(PORT_C,PIN_4,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_5,OUTPUT);
	/*motor two*/
	DIO_voidSetPinDir(PORT_C,PIN_6,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_7,OUTPUT);



}

void Motor_voidBackword(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_6,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);


}

void Motor_voidForward(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_7,LOW);

}

void Motor_voidRight(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 stop*/
	DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_6,HIGH); /*M2 forward*/
	DIO_voidSetPinValue(PORT_C,PIN_7,LOW);

}

void Motor_voidLeft(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 FORWARD*/
	DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);/*M2 STOP*/
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);

 }

void Motor_voidStop(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 FORWARD*/
	DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);/*M2 STOP*/
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);

 }

void Motor_voidDefault(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH);   /*rotate*/
	DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_6,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);


}








