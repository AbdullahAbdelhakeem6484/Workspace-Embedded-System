
#include"macros.h"
#include"STD_Types.h"
#include"ADC_interface.h"
#include"ADC_config.h"

#include<avr/interrupt.h>
#include<util/delay.h>
#include<avr/io.h>
#define F_CPU 12000000

//

static u16 ADC_value;

void ADC_voidInit(void)
{
	//Enable PIE • Bit 3 – ADIE: ADC Interrupt Enable
	SET_BIT(ADCSRA,3);
	//Enable GIE global last thing open it (external interrupt)
	SET_BIT(SREG,7);

	// 0 1 AVCC with external capacitor at AREF pin
	CLEAR_BIT(ADMUX,7);//REFS1
	SET_BIT(ADMUX,6); //REFS0

	CLEAR_BIT(ADMUX,5);// ADC right adjust Result

	SET_BIT(ADCSRA,7);//ENABLE ADC  Bit 7 – ADEN: ADC Enable

	//• Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
	CLEAR_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);


}

/*void ADC_voidSelectChannel(u8 channel)
{
	SET_BIT(ADCSRA,6);//STAR CONVERSION
}*/

u16 ADC_u16GetValue(u8 channel)//CHANGE 0 TO 7
{
	u16 ADC_value;
	ADMUX&=channel; //ZEROS 5 BIT IN CHANNEL (clear 5 LSB) (0b111 00000=0xE0)
	//ADMUX|=channel;//store in register after oring with channel
	SET_BIT(ADCSRA,6);//STAR CONVERSION

	/*• Bit 4 – ADIF: ADC Interrupt Flag
		This bit is set when an ADC conversion completes and the Data Registers are updated.*/
	while(GET_BIT(ADCSRA,4)==0);
	SET_BIT(ADCSRA,4); //CLEAR FLAG

	ADC_value=0;
	ADC_value=ADCL; //ADC_value|=ADCL; LOW
	ADC_value|=(ADCH<<8);

	return ADC_value; //return 10
}


void ADC_voidStartConversion(void)
{
	/*Bit 6 – ADSC: ADC Start Conversion
		In Single Conversion mode, write this bit to one to start each conversion.*/
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

u16 ADC_u16GetCurrentValue(void)
{
	return ADC_value;


}




