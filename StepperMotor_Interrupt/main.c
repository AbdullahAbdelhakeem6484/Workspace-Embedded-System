/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include"STEPPER_config.h"
#include"STEPPER_interface.h"
#define F_CPU 12000000

int main (void)
{
	// low level configuration intrrupt sence ctrl 0
	CLEAR_BIT(MCUCR,1);
	CLEAR_BIT(MCUCR,0);

	//Enable PIE
	SET_BIT(GICR,6);
	//Enable GIE
	SET_BIT(SREG,7);

DIO_voidSetPinDir(PORT_D,PIN_2,INPUT);  //Interrupt 0 input
DIO_voidSetPinValue(PORT_D,PIN_2,HIGH);  //interrupt pin pull up
DIO_voidSetPinDir(PORT_A,PIN_0,OUTPUT); //port A pin 0 output

stepper_voidInit();
while(1)
{


					//stepper_void360Right();
					//stepper_voidRightForever();
					DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PIN_0
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(2);

					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PIN_1
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(2);
					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);//PIN_2
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(2);
					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);//PIN_3
					_delay_ms(2);
				}

return 0;
}


ISR(INT0_vect)
{
	do{

		//stepper_void360Left();
		//stepper_voidLeftForever();
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);//PIN_3
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);//PIN_2
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PIN_1
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PIN_0
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);}
	while(GET_BIT(PIND,2)==0);

}

