

#include"macros.h"
#include"STD_Types.h"
#include"LCD_interface.h"

#include"ADC_interface.h"
#include"DIO_interface.h"
#include<avr/interrupt.h>
#include<util/delay.h>
#include<avr/io.h>
#define F_CPU 12000000
#include<stdio.h>

//voltage divider
	 f32 digital,analogv=0,analogmv=0;
	 u8 x;
	 u8 voltageshow [7];
int main(void)
{
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

	DIO_voidSetPinDir(PORT_B,PIN_0,INPUT);  //
	DIO_voidSetPinValue(PORT_B,PIN_0,HIGH);




	LCD_voidInit();
	ADC_voidInit();
	ADC_voidSelectChannel(0);
	ADC_voidStartConversion();


	while(1)
	{
		digital=ADC_u16GetCurrentValue();
		analogv=(digital*5)/1024; //to be compatability
		analogmv=(digital*5000)/1024; //to be compatability
		x=GET_BIT(PINB,0);



					if(x==1)
					{
						//LCD_voidClear();
						//_delay_ms(500);

						LCD_voidSetCursor(1, 0);
						LCD_voidWriteString("Volt:");


						dtostrf(analogv, 6, 1, voltageshow); //convert float to string
						LCD_voidSendCommand(0x86);
						LCD_voidSetCursor(1, 7);
						LCD_voidWriteString(voltageshow);

						LCD_voidSetCursor(1, 15);
						LCD_voidWriteString("v");
						LCD_voidSetCursor(1, 7);




						//LCD_voidSendCommand(0x80 + 0x40 + 8);
						//LCD_voidClear();
						//_delay_ms(1000);


					}
					 if (x==0)
					{

						//_delay_ms(500);
						LCD_voidSetCursor(1, 0);
						LCD_voidWriteString("Volt:");

						//LCD_voidSendCommand(0x80 + 0x40 + 8);
						//LCD_voidSetCursor(1, 1);
						//LCD_voidWriteString("Volt:");
						dtostrf(analogmv, 6, 1, voltageshow); //convert float to string
						LCD_voidSendCommand(0x86);
						LCD_voidSetCursor(1, 7);
						LCD_voidWriteString(voltageshow);
						LCD_voidSetCursor(1, 14);
						LCD_voidWriteString("mv");


					}


	}
return 0;
}

//EXTERNAL INTERRUPT
ISR(INT0_vect)
{



}
