/*
 * task_2.c
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
PORTA=0b00000001;
_delay_ms(5000);
PORTA=0b00000010;
_delay_ms(1000);
PORTA=0b00000100;
_delay_ms(2000);

PORTA=0b00000010;
_delay_ms(1000);
PORTA=0b00000001;
_delay_ms(5000);

}
}
