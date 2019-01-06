/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"macros.h"
#include"STD_Types.h"
#include"ADC_interface.h"
#include"DIO_interface.h"
#include<avr/interrupt.h>
#include<util/delay.h>
#include<avr/io.h>
#define F_CPU 12000000
char arr[]={0b01011111,0b00000110,0b00111011,0b00101111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
int main(void)
{

	DDRB=0xff;
	DDRC=0xff;







	//Enable PIE
	SET_BIT(GICR,6);
	//Enable GIE
	SET_BIT(SREG,7);

	//RISING EDGE   EXTERNAL interrupt
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	//Special FunctionIO Register
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
	CLEAR_BIT(SFIOR,7);



	DIO_voidSetPinDir(PORT_D,PIN_2,INPUT);  //Interrupt 0 input
	DIO_voidSetPinValue(PORT_D,PIN_2,HIGH);  //interrupt pin pull up


	//voltage divider
	u16 digital,analog;
	DIO_voidSetPinDir(PORT_D,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_D,PIN_1,OUTPUT);
	ADC_voidInit();
	ADC_voidSelectChannel(0);
	ADC_voidStartConversion();
	while(1)
	{


		digital=ADC_u16GetCurrentValue();
		analog=(digital*500)/1024; //to be compatability
		if(analog>2)
		{
			PORTB =arr[analog %10]; //port B
			_delay_ms(5);
			PORTC=arr[analog /10]; //port C
			_delay_ms(5);
		}
		else
		{	DIO_voidSetPinValue(PORT_D,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_D,PIN_1,HIGH);

		}




	}




return 0;
}
ISR(INT0_vect)
{}































/*int main(void)
{    //voltage divider
	u16 digital,analog;
	DIO_voidSetPinDir(PORT_D,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_D,PIN_1,OUTPUT);
	ADC_voidInit();
	while(1)
	{
		digital=ADC_u16GetValue(0);
		analog=(digital*5)/1024; //to be compatability
		if(analog>2)
		{	DIO_voidSetPinValue(PORT_D,PIN_0,HIGH);
			DIO_voidSetPinValue(PORT_D,PIN_1,LOW);
		}
		else
		{	DIO_voidSetPinValue(PORT_D,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_D,PIN_1,HIGH);

		}




	}














return 0;
}
 */
