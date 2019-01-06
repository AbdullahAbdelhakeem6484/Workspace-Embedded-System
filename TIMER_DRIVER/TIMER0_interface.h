/*
 * TIMER_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_
#include"macros.h"
#include"STD_Types.h"
#include"DIO_interface.h"
#include<avr/io.h>
#define F_CPU 12000000
#include"TIMER0_config.h"



//#define  TCNT0  TCNT0=0x00;
/*The Timer/Counter Register gives direct access, both for read and write operations, to
														the Timer/Counter unit 8-bit counter.*/


void TIMER0_voidMode(void);
void TIMER0_voidCOModeNonPwm(void);
void TIMER0_voidCOModeFastPwm(void);
void TIMER0_voidCOMPhaseCorrectPWM(void);
void TIMER0_voidClockSelect(void);


#endif /* TIMER0_INTERFACE_H_ */
