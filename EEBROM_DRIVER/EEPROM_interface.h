/*
 * I2C_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidInit(void);
void EEPROM_voidWritByte(u8 page,u8 location,u8 byte);
u8 EEPROM_u8ReadByte(u8 page,u8 location);

#endif /* EEPROM_INTERFACE_H_ */
