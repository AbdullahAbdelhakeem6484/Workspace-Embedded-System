/*
 * STEPPER_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include"macros.h"
#include"STD_Types.h"
#include"DIO_interface.h"
#include"STEPPER_config.h"
#include"STEPPER_interface.h"
#include<util/delay.h>
#define F_CPU 12000000

void stepper_voidInit(void)
{
	DIO_voidSetPinDir(PORT_C,PIN_0,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_1,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_2,OUTPUT);
	DIO_voidSetPinDir(PORT_C,PIN_3,OUTPUT);
}
void stepper_voidRightForever(void)
{
		while(1)
			{
				DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PIN_0
				DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
				_delay_ms(2);

				DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
				DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PIN_1
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
				_delay_ms(2);
				DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
				DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
				DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);//PIN_2
				DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
				_delay_ms(2);
				DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
				DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
				DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
				DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);//PIN_3
				_delay_ms(2);
			}
}
void stepper_voidLeftForever(void)
{

	while(1)
	{
		DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
		DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
		DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
		DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);//PIN_3
		_delay_ms(2);
		DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
		DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
		DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);//PIN_2
		DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
		_delay_ms(2);
		DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
		DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PIN_1
		DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
		DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
		_delay_ms(2);
		DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PIN_0
		DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
		DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
		DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
		_delay_ms(2);
}
}
void stepper_voidStop(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
}

void stepper_void360Right(void)
{


	u32 i;
	for( i=0;i<520;i++)
	{
					DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PIN_0
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);
					_delay_ms(period);

					DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);
					DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PIN_1
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(period);
					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);
					DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);//PIN_2
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(period);
					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);
					DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);//PIN_3
					_delay_ms(period);


	}
	_delay_ms(1000);


}

void stepper_void360Left(void)
{
	u32 i;
		for( i=0;i<520;i++)
	{
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);//PIN_3
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);//PIN_2
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PIN_1
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PIN_0
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
	}
		_delay_ms(1000);

}

void stepper_void90Right(void)
{u32 i;
for( i=0;i<130;i++)
	{
					DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PIN_0
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(2);

					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PIN_1
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(2);
					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);//PIN_2
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(2);
					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);//PIN_3
					_delay_ms(2);
				}
_delay_ms(1000);

}
void stepper_void90Left(void)
{
	u32 i;
	for( i=0;i<130;i++)
	{
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);//PIN_3
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);//PIN_2
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PIN_1
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PIN_0
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
	}
	_delay_ms(1000);
}
void stepper_void270Right(void)
{
	u32 i;
	for( i=0;i<390;i++)
	{
					DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PIN_0
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(2);

					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PIN_1
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(2);
					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);//PIN_2
					DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
					_delay_ms(2);
					DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
					DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);//PIN_3
					_delay_ms(2);
				}
	_delay_ms(1000);

}
void stepper_void270Left(void)
{
	u32 i;
		for( i=0;i<390;i++)
	{
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,HIGH);//PIN_3
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,HIGH);//PIN_2
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_1,HIGH);//PIN_1
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(PORT_C,PIN_0,HIGH);//PIN_0
			DIO_voidSetPinValue(PORT_C,PIN_1,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_2,LOW);
			DIO_voidSetPinValue(PORT_C,PIN_3,LOW);
			_delay_ms(2);
	}
		_delay_ms(1000);

}
