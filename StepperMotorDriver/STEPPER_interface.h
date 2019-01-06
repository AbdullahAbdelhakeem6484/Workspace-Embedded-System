/*
 * STEPPER_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

void stepper_voidInit(void);

void stepper_voidRightForever(void);
void stepper_voidLeftForever(void);

void stepper_voidStop(void);

void stepper_void360Right(void);
void stepper_void360Left(void);

void stepper_void90Right(void);
void stepper_void90Left(void);

void stepper_void270Right(void);
void stepper_void270Left(void);



#endif /* STEPPER_INTERFACE_H_ */
