/*
 * MOTOR.c



 *
 *   Created on: 27/11/2018
 *      Author: Abdullah Abdelhakeem
 */
#include"MOTOR.h"
void MOTOR_voidInit(void)
{
	/*motor one output*/
	DIO_voidSetPinDir(PORT_C,PIN_4,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_5,OUTPUT);
	/*motor two output*/
	DIO_voidSetPinDir(PORT_C,PIN_6,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_7,OUTPUT);
}
void Motor_voidBackword(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,LOW); /*M1 RUN REVERSE*/
	DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_6,LOW); /*M1 RUN REVERSE*/
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);


}
void Motor_voidFORWARD(void)
    {
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH);/*M1 RUN FORWARD*/
	DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);/*M1 RUN FORWARD*/
	DIO_voidSetPinValue(PORT_C,PIN_7,LOW);

    }

void Motor_voidRIGHT(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,LOW); /*M1 RUN REVERSE*/
	DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_6,HIGH); /*M2 RUN FORWARD*/
	DIO_voidSetPinValue(PORT_C,PIN_7,LOW);
	//_delay_ms(1000);
}

void Motor_voidLEFT(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 RUN FORWARD*/
	DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_6,LOW);/*M2 RUN REVERSE*/
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);
	//_delay_ms(1000);

}

void Motor_voidStop(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 STOP*/
	DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);/*M2 STOP*/
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);
	_delay_ms(1000);


}
void Motor_voidDefault(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 RUN FORWARD*/
	DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_6,LOW); /*M2 RUN REVERSE*/
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);
	_delay_ms(1500);



}


