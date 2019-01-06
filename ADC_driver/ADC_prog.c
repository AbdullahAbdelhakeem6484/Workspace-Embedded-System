/*
 * ADC_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

/*
 * ADC_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"macros.h"
#include"STD_Types.h"
#include"ADC_interface.h"

#include<avr/interrupt.h>
#include<util/delay.h>
#include<avr/io.h>
#define F_CPU 12000000

static u16 ADC_value;


u16 ADC_u16GetCurrentValue(void)
{
	return ADC_value;


}

void ADC_voidInit(void)
{
	//Enable PIE
	SET_BIT(ADCSRA,3);
	//Enable GIE global last thing open it
	SET_BIT(SREG,7);
	//ACVV
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

	CLEAR_BIT(ADMUX,5);//right adjust
	SET_BIT(ADCSRA,7);//ENABLE ADC

	CLEAR_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);


}

u16 ADC_u16GetValue(u8 channel)//CHANGE 0 TO 7
{
	u16 ADC_value;
	ADMUX&=0XE0; //ZEROS 5 BIT IN CHANNEL (clear 5 LSB)
	ADMUX|=channel;//store in register after oring with channel
	SET_BIT(ADCSRA,6);//STAR CONVERSION

	while(GET_BIT(ADCSRA,4)==0);
	SET_BIT(ADCSRA,4); //CLEAR FLAG

	ADC_value=0;
	ADC_value=ADCL; //ADC_value|=ADCL; LOW
	ADC_value|=(ADCH<<8);

	return ADC_value; //return 10


}
void ADC_voidSelectChannel(u8 channel)
{

	SET_BIT(ADCSRA,6);//STAR CONVERSION





}

void ADC_voidStartConversion(void)
{
	if(GET_BIT(ADCSRA,6)==0) //finish  conversion
	{
	SET_BIT(ADCSRA,4); //
	}

}
ISR(ADC_vect)
{
	ADC_value=0;
	ADC_value|=ADCL;
	ADC_value|=(ADCH<<8);

}
