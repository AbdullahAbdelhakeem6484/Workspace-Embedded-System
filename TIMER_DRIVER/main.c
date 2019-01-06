#include"macros.h"
#include"STD_Types.h"
#include"DIO_interface.h"
#include<avr/io.h>
#define F_CPU 12000000
#include"TIMER0_interface.h"




int main(void)
{
	 u8 timerOverflowCount=0;
	 DIO_voidSetPinDir(PORT_A,PIN_1,OUTPUT);
	 TCNT0=0x00;
	 TIMER0_voidMode();
	 TIMER0_voidClockSelect();

	while(1)
	{
		 while ((TIFR & 0x01) == 0);/*The OCF0 bit is set (one) when a compare match occurs between the Timer/Counter0
											and the data in OCR0 – Output Compare Register0. OCF0 is cleared by hardware when
											executing the corresponding interrupt handling vector.*/
		  TCNT0 = 0x00;
		  TIFR=0x01; //clear timer overflow flag
		 timerOverflowCount++;
		 if (timerOverflowCount>=6)
		 {
			 TOGGLE_BIT(PORT_A,1);
			 timerOverflowCount=0;
		 }
	}
}



}









return 0;
}
