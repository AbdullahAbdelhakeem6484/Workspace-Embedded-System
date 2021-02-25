/*
 * main.c
 *
 *   Created on: 27/11/2018
 *      Author: Abdullah Abdelhakeem
 */
#include "../lib/std_types.h"
#include "../lib/macros.h"
#include "ultrasonic.h"
#include "timer.h"
#include "DIO_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 12000000UL





u8 sensor_working=0;
u8 rising_edge=0;
u32 timer_counter=0;
u32 distance;

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
	/*PWM TIMER0 AND TIMER2*/
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
/*******************************************/
	/*motor one*/
	DIO_voidSetPinDir(PORT_C,PIN_4,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_5,OUTPUT);
	/*motor two*/
	DIO_voidSetPinDir(PORT_C,PIN_6,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_7,OUTPUT);

/*****************************************/
while(1)
{
	ultrasonic_init();
	ultrasonic_triger();
	if(distance>10)
	{
			set_timercounter0_compare_value(130);
			/*OCR0 register value is set to 180*/

			set_timercounter2_compare_value(130);
			/*OCR2 register value is set to 180*/
			Motor_voidFORWARD();
			_delay_ms(2000);
	}
	if(distance<10)
	{


			set_timercounter0_compare_value(110);
			/*OCR0 register value is set to 180*/

			set_timercounter2_compare_value(110);
			/*OCR2 register value is set to 180*/
			Motor_voidBackword();
			_delay_ms(2000);
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

/******************ultrasonic****************/
void ultrasonic_init(void){

  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  enable_ex_interrupt();
  timer0_init();
  return;
}

void enable_ex_interrupt(void){

  MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
  GICR  |= (1<<INT1);			// Enable INT1 interrupts.

  return;
}

void ultrasonic_triger(void){
  if(!sensor_working){
    TRIGER_PORT|=(1<<TRIGER);
    _delay_us(15);
    TRIGER_PORT&=~(1<<TRIGER);
    sensor_working=1;
  }
}

ISR(INT1_vect){
  if(sensor_working==1){
    if(rising_edge==0){
      TCNT0=0x00;
      rising_edge=1;
      timer_counter=0;
    }
  else{
    distance=(timer_counter*256+TCNT0)/466;
    //lcd_goto_xy(1,0);
  	//itoa(distance,distance_str,10);
  	//strcat(distance_str, " cm ");
  	//lcd_write_word(distance_str);
  	//_delay_ms(40);
    timer_counter=0;
    rising_edge=0;
  }
}}

ISR(TIMER0_OVF_vect){
    timer_counter++;
    if(timer_counter >730){
      TCNT0=0x00;
      sensor_working=0;
      rising_edge=0;
      timer_counter=0;
    }
}



/*********timer***************/
void timer0_init(void)
{
	    	/* Disable Timer 0 */
	    	TCCR0 = DISABLE_MODULE_VALUE;
	    	/* Setting pre scaler */
	    	TCCR0 = (PRESCLR1_VALUE);
	    	/* Initializing the timer with zero */
	    	TCNT0 = ZER0_INITIALIZER;
				/* Timer overflow interrupt enable*/
				TIMSK |=(1<<TOIE0);

	return;
}
