/*
 * keypad.h
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

//connect colum with lower nibble and rows with upper nibble
#define key_port PORTA
#define key_ddr DDRA
#define key_pin PINA

char takekey();


#endif /* KEYPAD_H_ */
