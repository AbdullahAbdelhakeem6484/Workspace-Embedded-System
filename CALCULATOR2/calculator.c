/*
 * calculator.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */



#include<avr/io.h>
/*Includes io.h header file where all the Input/Output Registers and its Bits are defined for all AVR microcontrollers*/

#define	F_CPU	12000000
/*Defines a macro for the delay.h header file. F_CPU is the microcontroller frequency value for the delay.h header file. Default value of F_CPU in delay.h header file is 1000000(1MHz)*/

#include<util/delay.h>
/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/

#include"calculator_config.h"
/*4X4 Keypad Function Declarations*/


int main(void)
{
	DDRB=0xff;
	/*All the 8 pins of PortB are declared output (data pins of LCD are connected)*/

	DDRD=0x07;
	/*PD0, PD1 and PD2 pins of PortD are declared output (control pins of LCD are connected)*/

	DDRC=0x0f;
	/*PortC's upper 4 bits are declared input and lower 4 bits are declared output(4x4 Keypad is connected)*/

	PORTC=0xff;
	/*PortC's lower 4 bits are given high value and pull-up are enabled for upper 4 bits*/

	unsigned char keypad_value;
	/*Variable declarations*/

	lcd_init();
	/*LCD initialization*/

	lcd_string_write("ABLab Solutions");
	/*String display in 1st row of LCD*/

	lcd_command_write(0xc0);
	/*Cursor moves to 2nd row 1st column of LCD*/

	lcd_string_write("www.ablab.in");
	/*String display in 2nd row of LCD*/

	_delay_ms(500);
	_delay_ms(500);
	_delay_ms(500);
	_delay_ms(500);
	/*Display stays for 2 second*/

	lcd_command_write(0x01);
	/*Clear Screen*/

	/*Start of infinite loop*/
	while(1)
	{
		lcd_command_write(0x80);
		/*Cursor moves to 1st row 1st column of LCD*/

		lcd_string_write("Press any Key");
		/*String display in 1st row of LCD*/

		lcd_command_write(0xc0);
		/*Cursor moves to 2nd row 1st column of LCD*/

		lcd_string_write("Key Value: ");
		/*String display in 2nd row of LCD*/

		keypad_value=read_keypad();
		/*Scan's 4X4 keypad and returns pressed key value or default value*/

		/*Checking if any key is pressed or not*/
		if(keypad_value!=0xff)
		{
			switch(keypad_value)
			{
			    case 0:
					lcd_data_write('0');
					/*Displays 0 in 2nd row of LCD*/

			    	break;
					/*Break statement*/

			    case 1:
					lcd_data_write('1');
					/*Displays 1 in 2nd row of LCD*/

			    	break;
					/*Break statement*/

			    case 2:
					lcd_data_write('2');
					/*Displays 2 in 2nd row of LCD*/

			    	break;
					/*Break statement*/

				case 3:
					lcd_data_write('3');
					/*Displays 3 in 2nd row of LCD*/

			    	break;
					/*Break statement*/

			    case 4:
					lcd_data_write('4');
					/*Displays 4 in 2nd row of LCD*/

			    	break;
					/*Break statement*/

			    case 5:
					lcd_data_write('5');
					/*Displays 5 in 2nd row of LCD*/

			    	break;
					/*Break statement*/

			    case 6:
					lcd_data_write('6');
					/*Displays 6 in 2nd row of LCD*/

			    	break;
					/*Break statement*/

			    case 7:
					lcd_data_write('7');
					/*Displays 7 in 2nd row of LCD*/

			    	break;
					/*Break statement*/

			    case 8:
					lcd_data_write('8');
					/*Displays 8 in 2nd row of LCD*/

			    	break;
					/*Break statement*/

			    case 9:
					lcd_data_write('9');
					/*Displays 9 in 2nd row of LCD*/

			    	break;
					/*Break statement*/

				case 10:
					lcd_data_write('*');
					/*Displays * in 2nd row of LCD*/

			    	break;
					/*Break statement*/

				case 11:
					lcd_data_write('#');
					/*Displays # in 2nd row of LCD*/

			    	break;
					/*Break statement*/

				case 12:
					lcd_data_write('A');
					/*Displays A in 2nd row of LCD*/

			    	break;
					/*Break statement*/

				case 13:
					lcd_data_write('B');
					/*Displays B in 2nd row of LCD*/

			    	break;
					/*Break statement*/

				case 14:
					lcd_data_write('C');
					/*Displays C in 2nd row of LCD*/

			    	break;
					/*Break statement*/;

				case 15:
					lcd_data_write('D');
					/*Displays D in 2nd row of LCD*/

			    	break;
					/*Break statement*/;
			}
		}
		else
			;
			/*Null statement*/

		_delay_ms(200);
		/*200ms delay as guard time between two consecutive pressing of key*/
	}
}
/*End of program*/

