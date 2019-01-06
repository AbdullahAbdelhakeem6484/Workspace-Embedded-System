/*
 * UART_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);
void UART_voidSendByte(u8 Byte);
u8 UART_u8ReceiveByte(void);
void UART_voidSendString(u8 * string);

void UART_voidReceiveString(u8 *Str);

#endif /* UART_INTERFACE_H_ */
