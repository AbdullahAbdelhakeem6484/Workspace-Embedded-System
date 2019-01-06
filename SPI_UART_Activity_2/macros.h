/*
 * macros.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: express
 */

#ifndef MACROS_H_
#define MACROS_H_
#define SET_BIT(reg,Pin) reg|=(1<<Pin)
#define CLEAR_BIT(reg,Pin) reg&=~(1<<Pin)
#define TOGGLE_BIT(reg,Pin) reg^=(1<<Pin)
#define GET_BIT(Reg,Pin) ((Reg>>Pin&1))

#endif /* MACROS_H_ */
