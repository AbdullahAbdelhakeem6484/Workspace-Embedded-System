/*
 * TIMER2_prog.c

 *
 *   Created on: 27/11/2018
 *      Author: Abdullah Abdelhakeem
 */
#include"TIMER1_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>

u32 TimerOverflow = 0;


ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;		/* Increment Timer Overflow count */
}


void TIMER1_voidSet(void)
 {
	 TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
	 	TCCR1A = 0;				/* Set all bit to zero Normal operation */
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



 }
