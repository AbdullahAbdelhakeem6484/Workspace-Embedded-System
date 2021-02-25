/*
 * TIMER02_interface.h

 *
 *   Created on: 27/11/2018
 *      Author: Abdullah Abdelhakeem
 */

#include "DIO_interface.h"
#include <avr/io.h>
#include <util/delay.h>

#ifndef TIMER02_INTERFACE_H_
#define TIMER02_INTERFACE_H_

/*Timer Counter 0 Function Declarations*/
void Timer0_voidInit(void);
void set_timercounter0_mode(unsigned char mode);
void set_timercounter0_prescaler(unsigned char prescaler_value);
void set_timercounter0_output_mode(unsigned char output_mode);
void set_timercounter0_compare_value(unsigned char compare_value);

/*Timer Counter 2 Function Declarations*/
void Timer1_voidInit(void);
void set_timercounter2_mode(unsigned char mode);
void set_timercounter2_prescaler(unsigned char prescaler_value);
void set_timercounter2_output_mode(unsigned char output_mode);
void set_timercounter2_compare_value(unsigned char compare_value);

#endif /* TIMER02_INTERFACE_H_ */
