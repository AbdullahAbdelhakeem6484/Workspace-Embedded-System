/*
 * test5.c
 
 *
 * Created: 9/16/2016 5:08:21 PM
 * Author : WALY
 */
 
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "keypad.h"
#include "lcd.h"
#include "types.h"
#include "calculator.h"


int main(void)
{
    keypad_init();
	lcd_init();
	lcd_write_string("     Hello!");
	_delay_ms(500);
	lcd_clearDisplay();
	lcd_write_string("     (^__^)");
	_delay_ms(750);
	lcd_clearDisplay();
	
    uint8 Flag;
 
    while (1) 
    {
		Flag=StartPoint;
		while(Flag==StartPoint)		{   Flag=getdata();	  }
		while(Flag==AnalyzePoint)	{   Flag=analyze();	  }
		while(Flag==CalculatePoint)	{   Flag=calculate(); }
		while(Flag==DisplayPoint)	{   Flag=display();	  }
		while(Flag==Reset)			{   Flag=Resetall();  }
    }
}

