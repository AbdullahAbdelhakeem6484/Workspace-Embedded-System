/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include "../lib/std_types.h"
#include "../lib/macros.h"

#include "DIO_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


/*Timer Counter 0 Function Declarations*/
void set_timercounter0_mode(unsigned char mode);
void set_timercounter0_prescaler(unsigned char prescaler_value);
void set_timercounter0_output_mode(unsigned char output_mode);

void set_timercounter0_compare_value(u32 compare_value);




int main (void)
{
	/*PWM TIMER0 AND TIMER2**/
	DIO_voidSetPinDir(PORT_B,PIN_3,OUTPUT); //OC0


/*************************/
	set_timercounter0_mode(3);
	/*Timer counter 0 is set to fast pwm mode*/

	set_timercounter0_prescaler(8);
	/*Timer counter 0 frequency is set to 3.90625KHz*/

	set_timercounter0_output_mode(2);
	/*Timer counter 0 output mode is set  to non-inverting mode*/
/**************************/



while(1)
{


		set_timercounter0_compare_value(0);
		/*OCR0 register value is set to 180*/

		_delay_ms(500);
		set_timercounter0_compare_value(63);
				/*OCR0 register value is set to 180*/
		_delay_ms(500);

		set_timercounter0_compare_value(127);
						/*OCR0 register value is set to 180*/
				_delay_ms(500);
				set_timercounter0_compare_value(191);
								/*OCR0 register value is set to 180*/
						_delay_ms(500);
						set_timercounter0_compare_value(255);
														/*OCR0 register value is set to 180*/
												_delay_ms(500);





}


return 0;
}

/*****************************************************************/

/*Timer Counter 0 Function Definitions*/
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

void set_timercounter0_compare_value(u32 compare_value)
{
	OCR0= compare_value;
}




