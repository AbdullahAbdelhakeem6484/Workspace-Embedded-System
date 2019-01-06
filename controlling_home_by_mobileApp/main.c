
#include"STD_Types.h"
#include"macros.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "I2C_interface.h"
#include "EEPROM_interface.h"
#include "LCD_interface.h"

#include<avr/io.h>

#define F_CPU 12000000
#include<util/delay.h>


/*
static u32 j=0;//global variable for counting locations (where each block contain 256 location )
int main(void)
{
	u32 i=0; //local variable for counting indexes of array of strucure
	struct system
	{
		u8 userName[10];
		u8 password[10];

	};

		struct system persons[3]={ {"abdullah",111},
									{"eisa",222},
									{"omar",000},

							     };

EEPROM_voidInit();
LCD_voidInit();
/******************111111*************************/

/*element 0 :  page 0----location(0->6)(7->10)*/

/*
for(i=0,j=0;i<7;++i,++j)
{
	EEPROM_voidWritByte(0,j,persons[0].userName[i]); //EEPROM_voidWritByte(u8 page(block1),u8 location(each block 256 loc),u8 byte(1loc));
	_delay_ms(10);
}

for(i=0;i<3;i++,++j)
{
	EEPROM_voidWritByte(0,j,persons[0].password[i]); //EEPROM_voidWritByte(u8 page(block1),u8 location(each block 256 loc),u8 byte(1loc));
	_delay_ms(10);
}
/***************************************************/
/*******************2222222************************/
/*for(i=0;i<4;++i,++j)
{
	EEPROM_voidWritByte(0,j,persons[1].userName[i]); //EEPROM_voidWritByte(u8 page(block1),u8 location(each block 256 loc),u8 byte(1loc));
	_delay_ms(10);
}

for(i=0;i<3;i++,++j)
{
	EEPROM_voidWritByte(0,j,persons[1].password[i]); //EEPROM_voidWritByte(u8 page(block1),u8 location(each block 256 loc),u8 byte(1loc));
	_delay_ms(10);
}
/***************************************************/
/*****************333333333**************************/
/*for(i=0;i<4;++i,++j)
{
	EEPROM_voidWritByte(0,j,persons[2].userName[i]); //EEPROM_voidWritByte(u8 page(block1),u8 location(each block 256 loc),u8 byte(1loc));
	_delay_ms(10);
}

for(i=0;i<3;i++,++j)
{
	EEPROM_voidWritByte(0,j,persons[2].password[i]); //EEPROM_voidWritByte(u8 page(block1),u8 location(each block 256 loc),u8 byte(1loc));
	_delay_ms(10);
}
LCD_voidWriteString("DONE");


while(1)
{}


return 0;
}

*/
u32 j=0;
int main(void)
{

	EEPROM_voidInit();
	LCD_voidInit();
	u8 username[10];
	u8 password[10];

for(u8 i=0,j=0;i<7;++i,++j)
{
	username [i]=EEPROM_u8ReadByte(0,j);//EEPROM_u8ReadByte(u8 page,u8 location);
}

for(u8 k=0;k<3;k++,++j)
	{
	 password[k]=EEPROM_u8ReadByte(0,j);//EEPROM_u8ReadByte(u8 page,u8 location);

	}
LCD_voidSetCursor(0,0);

LCD_voidWriteString(username);
LCD_voidSetCursor(1,0);

LCD_voidWriteString(password);





while(1)
{}

return 0;
}
