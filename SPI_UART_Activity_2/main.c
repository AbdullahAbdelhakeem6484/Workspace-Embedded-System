/*
 * main.c
 *
 *  Created on: Sep 29, 2018
 *      Author: hassan
 */
#include "std_type.h"
#include "macros.h"
#include "SPI_interface.h"
#include "UART_interface.h"
int main (void)
{
   u8 Received_UART;
   UART_voidInit();
    SPI_voidMasterInit();
    SPI_voidSlaveSelect();
    while(1)
    {
    	Received_UART = UART_u8RecieveByte();

    	SPI_u8Transfer(Received_UART);
    }
 return 0;
}
