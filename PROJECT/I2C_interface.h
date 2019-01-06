/*
 * I2C_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void I2C_voidInit(void);
void I2C_voidSendStart(void);
void I2C_voidSendStop(void);
void I2C_voidSend_SLA_W(u8 SLA);
void I2C_voidSend_SLA_R(u8 SLA);
void I2C_voidSendData(u8 Data);
u8 I2C_u8ReceiveWithNoAck(void);
u8 I2C_u8CheckStatus(u8 status);

#endif /* I2C_INTERFACE_H_ */
