/*
 * Timer_Driver_config.h
 *
 *  Created on: Sep 15, 2018
 *      Author: Abdullah Abdelhakeem
 */

#ifndef TIMER_DRIVER_CONFIG_H_
#define TIMER_DRIVER_CONFIG_H_     //TIMER0 8bit timer
//______________________________________________________________________________
#define Timer_Mode     Fast_PWM

#define Normal_Mode        11
#define PWM_Phase_Correct  12
#define CTC_Mode           13
#define Fast_PWM           14

//_____________________________________________________________________________
#define Compare_Output_Mode_Non_PWM    Non_PWM_OC0_Disconnectd

#define Non_PWM_OC0_Disconnectd   21
#define Non_PWM_Toggle_OC0        22
#define Non_PWM_Clear_OC0         23
#define Non_PWM_Set_OC0           24

//______________________________________________________________________________
#define Compare_Output_Mode_Fast_PWM   Fast_PWM_Clear_OC0_On_Compare_Set_OC0_On_Top

#define Fast_PWM_OC0_Disconnected                     31
#define Fast_PWM_Reserved                             32
#define Fast_PWM_Clear_OC0_On_Compare_Set_OC0_On_Top  33
#define Fast_PWM_SET_OC0_On_Compare_Clear_OC0_On_Top  34

//_______________________________________________________________________________
#define Compare_Output_Mode_PWM_Phase_Correct  Compare_Mode_Phase_Correct_OC0_Disconnected

#define Compare_Mode_Phase_Correct_OC0_Disconnected                           41
#define Compare_Mode_Phase_Correct_Reserved                                   42
#define Compare_Mode_Phase_Correct_Clear_OC0_Upcounting_Set_OC0_Downcounting  43
#define Compare_Mode_Phase_Correct_Set_OC0_Upcounting_Clear_OC0_Downcounting  44

//_______________________________________________________________________________

#define Clock_Select   NO_Prescalling

#define No_Cock_Source                               51
#define NO_Prescalling                               52
#define CLK/8                                        53
#define CLK/64                                       54
#define CLK/256                                      55
#define CLK/1024                                     56
#define External_Clock_On_T0_Clock_On_Falling_Edge   57
#define External_Clock_On_T0_Clock_On_Rising_Edge    58

//_________________________________________________________________________________


#endif /* TIMER_DRIVER_CONFIG_H_ */
