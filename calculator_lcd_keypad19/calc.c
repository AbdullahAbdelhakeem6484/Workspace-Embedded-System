/*
 * calc.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */
#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 12000000
#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"


#include<string.h>

//Define Macros
#define Error  13    // Any value other than 0 to 9 is good here

//Function declarations
void cct_init(void);
void delay(int);
void lcdinit(void);
void writecmd(int);
void writedata(char);
void writeline(char[]);
void ReturnHome(void);
char READ_SWITCHES(void);
char get_key(void);
int get_num(char);
char get_func(char);
void DispError(int);
void disp_num(int);


//*******************
//Pin description
/*
P2 is data bus
P3.7 is RS
P3.6 is E
P1.0 to P1.3 are keypad row outputs
P1.4 to P1.7 are keypad column inputs
*/
//********************
// Define Pins
//********************
#define no_key  0xFF
#define R1_PORT   PORT_A
#define R2_PORT   PORT_A
#define R3_PORT   PORT_A
#define R4_PORT   PORT_A


#define C1_PORT   PORT_A
#define C2_PORT   PORT_A
#define C3_PORT   PORT_A
#define C4_PORT   PORT_A

#define R1_PIN   PIN_7
#define R2_PIN   PIN_6
#define R3_PIN   PIN_5
#define R4_PIN   PIN_4


#define C1_PIN   PIN_3
#define C2_PIN   PIN_2
#define C3_PIN   PIN_1
#define C4_PIN   PIN_0

#define RS_PORT  PORT_B
#define RS_PIN   PIN_0

#define RW_PORT  PORT_B
#define RW_PIN   PIN_1

#define EN_PORT  PORT_B
#define EN_PIN   PIN_2

#define D0_PORT  PORT_D
#define D1_PORT  PORT_D
#define D2_PORT  PORT_D
#define D3_PORT  PORT_D
#define D4_PORT  PORT_D
#define D5_PORT  PORT_D
#define D6_PORT  PORT_D
#define D7_PORT  PORT_D

#define D0_PIN  PIN_0
#define D1_PIN  PIN_1
#define D2_PIN  PIN_2
#define D3_PIN  PIN_3
#define D4_PIN  PIN_4
#define D5_PIN  PIN_5
#define D6_PIN  PIN_6
#define D7_PIN  PIN_7


// ***********************************************************
// Main program
//
int main(void)
{
   char key;                     //key char for keeping record of pressed key
   int num1 = 0;                 //First number
   char func = '+';              //Function to be performed among two numbers
   int num2 = 0;                 //Second number

   cct_init();                   //Make input and output pins as required
   lcdinit();                    //Initilize LCD

   while(1)
   {

     //get numb1
     key = get_key();
     writecmd(0x01);            //clear display

	 writedata(key);            //Echo the key pressed to LCD
	 num1 = get_num(key);       //Get int number from char value, it checks for wrong input as well

	 if(num1!=Error)            //if correct input then proceed, num1==Error means wrong input
	 {
		 //get function
		 key = get_key();
		 writedata(key);                  //Echo the key pressed to LCD
		 func = get_func(key);            //it checks for wrong func

		 if(func!='e')                    //if correct input then proceed, func=='e' means wrong input
		 {
			 //get numb2
			 key = get_key();
			 writedata(key);              //Echo the key pressed to LCD
			 num2 = get_num(key);         //Get int number from char value, it checks for wrong input as well

			 if(num2!=Error)              //if correct input then proceed, num2==Error means wrong input
			 {
				 //get equal sign
				 key = get_key();
				 writedata(key);          //Echo the key pressed to LCD

				 if(key == '=')           //if = is pressed then proceed
				 {
					 switch(func)         //switch on function
					 {
					 case '+': disp_num(num1+num2); break;
					 case '-': disp_num(num1-num2); break;
					 case 'x': disp_num(num1*num2); break;
					 case '/': disp_num(num1/num2); break;
					 }
				 }
				 else				      //key other then = here means error wrong input
				 {
					 if(key == 'C')       //if clear screen is pressed then clear screen and reset
					 {
					    writecmd(0x01);   //Clear Screen

					 }
					 else
					 {
					 	DispError(0); 	  //Display wrong input error

					 }
				 }
			 }
		 }
     }
   }
}



void cct_init(void)
{//KEYPAD
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

		DIO_voidSetPinDir(D0_PORT,D0_PIN,OUTPUT);
		DIO_voidSetPinDir(D1_PORT,D1_PIN,OUTPUT);
		DIO_voidSetPinDir(D2_PORT,D2_PIN,OUTPUT);
		DIO_voidSetPinDir(D3_PORT,D3_PIN,OUTPUT);
		DIO_voidSetPinDir(D4_PORT,D4_PIN,OUTPUT);
		DIO_voidSetPinDir(D5_PORT,D5_PIN,OUTPUT);
		DIO_voidSetPinDir(D6_PORT,D6_PIN,OUTPUT);
		DIO_voidSetPinDir(D7_PORT,D7_PIN,OUTPUT);

		DIO_voidSetPinDir(RS_PORT,RS_PIN,OUTPUT);
		DIO_voidSetPinDir(RW_PORT,RW_PIN,OUTPUT);
		DIO_voidSetPinDir(EN_PORT,EN_PIN,OUTPUT);




	}


void delay(int a)
{
   int i;
   for(i=0;i<a;i++);   //null statement
}

void writedata(char Character)
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


void writecmd(int Command)
{
	DIO_voidSetPinValue(RS_PORT,RS_PIN,LOW);
		DIO_voidSetPinValue(RW_PORT,RW_PIN,LOW);

		DIO_voidSetPinValue(D0_PORT,D0_PIN,GET_BIT(Command,PIN_0));
		DIO_voidSetPinValue(D1_PORT,D1_PIN,GET_BIT(Command,PIN_1));
		DIO_voidSetPinValue(D2_PORT,D2_PIN,GET_BIT(Command,PIN_2));
		DIO_voidSetPinValue(D3_PORT,D3_PIN,GET_BIT(Command,PIN_3));
		DIO_voidSetPinValue(D4_PORT,D4_PIN,GET_BIT(Command,PIN_4));
		DIO_voidSetPinValue(D5_PORT,D5_PIN,GET_BIT(Command,PIN_5));
		DIO_voidSetPinValue(D6_PORT,D6_PIN,GET_BIT(Command,PIN_6));
		DIO_voidSetPinValue(D7_PORT,D7_PIN,GET_BIT(Command,PIN_7));

		DIO_voidSetPinValue(EN_PORT,EN_PIN,HIGH);
		_delay_ms(2);
		DIO_voidSetPinValue(EN_PORT,EN_PIN,LOW);

}

void lcdinit(void)
{
  /*///////////// Reset process from datasheet /////////
     delay(15000);
   writecmd(0x30);
     delay(4500);
   writecmd(0x30);
     delay(300);
   writecmd(0x30);
     delay(650);
  /////////////////////////////////////////////////////
   writecmd(0x38);    //function set
   writecmd(0x0c);    //display on,cursor off,blink off
   writecmd(0x01);    //clear display
   writecmd(0x06);    //entry mode, set increment*/
	//LCD


			writecmd(0x38);    //turn on
			_delay_ms(5);
			writecmd(0x0C);   //make cursor invisible
			_delay_ms(5);

			writecmd(0x01); //clear screan
			_delay_ms(5);



}

void ReturnHome(void)     /* Return to 0 cursor location */
{
   writecmd(0x02);
   delay(1500);

}

void writeline(char Line[])
{
   int i;
   for(i=0;i<strlen(Line);i++)
   {
      writedata(Line[i]);     /* Write Character */
   }

   ReturnHome();          /* Return to 0 cursor position */
}

char READ_SWITCHES(void)
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
         	// Means no key has been pressed


char get_key(void)           //get key from user
{
	char key = 'n';              //assume no key pressed

	while(key=='n')              //wait untill a key is pressed
		key = READ_SWITCHES();   //scan the keys again and again

	return key;                  //when key pressed then return its value
}

int get_num(char ch)         //convert char into int
{
	switch(ch)
	{
		case '0': return 0; break;
		case '1': return 1; break;
		case '2': return 2; break;
		case '3': return 3; break;
		case '4': return 4; break;
		case '5': return 5; break;
		case '6': return 6; break;
		case '7': return 7; break;
		case '8': return 8; break;
		case '9': return 9; break;
		case 'C': writecmd(0x01); return Error; break;  //this is used as a clear screen and then reset by setting error
		default: DispError(0); return Error; break;     //it means wrong input
	}
}

char get_func(char chf)            //detects the errors in inputted function
{
	if(chf=='C')                   //if clear screen then clear the LCD and reset
	{
		writecmd(0x01);            //clear display

		return 'e';
	}

	if( chf!='+' && chf!='-' && chf!='x' && chf!='/' )  //if input is not from allowed funtions then show error
	{
		DispError(1);

		return 'e';
	}

	return chf;                        //function is correct so return the correct function
}


void DispError(int numb)           //displays differet error messages
{
	writecmd(0x01);                //clear display

	switch(numb)
	{
	case 0: 	writeline("Wrong Input");      break;
	case 1: 	writeline("Wrong Function");   break;
	default:    writeline("Wrong Input");      break;
	}
}

void disp_num(int numb)            //displays number on LCD
{
	unsigned char UnitDigit  = 0;  //It will contain unit digit of numb
	unsigned char TenthDigit = 0;  //It will contain 10th position digit of numb

	if(numb<0)
	{
		numb = -1*numb;  // Make number positive
		writedata('-');	 // Display a negative sign on LCD
	}

	TenthDigit = (numb/10);	          // Findout Tenth Digit

	if( TenthDigit != 0)	          // If it is zero, then don't display
		writedata(TenthDigit+0x30);	  // Make Char of TenthDigit and then display it on LCD

	UnitDigit = numb - TenthDigit*10;

	writedata(UnitDigit+0x30);	  // Make Char of UnitDigit and then display it on LCD
}


