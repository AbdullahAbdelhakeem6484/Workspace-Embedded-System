/*
 * ADC_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
u16 ADC_u16GetValue(u8 channel);
void ADC_voidInit(void);

u16 ADC_u16GetCurrentValue(void);

void ADC_voidSelectChannel(u8 channel);
void ADC_voidStartConversion(void);

#endif /* ADC_INTERFACE_H_ */
