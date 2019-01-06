/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>

char arr[]={0b01011111,0b00000110,0b00111011,0b00101111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
int main (void)
{
	int left_digit=0;
	int right_digit=0;
	int i=0;
	int j=0;
	 DDRA=0xff;
	 DDRD=0xff;
	 DDRB=0xff;


	while(1){
	for(i=30;i>=0;i--){
	  left_digit=i/10;
	  right_digit=i%10;
	 PORTB=0B00000001;

	   for(j=100;j>=1;j--)
	   {
	   PORTA &=~(1<<7);
	   PORTD|=(1<<7);
	   PORTA =arr[right_digit];
	   _delay_ms(2);

	   PORTA|=(1<<7);
	   PORTA &=~(1<<7);
	   PORTD=arr[left_digit];
	   _delay_ms(2);


      }

	}

	for(i=10;i>=0;i--){

		  left_digit=i/10;
		  right_digit=i%10;
		 PORTB=0B00000000;
		 PORTB=0B00000010;

		   for(j=100;j>=1;j--)
		   {
		   PORTA &=~(1<<7);
		   PORTD|=(1<<7);
		   PORTA =arr[right_digit];
		   _delay_ms(2);

		   PORTA|=(1<<7);
		   PORTA &=~(1<<7);
		   PORTD=arr[left_digit];
		   _delay_ms(2);


	      }

		}
	for(i=15;i>=0;i--){

			  left_digit=i/10;
			  right_digit=i%10;
			 PORTB=0B00000000;
			 PORTB=0B00000100;


			   for(j=100;j>=1;j--)
			   {
			   PORTA &=~(1<<7);
			   PORTD|=(1<<7);
			   PORTA =arr[right_digit];
			   _delay_ms(2);

			   PORTA|=(1<<7);
			   PORTA &=~(1<<7);
			   PORTD=arr[left_digit];
			   _delay_ms(2);


		      }

			}
	for(i=5;i>=0;i--){

			  left_digit=i/10;
			  right_digit=i%10;
			 PORTB=0B00000000;
			 PORTB=0B00000010;

			   for(j=100;j>=1;j--)
			   {
			   PORTA &=~(1<<7);
			   PORTD|=(1<<7);
			   PORTA =arr[right_digit];
			   _delay_ms(2);

			   PORTA|=(1<<7);
			   PORTA &=~(1<<7);
			   PORTD=arr[left_digit];
			   _delay_ms(2);


		      }

			}


	}
	return 0;}
