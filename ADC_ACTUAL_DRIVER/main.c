
#include"macros.h"
#include"STD_Types.h"
#include"ADC_interface.h"
#include"DIO_interface.h"
#include<avr/interrupt.h>
#include<util/delay.h>
#define F_CPU 12000000

int main(void)
{
	u16 digital,analog;
	ADC_voidInit();
	while(1)
	{
		ADC_u16GetValue(ADC0); //channel

		ADC_voidStartConversion();

		digital=ADC_u16GetCurrentValue();

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
