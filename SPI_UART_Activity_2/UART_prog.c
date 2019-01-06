/*
 * UART_prog.c
 *
 *  Created on: Sep 28, 2018
 *      Author: hassan
 */
#include "std_type.h"
#include"macros.h"
#include<avr/io.h>



void UART_voidInit(void)
{
	// ENABLE TX,RX
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,8);

	//SELECT 8-BIT CHARCTER SIZE
	 CLEAR_BIT(UCSRB,2);
	 SET_BIT(UCSRC,2);
	 SET_BIT(UCSRC,1);

	 // SET ASSYNC
	 CLEAR_BIT(UCSRC,6);
	 // NO PURITY
	 CLEAR_BIT(UCSRC,4);
	 CLEAR_BIT(UCSRC,5);

	 // 1 STOP BIT
	 CLEAR_BIT(UCSRC,3);
	 // SET BIT RATE
	 UBRRH=0;
	 UBRRL=77;
}

void UART_voidSendByte(u8 Byte)
{

while (GET_BIT(UCSRA,5)==0);
UDR=Byte;
}

u8 UART_u8RecieveByte(void)
{
	while (GET_BIT(UCSRA,7)==0);
	return UDR ;

}

