/*
 * main.c
 *
 *   Created on: 16/11/2018
 *      Author: Abdullah Abdelhakeem
 */
#include "STD_Types.h"
#include "macros.h"

#include "DIO_interface.h"
#include "ULTRASONIC.h"
#include "IR_Sensor.h"
#include "EX_Interrupt_config.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "MOTOR_interface.h"
#define F_CPU 12000000



u32 TimerOverflow = 0;
int main (void)
{
	f64 distance=0;
	u32 count;

	ULTRASONIC_voidInit(); //ultrasonic sensor
	IRSensor_voidInit(); //ir sensor
	Motor_voidInit(); //motor
	EX_Interrupt_voidInitINT0();//initialization interrupt 0
	EX_Interrupt_voidSetINT0();//set INT0

	SET_BIT(SREG,7);				/* Enable global interrupt SET_BIT(SREG,7)=sei();	 */
	TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
	TCCR1A = 0;				/* Set all bit to zero Normal operation */

while(1)
{

	ULTRASONIC_voidTrigger();



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



	if(distance>10)
		{
			Motor_voidForward();
		}

	if((distance<=10) &&(GET_BIT(PIND,3)==1) &&(GET_BIT(PIND,4)==0))/*right sensor is blocked*/
		{
			Motor_voidRight();
		}


	if((distance<=10) &&(GET_BIT(PIND,3)==0) &&(GET_BIT(PIND,4)==1))/*left sensor is blocked*/
		{

			Motor_voidLeft();
		}
	if((distance<=10) &&(GET_BIT(PIND,3)==0) &&(GET_BIT(PIND,4)==0))/*both sensor are blocked*/
		{
			Motor_voidBackword();
		}

	if((distance<=10) &&(GET_BIT(PIND,3)==1) &&(GET_BIT(PIND,4)==1))/*both sensor are opened*/
		{
			Motor_voidLeft();
		}



}


return 0;
}



ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;		/* Increment Timer Overflow count */
}

ISR(INT0_vect)
{
	Motor_voidStop();
	_delay_ms(1000);
}
