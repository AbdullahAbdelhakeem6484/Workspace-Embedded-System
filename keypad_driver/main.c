/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */
#include"STD_Types.h"
#include"macros.h"

#include"keypad_interface.h"
#include<avr/io.h>

int main(void)
{
	u8 seg[]={0b01011111,0b00000110,0b00111011,0b00101111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	KEYPAD_voidInit();
	DDRB=0xFF;
	u8 x;
	while(1)
	{
	x=KEYPAD_u8GetKey();
	if(x!=no_key)
	{
		PORTB=seg[x];
	}
	else
	{
		PORTB=0;
	}
	}

return 0;
}
