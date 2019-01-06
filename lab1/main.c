/*
 * main.c
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
PORTA=0b11111111;
_delay_ms(1000);
//PORTA=0b00000000;
//_delay_ms(1000);


}


return 0;

}
