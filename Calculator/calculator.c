/*
 * calculator.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include"STD_Types.h"
#include"macros.h"
#define F_CPU 12000000
#include<util/delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include"keypad_interface.h"
#include"keypad_config.h"
#include"calc_interface.h"





int main(void)
{
		cal_init();
/*void cal_init(void){
KEYPAD_voidInit();
LCD_voidInit(); }*/

//void dis_string(unsigned char row, unsigned char col, char *str);
			dis_string(0,0,"Abdullah_Amer ");
			dis_string(1,4,"Happy Eid ");
/*void dis_string(unsigned char row, unsigned char col, char *str)
{
dis_position( row, col );

while (*str!='\0')		//while string pointer do not point to nothing
{
dis_char(*str);		//call dis_char functions to display what string pointer points to

++str;				//increment string pointer to point to the next character in the array
}
}*/

			_delay_ms(50);

			for (int start = 0;start < 25; ++start)
			{
				_delay_ms(5);
				//void dis_shift(char dir);
				dis_shift('L');
				/*void dis_shift(char dir)
{
	if ( dir == 'R' )
	{
		cmd(1);				//SHIFT RIGHT COMMAND 0X18
		cmd(8);
	}
	else if ( dir == 'L' )
	{
		cmd(1);				//SHIFT LEFT COMMAND 0X1C
		cmd(12);
	}
}*/
			}

    	while(1)
    	{
			calculate();
			/*void calculate(void)
{
		key = key_scan();		//obtain key pressed

		if (key != 0)			//if key = true
		{
			cal_op();			//first check if pressed key is operation identifier
			cal_run();			//store number or apply operation
			key = 0;			//clear key for next trial
		}
}
			 * */
    	}
}
