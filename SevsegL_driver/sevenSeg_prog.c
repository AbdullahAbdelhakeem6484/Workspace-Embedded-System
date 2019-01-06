/*
 * sevenSeg_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"
#include"sevenSeg_interface.h"
#include"sevenSeg_config.h"
#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 12000000

void SEVL_voidInit(void)
{
		DIO_voidSetPinDir(B0_PORT,B0_PIN,OUTPUT);
		DIO_voidSetPinDir(B1_PORT,B1_PIN,OUTPUT);
		DIO_voidSetPinDir(B2_PORT,B2_PIN,OUTPUT);
		DIO_voidSetPinDir(B3_PORT,B3_PIN,OUTPUT);
		DIO_voidSetPinDir(B4_PORT,B4_PIN,OUTPUT);
		DIO_voidSetPinDir(B5_PORT,B5_PIN,OUTPUT);
		DIO_voidSetPinDir(B6_PORT,B6_PIN,OUTPUT);
		DIO_voidSetPinDir(B7_PORT,B7_PIN,OUTPUT);

}
void SEVL_VoidDisplayNumber(u32 number)
{
   u8 seg_code[]={0b01011111,0b00000110,0b00111011,0b00101111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
   u8 temp;
   u8 num;

   	   num=number;
	   temp = num% 10;
	   PORT =seg_code[temp];
	   _delay_ms(300);
}
