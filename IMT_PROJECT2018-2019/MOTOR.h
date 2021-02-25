/*
 * MOTOR.h


 *
 *   Created on: 27/11/2018
 *      Author: Abdullah Abdelhakeem
 */
#include "DIO_interface.h"
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 12000000

#ifndef MOTOR_H_
#define MOTOR_H_



void MOTOR_voidInit(void);
void Motor_voidBackword(void);
void Motor_voidFORWARD(void);
void Motor_voidRIGHT(void);
void Motor_voidLEFT(void);
void Motor_voidStop(void);
void Motor_voidDefault(void);

#endif /* MOTOR_H_ */
