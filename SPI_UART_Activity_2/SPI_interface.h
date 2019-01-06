/*
 * SPI_interface.h
 *
 *  Created on: Sep 29, 2018
 *      Author: hassan
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_u8Transfer(u8 byte);
void SPI_voidSlaveSelect(void);
void SPI_voidSlaveRelease(void);









#endif /* SPI_INTERFACE_H_ */
