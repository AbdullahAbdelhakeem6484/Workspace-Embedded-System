/*
 * UART_prog.c
 *
 *  Created on: Sep 28, 2018
 *      Author: abdullah abdelhakeem
 */

#include"../lib/macros.h"
#include"../lib/std_types.h"


#include"UART_private.h"


void UART_voidInit(void)
{
	SET_BIT(UCSRB,3);  //TX enable
	SET_BIT(UCSRB,4);  //RX enable

	CLEAR_BIT(UCSRB,2); //8 bit char
	SET_BIT(UCSRC,2);
	SET_BIT(UCSRC,1);

	CLEAR_BIT(UCSRC,6); //asych

	CLEAR_BIT(UCSRC,5);//no parity
	CLEAR_BIT(UCSRC,4);

	CLEAR_BIT(UCSRC,3);//one stop bit

	UBRRH=0;
	UBRRL=77; //9615 bode rate
}

void UART_voidSendByte(u8 Byte)
{
	while(GET_BIT(UCSRA,5)==0);   // check udr is empty -- ready to send another byte

	UDR = Byte;
}

u8 UART_voidReceiveByte(void)
{

	while(GET_BIT(UCSRA,7)==0); // check recieve complete
	return UDR;

}























