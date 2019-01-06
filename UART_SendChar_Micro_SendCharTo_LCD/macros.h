/*
 * macros.h
 *
 *  Created on: ??�/??�/????
 *      Author: abdullah abdelhakeem
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(Reg,Pin)  Reg|=(1<<Pin)
#define CLEAR_BIT(Reg,Pin)  Reg&=~(1<<Pin)
#define TOGGLE_BIT(Reg,Pin)  Reg^=(1<<Pin)
#define GET_BIT(Reg,Pin)    ((Reg>>Pin)&1)


#endif /* MACROS_H_ */
