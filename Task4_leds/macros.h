/*
 * macros.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(Reg,Pin)  Reg|=(1<<Pin)
#define CLEAR_BIT(Reg,Pin)  Reg&=~(1<<Pin)
#define TOGGLE_BIT(Reg,Pin)  Reg^=(1<<Pin)


#endif /* MACROS_H_ */
