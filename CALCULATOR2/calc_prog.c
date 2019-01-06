/*
 * calc_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


/*4X4 Keypad Function Definitions*/
unsigned char read_keypad(void)
{
	unsigned char keypad_input=0xff,keypad_output=0xff;
	KEYPAD_PORT=0xfe;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
		keypad_output=0x01;
	else if(keypad_input==0xd0)
		keypad_output=0x02;
	else if(keypad_input==0xb0)
		keypad_output=0x03;
	else if(keypad_input==0x70)
		keypad_output=0x0c;
	else
		;

	KEYPAD_PORT=0xfd;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
		keypad_output=0x04;
	else if(keypad_input==0xd0)
		keypad_output=0x05;
	else if(keypad_input==0xb0)
		keypad_output=0x06;
	else if(keypad_input==0x70)
		keypad_output=0x0d;
	else
		;

	KEYPAD_PORT=0xfb;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
		keypad_output=0x07;
	else if(keypad_input==0xd0)
		keypad_output=0x08;
	else if(keypad_input==0xb0)
		keypad_output=0x09;
	else if(keypad_input==0x70)
		keypad_output=0x0e;
	else
		;

	KEYPAD_PORT=0xf7;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
		keypad_output=0x0a;
	else if(keypad_input==0xd0)
		keypad_output=0x00;
	else if(keypad_input==0xb0)
		keypad_output=0x0b;
	else if(keypad_input==0x70)
		keypad_output=0x0f;
	else
		;

	return keypad_output;
}

/*Alphanumeric LCD Function Definitions*/
void lcd_data_write(char data)
{
	LCD_CONT_PORT=_BV(LCD_EN)|_BV(LCD_RS);
	LCD_DATA_PORT=data;
	_delay_ms(1);
	LCD_CONT_PORT=_BV(LCD_RS);
	_delay_ms(1);
}

void lcd_command_write(char command)
{
	LCD_CONT_PORT=_BV(LCD_EN);
	LCD_DATA_PORT=command;
	_delay_ms(1);
	LCD_CONT_PORT=0x00;
	_delay_ms(1);
}

void lcd_init()
{
	lcd_command_write(0x38);
	lcd_command_write(0x01);
	lcd_command_write(0x06);
	lcd_command_write(0x0e);
}

void lcd_string_write(char *string)
{
	while (*string)
	lcd_data_write(*string++);
}


