#include<avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 12000000UL
#include"STD_Types.h"
#include"macros.h"
#include"DIO_interface.h"


#define   TRIGER_DDR    DDRD
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTD
#define   ECHO_PULLUP   PORTD
#define   TRIGER        0
#define   ECHO          3

/*************************************************
 *  API functions
 *************************************************/

void ultrasonic_init(void);
void enable_ex_interrupt(void);
void ultrasonic_triger(void);


u8 sensor_working=0;
u8 rising_edge=0;
u32 timer_counter=0;
u32 distance;
//u8 distance_str[10];

void ultrasonic_init(void){

  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  enable_ex_interrupt();
  //timer0_init();
  //• Bit 6, 3 – WGM01:0: Waveform Generation Mode
  			CLEAR_BIT(TCCR0,6);
  			CLEAR_BIT(TCCR0,3);
  	//• Bit 2:0 – CS02:0: Clock Select clkI/O/(No prescaling)
  			SET_BIT(TCCR0,0);
  			CLEAR_BIT(TCCR0,1);
  			CLEAR_BIT(TCCR0,2);
  	//• Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
  			SET_BIT(TIMSK,0);
  return;
}

void enable_ex_interrupt(void){

  MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
  GICR  |= (1<<INT1);			// Enable INT1 interrupts.

  return;
}

void ultrasonic_triger(void){
  if(!sensor_working){
    TRIGER_PORT|=(1<<TRIGER);
    _delay_us(15);
    TRIGER_PORT&=~(1<<TRIGER);
    sensor_working=1;
  }
}

ISR(INT1_vect){
  if(sensor_working==1){
    if(rising_edge==0){
      TCNT0=0x00;
      rising_edge=1;
      timer_counter=0;
    }
  else{
    distance=(timer_counter*256+TCNT0)/466;
    timer_counter=0;
    rising_edge=0;
  }
}}

ISR(TIMER0_OVF_vect){
    timer_counter++;
    if(timer_counter >730){
      TCNT0=0x00;
      sensor_working=0;
      rising_edge=0;
      timer_counter=0;
    }
}


void Motor_voidBackword(void)
{
	DIO_voidSetPinValue(PORT_C,PIN_4,LOW); /*Motor_1___pin1A*/
	DIO_voidSetPinValue(PORT_C,PIN_5,HIGH); /*Motor_1___pin2A*/
	DIO_voidSetPinValue(PORT_C,PIN_6,LOW); /*Motor_2___pin1B*/
	DIO_voidSetPinValue(PORT_C,PIN_7,HIGH);  /*Motor_2___pin2B*/


}
void Motor_voidFORWARD(void)
    {
	DIO_voidSetPinValue(PORT_C,PIN_4,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_5,LOW);
	DIO_voidSetPinValue(PORT_C,PIN_6,HIGH);
	DIO_voidSetPinValue(PORT_C,PIN_7,LOW);

    }

int main(){

/*motor one*/
DIO_voidSetPinDir(PORT_C,PIN_4,OUTPUT);
DIO_voidSetPinDir(PORT_C,PIN_5,OUTPUT);
/*motor two*/
DIO_voidSetPinDir(PORT_C,PIN_6,OUTPUT);
DIO_voidSetPinDir(PORT_C,PIN_7,OUTPUT);

ultrasonic_init();
sei();

while(1){
	ultrasonic_triger();

  if(distance>10)
  {
	  Motor_voidFORWARD();
	  _delay_ms(2000);
  }
  if(distance<10)
    {
	  Motor_voidBackword();
  	  _delay_ms(2000);
    }


}

  return 0;
}
