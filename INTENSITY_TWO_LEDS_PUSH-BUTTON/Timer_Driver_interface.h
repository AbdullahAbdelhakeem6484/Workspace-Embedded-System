/*
 * Timer_Driver_interface.h
 *
 *  Created on: Sep 15, 2018
 *      Author: Abdullah Abdelhakeem
 */

#ifndef TIMER_DRIVER_INTERFACE_H_
#define TIMER_DRIVER_INTERFACE_H_    //TIMER0 8bit timer

void Timer_voidInit(u16 Start);
void Timer_u32_OVF_Counter(u32 value);

#define OCR0  PWM_Value




#endif /* TIMER_DRIVER_INTERFACE_H_ */
