/*
 * TIMER.c
 *
 * Created: 9/7/2022 11:40:58 PM
 *  Author: Mahmoud
 */ 
#include "TIMER.h"
volatile uint32 ov;
// all this functions working on 8MHZ internal clock
void Delay_ms(uint32 value){
	while(value>0){
	TCNT0=131;// load value to make delay 1ms
	TCCR0=0x03;//working in normal mode and 64 prescalar
	while((READ_BIT(TIFR,0))==0);// wait for TVOD to be 1
	SET_BIT(TIFR,0); // clear TIFR
	TCCR0=0x00;// stop timer
	value--;
    }
}
void Delay_us(uint32 value){
	while(value>0){
		TCNT0=248;//load value to make delay 1us
		TCCR0=0x01;//working in normal mode and 0 prescalar
		while((READ_BIT(TIFR,0))==0);
		SET_BIT(TIFR,0);
		TCCR0=0x00;
		value--;
	}
}
void PWM(uint32 duty_cycle){
	if (duty_cycle <=255)
	{
		DIO_init_pin(PORT_B,PIN3,OUT);
		OCR0=duty_cycle;
		TCCR0 = 0x62;//here in pwm correct phase 8 prescalar 
	}
	else{
		//error 
	}
}

uint32 pulseWidth(){
	uint32 t1,t2;
	// IN NORMAL MODE
	TCCR1A = 0X00;
	// WE ENABLE INPUT CAPTURE RAISING EDGE WITH PRESCALAR 8
	TCCR1B |= 1<<ICES1 | 1<<2;
	cli();// disable the interupt
	while(!READ_BIT(TIFR,5)); // we until ICF1 to set
	t1 = ICR1;
	TIFR |= (1<<5); //clear ICF1
	TIFR |= 1<<2;	/* Clear Timer Overflow flag */
	// WE ENABLE INPUT CAPTURE FAILING EDGE WITH PRESCALAR 8
	sei();
	TCCR1B |= 0<<ICES1 | 1<<2;
	TIMSK |= 1<<TOIE1; // enable interrupt  of timer 1
	while(!READ_BIT(TIFR,5)); // we until ICF1 to set
	t2 = ICR1 ;
	TIFR = (1<<5); //clear ICF1
	TIFR = 1<<2;	/* Clear Timer Overflow flag */
	//TIMSK |= 0<<TOIE1; // disable interrupt  of timer 1
	t2 = (t2 + ov*65538) - t1 ;
	ov=0;
	DIO_write_port(PORT_B,0xFF);
	Delay_ms(2000);
	return t2;
}
ISR(TIMER_1_OVROF){
	ov++;
	DIO_write_port(PORT_B,ov);
}