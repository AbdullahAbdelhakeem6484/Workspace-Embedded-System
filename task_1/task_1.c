/*
 * task_1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */

#include <avr/io.h>
#define F_CPU 12000000
#include <util/delay.h>

int main (void)
{
DDRA=0XFF;
while (1)
{
PORTA=0b10000001;
_delay_ms(200);
PORTA=0b01000010;
_delay_ms(200);
PORTA=0b00100100;
_delay_ms(200);
PORTA=0b00011000;
_delay_ms(200);
PORTA=0b00100100;
_delay_ms(200);
PORTA=0b01000010;
_delay_ms(200);
PORTA=0b10000001;
_delay_ms(200);


}




}
