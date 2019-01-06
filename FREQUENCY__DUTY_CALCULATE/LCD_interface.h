/*
 * LCD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit(void);
void LCD_voidWriteCharacter(u8 Character);
void LCD_voidSendCommand(u8 Command);
void LCD_voidWriteString(u8 *string);

void LCD_voidSetCursor(char a, char b);
void LCD_voidClear(void);
void Lcd_voidShiftRight(void);
void Lcd_voidShiftLeft(void);
void LCD_voidWrite(u8 Num_1);
void LCD_voidwriteNumber(u32 Num,u8 R,u8 C);


#endif /* LCD_INTERFACE_H_ */
