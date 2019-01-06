/*
 * SERVO_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"SERVO_interface.h"

void SERVO_voidAngle(u8 angle)
{

	switch(angle)
	{
		case 0:
					for(u32 i=0;i<50;i++) //zero Angle
					{

						DIO_voidSetPinValue(SERVO_PORT,SERVO_PIN,HIGH);
						_delay_us(60);
						DIO_voidSetPinValue(SERVO_PORT,SERVO_PIN,LOW);
						_delay_us(19940);

					}
		break;

		case 45:

					for(u32 i=0;i<50;i++)// angle 45
					{
						DIO_voidSetPinValue(SERVO_PORT,SERVO_PIN,HIGH);
						_delay_us(100);
						DIO_voidSetPinValue(SERVO_PORT,SERVO_PIN,LOW);
						_delay_us(19900);


				   }
		break;

		case 90:
					for(u32 i=0;i<50;i++)//angle 90
					{
						DIO_voidSetPinValue(SERVO_PORT,SERVO_PIN,HIGH);
						_delay_us(1000);
						DIO_voidSetPinValue(SERVO_PORT,SERVO_PIN,LOW);
						_delay_us(19000);


					}
		break;

		case 135:
					for(u32 i=0;i<50;i++)//angle 135
					{
						DIO_voidSetPinValue(SERVO_PORT,SERVO_PIN,HIGH);
						_delay_us(1500);
						DIO_voidSetPinValue(SERVO_PORT,SERVO_PIN,LOW);
						_delay_us(18500);


					}
		break;


		case 180:

					for(u32 i=0;i<50;i++)//angle 180
					{
						DIO_voidSetPinValue(SERVO_PORT,SERVO_PIN,HIGH);
						_delay_us(2000);
						DIO_voidSetPinValue(SERVO_PORT,SERVO_PIN,LOW);
						_delay_us(18000);


					}
		break;
}
}
