/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */

#include"STD_Types.h"
#include"macros.h"
#include "LCD_interface.h"
#include"DIO_interface.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#define F_CPU 12000000

f32 Ton,Toff,Ttot;
u8 first_reading=1;
u8 state;
u16 freq=0;
u8 duty=0;
u32 ovf_count;
/*
int main(void)
{
	DIO_voidSetPinDir(PORT_A,PIN_0,OUTPUT);

while(1)
{

	DIO_voidSetPinValue(PORT_A,PIN_0,HIGH);
		 _delay_ms(10);
		 DIO_voidSetPinValue(PORT_A,PIN_0,LOW);
		 _delay_ms(10);




}


return 0;
}
*/



int main (void)
{


LCD_voidInit();
DIO_voidSetPinDir(PORT_D,PIN_6,INPUT);

DIO_voidSetPinDir(PORT_A,PIN_0,OUTPUT);
//DIO_voidSetPinDir(3,6,0);

TCCR1A=0;//Waveform Generation Mode Bit Description(1)

//� Bit 4:3 � WGM13:2: Waveform Generation Mode
CLEAR_BIT(TCCR1B,4);
CLEAR_BIT(TCCR1B,3);

SET_BIT(TCCR1B,6); //� Bit 6 � ICES1: Input Capture Edge Select

//Bit 2:0 � CS12:0: Clock Select
//No clock source (Timer/Counter stopped).
CLEAR_BIT(TCCR1B,2);
CLEAR_BIT(TCCR1B,1);
SET_BIT(TCCR1B,0);

//interrupt
SET_BIT(TIMSK,5);//� Bit 5 � TICIE1: Timer/Counter1, Input Capture Interrupt Enable
SET_BIT(TIMSK,2);//� Bit 2 � TOIE1: Timer/Counter1, Overflow Interrupt Enable

SET_BIT(SREG,7); //GIE



LCD_voidWriteString("freq= ");
//LCD_voidwriteNumber(freq,1,6);
LCD_voidSetCursor(2,0);
LCD_voidWriteString("duty= ");
//LCD_voidwriteNumber(duty,1,6);
while(1)
{
	Ttot=Ton+Toff;
	freq=(u16)(1/Ttot);
	duty=((u8)(Ton*100/Ttot));
	LCD_voidwriteNumber(freq,1,6);
	LCD_voidwriteNumber(duty,2,6);


	/* DIO_voidSetPinValue(PORT_A,PIN_0,HIGH);
	 _delay_ms(10);
	 DIO_voidSetPinValue(PORT_A,PIN_0,LOW);
	 _delay_ms(10);*/

}



return 0;
}



ISR(TIMER1_OVF_vect)
{

ovf_count++;

}

ISR(TIMER1_CAPT_vect)
{
	if(first_reading==1)
	{
		TCNT1=0;
		CLEAR_BIT(TCCR1B,6); //� Bit 6 � ICES1: Input Capture Edge Select
		ovf_count=0;
		state=1;
		first_reading=0;
	}
	else
	{
		if(state==1)
		{
			TCNT1=0;
			SET_BIT(TCCR1B,6); //� Bit 6 � ICES1: Input Capture Edge Select
			Ton=(f32)((ICR1+(ovf_count*65536)) *(f32)((f32)1/12000000));
			ovf_count=0;
			state=0;
		}
		else
		{
			TCNT1=0;
			CLEAR_BIT(TCCR1B,6); //� Bit 6 � ICES1: Input Capture Edge Select
			Toff=(f32)((ICR1+(ovf_count*65536)) *(f32)((f32)1/12000000));
			ovf_count=0;
			state=1;


		}



	}




}

