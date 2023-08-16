/*
 * SERVO.c
 *
 * Created: 10/18/2022 9:37:48 PM
 *  Author: Mahmoud
 */ 
#include "SERVO.h"
void servo_int_A(){
	ICR1 = 19999 ;  //fPWM=50Hz (Period = 20ms Standard).
	//ICR1 = 19999 >> 8;
	TCNT1 = 0;
	//TCNT = 0;
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/8 mode 14  */
    TCCR1A = (1<<1)|(1<<7);
	TCCR1B = (1<<3)|(1<<4)|(1<<1);
	
	DIO_init_pin(PORT_D,PIN5,OUT);   //PWM Pins as Out
}
void servo_write_A(uint16 degree){
	/* the value to set degree
	 1ms 90+ 1000 
	 1.5ms 0 1500
	 2ms -90 2000
	 */
	OCR1A = degree;
	//OCR1AH = degree >> 8;
}
