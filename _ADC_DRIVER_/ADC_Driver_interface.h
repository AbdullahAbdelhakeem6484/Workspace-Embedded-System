/*
 * ADC_Driver_interface.h
 *
 *  Created on: Sep 7, 2018
 *      Author: Abdullah Abdelhakeem
 */

#ifndef ADC_DRIVER_INTERFACE_H_
#define ADC_DRIVER_INTERFACE_H_

void ADC_voidInit(void);

u16 ADC_u16GetValue(u8 channel);

void ADC_voidSelectChannel(u8 channel);

void ADC_voidStartConversion(void);

u16 ADC_u16GetCurrentValue(void);

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7


#endif /* ADC_DRIVER_INTERFACE_H_ */
