/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"
#include"STEPPER_config.h"
#include"STEPPER_interface.h"
#include<util/delay.h>
#define F_CPU 12000000

int main(void)
{
	stepper_voidInit();

	stepper_void90Right();
	stepper_void90Left();

	stepper_void270Right();
	stepper_void270Left();

	stepper_void360Right();
	stepper_void360Left();



}
