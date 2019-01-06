/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"
#include"sevenSeg_interface.h"
#include"sevenSeg_config.h"

/* start the main program */
int main(void)
{
   u32 i;
   SEVR_voidInit();
   while(1)
    {
	    for(i=0;i<10;i++)	 // loop to display 0000-9999
		 {
	    	SEVR_VoidDisplayNumber(i);
		 }
	}
   return 0;
  }
