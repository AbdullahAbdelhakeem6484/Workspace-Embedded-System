/*
 * ADC_prog.c
 *
 *  Created on: ??˛/??˛/????
 *      Author: Fly labs
 */

/*
 * ADC_prog.c
 *
 *  Created on: ??˛/??˛/????
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
	//Enable PIE  ADC Interrupt Enable
	SET_BIT(ADCSRA,3);
	//Enable GIE global last thing open it
	SET_BIT(SREG,7);
	//ACVV 0 1 AVCC with external capacitor at AREF pin 7-6
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

	CLEAR_BIT(ADMUX,5);//right adjust
	SET_BIT(ADCSRA,7);//ENABLE ADC
// ADC Prescaler Select Bits (division factor=4)
	CLEAR_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);

	SET_BIT(ADCSRA,5); //AUTO TRIGGER ENABLE

}

u16 ADC_u16GetValue(u8 channel)//CHANGE 0 TO 7
{
	u16 ADC_value;
	//Bits 4:0 ñ MUX4:0: Analog Channel and Gain Selection Bits 10x gain  01000
	ADMUX&=0XE0; //ZEROS 5 BIT IN CHANNEL (clear 5 LSB) (1010 0011 & 1110 0000 = 101 00000)
	ADMUX|=channel;//store in register after oring with channel
	// Bit 6 ñ ADSC: ADC Start Conversion
	SET_BIT(ADCSRA,6);//STAR CONVERSION

	while(GET_BIT(ADCSRA,4)==0); //Bit 4 ñ ADIF: ADC Interrupt Flag  ÂÌ›÷· „” ‰Ì Â‰« ÿÊ· „« «·›·«Ã   » 0
	SET_BIT(ADCSRA,4); //CLEAR FLAG

	ADC_value=0;
	ADC_value=ADCL; //(0,1,2,3,4,5,6,7),8,9, (read from ADCL  ADCL must be read first, then ADCH.)
	ADC_value|=(ADCH<<8); //(EX ADC_VALUE=ADCL 0111 1011  | (10100 00 _00<<8 1101 0101_  ),, )

	return ADC_value; //return 10


}
void ADC_voidSelectChannel(u8 channel)
{
//Bit 6 ñ ADSC: ADC Start Conversion
	SET_BIT(ADCSRA,6);

}

void ADC_voidStartConversion(void)
{
	if(GET_BIT(ADCSRA,6)==0) //END  conversion
	{
	SET_BIT(ADCSRA,4); //ï Bit 4 ñ ADIF: ADC Interrupt Flag
	}

}
ISR(ADC_vect)
{
	ADC_value=0;
	ADC_value|=ADCL;
	ADC_value|=(ADCH<<8);

}
