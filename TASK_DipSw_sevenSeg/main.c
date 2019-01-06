/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */


#include"../lib/STD_Types.h"
#include"../lib/macros.h"
#include<avr/io.h>
#define F_CPU 12000000
#include<util/delay.h>

int main (void)
{
	u8 x1,x2,x3,x4;
    //7seg output  (1)
	SET_BIT(DDRD,0);
	SET_BIT(DDRD,1);
	SET_BIT(DDRD,2);
	SET_BIT(DDRD,3);
	SET_BIT(DDRD,4);
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
	//dip switch input (0)
	CLEAR_BIT(DDRA,0);
	CLEAR_BIT(DDRA,1);
	CLEAR_BIT(DDRA,2);
	CLEAR_BIT(DDRA,3);
	//pull up turn on (port high)
	SET_BIT(PORTA,0);
	SET_BIT(PORTA,1);
	SET_BIT(PORTA,2);
	SET_BIT(PORTA,3);
	while(1)
	{

		x1=GET_BIT(PINA,0);
		x2=GET_BIT(PINA,1);
		x3=GET_BIT(PINA,2);
		x4=GET_BIT(PINA,3);
	if(x1==0)  //pull down
				{
			PORTD=0b00000001; //a
			_delay_ms(150);
			PORTD=0b00000010; //b
			_delay_ms(150);
			PORTD=0b00000100; //c
			_delay_ms(150);
			PORTD=0b00001000; //d
			_delay_ms(150);
			PORTD=0b00010000; //e
			_delay_ms(150);
			/*PORTD=0b00100000; //g
			_delay_ms(500);*/
			PORTD=0b01000000; //f
			_delay_ms(150);
						}
				else
				{
					PORTD=0b00000000;
				}

		if(x2==0)  //pull up (micro out 1 when press on sw (0 out ) 1>>0 complete circuit )
				{
					PORTD=0b00000001;
					_delay_ms(150);
					PORTD=0b01000000;
					_delay_ms(150);
					PORTD=0b00010000;
					_delay_ms(150);
					PORTD=0b00001000;
					_delay_ms(150);
					PORTD=0b00000100;
					_delay_ms(150);
					PORTD=0b00000010;
					_delay_ms(150);

					/*PORTD=0b00100000;
					_delay_ms(500);*/




				}
				else
				{
					PORTD=0b00000000;
				}
		if(x3==0)  //pull up
				{
					PORTD=0b00000001; //a
					_delay_ms(150);
					PORTD=0b00000010; //b
					_delay_ms(150);
					PORTD=0b00100000; //g
					_delay_ms(150);
					PORTD=0b00010000; //e
					_delay_ms(150);
					PORTD=0b00001000; //d
					_delay_ms(150);
					PORTD=0b00000100; //c
					_delay_ms(150);
					PORTD=0b00100000; //g
					_delay_ms(150);
					PORTD=0b01000000; //f
					_delay_ms(150);



				}
				else
				{
					PORTD=0b00000000;
				}
		if(x4==0)  //pull up
				{
					PORTD=0b00000001; //a
					_delay_ms(150);
					PORTD=0b01000000; //f
					_delay_ms(150);
					PORTD=0b00100000; //g
					_delay_ms(150);
					PORTD=0b00000100; //c
					_delay_ms(150);
					PORTD=0b00001000; //d
					_delay_ms(150);
					PORTD=0b00010000; //e
					_delay_ms(150);
					PORTD=0b00100000; //g
					_delay_ms(150);
					PORTD=0b00000010; //b
					_delay_ms(150);
					}
						else
						{
							PORTD=0b00000000;
						}


	}

return 0;


}
