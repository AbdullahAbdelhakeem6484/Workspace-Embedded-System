/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#include"STD_Types.h"
#include"macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "keypad_interface.h"
#include "UART_interface.h"
#include "EEPROM_interface.h"
#include "I2C_interface.h"
#include "SERVO_interface.h"


#include<avr/io.h>

#define F_CPU 12000000
#include<util/delay.h>

void getPassword(u8 array[]);
u8 password[6];
u8 compare=0;
//u32 i;
//u32 getPassword(void);
int main(void)
{


	UART_voidInit();
	KEYPAD_voidInit();
	LCD_voidInit();
	I2C_voidInit();
	EEPROM_voidInit();
	LCD_voidClear();

	LCD_voidSetCursor (0,0);
	LCD_voidWriteString("PLS Enter Pass");

	getPassword(password);
	compare=strcmp(password,"1234");
	if(compare==0)
	{
		LCD_voidSetCursor (1 ,8);
		LCD_voidWriteString("correct");

	SERVO_voidAngle(90);
	_delay_ms(3000);
	SERVO_voidAngle(0);
	}
	else{
		LCD_voidSetCursor (1 ,8);
		LCD_voidWriteString("error");
	}
while(1)
{}

return 0;
}


void getPassword(u8 array[])
{
	s8 i;
	u8 key;
	for (i = 0; i < 4; i++)
	{
		key = KEYPAD_u8GetKey();
		if (key == '*')
		{
			LCD_voidSetCursor(1, 0);
			LCD_voidWriteString("                ");
			i = -1;
			continue;
		}
		else if ((key >= 0) && (key <= 9))
		{
			array[i] = key;
		}
		else
		{
			i -= 1;
			continue;
		}
		_delay_ms(400);
		LCD_voidSetCursor(1, i + 3);
		//LCD_voidWriteCharacter(key);
		LCD_voidWriteCharacter('*');
		//LCD_voidWrite(array);

		if (i == 4)
		{
			key = KEYPAD_u8GetKey();
			if (key == 13)
			{
				break;
			}
			else if (key == '*')
			{
				LCD_voidSetCursor(1, 0);
				LCD_voidWriteString("                ");
				i = -1;
				continue;
			}
		}
	}

}


















/*u32 getPassword(void)
{

	LCD_voidSetCursor (0,0);
	LCD_voidWriteString("PLS Enter Pass");
	for(i=0;i<4;i++)
	{
		while(password[i]==0)
		{
			password[i]=KEYPAD_u8GetKey();
		}
		if(password[i]==1)  password[i]='1';
		if(password[i]==2)  password[i]='2';
		if(password[i]==3)  password[i]='3';
		if(password[i]==4)  password[i]='4';
		if(password[i]==5)  password[i]='5';
		if(password[i]==6)  password[i]='6';
		if(password[i]==7)  password[i]='7';
		if(password[i]==8)  password[i]='8';
		if(password[i]==9)  password[i]='9';
		_delay_ms(1000);
		 LCD_voidSetCursor (1 ,i+1);
		 LCD_voidWriteCharacter('*');

	}
	if(strcmp(password,"1234")==0)
		{
		return 1;
		 	 /*LCD_voidSetCursor (1 ,6);
			LCD_voidWriteString("correct");*/
	/*	}
	else
	{
		LCD_voidSetCursor (1 ,6);
		LCD_voidWriteString("correct");

	}





}

*/





























//#define BUTTON_DELAY 400 /*define a time value of each button press */
/*void getPassword(u8 array[]);
void prepareToSend(u8 array[], u8 array2[]);


int main (void)

{

	u8 key=0;
	u8 i=0;
	u32 pass[4];

	KEYPAD_voidInit();
	LCD_voidInit();
	I2C_voidInit();
	EEPROM_voidInit();

while(1)
{
	getPassword(pass[4]);




}






return 0;
}




void getPassword(u8 array[])
{
	s8 i;
	u8 key;
	for (i = 0; i < 5; i++)
	{
		key = KEYPAD_u8GetKey();
		if (key == '*')
		{
			LCD_voidSetCursor (1, 0);
			LCD_voidWriteString("                ");
			i = -1;
			continue;
		}
		else if ((key >= 0) && (key <= 9))
		{
			array[i] = key;
		}
		else
		{
			i -= 1;
			continue;
		}
		_delay_ms(BUTTON_DELAY);
		LCD_voidSetCursor(1, i + 3);
		LCD_voidWriteCharacter('*');

		if (i == 4)
		{
			key = KEYPAD_u8GetKey();
			if (key == 13)
			{
				break;
			}
			else if (key == '*')
			{
				LCD_voidSetCursor (1, 0);
				LCD_voidWriteString("                ");
				i = -1;
				continue;
			}
		}
	}

}

void prepareToSend(u8 array[], u8 array2[])
{
	s8 i = 0;
	for (i = 0; i < 6; i++)
	{
		array2[i] = array[i];
		if (i == 5)
		{
			array2[i] = '#';
			//break;
		}
	}
}
*/
