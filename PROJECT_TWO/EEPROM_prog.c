/*
 * I2C_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"STD_Types.h"
#include"macros.h"
#include "EEPROM_interface.h"
#include "I2C_interface.h"
#include<avr/io.h>

void EEPROM_voidInit(void)
{
	I2C_voidInit();
}

////////////
void EEPROM_voidWritByte(u8 page,u8 location,u8 byte)
{
	I2C_voidSendStart();
    if(I2C_u8CheckStatus(0X08)!=1)
    {
    	return ; //out of function
    }

    switch(page)
    {
    case 0:
    	I2C_voidSend_SLA_W(0b01010000);//address of page 0 1010 A2 P1 P0
    	break;

    case 1:
        I2C_voidSend_SLA_W(0b01010001);//address of page 0 1010 A2 P1 P0
        break;
    case 2:
		I2C_voidSend_SLA_W(0b01010010);//address of page 0 1010 A2 P1 P0
		break;
    case 3:
		I2C_voidSend_SLA_W(0b01010011);//address of page 0 1010 A2 P1 P0
		break;
    }

    if(I2C_u8CheckStatus(0X18)!=1)
        {
        	return ; //out of function
        }
    I2C_voidSendData(location);
    if(I2C_u8CheckStatus(0X28)!=1)
			{
				return ; //out of function
			}

    I2C_voidSendData(byte);
	if(I2C_u8CheckStatus(0X28)!=1)
				{
					return ; //out of function
				}

	I2C_voidSendStop();

}


//////////////////////
u8 EEPROM_u8ReadByte(u8 page,u8 location) //write first and read
{
	u8 x;

	I2C_voidSendStart(); //send start
	    if(I2C_u8CheckStatus(0X08)!=1)
	    {
	    	return 0xff; //out of function
	    }
	     //send to write
	    switch(page)
	    {
	    case 0:
	    	I2C_voidSend_SLA_W(0b01010000);//address of page 0 1010 A2 P1 P0
	    	break;

	    case 1:
	        I2C_voidSend_SLA_W(0b01010001);//address of page 0 1010 A2 P1 P0
	        break;
	    case 2:
			I2C_voidSend_SLA_W(0b01010010);//address of page 0 1010 A2 P1 P0
			break;
	    case 3:
			I2C_voidSend_SLA_W(0b01010011);//address of page 0 1010 A2 P1 P0
			break;
	    }

	    if(I2C_u8CheckStatus(0X18)!=1)
	        {
	        	return 0xff ; //out of function
	        }
	    I2C_voidSendData(location);
	    if(I2C_u8CheckStatus(0X28)!=1)
				{
					return 0xff ; //out of function
				}

	    /************Repeat start******************/
	    I2C_voidSendStart();
	    if(I2C_u8CheckStatus(0X10)!=1)
			{
				return 0xff ; //out of function
			}

	    switch(page)
	    	    {
	    	    case 0:
	    	    	I2C_voidSend_SLA_R(0b01010000);//address of page 0 1010 A2 P1 P0
	    	    	break;

	    	    case 1:
	    	        I2C_voidSend_SLA_R(0b01010001);//address of page 0 1010 A2 P1 P0
	    	        break;
	    	    case 2:
	    			I2C_voidSend_SLA_R(0b01010010);//address of page 0 1010 A2 P1 P0
	    			break;
	    	    case 3:
	    			I2C_voidSend_SLA_R(0b01010011);//address of page 0 1010 A2 P1 P0
	    			break;
	    	    }
	    if(I2C_u8CheckStatus(0X40)!=1)
				{
					return 0xff ; //out of function
				}
	    x=I2C_u8ReceiveWithNoAck();
	    I2C_voidSendStop();
	    return x;







}
