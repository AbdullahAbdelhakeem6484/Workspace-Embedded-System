/*
 * SPI_prog.c
 *
 *  Created on: 29/9/2018
 *      Author: Abdullah Abdelhakeem
 */


#include"STD_Types.h"
#include"macros.h"
#include "DIO_interface.h"
#include<avr/io.h>
//#include "UART_interface.h"


void SPI_voidMasterInit(void)
{
	//	• Bit 6 – SPE: SPI Enable
		SET_BIT(SPCR,6);
	//• Bit 5 – DORD: Data Order /*When the DORD bit is written to zero, the MSB of the data word is transmitted first.*/
		CLEAR_BIT(SPCR,5);

	//• Bit 4 – MSTR: Master/Slave Select /*This bit selects Master SPI mode when written to one*/
		/*and Slave SPI mode when written logic zero.*/

		SET_BIT(SPCR,4); //MASTER

	//• Bit 3 – CPOL: Clock Polarity /*When CPOL is written to zero, SCK is low when idle*/
		/*CPOL    Leading Edge     Trailing Edge*/
		/*0         Falling            Rising*/
		CLEAR_BIT(SPCR,3);

	//• Bit 2 – CPHA: Clock Phase
		/*The settings of the Clock Phase bit (CPHA) determine if data is sampled on the leading */
		 /* (first) or trailing (last) edge of SCK. */
		SET_BIT(SPCR,2);

	//• Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0 /*fosc/64*/

		SET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		SET_BIT(SPSR,0); //• Bit 0 – SPI2X: Double SPI Speed Bit

		DIO_voidSetPinDir(PORT_B,PIN_4,OUTPUT);
		DIO_voidSetPinDir(PORT_B,PIN_5,OUTPUT);
		DIO_voidSetPinDir(PORT_B,PIN_7,OUTPUT);
		DIO_voidSetPinDir(PORT_B,PIN_6,INPUT);


}


void SPI_voidSlaveInit(void)
{
	//	• Bit 6 – SPE: SPI Enable
			SET_BIT(SPCR,6);
		//• Bit 5 – DORD: Data Order /*When the DORD bit is written to zero, the MSB of the data word is transmitted first.*/
			CLEAR_BIT(SPCR,5);

		//• Bit 4 – MSTR: Master/Slave Select /*This bit selects Master SPI mode when written to one*/
			/*and Slave SPI mode when written logic zero.*/

			CLEAR_BIT(SPCR,4); //SLAVE

		//• Bit 3 – CPOL: Clock Polarity /*When CPOL is written to zero, SCK is low when idle*/
			/*CPOL    Leading Edge     Trailing Edge*/
			/*0         Falling            Rising*/
			CLEAR_BIT(SPCR,3);

		//• Bit 2 – CPHA: Clock Phase
			/*The settings of the Clock Phase bit (CPHA) determine if data is sampled on the leading */
			 /* (first) or trailing (last) edge of SCK. */
			SET_BIT(SPCR,2);

		//• Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0 /*fosc/64*/

			SET_BIT(SPCR,0);
			SET_BIT(SPCR,1);
			SET_BIT(SPSR,0); //• Bit 0 – SPI2X: Double SPI Speed Bit

			DIO_voidSetPinDir(PORT_B,PIN_4,INPUT);
			DIO_voidSetPinValue(PORT_B,PIN_4,HIGH);

			DIO_voidSetPinDir(PORT_B,PIN_5,INPUT);
			DIO_voidSetPinDir(PORT_B,PIN_7,INPUT);
			DIO_voidSetPinDir(PORT_B,PIN_6,OUTPUT);


}

u8 SPI_u8Transfer(u8 Byte)
{
  SPDR=Byte;
  while(GET_BIT(SPSR,7)==0);
  return SPDR;
}


void SPI_voidSlaveSelect(void)
{

	DIO_voidSetPinValue(PORT_B,PIN_4,LOW);

}

void SPI_voidSlaveRelease(void)
{
	DIO_voidSetPinValue(PORT_B,PIN_4,HIGH);


}
