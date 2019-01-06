/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: express
 */
#include"../LIB/std_type.h"
#include"../LIB/macros.h"
#include"SPI_INTERFACE.h"
#include "UART_INTERFACE.h"
int main(void)
{
	UART_voidInit();
	SPI_voidSlaveInit();
	u8 resevied;
	while (1)
	{
		resevied=SPI_u8Transfer(0xff);
		UART_voidSendByte(resevied);
	}
	return 0;
}

