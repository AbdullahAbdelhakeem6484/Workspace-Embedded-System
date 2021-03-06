/*
 * calc_prog.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */
#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"
#include "LCD_interface.h"
#include"LCD_config.h"
#include"keypad_interface.h"
#include"keypad_config.h"
#include"calc_interface.h"



static u32 key;		     //key variable to store pressed key
static u32 op;			 //op variable to store operation ID and op_char for operation symbol
static u8 op_char;
u32 a, b;					//a & b variables to store two numbers of operation
static f64 result;			//result value should be stored in this variable
static u8 lcd_buf[16];		//lcd_buf array is the lcd buffer


/*initialize keypad and lcd*/

void cal_init(void)
{
	KEYPAD_voidInit();

	LCD_voidInit();

}
/*INITIALIZE DATABUS TO HW PORT*/

u8 KEYPAD_u8GetKey(void)
{
	u8 temp;
	DIO_voidSetPinValue(R1_PORT,R1_PIN,LOW); //DETECT ONE PUTTON ROW
	DIO_voidSetPinValue(R2_PORT,R2_PIN,HIGH);
	DIO_voidSetPinValue(R3_PORT,R3_PIN,HIGH);
	DIO_voidSetPinValue(R4_PORT,R4_PIN,HIGH);

   temp=0;
   temp|=(DIO_u8GetPinValue(C4_PORT,C4_PIN)<<0);
   temp|=(DIO_u8GetPinValue(C3_PORT,C3_PIN)<<1);
   temp|=(DIO_u8GetPinValue(C2_PORT,C2_PIN)<<2);
   temp|=(DIO_u8GetPinValue(C1_PORT,C1_PIN)<<3);

   switch(temp)
   {
   case 0x0E:
	   return '*';
   case 0x0D:
   	   return '#';
   case 0x0B:
   	   return 0;
   case 0x07:
   	   return '=';


   }

    DIO_voidSetPinValue(R1_PORT,R1_PIN,HIGH); //DETECT ONE PUTTON ROW
   	DIO_voidSetPinValue(R2_PORT,R2_PIN,LOW);
   	DIO_voidSetPinValue(R3_PORT,R3_PIN,HIGH);
   	DIO_voidSetPinValue(R4_PORT,R4_PIN,HIGH);

      temp=0;
      temp|=(DIO_u8GetPinValue(C4_PORT,C4_PIN)<<0);
      temp|=(DIO_u8GetPinValue(C3_PORT,C3_PIN)<<1);
      temp|=(DIO_u8GetPinValue(C2_PORT,C2_PIN)<<2);
      temp|=(DIO_u8GetPinValue(C1_PORT,C1_PIN)<<3);

      switch(temp)
      {
      case 0x0E:
   	   return '/';
      case 0x0D:
      	   return 9;
      case 0x0B:
      	   return 8;
      case 0x07:
      	   return 7;


      }
        DIO_voidSetPinValue(R1_PORT,R1_PIN,HIGH); //DETECT ONE PUTTON ROW
      	DIO_voidSetPinValue(R2_PORT,R2_PIN,HIGH);
      	DIO_voidSetPinValue(R3_PORT,R3_PIN,LOW);
      	DIO_voidSetPinValue(R4_PORT,R4_PIN,HIGH);

         temp=0;
         temp|=(DIO_u8GetPinValue(C4_PORT,C4_PIN)<<0);
         temp|=(DIO_u8GetPinValue(C3_PORT,C3_PIN)<<1);
         temp|=(DIO_u8GetPinValue(C2_PORT,C2_PIN)<<2);
         temp|=(DIO_u8GetPinValue(C1_PORT,C1_PIN)<<3);

         switch(temp)
         {
         case 0x0E:
      	   return '-';
         case 0x0D:
         	   return 6;
         case 0x0B:
         	   return 5;
         case 0x07:
         	   return 4;


         }

           DIO_voidSetPinValue(R1_PORT,R1_PIN,HIGH); //DETECT ONE PUTTON ROW
         	DIO_voidSetPinValue(R2_PORT,R2_PIN,HIGH);
         	DIO_voidSetPinValue(R3_PORT,R3_PIN,HIGH);
         	DIO_voidSetPinValue(R4_PORT,R4_PIN,LOW);

            temp=0;
            temp|=(DIO_u8GetPinValue(C4_PORT,C4_PIN)<<0);
            temp|=(DIO_u8GetPinValue(C3_PORT,C3_PIN)<<1);
            temp|=(DIO_u8GetPinValue(C2_PORT,C2_PIN)<<2);
            temp|=(DIO_u8GetPinValue(C1_PORT,C1_PIN)<<3);

            switch(temp)
            {
            case 0x0E:
         	   return '+';
            case 0x0D:
            	   return 3;
            case 0x0B:
            	   return 2;
            case 0x07:
            	   return 1;


            }

            return no_key;

}



/*SWITCH BETWEEN COMMAND MODE OR DATA MODE*/



/*DISPLAY CHARACHTER*/


void LCD_voidWriteCharacter(u8 Character)
{


	DIO_voidSetPinValue(RS_PORT,RS_PIN,HIGH);
	DIO_voidSetPinValue(RW_PORT,RW_PIN,LOW);

	DIO_voidSetPinValue(D0_PORT,D0_PIN,GET_BIT(Character,PIN_0));
	DIO_voidSetPinValue(D1_PORT,D1_PIN,GET_BIT(Character,PIN_1));
	DIO_voidSetPinValue(D2_PORT,D2_PIN,GET_BIT(Character,PIN_2));
	DIO_voidSetPinValue(D3_PORT,D3_PIN,GET_BIT(Character,PIN_3));
	DIO_voidSetPinValue(D4_PORT,D4_PIN,GET_BIT(Character,PIN_4));
	DIO_voidSetPinValue(D5_PORT,D5_PIN,GET_BIT(Character,PIN_5));
	DIO_voidSetPinValue(D6_PORT,D6_PIN,GET_BIT(Character,PIN_6));
	DIO_voidSetPinValue(D7_PORT,D7_PIN,GET_BIT(Character,PIN_7));

	DIO_voidSetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(EN_PORT,EN_PIN,LOW);

}

/*SET CURSOR POSITION*/
/*SET CURSOR POSITION*/



void dis_position(char i, char j)
{
	if (i==0)			//IF i = 0 DISPLAY IN FIRST LINE
	{					//COMMAND FOR FIRST LINE IS 0X80
		LCD_voidSendCommand(8);			//SEND COMMAND msb FIRST AND lsb SECOND
		LCD_voidSendCommand(j);			//j IS THE HORIZONTAL POSITION
	}
	else if (i==1)		//IF i = 1 DISPLAY IN SECOND LINE
	{
		LCD_voidSendCommand(12);		//COMMAND FOR SECOND LINE IS 0XC0, C = 12
		LCD_voidSendCommand(j);
	}
}


/*DISPLAY STRING*/
void dis_string(unsigned char row, unsigned char col, char *str)
{
	dis_position( row, col );

	while (*str!='\0')		//while string pointer do not point to nothing
	{
		LCD_voidWriteCharacter(*str);		//call dis_char functions to display what string pointer points to

		++str;				//increment string pointer to point to the next character in the array
	}
}


/*determine calculator operation*/


void cal_op(void)
{
	 if(key==0x0D)			//operation add
	{
		key=0;
		op=1;
		op_char='+';
	}

	else if(key==0x0C)		//operation subtraction
	{
		key=0;
		op=2;
		op_char='-';
	}

	else if(key==0x0B)		//operation multiplication
	{
		key=0;
		op=3;
		op_char='x';
	}

	else if(key==0x0A)		//operation division
	{
		key=0;
		op=4;
		op_char='/';
	}

	else if(key==0x0E)		//operation execution
	{
		key=0;
		op=5;
	}

	else if(key=='0')		//allow ZERO-Bug Fix
	{
		key=0;
	}

	else if(key==0x0F)		//operation on/clear
	{
		a=0;
		b=0;
		result=0;
		op=0;
		key = 0;
		clr_dis();
	}
}

/*run the calculation process*/


void cal_run(void)
{

		if(op==0)										//if no operation is selected then store the first number
		{
			a=a*10+key;									//storing number of n digits
			sprintf(lcd_buf,"%1li",a);
			dis_string(0,0,lcd_buf);
		}
														//if Any operation is selected then start storing the second number
		else if(op==1 || op==2 || op==3 || op==4)
		{
			b=b*10+key;									//display both numbers at the same time through lcd buffer
			sprintf(lcd_buf,"%1li%c%1li",a,op_char,b);
			dis_string(0,0,lcd_buf);
		}

		else if(op==5)									//if operation execute is selected
		{
														//select between different operations
			if(op_char=='+')
				result=a+b;

			else if(op_char=='-')
				result=a-b;

			else if(op_char=='x')
				result=a*b;

			else if(op_char=='/')
				result=(float)a/b;
														//display the result
			sprintf(lcd_buf,"=%.2f",result);
			dis_string(1,0,lcd_buf);

			a=0;										//clear the memory for next calculation
			b=0;
			result=0;
			op=0;
		}
}

/*run the calculator*/


void calculate(void)
{
		key = key_scan();		//obtain key pressed

		if (key != 0)			//if key = true
		{
			cal_op();			//first check if pressed key is operation identifier
			cal_run();			//store number or apply operation
			key = 0;			//clear key for next trial
		}
}
/*DISPLAY SHIFTTING
void dis_shift(char dir)
{
	if ( dir == 'R' )
	{
		LCD_voidSendCommand(1);				//SHIFT RIGHT COMMAND 0X18
		LCD_voidSendCommand(8);
	}
	else if ( dir == 'L' )
	{
		LCD_voidSendCommand(1);				//SHIFT LEFT COMMAND 0X1C
		LCD_voidSendCommand(12);
	}
}*/
