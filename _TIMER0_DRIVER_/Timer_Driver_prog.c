/*
 * Timer_Driver_prog.c
 *
 *  Created on: Sep 15, 2018
 *      Author: Abdullah Abdelhakeem
 */

#include"../lib/STD_Types.h"
#include"../lib/macros.h"
#include"DIO_interface.h"
#include"Timer_Driver_config.h"

#include<avr/io.h>
#include<avr/interrupt.h>                //TIMER0 8bit timer

static u32 OVF_counter;
static u32 OVF_Value;

void Timer_voidInit(u16 Start)
{
#if Timer_Mode == Normal_Mode

	CLEAR_BIT(TCCR0,6);//Normal mode
	CLEAR_BIT(TCCR0,3);

#if Compare_Output_Mode_Non_PWM ==     Non_PWM_OC0_Disconnectd
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif Compare_Output_Mode_Non_PWM ==    Non_PWM_Toggle_OC0
	SET_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif Compare_Output_Mode_Non_PWM ==    Non_PWM_Clear_OC0
	CLEAR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif Compare_Output_Mode_Non_PWM ==    Non_PWM_Set_OC0
	Set_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#endif
//________________________________________________________________
#elif Timer_Mode == PWM_Phase_Correct

	SET_BIT(TCCR0,6);
	CLEAR_BIT(TCCR0,3);

#if Compare_Output_Mode_PWM_Phase_Correct == Compare_Mode_Phase_Correct_OC0_Disconnected
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif Compare_Output_Mode_PWM_Phase_Correct == Compare_Mode_Phase_Correct_Reserved
	SET_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif Compare_Output_Mode_PWM_Phase_Correct == Compare_Mode_Phase_Correct_Clear_OC0_Upcounting_Set_OC0_Downcounting
	CLEAR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif Compare_Output_Mode_PWM_Phase_Correct == Compare_Mode_Phase_Correct_Set_OC0_Upcounting_Clear_OC0_Downcounting
	Set_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#endif
//___________________________________________________________________
#elif Timer_Mode == CTC_Mode

	CLEAR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#if Compare_Output_Mode_Non_PWM ==    Non_PWM_OC0_Disconnectd
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif Compare_Output_Mode_Non_PWM ==    Non_PWM_Toggle_OC0
	SET_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif Compare_Output_Mode_Non_PWM ==    Non_PWM_Clear_OC0
	CLEAR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif Compare_Output_Mode_Non_PWM ==    Non_PWM_Set_OC0
	Set_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#endif
//___________________________________________________________________
#elif Timer_Mode == Fast_PWM

	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#if Compare_Output_Mode_Fast_PWM == Fast_PWM_OC0_Disconnected
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif Compare_Output_Mode_Fast_PWM == Fast_PWM_Reserved
	SET_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif Compare_Output_Mode_Fast_PWM == Fast_PWM_Clear_OC0_On_Compare_Set_OC0_On_Top
	CLEAR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif Compare_Output_Mode_Fast_PWM == Fast_PWM_SET_OC0_On_Compare_Clear_OC0_On_Top
	Set_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#endif

#endif
//_____________________________________________________________________
#if Clock_Select ==   No_Cock_Source
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);
#elif Clock_Select ==   NO_Prescalling
	CLEAR_BIT(TCCR0,2); //no Prescaler
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
#elif Clock_Select == CLK/8
	CLEAR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);
#elif Clock_Select == CLK/64
	CLEAR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
#elif Clock_Select == CLK/256
	SET_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);
#elif Clock_Select == CLK/1024
	SET_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
#elif Clock_Select == External_Clock_On_T0_Clock_On_Falling_Edge
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);
#elif Clock_Select == External_Clock_On_T0_Clock_On_Rising_Edge
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
#endif

	TCNT0 = Start;

	//SET_BIT(TIMSK,0); //PIE overflow interrupt

    SET_BIT(SREG,7); // Global interrupt enable
}

void Timer_u32_OVF_Counter(u32 value)
{
	OVF_Value = value;

}


/*ISR(TIMER0_OVF_vect)
{
	OVF_counter++;
	if(OVF_counter == OVF_Value)
	{
		OVF_counter =0;
		//DIO_voidTogglePinValue(PORT_A,PIN_0);
	}
}*/
