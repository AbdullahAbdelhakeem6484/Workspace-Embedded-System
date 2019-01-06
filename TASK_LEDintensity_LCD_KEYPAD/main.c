
#include"macros.h"
#include"STD_Types.h"
#include"LCD_interface.h"
#include"DIO_interface.h"
#include"ADC_interface.h"
#include<util/delay.h>
#include<avr/io.h>
#define F_CPU 12000000

int main(void)
{


	//timer
	//• Bit 6, 3 – WGM01:0: Waveform Generation Mode
				SET_BIT(TCCR0,6);
				CLEAR_BIT(TCCR0,3);
	//Compare Output Mode, Fast PWM Mode(1) Clear OC0 on compare match, set OC0 at TOP
				CLEAR_BIT(TCCR0,4);
				SET_BIT(TCCR0,5);

	//• Bit 2:0 – CS02:0: Clock Select clkI/O/(No prescaling)
				SET_BIT(TCCR0,0);
				CLEAR_BIT(TCCR0,1);
				CLEAR_BIT(TCCR0,2);

	DIO_voidSetPinDir(PORT_B,PIN_3,OUTPUT); //ocr0 timer

	DIO_voidSetPinDir(PORT_C,PIN_0,INPUT);//keypad pushbutton to increment
	DIO_voidSetPinDir(PORT_C,PIN_1,INPUT);//keypad pushbutton to decrement
	DIO_voidSetPinDir(PORT_C,PIN_0,INPUT);//ok
	DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PULL UP
	DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PULL UP
	DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PULL UP

	u32 x,y,z ;
	u32 i=0;
	u8 c[7];



	ADC_voidInit();
	LCD_voidInit(); //lcd initialization

	LCD_voidWriteString("Welcome On LCD");
	_delay_ms(2000);



	LCD_voidSetCursor(1,0);
	LCD_voidWriteString("Select-Intensity");
	LCD_voidSetCursor(2, 0);
	LCD_voidWriteString("     %");
	//OCR0=0;

while(1)
{
		x=GET_BIT(PINC,0);//increment
		y=GET_BIT(PINC,1);//decrement
		z=GET_BIT(PINC,2);	//done

	if(x==0)
	{
	/*	LCD_voidSetCursor(2, 0);
		LCD_voidWriteString("10");
		i+=10;
		itoa(i ,c, 10);
		LCD_voidSetCursor(2, 0);
		LCD_voidWriteString(c);*/
		for(i=0;i<100;i+10)
		{
			if(x==0){
			itoa(i ,c, 10);
			LCD_voidSetCursor(2, 0);
			LCD_voidWriteString(c);
			}




		}

	}
	else if(y==0)
	{

		itoa(i ,c, 10);
		LCD_voidSetCursor(2, 0);
		LCD_voidWriteString(c);
		i-=10;
	}
	else if(z==0)
	{
		if(i==0)
		{OCR0=0;}
		else if(i==10)
		{OCR0=10;}
		else if(i==20)
				{OCR0=20;}
		else if(i==30)
				{OCR0=30;}
		else if(i==40)
				{OCR0=40;}
		else if(i==50)
				{OCR0=50;}
		else if(i==60)
				{OCR0=60;}
		else if(i==70)
				{OCR0=70;}
		else if(i==80)
				{OCR0=80;}
		else if(i==90)
				{OCR0=90;}
		else if(i==100)
				{OCR0=100;}
		else{}
	}
	else{}
}
return 0;
}




















/*if(x==0)
	{
		 if (OCR0<255)
		{
			a=OCR0++;
			LCD_voidSetCursor(2, 0);
			i+=10;
			dtostrf(i, 6, 1, show);
			LCD_voidWriteString(show);
		}
		_delay_ms(50);

		//dtostrf(OCR0, 6, 1, show); //convert float to string

		//arr++;

	}
	else if(y==0)
	{
		if (OCR0>0)
			{
				a=OCR0--;
			}
			_delay_ms(50);


		dtostrf(OCR0, 6, 1, show); //convert float to string
		LCD_voidSetCursor(2, 0);
		LCD_voidWriteString(show);
		//arr--;
	}


	else if(z==0)
	{
		LCD_voidSetCursor(2, 1);
		LCD_voidWriteString(" ");
		OCR0;
	}

	else {}*/


/*if(x==0)
	{

		//dtostrf(i, 6, 1, show); //convert float to string
		if(OCR0<255)
		{
			OCR0++;

			if((OCR0>0)&&(OCR0<25))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("10");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("20");

			}
			else if((OCR0>50)&&(OCR0<75))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("30");

			}
			else if((OCR0>75)&&(OCR0<100))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("40");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("50");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("60");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("70");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("80");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("90");

			}
			else
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("100");

			}
		}

	}
	else if(y==0)
	{

		if(OCR0>0)

		{
			OCR0--;
			if((OCR0>0)&&(OCR0<25))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("10");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("20");

			}
			else if((OCR0>50)&&(OCR0<75))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("30");

			}
			else if((OCR0>75)&&(OCR0<100))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("40");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("50");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("60");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("70");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("80");

			}
			else if((OCR0>25)&&(OCR0<50))
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("90");

			}
			else
			{
				LCD_voidSetCursor(2, 0);
				LCD_voidWriteString("100");

			}
		}
	}


	else if(z==0)
	{
		if(OCR0<255)
		{
		 a=OCR0;
		_delay_ms(50);
		}
		if(OCR0<0)
		{
			a=OCR0;
			_delay_ms(50);

		}
	}
	else {OCR0=0;}
}


return 0;
}*/













/*if(x==0)
	{
		itoa(i ,c, 10);
		LCD_voidSetCursor(2, 0);
		LCD_voidWriteString(c);
		i+=10;

	}


	 if(y==0)
	{

		itoa(i ,c, 10);
		LCD_voidSetCursor(2, 0);
		LCD_voidWriteString(c);
		i-=10;



	}
	if(z==0)
	{
		if(i==0)
		{OCR0=0;}
		else if(i==10)
		{OCR0=10;}
		else if(i==20)
				{OCR0=20;}
		else if(i==30)
				{OCR0=30;}
		else if(i==40)
				{OCR0=40;}
		else if(i==50)
				{OCR0=50;}
		else if(i==60)
				{OCR0=60;}
		else if(i==70)
				{OCR0=70;}
		else if(i==80)
				{OCR0=80;}
		else if(i==90)
				{OCR0=90;}
		else if(i==100)
				{OCR0=100;}
		else{}



	}

 * */
