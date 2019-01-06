/*
 * keyPad_interface.h
 *
 *  Created on: Aug 18, 2018
 *      Author: Abdullah Abdelhakeem
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

void KEYPAD_voidInit(void);
u8   KEYPAD_u8GetKey(void);

u8 KEYPAD_voidInitTemp(u8 bit_1,u8 bit_2,u8 bit_3,u8 bit_4);


#define NO_KEY 0xFF   // an assumed number , can be changed 3ady

#endif /* KEYPAD_INTERFACE_H_ */
