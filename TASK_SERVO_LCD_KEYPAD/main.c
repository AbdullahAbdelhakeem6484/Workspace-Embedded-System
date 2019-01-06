/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"macros.h"
#include"STD_Types.h"
#include"LCD_interface.h"
#include"DIO_interface.h"

#include<util/delay.h>
#include<avr/io.h>
#define F_CPU 12000000


int main(void)
{
	u16 i;
	u8 x,y;

	DIO_voidSetPinDir(PORT_C,PIN_0,INPUT);//keypad pushbutton to rotate left
	DIO_voidSetPinDir(PORT_C,PIN_1,INPUT);//keypad pushbutton to rotate right
	DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PULL UP
	DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PULL UP


	DIO_voidSetPinDir(PORT_C,PIN_2,OUTPUT);//signal for servo motor

	DIO_voidSetPinDir(PORT_C,PIN_7,OUTPUT);//LED

	LCD_voidInit(); //lcd initialization
	LCD_voidWriteString("Angle:");

		while(1)
		{
			x=GET_BIT(PINC,0);
			y=GET_BIT(PINC,1);
			/*if(x==0)
			{SET_BIT(PORTC,7);}
			else
			{CLEAR_BIT(PORTC,7);}*/

if(x==0){
			for( i=0;i<50;i++) //zero Angle
			{

				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
				_delay_us(60);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				_delay_us(19940);
				LCD_voidSetCursor(2, 1);
				LCD_voidWriteString("0");
			}



			for( i=0;i<50;i++)// angle 45
			{
				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
				_delay_us(100);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				_delay_us(19900);
				LCD_voidSetCursor(2, 1);
				LCD_voidWriteString("45");

	       }


			for( i=0;i<50;i++)//angle 90
			{
				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
				_delay_us(1000);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				_delay_us(19000);
				LCD_voidSetCursor(2, 1);
				LCD_voidWriteString("90");

			}


			for( i=0;i<50;i++)//angle 135
			{
				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
				_delay_us(1500);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				_delay_us(18500);
				LCD_voidSetCursor(2, 1);
				LCD_voidWriteString("135");

			}




			for( i=0;i<50;i++)//angle 180
			{
				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
				_delay_us(2000);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				_delay_us(18000);
				LCD_voidSetCursor(2, 1);
				LCD_voidWriteString("180");

			}

			LCD_voidClear();
			LCD_voidWriteString("Angle:");
			LCD_voidSetCursor(2, 1);
			LCD_voidWriteString("180");
}

			/////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////
else if(y==0)
{
			for( i=0;i<50;i++)//angle 180
			{
				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
				_delay_us(2000);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				_delay_us(18000);
				LCD_voidSetCursor(2, 1);
				LCD_voidWriteString("180");
				SET_BIT(PORTC,1);
			}

			for( i=0;i<50;i++)//angle 135
			{
				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
				_delay_us(1500);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				_delay_us(18500);
				LCD_voidSetCursor(2, 1);
				LCD_voidWriteString("135");
			}
			LCD_voidClear();
			LCD_voidWriteString("Angle:");

			for( i=0;i<50;i++)//angle 90
			{
				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
				_delay_us(1000);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				_delay_us(19000);
				LCD_voidSetCursor(2, 1);
				LCD_voidWriteString("90");
			}

			for( i=0;i<50;i++)// angle 45
			{
				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
				_delay_us(100);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				_delay_us(19900);
				LCD_voidSetCursor(2, 1);
				LCD_voidWriteString("45");
			}
			LCD_voidClear();
			LCD_voidWriteString("Angle:");

			for( i=0;i<50;i++) //zero Angle
			{
				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
				_delay_us(60);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				_delay_us(19940);
				LCD_voidSetCursor(2, 1);
				LCD_voidWriteString("0");

			}
}
else
{
	DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
}

		}
		return 0;
}




