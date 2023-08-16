/*
 * BUTTON.c
 *
 * Created: 9/7/2022 11:39:50 PM
 *  Author: Mahmoud
 */ 
#include "BUTTON.h"

//initialize
void BUTTON_init(uint8 buttonPort,uint8 buttonPin){
	DIO_init_pin(buttonPort,buttonPin,IN);
}

// button read
uint8 BUTTON_read(uint8 buttonPort,uint8 buttonPin){
	return DIO_read_pin(buttonPort,buttonPin);
}