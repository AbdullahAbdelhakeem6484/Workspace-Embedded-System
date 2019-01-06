/*
 * LCD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void port(char cmd_port);
void mode_select(char m);
void enb_tri(void);
void set_port(void);
void cmd(char cmd_data);
void lcd_init(void);
void dis_char(char data);
void dis_position(char i, char j);
void clr_dis(void);
void dis_string(unsigned char row, unsigned char col, char *str);
void dis_shift(char dir);

#endif /* LCD_INTERFACE_H_ */
