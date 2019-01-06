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

	DIO_voidSetPinDir(PORT_A,PIN_0,OUTPUT);


while(1)
{



	Receive_Byte=UART_u8ReceiveByte();
	if(Receive_Byte=='a')
	{
		DIO_voidSetPinValue(PORT_A,PIN_0,HIGH);
	}
	else
	{
		DIO_voidSetPinValue(PORT_A,PIN_0,LOW);

	}

}



return 0;
}

