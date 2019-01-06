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

void __vector_11(void)  __attribute__((signal,used,externally_visible));
void led_func(void);
void led_func2(void);
void StartOS(void);
void Scheduler(void);

u32 OVF_count;

typedef enum {
	paused=0,
	running,
}stateType;

typedef struct{
	u32 firstDelay;
	u32 priodicity;
	void (*codePtr)(void);
	stateType task_state;
}task_type;

task_type *tasks_arr[2] = {0};



int main (void)
{
	task_type led_task;
	task_type led_task2;

	DIO_voidSetPinValue(PORT_D,PIN_7,HIGH);

	DIO_voidSetPinDir(PORT_D,PIN_7,OUTPUT);
	DIO_voidSetPinDir(PORT_D,PIN_6,OUTPUT);

	led_task.firstDelay = 0;
	led_task.priodicity = 500;
	led_task.codePtr    = led_func;
	led_task.task_state = running;

	led_task2.firstDelay = 0;
	led_task2.priodicity = 1000;
	led_task2.codePtr    = led_func2;
	led_task2.task_state = running;

	tasks_arr[0]=&led_task;
	tasks_arr[1]=&led_task2;

	StartOS();

	while(1);

	return 0;
}


void Scheduler(void)
{

	u8 i;
	for(i=0;i<2;i++)
	{
		if(tasks_arr[i]!=0)
		{
			if(tasks_arr[i]->task_state==running)
			{
				if(tasks_arr[i]->firstDelay==0)
				{
					tasks_arr[i]->codePtr();
					tasks_arr[i]->firstDelay=tasks_arr[i]->priodicity-1;

				}
				else
				{
					tasks_arr[i]->firstDelay--;
				}
			}

		}

	}
}


void __vector_11(void)
{
	OVF_count++;
	if(OVF_count==47)
	{
		OVF_count=0;
		TCNT0=32;
		Scheduler();
	}



}


void StartOS(void)
{
	TCNT0=32;

	//• Bit 6, 3 – WGM01:0: Waveform Generation Mode
	CLEAR_BIT(TCCR0,6);
	CLEAR_BIT(TCCR0,3);
	//• Bit 2:0 – CS02:0: Clock Select clkI/O/(No prescaling)
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	//• Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
	SET_BIT(TIMSK,0);

	SET_BIT(SREG,7);
}

void led_func(void)
{
	DIO_voidTogglePinValue(PORT_D,PIN_7);
}

void led_func2(void)
{
	DIO_voidTogglePinValue(PORT_D,PIN_6);
}
