/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"macros.h"
#include"STD_Types.h"
#include<avr/io.h>
#include"DIO_interface.h"
#include "LCD_interface.h"




int main (void)
{
	u8 x=6;
	LCD_voidInit();
	LCD_voidWriteCharacter(x+0x30); //0x30 ascii zero
	while(1);


return 0;
}

