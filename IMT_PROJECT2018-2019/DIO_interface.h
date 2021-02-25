/*
 * DIO_interface.h

 *
 *  Created on: Aug 11, 2018
 *      Author: Abdullah Abdelhakeem
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "DIO_interface.h"
#include <avr/io.h>
#include "std_types.h"

#define PORT_A    0
#define PORT_B    1
#define PORT_C    2
#define PORT_D    3

#define PIN_0     0
#define PIN_1     1
#define PIN_2     2
#define PIN_3     3
#define PIN_4     4
#define PIN_5     5
#define PIN_6     6
#define PIN_7     7

#define OUTPUT    1
#define INPUT     0

#define HIGH      1
#define LOW       0


void DIO_voidSetPinDir(u8 Port,u8 Pin,u8 Dir);
void DIO_voidSetPinValue(u8 Port,u8 Pin,u8 Value);
void DIO_voidTogglePinValue(u8 Port,u8 Pin);


#endif /* DIO_INTERFACE_H_ */
