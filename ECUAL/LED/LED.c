/*
 * LED.c
 *
 * Created: 9/7/2022 11:37:56 PM
 *  Author: Mahmoud
 */ 
#include "LED.h"

void LED_init(uint8 ledPort,uint8 ledPin){
	DIO_init_pin(ledPort,ledPin,OUT);
}
void LED_on(uint8 ledPort,uint8 ledPin){
	DIO_write_pin(ledPort,ledPin,HIGH);
}
void LED_off(uint8 ledPort,uint8 ledPin){
	DIO_write_pin(ledPort,ledPin,LOW);
}
void LED_toggle(uint8 ledPort,uint8 ledPin){
	DIO_toggle_pin(ledPort,ledPin);
}
