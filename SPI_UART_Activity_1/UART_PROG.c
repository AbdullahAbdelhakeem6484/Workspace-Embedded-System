/*
 * UART_PROG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: express
 */
#include"../LIB/std_type.h"
#include"../LIB/macros.h"
#include<avr/io.h>
void UART_voidInit(void)
{  //Enaple Tx,Rx
SET_BIT(UCSRB,4);
SET_BIT(UCSRB,3);
    //select 8-bit Character size
CLEAR_BIT(UCSRB,2);
SET_BIT(UCSRC,2);
SET_BIT(UCSRC,1);
// set asychonnous
CLEAR_BIT(UCSRC,6);
// no proity
CLEAR_BIT(UCSRC,4);
CLEAR_BIT(UCSRC,5);
// 1 stop BIT
CLEAR_BIT(UCSRC,3);
// SEt 961 BOUD rate
UBRRH=0;
UBRRL=77;
}
void UART_voidSendByte(u8 Byte)
{
while(GET_BIT(UCSRA,5)==0);
UDR=Byte;
}
u8 UART_u8ReciveByte(void)
{

while(GET_BIT(UCSRA,7)==0);
return UDR;


}
