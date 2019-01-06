/*
 * main.c
 *
 *   Created on: 15/11/2018
 *      Author: Abdullah Abdelhakeem
 */
#include "STD_Types.h"
#include"macros.h"
#include <avr/io.h>
#include"DIO_interface.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 12000000

u32 time_taken;
u32 distance=0;
/*calculate distance */
void ULTRASONIC_voidCalculateDistance(void)
{

 //Waveform Generation Mode Bit Description NORMAL*/
	CLEAR_BIT(TCCR1A,0);
	CLEAR_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1B,4);

	//0 0 1 clkI/O/1 (No prescaling)
	SET_BIT( TCCR1B,0);
	CLEAR_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,2);

	TCNT1H=0;
	TCNT1H=0;
   PORTD|=1<<1;
	/*SET_BIT  (PORT_D,1);//trigger HIGH*/
	_delay_us(10);
	PORTD &=~(1<<1);
   /*CLEAR_BIT (PORT_D,1);//trigger Low*/

	while(GET_BIT(PIND,2)==0);
	TCNT1=0x00; //Init counter

	while(GET_BIT(PIND,2)==1);
	TCCR1B=0x00;//Stop Timer

	time_taken=(TCNT1L|(TCNT1H<<8));
	distance = (time_taken*0.034)/2;  //distance (count_a = pulse/58;) (cm*us))



}

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


	PORTD &=~(1<<1);
	_delay_us(2);



	/*ULTRASONIC*/
	DIO_voidSetPinDir(PORT_D,PIN_1,OUTPUT); /*trigger as output */
	DIO_voidSetPinDir(PORT_D,PIN_2,INPUT); /*echo as input*/

	/*BOTH IR sensors pins are declared as input*/
	DIO_voidSetPinDir(PORT_D,PIN_3,INPUT); // RIGHT SENSOR
	DIO_voidSetPinDir(PORT_D,PIN_4,INPUT);//LEFT SENSOR

	/*motor one*/
	DIO_voidSetPinDir(PORT_C,PIN_4,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_5,OUTPUT);
	/*motor two*/
	DIO_voidSetPinDir(PORT_C,PIN_6,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_7,OUTPUT);








while(1)
{
	ULTRASONIC_voidCalculateDistance();
	if(distance>5)/*FORWARD*/
	{
		DIO_voidSetPinValue(PORT_C,PIN_4,LOW); 	/*Motor_1___pin1A*/ /*M1 & M2 RUNNING FORWARD*/
		DIO_voidSetPinValue(PORT_C,PIN_5,HIGH); /*Motor_1___pin2A*/
		DIO_voidSetPinValue(PORT_C,PIN_6,HIGH); /*Motor_2___pin1B*/
		DIO_voidSetPinValue(PORT_C,PIN_7,LOW);  /*Motor_2___pin2B*/
	}

	ULTRASONIC_voidCalculateDistance();
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

	ULTRASONIC_voidCalculateDistance();
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

	ULTRASONIC_voidCalculateDistance();
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

	ULTRASONIC_voidCalculateDistance();
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


/*
ISR(INT0_vect)
{
  if(i == 1)
  {
    TCCR1B = 0;
    time_taken = TCNT1;
    TCNT1 = 0;
    i = 0;
  }

  if(i==0)
  {
    TCCR1B |= 1<<CS10;
    i = 1;
  }
}
*/
