/*
 * UART_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


#include"STD_Types.h"
#include"macros.h"
#include "DIO_interface.h"
#include<avr/io.h>
//#include "UART_interface.h"

void UART_voidInit(void)
{
	//• Bit 4 – RXEN: Receiver Enable
	//• Bit 3 – TXEN: Transmitter Enable
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,3);

	//• Bit 2 – UCSZ2: Character Size
	//• Bit 2:1 – UCSZ1:0: Character Size
	CLEAR_BIT(UCSRB,2);
	SET_BIT(UCSRC,2);
	SET_BIT(UCSRC,1);

	//• Bit 6 – UMSEL: USART Mode Select
	CLEAR_BIT(UCSRC,6);

	//• Bit 5:4 – UPM1:0: Parity Mode
	CLEAR_BIT(UCSRC,4);
	CLEAR_BIT(UCSRC,5);

	//• Bit 3 – USBS: Stop Bit Select
	CLEAR_BIT(UCSRC,3);

	UBRRH=0;
	UBRRL=77;




}

void UART_voidSendByte(u8 Byte)
{
	while(GET_BIT(UCSRA,5)==0);
	UDR=Byte;


}
u8 UART_u8ReceiveByte(void)
{
	while(GET_BIT(UCSRA,7)==0);
	return UDR;

}

void UART_voidSendString(u8 * string)
{

	u8 i=0;
	while(string[i]!=0) //asci of null terminator is zero
	{
		UART_voidSendByte(string[i]);
		i++;


	}


}
