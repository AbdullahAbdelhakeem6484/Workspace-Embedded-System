/*
 * UART_interface.h
 *
 *  Created on: Sep 28, 2018
 *      Author: abdullah abdelhakeem
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_voidInit(void);

void UART_voidSendByte(u8 Byte);

u8 UART_voidReceiveByte(void);

#endif /* UART_INTERFACE_H_ */
