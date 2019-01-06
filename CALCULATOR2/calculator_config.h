/*
 * calculator_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef CALCULATOR_CONFIG_H_
#define CALCULATOR_CONFIG_H_

#define		KEYPAD_PORT		PORTC
/*KEYPAD_PORT is the microcontroller PORT Register to which 4X4 keypad is connected. Here it is connected to PORTC*/

#define		KEYPAD_PIN		PINC
/*KEYPAD_PIN is the microcontroller PIN Register to which 4X4 keypad is connected. Here it is connected to PINC*/

#define		LCD_DATA_PORT		PORTB
/*LCD_DATA_PORT is the microcontroller PORT Register to which the data pins of the LCD are connected. Here it is connected to PORTB*/

#define 	LCD_CONT_PORT		PORTD
/*LCD_CONT_PORT is the microcontroller PORT Register to which the control pins of the LCD are connected. Here it is connected to PORTD*/

#define 	LCD_RS 		PD0
/*LCD_RS is the microcontroller Port pin to which the RS pin of the LCD is connected. Here it is connected to PD0*/

#define 	LCD_RW 		PD1
/*LCD_RW is the microcontroller Port pin to which the RW pin of the LCD is connected. Here it is connected to PD1*/

#define 	LCD_EN 		PD2
/*LCD_EN is the microcontroller Port pin to which the EN pin of the LCD is connected. Here it is connected to PD2*/


#endif /* CALCULATOR_CONFIG_H_ */
