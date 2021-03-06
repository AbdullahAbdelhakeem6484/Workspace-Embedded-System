/*
 * LCD_prog.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */


#include"STD_Types.h"
#include"macros.h"

#define F_CPU 12000000
#include<util/delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{



	DIO_voidSetPinDir(D0_PORT,D0_PIN,OUTPUT);
	DIO_voidSetPinDir(D1_PORT,D1_PIN,OUTPUT);
	DIO_voidSetPinDir(D2_PORT,D2_PIN,OUTPUT);
	DIO_voidSetPinDir(D3_PORT,D3_PIN,OUTPUT);
	DIO_voidSetPinDir(D4_PORT,D4_PIN,OUTPUT);
	DIO_voidSetPinDir(D5_PORT,D5_PIN,OUTPUT);
	DIO_voidSetPinDir(D6_PORT,D6_PIN,OUTPUT);
	DIO_voidSetPinDir(D7_PORT,D7_PIN,OUTPUT);

	DIO_voidSetPinDir(RS_PORT,RS_PIN,OUTPUT);
	DIO_voidSetPinDir(RW_PORT,RW_PIN,OUTPUT);
	DIO_voidSetPinDir(EN_PORT,EN_PIN,OUTPUT);

	LCD_voidSendCommand(0x38);    //turn on
	_delay_ms(5);
	LCD_voidSendCommand(0x0C);   //make cursor invisible
	_delay_ms(5);

	LCD_voidSendCommand(0x01); //clear screan
	_delay_ms(5);






}

void LCD_voidWriteCharacter(u8 Character)
{


	DIO_voidSetPinValue(RS_PORT,RS_PIN,HIGH);
	DIO_voidSetPinValue(RW_PORT,RW_PIN,LOW);

	DIO_voidSetPinValue(D0_PORT,D0_PIN,GET_BIT(Character,PIN_0));
	DIO_voidSetPinValue(D1_PORT,D1_PIN,GET_BIT(Character,PIN_1));
	DIO_voidSetPinValue(D2_PORT,D2_PIN,GET_BIT(Character,PIN_2));
	DIO_voidSetPinValue(D3_PORT,D3_PIN,GET_BIT(Character,PIN_3));
	DIO_voidSetPinValue(D4_PORT,D4_PIN,GET_BIT(Character,PIN_4));
	DIO_voidSetPinValue(D5_PORT,D5_PIN,GET_BIT(Character,PIN_5));
	DIO_voidSetPinValue(D6_PORT,D6_PIN,GET_BIT(Character,PIN_6));
	DIO_voidSetPinValue(D7_PORT,D7_PIN,GET_BIT(Character,PIN_7));

	DIO_voidSetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(EN_PORT,EN_PIN,LOW);

}

void LCD_voidSendCommand(u8 Command)
{
	DIO_voidSetPinValue(RS_PORT,RS_PIN,LOW);
	DIO_voidSetPinValue(RW_PORT,RW_PIN,LOW);

	DIO_voidSetPinValue(D0_PORT,D0_PIN,GET_BIT(Command,PIN_0));
	DIO_voidSetPinValue(D1_PORT,D1_PIN,GET_BIT(Command,PIN_1));
	DIO_voidSetPinValue(D2_PORT,D2_PIN,GET_BIT(Command,PIN_2));
	DIO_voidSetPinValue(D3_PORT,D3_PIN,GET_BIT(Command,PIN_3));
	DIO_voidSetPinValue(D4_PORT,D4_PIN,GET_BIT(Command,PIN_4));
	DIO_voidSetPinValue(D5_PORT,D5_PIN,GET_BIT(Command,PIN_5));
	DIO_voidSetPinValue(D6_PORT,D6_PIN,GET_BIT(Command,PIN_6));
	DIO_voidSetPinValue(D7_PORT,D7_PIN,GET_BIT(Command,PIN_7));

	DIO_voidSetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(EN_PORT,EN_PIN,LOW);


}

void LCD_voidWriteString(u8 *string)
{

	while(*string!='\0')
	{
		LCD_voidWriteCharacter(*string);
		string++;

	}


}
void LCD_voidSetCursor(char a, char b)
{
	if(a == 1)
		LCD_voidSendCommand(0x80 + b);
	else if(a == 2)
		LCD_voidSendCommand(0xC0 + b);
}
void LCD_voidClear(void)
{
	LCD_voidSendCommand(0x01);
}

void Lcd_voidShiftRight(void)
{
	LCD_voidSendCommand(0x1C);
}

void Lcd_voidShiftLeft(void)
{
	LCD_voidSendCommand(0x18);
}

