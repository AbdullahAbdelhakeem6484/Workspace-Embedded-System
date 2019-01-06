/*
 * calc_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef CALC_INTERFACE_H_
#define CALC_INTERFACE_H_

unsigned char read_keypad(void);

/*Alphanumeric LCD Function Declarations*/
void lcd_data_write(char data);
void lcd_command_write( char command);
void lcd_init();
void lcd_string_write( char *string);

#endif /* CALC_INTERFACE_H_ */
