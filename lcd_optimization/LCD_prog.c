/*
 * LCD_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


#ifndef F_CPU
#define F_CPU 12000000 // 16 MHz clock speed
#endif
#include <avr/io.h>
#include <util/delay.h>
#include"macros.h"
#include"STD_Types.h"
/********************************************************************************************************/

/*SEND DATA TO HW PORT*/

void port(char cmd_port)
{
	if(cmd_port&1)
		SET_BIT(PORTB,0);		//IF 1ST BIT = 1 RAISE PB0
	else
		CLEAR_BIT(PORTB,0);		//IF 1ST BIT = 0 CLR PB0

	if(cmd_port&2)
		SET_BIT(PORTB,1);		//IF 2ND BIT = 1 RAISE PB1
	else
		CLEAR_BIT(PORTB,1);		//IF 2ND BIT = 0 CLR PB1

	if(cmd_port&4)
		SET_BIT(PORTB,2);		//IF 3RD BIT = 1 RAISE PB2
	else
		CLEAR_BIT(PORTB,2);		//IF 3RD BIT = 0 CLR PB2

	if(cmd_port&8)
		SET_BIT(PORTB,3);		//IF 4TH BIT = 1 RAISE PB3
	else
		CLEAR_BIT(PORTB,3);		//IF 4TH BIT = 0 CLR PB3
}

/*SWITCH BETWEEN COMMAND MODE OR DATA MODE*/



void mode_select(char m)
{
	if ( m == 0)
		CLEAR_BIT(PORTB,5);		// RS = 0 --> SWITCH TO LCD CONTROL REGISTER - COMMAND MODE

	if ( m == 1)
		SET_BIT(PORTB,5);		   // RS = 1 --> SWITCH TO LCD DATA REGISTER - DATA MODE
}

/*TRIIGERS THE ENABLE BIT*/
void enb_tri(void)
{
	SET_BIT(PORTB,4);		//RAISE ENABLE EN = 1
	_delay_us(50);

	CLEAR_BIT(PORTB,4);		//TOGGLE ENABLE
	_delay_us(500);			//HIGH DELAY TO PREVENT DATA OVER FLOW
}

/*INITIALIZE DATABUS TO HW PORT*/
void set_port(void)
{
	DDRB |= 0X3F;	//ASSIGN DATABUS PB0-PB3, CONTROLBUS EN-PB4 RS-PB5
}

/*SEND COMMANDS OVER DATA BUS*/



void cmd(char cmd_data)
{
	mode_select(0);			//SELECT COMMAND MODE

	port(cmd_data);			//SEND COMAND TO PORT (DATABUS)

	enb_tri();				//ENABLE TRIGGER
}

/*INTIALLIZE LCD*/



void lcd_init(void)
{
	set_port();		//SET DATABUS

	cmd(0);			//RETURN CURSOR TO HOME POISTION - COMMAND 0X02
	cmd(2);

	cmd(2);			//DISPLAY IN 2-LINES AND 4-BIT DATA MODE - COMMAND 0X28
	cmd(8);

	cmd(0);			//DISPLAY NO CURSOR AND NO BLINK - COMMAND 0X0C
	cmd(12);

	cmd(0);			//DD RAM ADDRESS WITH NO OFFSET - COMMAND 0X06
	cmd(6);
}

/*DISPLAY CHARACHTER*/



void dis_char(char data)
{
	char msb, lsb;

	msb = data & 0xF0;		//ASSIGN DATA MOST SIGNIFICANT BITS TO msb

	lsb = data & 0x0F;		//ASSIGN DATA LEAST SIGNIFICANT BITS TO lsb

	mode_select(1);			//SELECT DATA MODE

	port(msb>>4);			//SEND msb OVER DATABUS

	enb_tri();

	port(lsb);				//SEND lsb OVER DATABUS

	enb_tri();
}

/*SET CURSOR POSITION*/



void dis_position(char i, char j)
{
	if (i==0)			//IF i = 0 DISPLAY IN FIRST LINE
	{					//COMMAND FOR FIRST LINE IS 0X80
		cmd(8);			//SEND COMMAND msb FIRST AND lsb SECOND
		cmd(j);			//j IS THE HORIZONTAL POSITION
	}
	else if (i==1)		//IF i = 1 DISPLAY IN SECOND LINE
	{
		cmd(12);		//COMMAND FOR SECOND LINE IS 0XC0, C = 12
		cmd(j);
	}
}

/*CLEAR LCD*/



void clr_dis(void)
{
	cmd(0);		//CLEAR DISPLAY COMMAND 0X01
	cmd(1);

	cmd(0);		//RETTURN CURSOR HOME COMMAND 0X02
	cmd(2);
}

/*DISPLAY STRING*/



void dis_string(unsigned char row, unsigned char col, char *str)
{
	dis_position( row, col );

	while (*str!='\0')		//while string pointer do not point to nothing
	{
		dis_char(*str);		//call dis_char functions to display what string pointer points to

		++str;				//increment string pointer to point to the next character in the array
	}
}

/*DISPLAY SHIFTTING*/



void dis_shift(char dir)
{
	if ( dir == 'R' )
	{
		cmd(1);				//SHIFT RIGHT COMMAND 0X18
		cmd(8);
	}
	else if ( dir == 'L' )
	{
		cmd(1);				//SHIFT LEFT COMMAND 0X1C
		cmd(12);
	}
}

