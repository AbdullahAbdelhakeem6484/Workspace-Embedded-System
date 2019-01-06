/*
 * SPI_prog.c
 *
 *  Created on: Sep 29, 2018
 *      Author: hassan
 */
#include "std_type.h"
#include "macros.h"
#include "DIO_interface.h"
#include <avr/io.h>

void SPI_voidMasterInit(void)

{
	SET_BIT(SPCR,6);          //ENABLE
	CLEAR_BIT(SPCR,5);
	SET_BIT(SPCR,4);   // MASTER
	CLEAR_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	// PRESCALER
	SET_BIT(SPCR,1);
	SET_BIT(SPCR,0);
    SET_BIT(SPSR,0);
// MASTER PINS
DIO_voidSetPinDir(PORT_B,Pin_4,OUTPUT);
DIO_voidSetPinDir(PORT_B,Pin_5,OUTPUT);
DIO_voidSetPinDir(PORT_B,Pin_7,OUTPUT);
DIO_voidSetPinDir(PORT_B,Pin_6,INPUT);
}
void SPI_voidSlaveInit(void)
{
	SET_BIT(SPCR,6);          //ENABLE
	CLEAR_BIT(SPCR,5);
	CLEAR_BIT(SPCR,4);   // SLAVE
	CLEAR_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	// PRESCALER
	SET_BIT(SPCR,1);
	SET_BIT(SPCR,0);
    SET_BIT(SPSR,0);
// SLAVE PINS
DIO_voidSetPinDir(PORT_B,Pin_4,INPUT);
DIO_voidSetPinValue(PORT_B,Pin_4,HIGH); //INPUT PULL UP
DIO_voidSetPinDir(PORT_B,Pin_5,INPUT);
DIO_voidSetPinDir(PORT_B,Pin_7,INPUT);
DIO_voidSetPinDir(PORT_B,Pin_6,OUTPUT);
}
u8 SPI_u8Transfer(u8 byte)
{
	SPDR=byte;
	while (GET_BIT(SPSR,7)==0);
	return SPDR;
}

void SPI_voidSlaveSelect(void)
{
DIO_voidSetPinValue(PORT_B,Pin_4,LOW);
}

void SPI_voidSlaveRelease(void)

{
	DIO_voidSetPinValue(PORT_B,Pin_4,HIGH);
}
