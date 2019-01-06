/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


/*
 * main.c
 *
 *   Created on: 27/11/2018
 *      Author: Abdullah Abdelhakeem
 */
#include "../lib/std_types.h"
#include "../lib/macros.h"

#include "DIO_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int TimerOverflow = 0;



void Motor_voidBackword(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,LOW); /*Motor_1___pin1A*/
	DIO_voidSetPinValue(PORT_C,PIN_5,HIGH); /*Motor_1___pin2A*/
	DIO_voidSetPinValue(PORT_C,PIN_6,LOW); /*Motor_2___pin1B*/
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);  /*Motor_2___pin2B*/


}
void Motor_voidFORWARD(void)
    {
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_7,LOW);

    }

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


int main (void)
{
	f64 distance=0; //volatile f64 distance=0;
	u32 count;


	/*PWM TIMER0 AND TIMER2**/
	DIO_voidSetPinDir(PORT_B,PIN_3,OUTPUT); //OC0
	DIO_voidSetPinDir(PORT_D,PIN_7,OUTPUT); //OC2

/*************************/
	set_timercounter0_mode(3);
	/*Timer counter 0 is set to fast pwm mode*/

	set_timercounter0_prescaler(8);
	/*Timer counter 0 frequency is set to 3.90625KHz*/

	set_timercounter0_output_mode(2);
	/*Timer counter 0 output mode is set  to non-inverting mode*/
/**************************/
	set_timercounter2_mode(3);
	/*Timer counter 2 is set to fast pwm mode*/

	set_timercounter2_prescaler(8);
	/*Timer counter 2 frequency is set to 3.90625KHz*/

	set_timercounter2_output_mode(2);
	/*Timer counter 2 output mode is set to non-inverting mode*/





	/*ULTRASONIC*/
	DIO_voidSetPinDir(PORT_D,PIN_1,OUTPUT); /*trigger as output */
	//DIO_voidSetPinDir(PORT_D,PIN_6,INPUT); /*echo as input*/
	DIO_voidSetPinValue(PORT_D,PIN_6,HIGH);/*PULL UP*/

	/*BOTH IR sensors pins are declared as input*/
	DIO_voidSetPinDir(PORT_D,PIN_3,INPUT); // RIGHT SENSOR
	DIO_voidSetPinValue(PORT_D,PIN_3,HIGH);
	DIO_voidSetPinDir(PORT_D,PIN_4,INPUT);//LEFT SENSOR
	DIO_voidSetPinValue(PORT_D,PIN_4,HIGH);

	/*motor one*/
	DIO_voidSetPinDir(PORT_C,PIN_4,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_5,OUTPUT);
	/*motor two*/
	DIO_voidSetPinDir(PORT_C,PIN_6,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_7,OUTPUT);

	sei();					/* Enable global interrupt SET_BIT(SREG,7) */
	TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
	TCCR1A = 0;				/* Set all bit to zero Normal operation */








while(1)
{

	PORTD |= (1 << 1);/* Give 10us trigger pulse on trig. pin to HC-SR04 */
	_delay_us(10);
	PORTD &= (~(1 << 1));


	TCNT1 = 0;			/* Clear Timer counter */
	TCCR1B = 0x41;		/* Setting for capture rising edge, No pre-scaler*/
	TIFR = 1<<ICF1;		/* Clear ICP flag (Input Capture flag) */
	TIFR = 1<<TOV1;		/* Clear Timer Overflow flag */

	/*Calculate width of Echo by Input Capture (ICP) on PortD PD6 */

	while ((TIFR & (1 << ICF1)) == 0);	/* Wait for rising edge */
	TCNT1 = 0;			/* Clear Timer counter */
	TCCR1B = 0x01;		/* Setting for capture falling edge, No pre-scaler */
	TIFR = 1<<ICF1;		/* Clear ICP flag (Input Capture flag) */
	TIFR = 1<<TOV1;		/* Clear Timer Overflow flag */
	TimerOverflow = 0;	/* Clear Timer overflow count */

	while ((TIFR & (1 << ICF1)) == 0); /* Wait for falling edge */
	count = ICR1 + (65535 * TimerOverflow);	/* Take value of capture register */
	/* 12MHz Timer freq, sound speed =343 m/s, calculation mentioned in doc. */
	distance = (double)count / 466.47;


	//ULTRASONIC_voidCalculateDistance();
	if(distance>10)/*FORWARD*/
		{
			set_timercounter0_compare_value(180);
			/*OCR0 register value is set to 180*/

			set_timercounter2_compare_value(180);
			/*OCR2 register value is set to 180*/
			Motor_voidFORWARD();
		}


	//ULTRASONIC_voidCalculateDistance();
		if((distance<=10) &&(GET_BIT(PIND,3)==1) &&(GET_BIT(PIND,4)==0))/*right sensor is blocked*/
		{
			set_timercounter0_compare_value(180);
			/*OCR0 register value is set to 180*/

			set_timercounter2_compare_value(180);
			/*OCR2 register value is set to 180*/

			DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 FORWARD*/
			DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
			DIO_voidSetPinValue(PORT_C,PIN_6,HIGH); /*M2 STOP*/
			DIO_voidSetPinValue(PORT_C,PIN_7,LOW);


		}

		//ULTRASONIC_voidCalculateDistance();
		if((distance<=10) &&(GET_BIT(PIND,3)==0) &&(GET_BIT(PIND,4)==1))/*both sensor is open*/
		{
			set_timercounter0_compare_value(180);
			/*OCR0 register value is set to 180*/

			set_timercounter2_compare_value(180);
			/*OCR2 register value is set to 180*/

			DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 FORWARD*/
			DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);/*M2 STOP*/
			DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);


		}
		if((distance<=10) &&(GET_BIT(PIND,3)==0) &&(GET_BIT(PIND,4)==0))
		    {
				set_timercounter0_compare_value(180);
				/*OCR0 register value is set to 180*/

				set_timercounter2_compare_value(180);
				/*OCR2 register value is set to 180*/
				Motor_voidBackword();
		    }

		if((distance<=10) &&(GET_BIT(PIND,3)==1) &&(GET_BIT(PIND,4)==1))
		    {
				set_timercounter0_compare_value(180);
				/*OCR0 register value is set to 180*/

				set_timercounter2_compare_value(180);
				/*OCR2 register value is set to 180*/

				DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 FORWARD*/
				DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
				DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);/*M2 STOP*/
				DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);
		    }



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

void set_timercounter0_compare_value(unsigned char compare_value)
{
	OCR0=compare_value;
}
/*******************************************************/


/*******************************************************/
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


ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;		/* Increment Timer Overflow count */
}
