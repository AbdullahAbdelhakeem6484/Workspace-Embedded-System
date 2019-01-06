/*
 * calc.c
 *
 * Created: 25-Sep-16 2:47:42 PM
 *  Author: Serag
 */ 

#include "calc.h"

int main(void)
{
		cal_init();
		
			dis_string(0,0,"When      Come    ;)");
			dis_string(1,4,"Dreams    True ;)");
			
			_delay_ms(50);
			
			for (int start = 0;start < 25; ++start)
			{
				_delay_ms(5);
				dis_shift('L');
			}
		
    	while(1)
    	{
			calculate();
    	}
}