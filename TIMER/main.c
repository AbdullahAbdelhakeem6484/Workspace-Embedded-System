/*
  * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */
#include"macros.h"
#include"STD_Types.h"
#include<avr/io.h>
#include"DIO_interface.h"

#define F_CPU 12000000


//BY NEW ISR
u16 OVF_count;
u16  ms_count;
u16 desired;
u8 end_flag;
void __vector_11(void)  __attribute__((signal,__INTR_ATTRS)); //put in private.h
//OR void __vector_11(void)  __attribute__((signal,used,externally_visible));

void MS_Delay(u16 Time)
{
		TCNT0=32;

	//� Bit 6, 3 � WGM01:0: Waveform Generation Mode
			CLEAR_BIT(TCCR0,6);
			CLEAR_BIT(TCCR0,3);
	//� Bit 2:0 � CS02:0: Clock Select clkI/O/(No prescaling)
			SET_BIT(TCCR0,0);
			CLEAR_BIT(TCCR0,1);
			CLEAR_BIT(TCCR0,2);
	//� Bit 0 � TOIE0: Timer/Counter0 Overflow Interrupt Enable
			SET_BIT(TIMSK,0);

			desired=Time;
			OVF_count=0;
			ms_count=0;
			end_flag=0;

			SET_BIT(SREG,7);
			while(end_flag==0);
			CLEAR_BIT(TCCR0,0);


}

int main (void)
{
	DIO_voidSetPinDir(PORT_C,PIN_0,OUTPUT);


   while(1)
   {
			DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);
			MS_Delay(500);
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			MS_Delay(500);
   	}
return 0;
}



void __vector_11(void)
{
	OVF_count++;
	if(OVF_count==47)
	{
		OVF_count=0;
		TCNT0=32;
		ms_count++;
		if(ms_count==desired)
		{
			ms_count=0;
			end_flag=1;

		}
	}



}



/*
int main (void)
{
	TCNT0=32;
	DIO_voidSetPinDir(PORT_C,PIN_0,OUTPUT);
//� Bit 6, 3 � WGM01:0: Waveform Generation Mode
		CLEAR_BIT(TCCR0,6);
		CLEAR_BIT(TCCR0,3);
//� Bit 2:0 � CS02:0: Clock Select clkI/O/(No prescaling)
		SET_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);
//� Bit 0 � TOIE0: Timer/Counter0 Overflow Interrupt Enable
		SET_BIT(TIMSK,0);

		SET_BIT(SREG,7);

		while(1);


return 0;
}*/




//timer delay

/*
 #include"macros.h"
#include"STD_Types.h"
#include<avr/io.h>
#include"DIO_interface.h"
#include<avr/interrupt.h>
#define F_CPU 12000000

u16 OVF_count;
u16  ms_count;
u16 desired;
u8 end_flag;

void MS_Delay(u16 Time)
{
		TCNT0=32;

	//� Bit 6, 3 � WGM01:0: Waveform Generation Mode
			CLEAR_BIT(TCCR0,6);
			CLEAR_BIT(TCCR0,3);
	//� Bit 2:0 � CS02:0: Clock Select clkI/O/(No prescaling)
			SET_BIT(TCCR0,0);
			CLEAR_BIT(TCCR0,1);
			CLEAR_BIT(TCCR0,2);
	//� Bit 0 � TOIE0: Timer/Counter0 Overflow Interrupt Enable
			SET_BIT(TIMSK,0);

			desired=Time;
			OVF_count=0;
			ms_count=0;
			end_flag=0;

			SET_BIT(SREG,7);
			while(end_flag==0);
			CLEAR_BIT(TCCR0,0);


}

int main (void)
{
	DIO_voidSetPinDir(PORT_C,PIN_0,OUTPUT);


   while(1)
   {
			DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);
			MS_Delay(20);
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			MS_Delay(20);
   	}
return 0;
}



ISR(TIMER0_OVF_vect)
{
	OVF_count++;
	if(OVF_count==47)
	{
		OVF_count=0;
		TCNT0=32;
		ms_count++;
		if(ms_count==desired)
		{
			ms_count=0;
			end_flag=1;

		}
	}



}
 */