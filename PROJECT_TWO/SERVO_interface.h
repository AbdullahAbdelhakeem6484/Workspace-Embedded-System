/*
 * SERVO_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"macros.h"
#include"STD_Types.h"
#include"DIO_interface.h"
#include"SERVO_config.h"


#include<util/delay.h>
#include<avr/io.h>
#define F_CPU 12000000

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_


void SERVO_voidAngle(u8 angle);

#endif /* SERVO_INTERFACE_H_ */
