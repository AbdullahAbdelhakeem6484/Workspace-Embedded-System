/*
 * ADC_Driver_config.h

 *
 *  Created on: Sep 7, 2018
 *      Author: Abdullah Abdelhakeem
 */

#ifndef ADC_DRIVER_CONFIG_H_
#define ADC_DRIVER_CONFIG_H_



#define AREF_InternalVrefTurnedOFF  30
#define AVCC                        31
#define Reserved                    32
#define Internal_2560mv             33

#define Voltage_Refrence           AVCC

#define Devision_Factor_2     34
#define Devision_Factor_2A    35
#define Devision_Factor_4     36
#define Devision_Factor_8     37
#define Devision_Factor_16    8
#define Devision_Factor_32    9
#define Devision_Factor_64    10
#define Devision_Factor_128   11

#define Prescaler_Selsction   Devision_Factor_4

#define Right_Adjusment   12
#define Left_Adjusment    13

#define ADC_Data_Register    Right_Adjusment

#define Free_Running_Mode         14
#define Analog_Comparator         15
#define External_Interrupt_0      16
#define Counter0_Compare_Match    17
#define Counter0_Overflow         18
#define Counter_Compare_Match_B   19
#define Counter1_Overflow         20
#define Counter1_Capture_Event    21
#define No_Auto_Trigger           22

#define Auto_Trigger          Free_Running_Mode

#define ADC_Interrupt_ON   23
#define ADC_Interrupt_OFF  24

#define ADC_Interrupt   ADC_Interrupt_ON


#endif /* ADC_DRIVER_CONFIG_H_ */
