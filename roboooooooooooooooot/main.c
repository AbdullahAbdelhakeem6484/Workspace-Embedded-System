#include<avr/io.h>
#define	F_CPU	12000000
#include<util/delay.h>

/*Timer Counter 0 Function Declarations*/
void set_timercounter0_mode(unsigned char mode);
void set_timercounter0_prescaler(unsigned char prescaler_value);
void set_timercounter0_output_mode(unsigned char output_mode);
void set_timercounter0_compare_value(unsigned char compare_value);

/*Timer Counter 2 Function Declarations*/
void set_timercounter2_mode(unsigned char mode);
void set_timercounter2_prescaler(unsigned char prescaler_value);
void set_timercounter2_output_mode(unsigned char output_mode);
void set_timercounter2_compare_value(unsigned char compare_value);



int main(void)
{
	DDRB=0x08;
	/* PB3 pin of PORTB is declared output (PWM1 pin of DC Motor Driver is connected) */

	DDRD=0x80;
	/* PD7 pin of PORTD is declared output (PWM2 pin of DC Motor Driver is connected) */

	DDRC=0x0f;
	/*PC0,PC1,PC2 and PC3 pins of PortC are declared output ( i/p1,i/p2,i/p3 and i/p4 pins of DC Motor Driver are connected)*/

	set_timercounter0_mode(3);
	/*Timer counter 0 is set to fast pwm mode*/

	set_timercounter0_prescaler(4);
	/*Timer counter 0 frequency is set to 3.90625KHz*/

	set_timercounter0_output_mode(2);
	/*Timer counter 0 output mode is set  to non-inverting mode*/

	set_timercounter2_mode(3);
	/*Timer counter 2 is set to fast pwm mode*/

	set_timercounter2_prescaler(6);
	/*Timer counter 2 frequency is set to 3.90625KHz*/

	set_timercounter2_output_mode(2);
	/*Timer counter 2 output mode is set to non-inverting mode*/

	/*Start of infinite loop*/
	while(1)
	{
		set_timercounter0_compare_value(255);
		/*OCR0 register value is set to 255*/

		set_timercounter2_compare_value(255);
		/*OCR2 register value is set to 255*/

		PORTC=0x0a;
		/*Robot will move forward in forward direction*/

		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		/*Robot moves in forward direction for 4s with high speed*/

		set_timercounter0_compare_value(180);
		/*OCR0 register value is set to 180*/

		set_timercounter2_compare_value(180);
		/*OCR2 register value is set to 180*/

		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		/*Robot moves in forward direction for 4s with medium speed*/

		set_timercounter0_compare_value(100);
		/*OCR2 register value is set to 100*/

		set_timercounter2_compare_value(100);
		/*OCR2 register value is set to 100*/

		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		/*Robot moves in forward direction for 4s with low speed*/
	}
}
/*End of program*/


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
		TCCR0|=_BV(WGM00)|_BV(WGM01);
	}
	else
		;

}

void set_timercounter0_prescaler(unsigned char prescaler_value)
{
	TCCR0&=~(0x07);
	TCCR0|=prescaler_value;
}

void set_timercounter0_output_mode(unsigned char output_mode)
{
	TCCR0|=output_mode<<4;
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

/*Timer Counter 2 Function Definitions*/
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
		TCCR2|=_BV(WGM20)|_BV(WGM21);
	}
	else
		;

}

void set_timercounter2_prescaler(unsigned char prescaler_value)
{
	TCCR2&=~(0x07);
	TCCR2|=prescaler_value;
}

void set_timercounter2_output_mode(unsigned char output_mode)
{
	TCCR2|=output_mode<<4;
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
