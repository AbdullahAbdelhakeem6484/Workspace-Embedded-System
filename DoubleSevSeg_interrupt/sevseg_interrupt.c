/*
 * sevseg_interrupt.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */
/*1-In the beginning seven segment begins with the countdown.
 2- After pressing the switch and pressing continue, the count will change from countdown to countup(starting from the last countdown number) .
 3- After the switch is left, countdown counts (starting from the last number in  countup)?*/

#include"macros.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#define F_CPU 12000000


int i=99;


char arr[]={0b01011111,0b00000110,0b00111011,0b00101111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
int main (void)
{
	//char arr[]={0b01011111,0b00000110,0b00111011,0b00101111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};


	// low level configuration interrupt sense ctrl 0
		 	CLEAR_BIT(MCUCR,1);
		 	CLEAR_BIT(MCUCR,0);

		 	//Enable PIE
		 	SET_BIT(GICR,6);
		 	//Enable GIE
		 	SET_BIT(SREG,7);

		 	DDRD=0b00000000;
			PORTD=0b00000100;

		// DIO_voidSetPinDir(PORT_D,PIN_2,INPUT);  //Interrupt 0 input
		 //DIO_voidSetPinValue(PORT_D,PIN_2,HIGH);  //interrupt pin pull up


DDRA=0xff;
DDRB=0xff;

while(1)
{
			i--;
			PORTA =arr[i%10]; //port A
			//_delay_ms(1000);
			PORTB=arr[i/10]; //port D
			_delay_ms(1000);
			if(i==0)
			{i=99;}
}
return 0;
}

ISR(INT0_vect)
{

		i++;
		PORTA =arr[i%10]; //port A
		//_delay_ms(1000);
		PORTB=arr[i/10]; //port D
		_delay_ms(1000);
		if(i==99)
		{i=0;}
}







































/*
int tmp1=0,tmp2=1;
int tmp3=99,tmp4=100;

char arr[]={0b01011111,0b00000110,0b00111011,0b00101111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
int main (void)
{
	//char arr[]={0b01011111,0b00000110,0b00111011,0b00101111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};


	// low level configuration interrupt sense ctrl 0
		 	CLEAR_BIT(MCUCR,1);
		 	CLEAR_BIT(MCUCR,0);

		 	//Enable PIE
		 	SET_BIT(GICR,6);
		 	//Enable GIE
		 	SET_BIT(SREG,7);

		 	DDRD=0b00000000;
			PORTD=0b00000100;

		// DIO_voidSetPinDir(PORT_D,PIN_2,INPUT);  //Interrupt 0 input
		 //DIO_voidSetPinValue(PORT_D,PIN_2,HIGH);  //interrupt pin pull up

int i=0;
int j=0;
DDRA=0xff;
DDRB=0xff;

while(1)
{
	//x=GET_BIT(PIND,2);
	if(GET_BIT(PIND,2)==1)
	{


	for(i=99;i>=0;i--)
	  {
		  for(j=100;j>=1;j--)
			{	PORTA =arr[i%10]; //port A
				_delay_ms(5);
				PORTB=arr[i/10]; //port D
				_delay_ms(5);

				tmp1=i;
				tmp2=j;


			}
	  }
    }
}

return 0;
}


ISR(INT0_vect)
{
	int k,l;
for( k=tmp1;k<=99;k++)
				{	for( l=tmp2;l<100;l++)
						{	PORTA =arr[k%10]; //port A
							_delay_ms(5);
							PORTB=arr[k/10]; //port D
							_delay_ms(5);
							if(GET_BIT(PIND,2)==1)
							{

							tmp3=k;
							tmp4=l;
							break;}

						}


				}

}





*/





















/*for(i=99;i>=tmp3;i--)
	{	  left_digit=i/10;
		  right_digit=i%10;
		  for(j=100;j>=tmp4;j--)
			{	PORTA =arr[right_digit]; //port A
				_delay_ms(5);
				PORTB=arr[left_digit]; //port D
				_delay_ms(5);
				if(GET_BIT(PIND,2)==0)
					break;
			tmp1=i;
			tmp2=j;
			}
	}


	for( i=tmp1;i<=99;i++)
			{	for( j=tmp2;j<100;j++)
					{	PORTA =arr[i%10]; //port A
						_delay_ms(5);
						PORTB=arr[i/10]; //port D
						_delay_ms(5);
						if(GET_BIT(PIND,2)==1)
							break;
						tmp3=i;
						tmp4=j;
					}


			}*/
