/*
 * ADC_Driver_prog.c
 *
 *  Created on: Sep 7, 2018
 *      Author: Abdullah Abdelhakeem
 */


#include"../lib/STD_Types.h"
#include"../lib/macros.h"
#include"ADC_Driver_config.h"
#include"ADC_Driver_interface.h"
#include<avr/io.h>
#include<avr/interrupt.h>

static u16 ADC_Value;

void ADC_voidInit(void)
{
#if Voltage_Refrence  ==     AREF_InternalVrefTurnedOFF

	CLEAR_BIT(ADMUX,7);
	CLEAR_BIT(ADMUX,6);

#elif Voltage_Refrence  ==   AVCC

	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

#elif Voltage_Refrence  ==   Reserved

	SET_BIT(ADMUX,7);
	CLEAR_BIT(ADMUX,6);

#elif Voltage_Refrence  ==   Internal_2560mv

	SET_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

#endif

#if Prescaler_Selsction ==  Devision_Factor_2

	CLEAR_BIT(ADCSRA,2);  //ADC Prescaler selections
	CLEAR_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);

#elif Prescaler_Selsction ==  Devision_Factor_2A

	CLEAR_BIT(ADCSRA,2);  //ADC Prescaler selections
	CLEAR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

#elif Prescaler_Selsction ==  Devision_Factor_4

	CLEAR_BIT(ADCSRA,2);  //ADC Prescaler selections
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);

#elif Prescaler_Selsction ==  Devision_Factor_8

	CLEAR_BIT(ADCSRA,2);  //ADC Prescaler selections
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

#elif Prescaler_Selsction ==  Devision_Factor_16

	SET_BIT(ADCSRA,2);  //ADC Prescaler selections
	CLEAR_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);

#elif Prescaler_Selsction ==  Devision_Factor_32

	SET_BIT(ADCSRA,2);  //ADC Prescaler selections
	CLEAR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

#elif Prescaler_Selsction ==  Devision_Factor_64

	SET_BIT(ADCSRA,2);  //ADC Prescaler selections
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);

#elif Prescaler_Selsction ==  Devision_Factor_128

	SET_BIT(ADCSRA,2);  //ADC Prescaler selections
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

#endif

#if  ADC_Data_Register ==   Right_Adjusment

	CLEAR_BIT(ADMUX,5);  //right adjusment

#elif  ADC_Data_Register ==  Left_Adjusment

	SET_BIT(ADMUX,5);

#endif

#if Auto_Trigger    ==      Free_Running_Mode

	SET_BIT(ADCSRA,5);  // enable auto trigger for ADC
	CLEAR_BIT(SFIOR,5);   // auto trigger for adc by free running mode
	CLEAR_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,7);

#elif Auto_Trigger    ==      Analog_Comparator

	SET_BIT(ADCSRA,5);  // enable auto trigger for ADC
	SET_BIT(SFIOR,5);
	CLEAR_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,7);

#elif Auto_Trigger    ==      External_Interrupt_0

	SET_BIT(ADCSRA,5);  // enable auto trigger for ADC
	CLEAR_BIT(SFIOR,5);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,7);

#elif Auto_Trigger    ==      Counter0_Compare_Match

	SET_BIT(ADCSRA,5);  // enable auto trigger for ADC
	SET_BIT(SFIOR,5);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,7);

#elif Auto_Trigger    ==      Counter0_Overflow

	SET_BIT(ADCSRA,5);  // enable auto trigger for ADC
	CLEAR_BIT(SFIOR,5);
	CLEAR_BIT(SFIOR,6);
	SET_BIT(SFIOR,7);

#elif Auto_Trigger    ==      Counter_Compare_Match_B

	SET_BIT(ADCSRA,5);  // enable auto trigger for ADC
	SET_BIT(SFIOR,5);
	CLEAR_BIT(SFIOR,6);
	SET_BIT(SFIOR,7);

#elif Auto_Trigger    ==      Counter1_Overflow

	SET_BIT(ADCSRA,5);  // enable auto trigger for ADC
	CLEAR_BIT(SFIOR,5);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,7);

#elif Auto_Trigger    ==      Counter1_Capture_Event

	SET_BIT(ADCSRA,5);  // enable auto trigger for ADC
	SET_BIT(SFIOR,5);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,7);

#endif


	SET_BIT(ADCSRA,7);   //Enable ADC

#if ADC_Interrupt ==   ADC_Interrupt_ON

	SET_BIT(ADCSRA,3);  //enable adc interrupt
	SET_BIT(SREG,7);    //enable global interrupt

#elif ADC_Interrupt ==   ADC_Interrupt_OFF

	CLEAR_BIT(ADCSRA,3);  //disable adc interrupt

#endif

}

u16 ADC_u16GetValue(u8 channel)     //it has some problems and not preferable to use
{
	ADMUX &=0xE0;
	ADMUX |=channel;
	SET_BIT(ADCSRA,6); //start conversion
	while(GET_BIT(ADCSRA,4)==0);  //check if the flag is zero (conversion is over)
	SET_BIT(ADCSRA,4);   //make flag = 0
	ADC_Value = 0;
	ADC_Value = ADCL;
	ADC_Value |=(ADCH<<8);
	return ADC_Value;
}

void ADC_voidSelectChannel(u8 channel)
{
	ADMUX &=0xE0;
	ADMUX |=channel;

}

void ADC_voidStartConversion(void)
{
	if(GET_BIT(ADCSRA,6)==0)   // to check if you ended the last conversion to start a new one
	{
		SET_BIT(ADCSRA,6);
	}

}

ISR(ADC_vect)    //when conversion end ,it calculate ADC_Value and  it makes flag = 0 to be ready to start another conversion
{
	ADC_Value = 0;
	ADC_Value = ADCL;
	ADC_Value |=(ADCH<<8);

}
u16 ADC_u16GetCurrentValue(void)
{
	return ADC_Value;

}
