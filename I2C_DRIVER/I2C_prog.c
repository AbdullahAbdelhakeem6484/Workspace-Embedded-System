/*
 * I2C_prog.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#include"STD_Types.h"
#include"macros.h"
#include "I2C_interface.h"
#include<avr/io.h>


void I2C_voidInit(void)
{
	TWCR=(1<<2); //• Bit 2 – TWEN: TWI Enable Bit
	/*• Bits 7..0 – TWI Bit Rate Register TWBR should be 10 or higher if the TWI operates in Master mode. If TWBR is lower than
              10, the master may produce an incorrect output on SDA and SCL for the reminder of the byte.*/
	TWBR=8;
	TWSR=0;      //• Bits 7..3 – TWS: TWI Status • Bits 1..0 – TWPS: TWI Prescaler Bits
	TWAR=2;      //• Bits 7..1 – TWA: TWI (Slave) Address Register  (ADDRESS 1)
}

void I2C_voidSendStart(void)
{
	/*• Bit 7 – TWINT: TWI Interrupt Flag
	  • Bit 5 – TWSTA: TWI START Condition Bit
	  • Bit 2 – TWEN: TWI Enable Bit*/
	TWCR=(1<<7)|(1<<5)|(1<<2);
	while(GET_BIT(TWCR,7)==0); //The TWINT Flag must be cleared by software by writing a logic one to it.

}

void I2C_voidSendStop(void)
{
	/*• Bit 7 – TWINT: TWI Interrupt Flag
	  • Bit 4 – TWSTO: TWI STOP Condition Bit
	  • Bit 2 – TWEN: TWI Enable Bit*/
	TWCR=(1<<7)|(1<<4)|(1<<2);

}

void I2C_voidSend_SLA_W(u8 SLA) //SEND SLAVE ADDERSS
{
	TWDR=(SLA<<1);//so 1st pin 0          /*In Transmit mode, TWDR contains the next byte to be transmitted.*/
	TWCR=(1<<7)|(1<<2);        /*• Bit 7 – TWINT: TWI Interrupt Flag • Bit 2 – TWEN: TWI Enable Bit*/
	while(GET_BIT(TWCR,7)==0); //The TWINT Flag must be cleared by software by writing a logic one to it.


}

void I2C_voidSend_SLA_R(u8 SLA)
{
	TWDR=(SLA<<1)|0X01; //000 0001 0
	TWCR=(1<<7)|(1<<2);
	while(GET_BIT(TWCR,7)==0);


}

void I2C_voidSendData(u8 Data)
{
	TWDR=Data; //• Bits 7..0 – TWD: TWI Data Register
	TWCR=(1<<7)|(1<<2);
	while(GET_BIT(TWCR,7)==0);
}

u8 I2C_u8ReceiveWithNoAck(void) //clear without doing anything
{
	TWCR=(1<<7)|(1<<2);
	while(GET_BIT(TWCR,7)==0);
	return TWDR;

}

u8 I2C_u8CheckStatus(u8 status)
{
	if(status==(TWSR & 0xf8))
	{
		return 1;
	}
	else
	{
		return 0;


	}
}











