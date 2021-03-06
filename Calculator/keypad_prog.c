/*
 * keypad_prog.c
 *
 *  Created on: ??�/??�/????
 *      Author: Fly labs
 */
#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"
#include"keypad_interface.h"
#include"keypad_config.h"

void KEYPAD_voidInit(void)
{
	DIO_voidSetPinDir(R1_PORT,R1_PIN,OUTPUT);
	DIO_voidSetPinDir(R2_PORT,R2_PIN,OUTPUT);
	DIO_voidSetPinDir(R3_PORT,R3_PIN,OUTPUT);
	DIO_voidSetPinDir(R4_PORT,R4_PIN,OUTPUT);

	DIO_voidSetPinDir(C1_PORT,C1_PIN,INPUT);
	DIO_voidSetPinDir(C2_PORT,C2_PIN,INPUT);
	DIO_voidSetPinDir(C3_PORT,C3_PIN,INPUT);
	DIO_voidSetPinDir(C4_PORT,C4_PIN,INPUT);

	DIO_voidSetPinValue(C1_PORT,C1_PIN,HIGH);
	DIO_voidSetPinValue(C2_PORT,C2_PIN,HIGH);
	DIO_voidSetPinValue(C3_PORT,C3_PIN,HIGH);
	DIO_voidSetPinValue(C4_PORT,C4_PIN,HIGH);


}
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

