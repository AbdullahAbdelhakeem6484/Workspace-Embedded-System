
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

/********************code 1 password setting in EEPROM*******************/
/*
int main(void)
{

	u8 Newpass[4], Repass[4] ;



	UART_voidInit();
	LCD_voidInit();
	KEYPAD_voidInit();
	I2C_voidInit();
	EEPROM_voidInit();


*/
/****************************ENTER NEW PASSWORD***************************************/
/*	LCD_voidWriteString("Enter New Pass");

	Newpass[0]=UART_u8ReceiveByte();
	UART_voidSendByte(Newpass[0]);
	LCD_voidSetCursor (1,0);
	LCD_voidWriteCharacter(Newpass[0]);

	Newpass[1]=UART_u8ReceiveByte();
	UART_voidSendByte(Newpass[1]);
	LCD_voidSetCursor (1,1);
	LCD_voidWriteCharacter(Newpass[1]);

	Newpass[2]=UART_u8ReceiveByte();
	UART_voidSendByte(Newpass[2]);
	LCD_voidSetCursor (1,2);
	LCD_voidWriteCharacter(Newpass[2]);

	Newpass[3]=UART_u8ReceiveByte();
	UART_voidSendByte(Newpass[3]);
	LCD_voidSetCursor (1,3);
	LCD_voidWriteCharacter(Newpass[3]);

	//LCD_voidSetCursor (1,0);
	//LCD_voidWrite(Newpass);
	_delay_ms(1000);
	LCD_voidClear();*/
	/****************************RE-ENTER NEW PASSWORD***************************************/
/*	LCD_voidSetCursor (0,0);
	LCD_voidWriteString("Pls Enter Again");

	Repass[0]=UART_u8ReceiveByte();
	UART_voidSendByte(Repass[0]);
	LCD_voidSetCursor (1,0);
	LCD_voidWriteCharacter(Repass[0]);

	Repass[1]=UART_u8ReceiveByte();
	UART_voidSendByte(Repass[1]);
	LCD_voidSetCursor (1,1);
	LCD_voidWriteCharacter(Repass[1]);

	Repass[2]=UART_u8ReceiveByte();
	UART_voidSendByte(Repass[2]);
	LCD_voidSetCursor (1,2);
	LCD_voidWriteCharacter(Repass[2]);

	Repass[3]=UART_u8ReceiveByte();
	UART_voidSendByte(Repass[0]);
	LCD_voidSetCursor (1,3);
	LCD_voidWriteCharacter(Repass[3]);

	//LCD_voidSetCursor (1,0);
	//LCD_voidWrite(Repass);

	if((Newpass[0]==Repass[0])&&(Newpass[1]==Repass[1])&&(Newpass[2]==Repass[2])&&(Newpass[3]==Repass[3]))
	{


		EEPROM_voidWritByte(0,0,Repass[0]); //EEPROM_voidWritByte(u8 page,u8 location,u8 byte);
		_delay_ms(10);
		EEPROM_voidWritByte(0,1,Repass[1]);
		_delay_ms(10);
		EEPROM_voidWritByte(0,2,Repass[2]);
		_delay_ms(10);
		EEPROM_voidWritByte(0,3,Repass[3]);
		_delay_ms(10);
		_delay_ms(1000);
		LCD_voidClear();
		LCD_voidWriteString("SAVE");

	}
	else{
		_delay_ms(1000);
		LCD_voidClear();
		LCD_voidWriteString("ERROR (No Match)");

	}


while(1)
{ }



return 0;
}




*/





/***************************CODE 2 READ THE DATA WHICH THERE ARE IN EEPROM**************/
/*
int main(void)
{
	EEPROM_voidInit();
	LCD_voidInit();
	u8 x;
	x=EEPROM_u8ReadByte(0,0);  //EEPROM_u8ReadByte(u8 page,u8 location);
	LCD_voidWriteCharacter(x);
	x=EEPROM_u8ReadByte(0,1);
	LCD_voidWriteCharacter(x);
	x=EEPROM_u8ReadByte(0,2);
	LCD_voidWriteCharacter(x);
	x=EEPROM_u8ReadByte(0,3);
	LCD_voidWriteCharacter(x);







while(1)
{}


return 0;
}

*/

/*****************************SERVO MOTOR ***************************/




int main(void)
{

	//UART_voidInit();
	KEYPAD_voidInit();
	LCD_voidInit();
	I2C_voidInit();
	EEPROM_voidInit();

	DIO_voidSetPinDir(PORT_D,PIN_7,OUTPUT);
	u8 key_pressed =0;
	u8 key;
	u8 arr[4];
	u8 x[4];
	u8 i,flag=0;
//for(i=0;i<3;i++)
//{
	LCD_voidWriteString("PLS Enter Pass");
while(1)
{
	key=KEYPAD_u8GetKey();

		if(key!=no_key)
		{

			arr[0]=key;
			LCD_voidSetCursor (1,0);
			LCD_voidWrite(arr[0]);
			_delay_ms(10);


			arr[1]=key;
			LCD_voidSetCursor (1,1);
			LCD_voidWrite(arr[1]);
			_delay_ms(10);


			arr[2]=key;
			LCD_voidSetCursor (1,2);
			LCD_voidWrite(arr[2]);
			_delay_ms(10);


			arr[3]=key;
			LCD_voidSetCursor (1,3);
			LCD_voidWrite(arr[3]);
			_delay_ms(10);


		      }

/*
	arr[0]=KEYPAD_u8GetKey();
	LCD_voidSetCursor (1,0);
	LCD_voidWrite(arr[0]);
	_delay_ms(10);


	arr[1]=KEYPAD_u8GetKey();
	LCD_voidSetCursor (1,1);
	LCD_voidWrite(arr[1]);
	_delay_ms(10);


	arr[2]=KEYPAD_u8GetKey();
	LCD_voidSetCursor (1,2);
	LCD_voidWrite(arr[2]);
	_delay_ms(10);


	arr[3]=KEYPAD_u8GetKey();
	LCD_voidSetCursor (1,3);
	LCD_voidWrite(arr[3]);
	_delay_ms(10);
*/


	 //EEPROM_u8ReadByte(u8 page,u8 location);
		x[0]=EEPROM_u8ReadByte(0,0);
		x[1]=EEPROM_u8ReadByte(0,1);
		x[2]=EEPROM_u8ReadByte(0,2);
		x[3]=EEPROM_u8ReadByte(0,3);



		if((arr[0]==x[0])&&(arr[1]==x[1])&&(arr[2]==x[2])&&(arr[3]==x[3]))
			{
				LCD_voidSetCursor (1,6);
				LCD_voidWriteString("pass match");


				SERVO_voidAngle(90);
				_delay_ms(3000);
				SERVO_voidAngle(0);

				break;
			}
		else
		{
			LCD_voidSetCursor (1,6);
			LCD_voidWriteString("pass error");
		}




}
return 0;
}














/*


 for (i=0; i<3; i++)
				   {
					   scanf ("%d",&pass);
					   if(pass == 7788)
					   {
						   printf("Welcome Ahmed");
						   x = 1;
						   break;
					   }

					   else if (i<2)
					   {
						   printf("Try again: ");
					   }
				   }*/




























































/*
 // writing in page 0  (first 5  location) 1 byte
int main(void)
{
	EEPROM_voidInit();
	LCD_voidInit();
	EEPROM_voidWritByte(0,0,'A'); //EEPROM_voidWritByte(u8 page,u8 location,u8 byte);
	_delay_ms(10);
	EEPROM_voidWritByte(0,1,'b');
	_delay_ms(10);
	EEPROM_voidWritByte(0,2,'d');
	_delay_ms(10);
	EEPROM_voidWritByte(0,3,'u');
	_delay_ms(10);
	EEPROM_voidWritByte(0,4,'l');
	_delay_ms(10);
	LCD_voidWriteString("DONE");






while(1)
{}


return 0;
}


*/
/*
 // reading from page 0  (first 5  location) 1 byte

int main(void)
{
	EEPROM_voidInit();
	LCD_voidInit();
	u8 x;
	x=EEPROM_u8ReadByte(0,0);  //EEPROM_u8ReadByte(u8 page,u8 location);
	LCD_voidWriteCharacter(x);
	x=EEPROM_u8ReadByte(0,1);
	LCD_voidWriteCharacter(x);
	x=EEPROM_u8ReadByte(0,2);
	LCD_voidWriteCharacter(x);
	x=EEPROM_u8ReadByte(0,3);
	LCD_voidWriteCharacter(x);
	x=EEPROM_u8ReadByte(0,4);
	LCD_voidWriteCharacter(x);
	x=EEPROM_u8ReadByte(0,5);
	LCD_voidWriteCharacter(x);
	x=EEPROM_u8ReadByte(0,6);
	LCD_voidWriteCharacter(x);






while(1)
{}


return 0;
}
*/




//lcd with keypad
/*

int main(void)
{

	KEYPAD_voidInit();
	 LCD_voidInit();
	 u8 x;


while(1)
{
	x = KEYPAD_u8GetKey();
	LCD_voidSetCursor (0,0);
	LCD_voidWrite(x);
	//LCD_voidWriteCharacter(x);



}



return 0;
}

*/
