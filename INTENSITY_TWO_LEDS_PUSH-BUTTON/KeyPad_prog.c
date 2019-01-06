/*
 * KeyPad_prog.c
 *
 *  Created on: Aug 18, 2018
 *      Author: Abdullah Abdelhakeem
 */
#include "../lib/STD_Types.h"
#include "../lib/macros.h"
#include "DIO_interface.h"
#include "KeyPad_interface.h"
#include "KeyPad_config.h"
void KEYPAD_voidInit(void)
{
	DIO_voidSetPinDir(R1_PORT,R1_PIN,OUTPUT);
	DIO_voidSetPinDir(R2_PORT,R2_PIN,OUTPUT);
	DIO_voidSetPinDir(R3_PORT,R3_PIN,OUTPUT);
	DIO_voidSetPinDir(R4_PORT,R4_PIN,OUTPUT);

	DIO_voidSetPinDir(C1_PORT,C1_PIN,INPUT);
	DIO_voidSetPinDir(C2_PORT,C2_PIN,INPUT);
	DIO_voidSetPinDir(C3_PORT,C3_PIN,INPUT);
	DIO_voidSetPinDir(C4_PORT,C4_PIN,INPUT);

	DIO_voidSetPinValue(C1_PORT,C1_PIN,HIGH);   //to make each input bins with pull up ressistor
	DIO_voidSetPinValue(C2_PORT,C2_PIN,HIGH);
	DIO_voidSetPinValue(C3_PORT,C3_PIN,HIGH);
	DIO_voidSetPinValue(C4_PORT,C4_PIN,HIGH);
}
u8 KEYPAD_voidInitTemp(u8 bit_1,u8 bit_2,u8 bit_3,u8 bit_4)
{
	u8 temp;
	DIO_voidSetPinValue(R1_PORT,R1_PIN,bit_1);
	DIO_voidSetPinValue(R2_PORT,R2_PIN,bit_2);
	DIO_voidSetPinValue(R3_PORT,R3_PIN,bit_3);
	DIO_voidSetPinValue(R4_PORT,R4_PIN,bit_4);
	temp = 0;
	temp |=(DIO_u8GetPinValue(C4_PORT,C4_PIN)<<0);
	temp |=(DIO_u8GetPinValue(C3_PORT,C3_PIN)<<1);
	temp |=(DIO_u8GetPinValue(C2_PORT,C2_PIN)<<2);
	temp |=(DIO_u8GetPinValue(C1_PORT,C1_PIN)<<3);
	return temp;
}
u8   KEYPAD_u8GetKey(void)
{
	u8 temp;
	temp = KEYPAD_voidInitTemp(LOW,HIGH,HIGH,HIGH);
	switch(temp)
	{
	case 0x0E:
		return '*';
	case 0x0D:
		return '#';
	case 0x0B:
		return 0;
	case 0x07:
		return '=';
	}
	temp = KEYPAD_voidInitTemp(HIGH,LOW,HIGH,HIGH);
	switch(temp)
	{
	case 0x0E:
		return '/';
	case 0x0D:
		return 9;
	case 0x0B:
		return 8;
	case 0x07:
		return 7 ;
	}
	temp = KEYPAD_voidInitTemp(HIGH,HIGH,LOW,HIGH);
	switch(temp)
	{
	case 0x0E:
		return '-';
	case 0x0D:
		return 6;
	case 0x0B:
		return 5;
	case 0x07:
		return 4;
	}
	temp = KEYPAD_voidInitTemp(HIGH,HIGH,HIGH,LOW);
	switch(temp)
	{
	case 0x0E:
		return '+';
	case 0x0D:
		return 3;
	case 0x0B:
		return 2;
	case 0x07:
		return 1;
	}
return NO_KEY;
}
