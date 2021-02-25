/*
 * TIMER02.c

 *
*   Created on: 27/11/2018
 *      Author: Abdullah Abdelhakeem
 */

#include"TIMER02_interface.h"
#include "../lib/std_types.h"
#include "../lib/macros.h"

/*Timer Counter 0 Function Definitions*/
void Timer0_voidInit(void)
{
	DIO_voidSetPinDir(PORT_B,PIN_3,OUTPUT); //OC0
}

void set_timercounter0_mode(unsigned char mode)
{
	if(mode==0)
	{
		TCCR0|=0;
	}
	else if(mode==1)
	{
		TCCR0|=_BV(WGM00);
	}
	else if(mode==2)
	{
		TCCR0|=_BV(WGM01);
	}
	else if(mode==3)
	{
		//TCCR0|=_BV(WGM00)|_BV(WGM01);
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
	}
	else
		;

}

void set_timercounter0_prescaler(unsigned char prescaler_value)//CLK/8
{
	// TCCR0&=~(0x07);
	// TCCR0|=prescaler_value;
	CLEAR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);


}

void set_timercounter0_output_mode(unsigned char output_mode)
{
	//TCCR0|=output_mode<<4;
	CLEAR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
}

void enable_timercounter0_interrupt(unsigned char interrupt_type)
{
	TIMSK|=1<<interrupt_type;
}

void disable_timercounter0_interrupt(unsigned char interrupt_type)
{
	TIMSK&=~(1<<interrupt_type);
}

void set_timercounter0_compare_value(unsigned char compare_value)
{
	OCR0=compare_value;
}
/*******************************************************/


/*******************************************************/
/*Timer Counter 2 Function Definitions*/

void Timer2_voidInit(void)
{
	DIO_voidSetPinDir(PORT_D,PIN_7,OUTPUT); //OC2
}
void set_timercounter2_mode(unsigned char mode)
{
	if(mode==0)
	{
		TCCR2|=0;
	}
	else if(mode==1)
	{
		TCCR2|=_BV(WGM20);
	}
	else if(mode==2)
	{
		TCCR2|=_BV(WGM21);
	}
	else if(mode==3)
	{
		// TCCR2|=_BV(WGM20)|_BV(WGM21);
		SET_BIT(TCCR2,6);
		SET_BIT(TCCR2,3);
	}
	else
		;

}

void set_timercounter2_prescaler(unsigned char prescaler_value)
{
	// TCCR2&=~(0x07);
	// TCCR2|=prescaler_value;
	CLEAR_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	CLEAR_BIT(TCCR2,2);
}

void set_timercounter2_output_mode(unsigned char output_mode)
{
	// TCCR2|=output_mode<<4;
	CLEAR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);
}

void enable_timercounter2_interrupt(unsigned char interrupt_type)
{
	TIMSK|=1<<(interrupt_type+6);
}

void disable_timercounter2_interrupt(unsigned char interrupt_type)
{
	TIMSK&=~(1<<(interrupt_type+6));
}

void set_timercounter2_compare_value(unsigned char compare_value)
{
	OCR2=compare_value;
}
/**********************************************************************/
