/*
 * Ultrasonic sensor HC-05 interfacing with ATmega16
 * http://www.electronicwings.com
 */ 


#include "STD_Types.h"
#include"macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 12000000
#include <string.h>
#include <stdlib.h>
#include"LCD_interface.h"
#include"DIO_interface.h"




int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;		/* Increment Timer Overflow count */
}

int main(void)
{
	DIO_voidSetPinDir(PORT_B,PIN_0,OUTPUT);

	char string[10];
	long count;
	double distance;
	
	DDRD = 0x01;			/* Make trigger pin as output */
	PORTD = 0b01000000;			/* Turn on Pull-up */
	
	LCD_voidInit();
	//LCD_String_xy(1, 0, "Ultrasonic");
	LCD_voidSetCursor (0,0);
	 LCD_voidWriteString("Ultrasonic");
	
	sei();					/* Enable global interrupt */
	TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
	TCCR1A = 0;				/* Set all bit to zero Normal operation */

	while(1)
	{

		PORTD |= (1 << 0);/* Give 10us trigger pulse on trig. pin to HC-SR04 */
		_delay_us(10);
		PORTD &= (~(1 << 0));
		
		TCNT1 = 0;			/* Clear Timer counter */
		TCCR1B = 0x41;		/* Setting for capture rising edge, No pre-scaler*/
		TIFR = 1<<ICF1;		/* Clear ICP flag (Input Capture flag) */
		TIFR = 1<<TOV1;		/* Clear Timer Overflow flag */

		/*Calculate width of Echo by Input Capture (ICP) on PortD PD6 */
		
		while ((TIFR & (1 << ICF1)) == 0);	/* Wait for rising edge */
		TCNT1 = 0;			/* Clear Timer counter */
		TCCR1B = 0x01;		/* Setting for capture falling edge, No pre-scaler */
		TIFR = 1<<ICF1;		/* Clear ICP flag (Input Capture flag) */
		TIFR = 1<<TOV1;		/* Clear Timer Overflow flag */
		TimerOverflow = 0;	/* Clear Timer overflow count */

		while ((TIFR & (1 << ICF1)) == 0); /* Wait for falling edge */
		count = ICR1 + (65535 * TimerOverflow);	/* Take value of capture register */
		/* 8MHz Timer freq, sound speed =343 m/s, calculation mentioned in doc. */
		distance = (double)count / 466.47;

		dtostrf(distance, 2, 2, string);/* Convert distance into string */
		strcat(string, " cm   ");
		//LCD_String_xy(2, 0, "Dist = ");
		LCD_voidSetCursor (1,0);
		LCD_voidWriteString("Dist = ");
		//LCD_String_xy(2, 7, string);	/* Print distance on LDC16x2 */
		LCD_voidSetCursor (1,7);
		LCD_voidWriteString(string);
		_delay_ms(200);

		if(distance>5)
		   	    {
		   	    	DIO_voidSetPinValue(PORT_B,PIN_0,HIGH);
		   	    }
		   	    else
		   	    {
		   	    	DIO_voidSetPinValue(PORT_B,PIN_0,LOW);
		   	    }
	}
}
