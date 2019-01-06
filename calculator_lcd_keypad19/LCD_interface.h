/*
 * LCD_interface.h
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit(void);

void LCD_voidWriteCharacter(u8 Character);

void LCD_voidSendCommand(u8 Command);

void LCD_voidWriteString(u8 *string);



#endif /* LCD_INTERFACE_H_ */
