/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"macros.h"
#include"STD_Types.h"
#include<avr/io.h>
#include"DIO_interface.h"
#include "LCD_interface.h"
#include"FreeRTOS.h"
#include"task.h"


void TaskCode(void*pv);
xTaskHandle TaskHandler;
int main (void)
{
	DIO_voidSetPinDir(PORT_D,PIN_7,OUTPUT);
	xTaskCreate(TaskCode,"led_blink",60,NULL,1,&TaskHandler);

	vTaskStartScheduler();




return 0;
}


void TaskCode(void *pv)
{


	while(1)
	 {
		 DIO_voidSetPinValue(PORT_D,PIN_7,HIGH);
		 vTaskDelay(1000);
		 DIO_voidSetPinValue(PORT_D,PIN_7,LOW);
		 vTaskDelay(1000);


	 }



}



























































/*
 *
 * #include"macros.h"
#include"STD_Types.h"
#include<avr/io.h>
#include"DIO_interface.h"
#include"FreeRTOS.h"
#include"task.h"


void TaskCode(void*pv);
xTaskHandle TaskHandler;
int main (void)
{
	DIO_voidSetPinDir(PORT_D,PIN_7,OUTPUT);
	xTaskCreate(TaskCode,"led_blink",60,NULL,1,&TaskHandler);

	vTaskStartScheduler();




return 0;
}


void TaskCode(void *pv)
{


	while(1)
	 {
		 DIO_voidSetPinValue(PORT_D,PIN_7,HIGH);
		 vTaskDelay(1000);
		 DIO_voidSetPinValue(PORT_D,PIN_7,LOW);
		 vTaskDelay(1000);


	 }



}
 * */
