/*
 * TIMER_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"TIMER0_interface.h"
#include"macros.h"
#include"STD_Types.h"
#include"DIO_interface.h"
#include<avr/io.h>
#define F_CPU 12000000

#define mode==normal                 //Timer/Counter Control Register – TCCR0
#define comp_Fast_Pwm==clear_OC0     //Compare Output Mode, Fast PWM Mode(1) Compare Output Mode, Fast PWM Mode(1)
#define ClockSelect==No_prescaling   //• Bit 2:0 – CS02:0: Clock Select  clkI/O/(No prescaling)

void TIMER0_voidMode(void) //• Bit 6, 3 – WGM01:0: Waveform Generation Mode
{
#if mode==normal


	 CLEAR_BIT(TCCR0,6);
	 CLEAR_BIT(TCCR0,3)	;


#elif mode==pwm
	{
		SET_BIT(TCCR0,6) ;
		CLEAR_BIT(TCCR0,3);


	}

#elif mode==ctc
	{
		CLEAR_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);

	}
#elif mode==fast_pwm
	{
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);

	}
#else
	{}

#endif
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////


void TIMER0_voidCOModeNonPwm(void)//Compare Output Mode, non-PWM Mode
{
#if Compare_Output_Mode==normal
	{

	 CLEAR_BIT(TCCR0,4);
	 CLEAR_BIT(TCCR0,5)	;

	}
#elif Compare_Output_Mode==toggle_OC0
	{
		SET_BIT(TCCR0,4) ;
		CLEAR_BIT(TCCR0,5);


	}

#elif Compare_Output_Mode==clear_OC0
	{
		CLEAR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);

	}
#elif Compare_Output_Mode==set_OC0
	{
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5)	;

	}
#else
	{}

#endif


}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////


void TIMER0_voidCOModeFastPwm(void)// Compare Output Mode, Fast PWM Mode(1)
{
#if comp_Fast_Pwm==normal //normal
	{

	 CLEAR_BIT(TCCR0,4);
	 CLEAR_BIT(TCCR0,5)	;

	}
#elif comp_Fast_Pwm==reversed//Reserved
	{
		SET_BIT(TCCR0,4) ;
		CLEAR_BIT(TCCR0,5);


	}

#elif comp_Fast_Pwm==clear_OC0  //Clear OC0 on compare match, set OC0 at TOP
	{
		CLEAR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);

	}
#elif comp_Fast_Pwm==set_OC0 //Set OC0 on compare match, clear OC0 at TOP
	{
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5)	;

	}
#else
	{}

#endif


}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void TIMER0_voidCOMPhaseCorrectPWM(void) //Compare Output Mode, Phase Correct PWM Mode(1)
{
#if comp_phaseCorrect_Pwm==normal //normal
	{

	 CLEAR_BIT(TCCR0,4);
	 CLEAR_BIT(TCCR0,5)	;

	}
#elif comp_phaseCorrect_Pwm==reversed//Reserved
	{
		SET_BIT(TCCR0,4) ;
		CLEAR_BIT(TCCR0,5);


	}

#elif comp_phaseCorrect_Pwm==clear_OC0  /*Clear OC0 on compare match when up-counting. Set OC0 on compare
														match when downcounting.*/
	{
		CLEAR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);

	}
#elif comp_phaseCorrect_Pwm==set_OC0 /*Set OC0 on compare match when up-counting. Clear OC0 on compare
												match when downcounting*/
	{
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5)	;

	}
#else
	{}

#endif

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void TIMER0_voidClockSelect(void) //• Bit 2:0 – CS02:0: Clock Select
{
#if ClockSelect==No_Clk_Source
	{

	 CLEAR_BIT(TCCR0,0);
	 CLEAR_BIT(TCCR0,1)	;
	 CLEAR_BIT(TCCR0,2);

	}
#elif ClockSelect==No_prescaling
	{
	SET_BIT(TCCR0,0);
	 CLEAR_BIT(TCCR0,1)	;
	 CLEAR_BIT(TCCR0,2);


	}

#elif ClockSelect==prescaler8
	{
		CLEAR_BIT(TCCR0,0);
		 SET_BIT(TCCR0,1)	;
		 CLEAR_BIT(TCCR0,2);

	}
#elif ClockSelect==prescaler64
	{
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1)	;
			 CLEAR_BIT(TCCR0,2);

	}
#elif ClockSelect==prescaler256
	{
		CLEAR_BIT(TCCR0,0);
			 CLEAR_BIT(TCCR0,1)	;
		SET_BIT(TCCR0,2);

	}
#elif ClockSelect==prescaler1024
	{
		SET_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1)	;
		SET_BIT(TCCR0,2);

	}
#elif ClockSelect==prescalerFallingEdge //External clock source on T0 pin. Clock on falling edge
	{
		CLEAR_BIT(TCCR0,0);
			 SET_BIT(TCCR0,1)	;
			 SET_BIT(TCCR0,2);

	}
#elif ClockSelect==prescalerRisingEdge //External clock source on T0 pin. Clock on rising edge
	{
		SET_BIT(TCCR0,0);
	    SET_BIT(TCCR0,1)	;
	    SET_BIT(TCCR0,2);

	}
#else
	{}

#endif

}


