/*
 * SPI_INTERFACE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: express
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_u8Transfer(u8 Byte);
void SPI_voidSlaveSelect(void);
void SPI_voidSlaveRelase(void);


#endif /* SPI_INTERFACE_H_ */
