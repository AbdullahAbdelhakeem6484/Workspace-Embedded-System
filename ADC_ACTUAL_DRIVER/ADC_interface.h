/*
 * ADC_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"ADC_config.h"
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);
//void ADC_voidSelectChannel(u8 channel);
u16 ADC_u16GetValue(u8 channel);
u16 ADC_u16GetCurrentValue(void);
void ADC_voidStartConversion(void);




#endif /* ADC_INTERFACE_H_ */
