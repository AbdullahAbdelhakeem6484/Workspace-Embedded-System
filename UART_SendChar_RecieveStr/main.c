/*
 * main.c
 *
 *  Created on: 28/9/2018
 *      Author: Abdullah Abdlhakeem
 */
#include"STD_Types.h"
#include"macros.h"
#include "DIO_interface.h"
#include "UART_interface.h"

#define F_CPU 12000000
#include<util/delay.h>




int main(void)
{



	u8 Receive_Byte;
	UART_voidInit();

	DIO_voidSetPinDir(PORT_B,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_B,PIN_1,OUTPUT);
	DIO_voidSetPinDir(PORT_B,PIN_2,OUTPUT);
	DIO_voidSetPinDir(PORT_B,PIN_3,OUTPUT);


while(1)
{



	Receive_Byte=UART_u8ReceiveByte();
	if(Receive_Byte=='a')
	{
		UART_voidSendString("Apple ");
		DIO_voidSetPinValue(PORT_B,PIN_0,HIGH);
		DIO_voidSetPinValue(PORT_B,PIN_1,LOW);
		DIO_voidSetPinValue(PORT_B,PIN_2,LOW);
		DIO_voidSetPinValue(PORT_B,PIN_3,LOW);
	}
	else if(Receive_Byte=='b')
		{
			UART_voidSendString(" Book ");
			DIO_voidSetPinValue(PORT_B,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_B,PIN_1,HIGH);
			DIO_voidSetPinValue(PORT_B,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_B,PIN_3,LOW);
		}
	else if(Receive_Byte=='c')
		{
			UART_voidSendString(" Car ");
			DIO_voidSetPinValue(PORT_B,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_B,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_B,PIN_2,HIGH);
			DIO_voidSetPinValue(PORT_B,PIN_3,LOW);
		}
	else if(Receive_Byte=='d')
		{
			UART_voidSendString(" dog ");
			DIO_voidSetPinValue(PORT_B,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_B,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_B,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_B,PIN_3,HIGH);
		}



	else
	{
		DIO_voidSetPinValue(PORT_B,PIN_0,LOW);
		DIO_voidSetPinValue(PORT_B,PIN_1,LOW);
		DIO_voidSetPinValue(PORT_B,PIN_2,LOW);
		DIO_voidSetPinValue(PORT_B,PIN_3,LOW);

	}

}



return 0;
}

