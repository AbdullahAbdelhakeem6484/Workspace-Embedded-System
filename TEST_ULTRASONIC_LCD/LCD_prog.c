/*
 * LCD_prog.c
 *
 *  Created on: Aug 17, 2018
 *      Author: Abdullah Abdelhakeem
 */

#include "../lib/STD_Types.h"
#include"../lib/macros.h"


#include <util/delay.h>

#include"DIO_interface.h"
#include"LCD_interface.h"

#include"LCD_config.h"


void LCD_voidInit(void)
{
	DIO_voidSetPinDir(D0_PORT ,D0_PIN ,OUTPUT);
	DIO_voidSetPinDir(D1_PORT ,D1_PIN ,OUTPUT);
	DIO_voidSetPinDir(D2_PORT ,D2_PIN ,OUTPUT);
	DIO_voidSetPinDir(D3_PORT ,D3_PIN ,OUTPUT);
	DIO_voidSetPinDir(D4_PORT ,D4_PIN ,OUTPUT);
	DIO_voidSetPinDir(D5_PORT ,D5_PIN ,OUTPUT);
	DIO_voidSetPinDir(D6_PORT ,D6_PIN ,OUTPUT);
	DIO_voidSetPinDir(D7_PORT ,D7_PIN ,OUTPUT);

	DIO_voidSetPinDir(RS_PORT,RS_PIN,OUTPUT);
	DIO_voidSetPinDir(RW_PORT,RW_PIN,OUTPUT);
	DIO_voidSetPinDir(EN_PORT,EN_PIN,OUTPUT);

	LCD_voidSendCommand(FunctionSet8bit2Line5x7Dots);
	_delay_ms(5);
	LCD_voidSendCommand(DisplayOnCursorOff);
	_delay_ms(5);
	LCD_voidSendCommand(ClearWithDDRAM);
	_delay_ms(5);



}

void LCD_voidWriteCharacter(u8 Charater)
{
	DIO_voidSetPinValue(RS_PORT,RS_PIN,HIGH);
	DIO_voidSetPinValue(RW_PORT,RW_PIN,LOW);

	DIO_voidSetPinValue(D0_PORT ,D0_PIN ,GET_BIT(Charater,PIN_0));
	DIO_voidSetPinValue(D1_PORT ,D1_PIN ,GET_BIT(Charater,PIN_1));
	DIO_voidSetPinValue(D2_PORT ,D2_PIN ,GET_BIT(Charater,PIN_2));
	DIO_voidSetPinValue(D3_PORT ,D3_PIN ,GET_BIT(Charater,PIN_3));
	DIO_voidSetPinValue(D4_PORT ,D4_PIN ,GET_BIT(Charater,PIN_4));
	DIO_voidSetPinValue(D5_PORT ,D5_PIN ,GET_BIT(Charater,PIN_5));
	DIO_voidSetPinValue(D6_PORT ,D6_PIN ,GET_BIT(Charater,PIN_6));
	DIO_voidSetPinValue(D7_PORT ,D7_PIN ,GET_BIT(Charater,PIN_7));

	DIO_voidSetPinValue(EN_PORT ,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(EN_PORT ,EN_PIN,LOW);




}

void LCD_voidSendCommand(u8 Command)
{
	DIO_voidSetPinValue(RS_PORT,RS_PIN,LOW);
	DIO_voidSetPinValue(RW_PORT,RW_PIN,LOW);

	DIO_voidSetPinValue(D0_PORT ,D0_PIN ,GET_BIT(Command,PIN_0));
	DIO_voidSetPinValue(D1_PORT ,D1_PIN ,GET_BIT(Command,PIN_1));
	DIO_voidSetPinValue(D2_PORT ,D2_PIN ,GET_BIT(Command,PIN_2));
	DIO_voidSetPinValue(D3_PORT ,D3_PIN ,GET_BIT(Command,PIN_3));
	DIO_voidSetPinValue(D4_PORT ,D4_PIN ,GET_BIT(Command,PIN_4));
	DIO_voidSetPinValue(D5_PORT ,D5_PIN ,GET_BIT(Command,PIN_5));
	DIO_voidSetPinValue(D6_PORT ,D6_PIN ,GET_BIT(Command,PIN_6));
	DIO_voidSetPinValue(D7_PORT ,D7_PIN ,GET_BIT(Command,PIN_7));

	DIO_voidSetPinValue(EN_PORT ,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(EN_PORT ,EN_PIN,LOW);

}

void LCD_voidWriteString(u8 *String)
{
    while(*String != '\0')
    {
    	LCD_voidWriteCharacter( *String);
    	String ++;
    }
}



/*void LCD_voidShiftRightAndLeft(u8* String)
{

    u8 NumberOfCharacters;
	u8 i;
	NumberOfCharacters = 1;

	while(*String != '\0' )
    {
		String ++;
    	NumberOfCharacters++;
    }


	for (i=0;i<=(16-NumberOfCharacters);i++)
	{
		_delay_ms(1500);
		LCD_voidSendCommand(ShiftDisplayRight);
	}
	for (i=0;i<=(16-NumberOfCharacters);i++)
	{
		_delay_ms(1500);
		LCD_voidSendCommand(ShiftDisplayLeft);
	}


}*/

void LCD_voidSetCursor (u8 R, u8 C)
{
	if (R == 0 && C == 0)
	{
		LCD_voidSendCommand(Row0_Coulmn0);
	}
	else if (R == 0 && C == 1)
	{
		LCD_voidSendCommand(Row0_Coulmn1);
	}
	else if (R == 0 && C == 2)
	{
		LCD_voidSendCommand(Row0_Coulmn2);
	}
	else if (R == 0 && C == 3)
	{
		LCD_voidSendCommand(Row0_Coulmn3);
	}
	else if (R == 0 && C == 4)
	{
		LCD_voidSendCommand(Row0_Coulmn4);
	}
	else if (R == 0 && C == 5)
	{
		LCD_voidSendCommand(Row0_Coulmn5);
	}
	else if (R == 0 && C == 6)
	{
		LCD_voidSendCommand(Row0_Coulmn6);
	}
	else if (R == 0 && C == 7)
	{
		LCD_voidSendCommand(Row0_Coulmn7);
	}
	else if (R == 0 && C == 8)
	{
		LCD_voidSendCommand(Row0_Coulmn8);
	}
	else if (R == 0 && C == 9)
	{
		LCD_voidSendCommand(Row0_Coulmn9);
	}
	else if (R == 0 && C == 10)
	{
		LCD_voidSendCommand(Row0_Coulmn10);
	}
	else if (R == 0 && C == 11)
	{
		LCD_voidSendCommand(Row0_Coulmn11);
	}
	else if (R == 0 && C == 12)
	{
		LCD_voidSendCommand(Row0_Coulmn12);
	}
	else if (R == 0 && C == 13)
	{
		LCD_voidSendCommand(Row0_Coulmn13);
	}
	else if (R == 0 && C == 14)
	{
		LCD_voidSendCommand(Row0_Coulmn14);
	}
	else if (R == 0 && C == 15)
	{
		LCD_voidSendCommand(Row0_Coulmn15);
	}
	else if (R == 1 && C == 0)
	{
		LCD_voidSendCommand(Row1_Coulmn0);
	}
	else if (R == 1 && C == 1)
	{
		LCD_voidSendCommand(Row1_Coulmn1);
	}
	else if (R == 1 && C == 2)
	{
		LCD_voidSendCommand(Row1_Coulmn2);
	}
	else if (R == 1 && C == 3)
	{
		LCD_voidSendCommand(Row1_Coulmn3);
	}
	else if (R == 1 && C == 4)
	{
		LCD_voidSendCommand(Row1_Coulmn4);
	}
	else if (R == 1 && C ==5)
	{
		LCD_voidSendCommand(Row1_Coulmn5);
	}
	else if (R == 1 && C == 6)
	{
		LCD_voidSendCommand(Row1_Coulmn6);
	}
	else if (R == 1 && C == 7)
	{
		LCD_voidSendCommand(Row1_Coulmn7);
	}
	else if (R == 1 && C == 8)
	{
		LCD_voidSendCommand(Row1_Coulmn8);
	}
	else if (R == 2 && C == 9)
	{
		LCD_voidSendCommand(Row1_Coulmn9);
	}
	else if (R == 1 && C == 10)
	{
		LCD_voidSendCommand(Row1_Coulmn10);
	}
	else if (R == 1 && C == 11)
	{
		LCD_voidSendCommand(Row1_Coulmn11);
	}
	else if (R == 1 && C == 12)
	{
		LCD_voidSendCommand(Row1_Coulmn12);
	}
	else if (R == 1 && C == 13)
	{
		LCD_voidSendCommand(Row1_Coulmn13);
	}
	else if (R == 1 && C == 14)
	{
		LCD_voidSendCommand(Row1_Coulmn14);
	}
	else if (R == 1 && C == 15)
	{
		LCD_voidSendCommand(Row1_Coulmn15);
	}
	else
	{
		LCD_voidSendCommand(Row0_Coulmn0);
	}



}

/*void LCD_voidSinusoidal(u8* String)
{
    while(*String != '\0')
    {
    	u8 i;
    	i=1;

    	LCD_voidSetCursor(0,0);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	i++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(1,1);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(0,2);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(1,3);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(0,4);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(1,5);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(0,6);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(1,7);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(0,8);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(1,9);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(0,10);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(1,11);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(0,12);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(1,13);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(0,14);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}
    	LCD_voidSetCursor(1,15);
    	LCD_voidWriteCharacter( *String);
    	String ++;
    	if(*String == '\0')
    	{
    		break;
    	}

    }
}*/
/*void LCD_voidMovingSinusoidalCharacter(u8 Character)
{

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(1,1);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(0,2);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(1,3);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(0,4);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(1,5);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(0,6);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(1,7);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(0,8);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(1,9);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(0,10);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(1,11);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(0,12);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(1,13);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(0,14);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(1,15);

		LCD_voidWriteCharacter(Character);
		_delay_ms(1000);
		LCD_voidSendCommand(ClearWithDDRAM);
		LCD_voidSetCursor(0,0);
	}*/


void LCD_voidWrite(u8 Num_1)
{
	switch (Num_1)
	{
	case 0 :
		LCD_voidWriteCharacter('0');

		break;
	case 1 :
		LCD_voidWriteCharacter('1');

		break;
	case 2 :
		LCD_voidWriteCharacter('2');

		break;
	case 3 :
		LCD_voidWriteCharacter('3');

		break;
	case 4 :
		LCD_voidWriteCharacter('4');

		break;
	case 5 :
		LCD_voidWriteCharacter('5');

		break;
	case 6 :
		LCD_voidWriteCharacter('6');

		break;
	case 7 :
		LCD_voidWriteCharacter('7');

		break;
	case 8 :
		LCD_voidWriteCharacter('8');

		break;
	case 9 :
		LCD_voidWriteCharacter('9');

		break;
	case '+' :
		LCD_voidWriteCharacter('+');

		break;
	case '-' :
		LCD_voidWriteCharacter('-');

		break;
	case '*' :
		LCD_voidWriteCharacter('*');

		break;
	case '/' :
		LCD_voidWriteCharacter('/');
		break;
	case '=' :
		LCD_voidWriteCharacter('=');
		break;

	}
}

void LCD_voidwriteNumber(u32 Num,u8 R,u8 C)
{
	u32 Num_1;
	u32 Num_2,Intermediate_2,Num_3,Intermediate_3,Intermediate_4,Num_4,Num_5,Intermediate_5,Num_6,Intermediate_6,Num_7;

	if(Num<10)
	{
		LCD_voidSetCursor(R,C);
		LCD_voidWrite(Num);
	}
	else if(Num >=10 && Num <100)
	{
		Num_1 = Num / 10;
		LCD_voidSetCursor(R,C);
		LCD_voidWrite(Num_1);

		Num_2 = Num % 10;
		LCD_voidSetCursor(R,C+1);
		LCD_voidWrite(Num_2);
	}
	else if(Num >=100 && Num <1000)
	{ //123
		Num_1 = Num/100; //1
		LCD_voidSetCursor(R,C);
		LCD_voidWrite(Num_1);

		Num_2 = Num % 100; //23
		Intermediate_2 = Num_2 / 10; //2
		LCD_voidSetCursor(R,C+1);
		LCD_voidWrite(Intermediate_2);

		Num_3 = Num_2 % 10; //3
    	LCD_voidSetCursor(R,C+2);
		LCD_voidWrite(Num_3);
	}
	else if(Num >=1000 && Num <10000)
	{  ///1234
		Num_1 = Num/1000; //1
		LCD_voidSetCursor(R,C);
		LCD_voidWrite(Num_1);

		Num_2 = Num % 1000;  //234
		Intermediate_2= Num_2 / 100; //2
		LCD_voidSetCursor(R,C+1);
		LCD_voidWrite(Intermediate_2);

		Intermediate_3 = Num_2 % 100; //34
		Num_3 = Intermediate_3 /10; //3
		LCD_voidSetCursor(R,C+2);
		LCD_voidWrite(Num_3);

		Num_4 = Intermediate_3 % 10; //4
		LCD_voidSetCursor(R,C+3);
		LCD_voidWrite(Num_4);
	}
	/*else if(Num >=10000 && Num <100000)
	{ //12345
		Num_1 = Num/10000; //1
		LCD_voidSetCursor(R,C);
		LCD_voidWrite(Num_1);

		Num_2 = Num % 10000;  //2345
		Intermediate_2= Num_2 / 1000; //2
		LCD_voidSetCursor(R,C+1);
		LCD_voidWrite(Intermediate_2);

		Intermediate_3 = Num_2 % 1000; //345
		Num_3 = Intermediate_3 /100; //3
		LCD_voidSetCursor(R,C+2);
		LCD_voidWrite(Num_3);

		Num_4 = Intermediate_3 % 100; //45
		Intermediate_4 = Num_4 / 10; //4
		LCD_voidSetCursor(R,C+3);
		LCD_voidWrite(Intermediate_4);

		Num_5 = Num_4 % 10;      //5
		LCD_voidSetCursor(R,C+4);
		LCD_voidWrite(Num_5);

	}
	else if(Num >=100000 && Num <1000000)
	{  //123456
		Num_1 = Num/100000; //1
		LCD_voidSetCursor(R,C);
		LCD_voidWrite(Num_1);

		Num_2 = Num % 100000;  //23456
		Intermediate_2= Num_2 / 10000; //2
		LCD_voidSetCursor(R,C+1);
		LCD_voidWrite(Intermediate_2);

		Intermediate_3 = Num_2 % 10000; //3456
		Num_3 = Intermediate_3 /1000; //3
		LCD_voidSetCursor(R,C+2);
		LCD_voidWrite(Num_3);

		Num_4 = Intermediate_3 % 1000; //456
		Intermediate_4 = Num_4 / 100; //4
		LCD_voidSetCursor(R,C+3);
		LCD_voidWrite(Intermediate_4);

		Num_5 = Num_4 % 100;      //56
		Intermediate_5 = Num_5 /10;  //5
		LCD_voidSetCursor(R,C+4);
		LCD_voidWrite(Intermediate_5);

		Num_6 = Num_5 % 10;      //6
		LCD_voidSetCursor(R,C+5);
		LCD_voidWrite(Num_6);
	}
	else if(Num >=1000000 && Num <10000000)
	{  //1234567
		Num_1 = Num/1000000; //1
		LCD_voidSetCursor(R,C);
		LCD_voidWrite(Num_1);

		Num_2 = Num % 1000000;  //234567
		Intermediate_2= Num_2 / 100000; //2
		LCD_voidSetCursor(R,C+1);
		LCD_voidWrite(Intermediate_2);

		Intermediate_3 = Num_2 % 100000; //34567
		Num_3 = Intermediate_3 /10000; //3
		LCD_voidSetCursor(R,C+2);
		LCD_voidWrite(Num_3);

		Num_4 = Intermediate_3 % 10000; //4567
		Intermediate_4 = Num_4 / 1000; //4
		LCD_voidSetCursor(R,C+3);
		LCD_voidWrite(Intermediate_4);

		Num_5 = Num_4 % 1000;      //567
		Intermediate_5 = Num_5 /100;  //5
		LCD_voidSetCursor(R,C+4);
		LCD_voidWrite(Intermediate_5);

		Intermediate_6 = Num_5 % 100;  //67
		Num_6 = Intermediate_6/10 ; //6
		LCD_voidSetCursor(R,C+5);
		LCD_voidWrite(Num_6);

		Num_7 = Intermediate_6 % 10; //7
		LCD_voidSetCursor(R,C+6);
		LCD_voidWrite(Num_7);
	}*/









}
