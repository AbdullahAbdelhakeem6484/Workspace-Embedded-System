/*
 * KEYPAD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_






#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
#include <util/delay.h>

#define F_CPU 12000000   //12MHz Clock frequency


#include <avr/io.h>
#include <util/delay.h>

#define N_col 4
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN  PINA
#define KEYPAD_PORT_DIR DDRA

//macros
/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(sizeof(SREG)-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(sizeof(SREG)-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/*Configure a pin to input and in pull up configuration,as AVR feature*/
#define PULL_UP_BIT(DDR_REG,PORT_REG,BIT) {CLEAR_BIT(DDR_REG,BIT);SET_BIT(PORT_REG,BIT);}

/*Note on Connecting the keypad :Crucial
	PX7 is connect to the last pin to right in keypad,then go backward
	PX3 is connect to the last pin to down in keypad,then go up
*/
/*
 * Function responsible for getting the pressed keypad key
 */
uint8 KeyPad_getPressedKey(void);
/*
 * Responsible for returning a number of 4 bytes range of length "NumberOfPressing"
 * i.e. : if you clicked 1,5,9 respectively on keypad,you will get 159 as return
 * a delay from one press and another is equal to 300 ms(Approx to the Normal human Press)
 */
uint32 KeyPad_getSeriesOfPressedNumbers(uint8 NumberOfPressing);
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number); /*C code may be configurable*/

/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number); /*C code may be configurable*/

 uint32 powerOf(uint8 x,uint8 y);





#endif /* KEYPAD_INTERFACE_H_ */
