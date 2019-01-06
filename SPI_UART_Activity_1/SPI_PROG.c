/*
 * SPI_PROG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: express
 */
#include"../LIB/std_type.h"
#include"../LIB/macros.h"
#include"DIO_INTERFACE.h"
#include<avr/io.h>
void SPI_voidMasterInit(void)
{
	  //SPI Enaple
	SET_BIT(SPCR,6);
	// Select Data Order
	CLEAR_BIT(SPCR,5);
	// Select To Be Master
	SET_BIT(SPCR,4);
	// Select Clock Polarity
	CLEAR_BIT(SPCR,3);
	// Select Clock Phase
	SET_BIT(SPCR,2);
	// PreScalling
	SET_BIT(SPCR,1);
	SET_BIT(SPCR,0);
	SET_BIT(SPSR,0);
	// SS Pin
	DIO_voidSetPinDir(PORT_B,Pin_4,OUTPUT);
	// MOSI Pin
	DIO_voidSetPinDir(PORT_B,Pin_5,OUTPUT);
	// MISO Pin
	DIO_voidSetPinDir(PORT_B,Pin_6,INPUT);
	 //CLK Pin
	DIO_voidSetPinDir(PORT_B,Pin_7,OUTPUT);
}
void SPI_voidSlaveInit(void)
{
	  //SPI Enaple
	SET_BIT(SPCR,6);
	// Select Data Order
	CLEAR_BIT(SPCR,5);
	// Select To Be Slave
	CLEAR_BIT(SPCR,4);
	// Select Clock Polarity
	CLEAR_BIT(SPCR,3);
	// Select Clock Phase
	SET_BIT(SPCR,2);
	// PreScalling
	SET_BIT(SPCR,1);
	SET_BIT(SPCR,0);
	SET_BIT(SPSR,0);
	// SS Pin
	DIO_voidSetPinDir(PORT_B,Pin_4,INPUT);
	// MOSI Pin
	DIO_voidSetPinDir(PORT_B,Pin_5,INPUT);
	// MISO Pin
	DIO_voidSetPinDir(PORT_B,Pin_6,OUTPUT);
	 //CLK Pin
	DIO_voidSetPinDir(PORT_B,Pin_7,INPUT);
	      // INPUT PullUP
	DIO_voidSetPinValue(PORT_B,Pin_4,HIGH);
}
u8 SPI_u8Transfer(u8 Byte)
{
     SPDR=Byte;
     while(GET_BIT(SPSR,7)==0);
     return SPDR;
}
void SPI_voidSlaveSelect(void)
{
     DIO_voidSetPinValue(PORT_B,Pin_4,LOW);
}
void SPI_voidSlaveRelase(void)
{
	 DIO_voidSetPinValue(PORT_B,Pin_4,HIGH);
}




