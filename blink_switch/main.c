/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#include"../lib/STD_Types.h"
#include"../lib/macros.h"
#include<avr/io.h>

int main (void)
{
	u8 x;
	SET_BIT(DDRC,7); //output pin_D0
	CLEAR_BIT(DDRC,0); //Input pin_A0
	SET_BIT(PORTC,0); //Pin_A0 pull up resistance
	while(1)
	{

		x=GET_BIT(PINC,0);
		if(x==0)  //pull down
		{
			SET_BIT(PORTC,7);
		}
		else
		{
			CLEAR_BIT(PORTD,0);

		}


	}

return 0;


}
