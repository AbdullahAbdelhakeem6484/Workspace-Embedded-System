/*
 * calc_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef CALC_INTERFACE_H_
#define CALC_INTERFACE_H_

void cal_init(void);
void dis_string(unsigned char row, unsigned char col, char *str);
void dis_position(char i, char j);
void dis_shift(char dir);
void cal_op(void);
void cal_run(void);
void calculate(void);
void dis_shift(char dir);
#endif /* CALC_INTERFACE_H_ */
