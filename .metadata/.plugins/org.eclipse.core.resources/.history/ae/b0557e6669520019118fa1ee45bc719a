/*
 * main.c

 *   Created on: 27/11/2018
 *      Author: Abdullah Abdelhakeem
 */
/**************************************************************************
**	Project Name : Avoiding Robot With Metal Detector
**
**	Description: Avoiding Robot  Metal Detector	with DIO Module,
**				External Interrupt Ultrasonic ,IR sensors,PWM,ICU,
**
**				Sound velocity = 343.00 m/s = 34300 cm/s
**				Distance of Object (in cm) = (Sound velocity * TIMER Value) / 2
**				= (34300 * TIMER Value) / 2
** 	 	 	 	= 17150  * Timer Value
**
**
**				we have selected internal 12 MHz oscillator frequency for ATmega32,
**				with No-presale for timer frequency.
**				Then time to execute 1 instruction is 0.083 us So,
**				timer gets incremented after 0.083 us time elapse
**
**				 = 17150 x (TIMER value) x 0.083 x 10^-6 cm
**				 = (TIMER value) / 466.47 cm
**
**	Author: ABDULLAH ABDELHAKEEM
**	Company: IMT
**
***************************************************************************/
#include "std_types.h"
#include "macros.h"
#include"MOTOR.h"
#include"TIMER02_interface.h"
#include"IR-SENSOR.h"
#include"EX_Interrupt_config.h"
#include"ULTRASONIC.h"
#include"TIMER1_interface.h"




int main (void)
{
	/*******************FAST PWM TIMER0 AND TIMER2 (SPEED CONTROL of Motors)***/
	Timer0_voidInit(); //OC0
	Timer2_voidInit();//OC2
/*************************/
	set_timercounter0_mode(3);
	/*Timer counter 0 is set to fast pwm mode*/
	set_timercounter0_prescaler(8);
	/*Timer counter 0 frequency is set to 3.90625KHz*/
	set_timercounter0_output_mode(2);
	/*Timer counter 0 output mode is set  to non-inverting mode*/
/**************************/
	set_timercounter2_mode(3);
	/*Timer counter 2 is set to fast pwm mode*/
	set_timercounter2_prescaler(8);
	/*Timer counter 2 frequency is set to 3.90625KHz*/
	set_timercounter2_output_mode(2);
	/*Timer counter 2 output mode is set to non-inverting mode*/
/***************************************ULTRASONIC****************************/
	/*ULTRASONIC INITIALIZE*/
	ULTRASONIC_voidInit();
/**************************************IR SENSOR******************************/
	/*BOTH IR sensors pins are declared as input*/
	IR_Right_SENSOR_voidInit(); // RIGHT SENSOR
	IR_Left_SENSOR_voidInit();//LEFT SENSOR
/**************************************MOTORS*********************************/
	/*motors*/
	MOTOR_voidInit();
/************************************EXT INTERRUPT FOR METAL DETECTOR*********/
	EX_Interrupt_voidInitINT0();
	EX_Interrupt_voidSetINT0();

while(1)
{
	ULTRASONIC_voidTrigger(); //TRIGGER ULTRASONIC FOR GENERATR 8 SOUND WAVE
	ULTRASONIC_voidCalculation();/*CALCULATE THE TIME BY ICU THEN WITH KNOWING (TIME AND SPEED OF SOUND )WE CA CALCULATE THE DISTANCE  */
	if(distance>25)/*OPENED FROM FRONT*/
		{
			set_timercounter0_compare_value(180);
			/*OCR0 register value is set to 180*/
			set_timercounter2_compare_value(180);
			/*OCR2 register value is set to 180*/
			Motor_voidFORWARD();
		}

	if((distance<=25) &&(GET_BIT(PIND,3)==1) &&(GET_BIT(PIND,4)==0))/*CLOSED FROM RIGHT AND FRONT*/
		{
			set_timercounter0_compare_value(255);
			/*OCR0 register value is set to 255*/
			set_timercounter2_compare_value(255);
			/*OCR2 register value is set to 255*/
			Motor_voidRIGHT();
		}

	if((distance<=25) &&(GET_BIT(PIND,3)==0) &&(GET_BIT(PIND,4)==1))/*CLOSED FROM LEFT AND FRONT*/
		{
			set_timercounter0_compare_value(255);
			/*OCR0 register value is set to 255*/
			set_timercounter2_compare_value(255);
			/*OCR2 register value is set to 255*/
			Motor_voidLEFT();
		}

	if((distance<=25) &&(GET_BIT(PIND,3)==0) &&(GET_BIT(PIND,4)==0))/*CLOSED FROM ALL DIRECTIONS*/
		{
			set_timercounter0_compare_value(200);
			/*OCR0 register value is set to 200*/
			set_timercounter2_compare_value(200);
			/*OCR2 register value is set to 200*/
			Motor_voidBackword();
		}

	 if((distance<=25) &&(GET_BIT(PIND,3)==1) &&(GET_BIT(PIND,4)==1)) /*ONLY <=25 CM*/
		 {
			set_timercounter0_compare_value(255);
			/*OCR0 register value is set to 255*/
			set_timercounter2_compare_value(255);
			/*OCR2 register value is set to 255*/
			Motor_voidDefault();
		}
	 else
			 { }

	}
return 0;
}
