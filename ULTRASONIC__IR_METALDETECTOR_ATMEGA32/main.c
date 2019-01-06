/*
 * main.c
 *
 *   Created on: 16/11/2018
 *      Author: Abdullah Abdelhakeem
 */
#include "STD_Types.h"
#include"macros.h"
#include <avr/io.h>
#include"DIO_interface.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 12000000

int TimerOverflow = 0;



void Motor_voidBackword(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*Motor_1___pin1A*/
	DIO_voidSetPinValue(PORT_C,PIN_5,LOW); /*Motor_1___pin2A*/
	DIO_voidSetPinValue(PORT_C,PIN_6,LOW); /*Motor_2___pin1B*/
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);  /*Motor_2___pin2B*/
	_delay_ms(1000);

}




int main (void)
{
	f64 distance=0;
	u32 count;




	/*ULTRASONIC*/
	DIO_voidSetPinDir(PORT_D,PIN_1,OUTPUT); /*trigger as output */
	DIO_voidSetPinDir(PORT_D,PIN_6,INPUT); /*echo as input*/
	DIO_voidSetPinValue(PORT_D,PIN_6,HIGH);/*PULL UP*/

	/*BOTH IR sensors pins are declared as input*/
	DIO_voidSetPinDir(PORT_D,PIN_3,INPUT); // RIGHT SENSOR
	DIO_voidSetPinDir(PORT_D,PIN_4,INPUT);//LEFT SENSOR

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
	if(distance>5)/*FORWARD*/
	{
		DIO_voidSetPinValue(PORT_C,PIN_4,LOW); 	/*Motor_1___pin1A*/ /*M1 & M2 RUNNING FORWARD*/
		DIO_voidSetPinValue(PORT_C,PIN_5,HIGH); /*Motor_1___pin2A*/
		DIO_voidSetPinValue(PORT_C,PIN_6,HIGH); /*Motor_2___pin1B*/
		DIO_voidSetPinValue(PORT_C,PIN_7,LOW);  /*Motor_2___pin2B*/
	}

	//ULTRASONIC_voidCalculateDistance();
	if((distance<=5) &&(GET_BIT(PIND,3)==0) &&(GET_BIT(PIND,4)==1))/*left sensor is blocked*/
	{
		/*MOTOR RIGHT*/
		Motor_voidBackword();
		DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 STOP*/
		DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
		DIO_voidSetPinValue(PORT_C,PIN_6,HIGH); /*M2 FORWARD*/
		DIO_voidSetPinValue(PORT_C,PIN_7,LOW);
		_delay_ms(500);
	}

	//ULTRASONIC_voidCalculateDistance();
	if((distance<=5) &&(GET_BIT(PIND,3)==1) &&(GET_BIT(PIND,4)==0))/*right sensor is blocked*/
	{
		/*MOTOR LEFT*/
		Motor_voidBackword();
		DIO_voidSetPinValue(PORT_C,PIN_4,LOW); /*M1 FORWARD*/
		DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
		DIO_voidSetPinValue(PORT_C,PIN_6,HIGH); /*M2 STOP*/
		DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);
		_delay_ms(500);

	}

	//ULTRASONIC_voidCalculateDistance();
	if((distance<=5) &&(GET_BIT(PIND,3)==0) &&(GET_BIT(PIND,4)==0))/*both sensor is open*/
	{
		/*DEFAULT_1 MOTOR LEFT*/
		Motor_voidBackword();
		DIO_voidSetPinValue(PORT_C,PIN_4,LOW); /*M1 FORWARD*/
		DIO_voidSetPinValue(PORT_C,PIN_5,HIGH);
		DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);/*M2 STOP*/
		DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);
		_delay_ms(500);

	}

	//ULTRASONIC_voidCalculateDistance();
	if((distance<=5) &&(GET_BIT(PIND,3)==1) &&(GET_BIT(PIND,4)==1))/*both sensor is blocked*/
	{
		/*DEFAULT_1 REVERSE TO RIGHT*/
		Motor_voidBackword();
		DIO_voidSetPinValue(PORT_C,PIN_4,HIGH); /*M1 REVERSE*/
		DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
		DIO_voidSetPinValue(PORT_C,PIN_6,HIGH); /*M2 STOP*/
		DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);
		_delay_ms(1000);

	}




}


return 0;
}



ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;		/* Increment Timer Overflow count */
}
