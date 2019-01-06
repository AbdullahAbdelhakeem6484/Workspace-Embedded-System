/*
 * DIO_INTERFACE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: express
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define Pin_0 0
#define Pin_1 1
#define Pin_2 2
#define Pin_3 3
#define Pin_4 4
#define Pin_5 5
#define Pin_6 6
#define Pin_7 7
#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0
void DIO_voidSetPinDir(u8 Port,u8 Pin, u8 Dir);
void DIO_voidSetPinValue(u8 Port,u8 Pin,u8 Value);
void DIO_voidTogglePinValue(u8 Port,u8 Pin);
u8 DIO_u8GetPinValue(u8 Port,u8 Pin);

#endif /* DIO_INTERFACE_H_ */
