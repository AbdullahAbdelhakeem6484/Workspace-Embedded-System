/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 12000000 //frequency oscillator

int main(void)
{
DDRC=0XFF;
while(1)
{




			int x=1;
for(x=1;x<8;x++)
{
			PORTC=	x;
			_delay_ms(500);

}




}








return 0;


}

/*
 * PORTC=0XFF;
	_delay_ms(500);
	PORTC=0X00;
	_delay_ms(1000);*/

/*
 * int x=1;

			PORTC=	x;

			if (x==0x80)
			{
				x=1;
			}
			else
			{
				x = x << 1;
			}
 * */
