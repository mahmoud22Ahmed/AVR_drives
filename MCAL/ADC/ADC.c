/*
 * ADC.c
 *
 * Created: 9/14/2022 5:08:55 PM
 *  Author: Mahmoud
 */ 
/*
to get the digtal value of the input volt we Vread= (Vref/1024)*read
the ADC works on Frequancy less than 200KHZ 
*/
#include "ADC.h"
void ADC_int(uint8 portName,uint8 pinNumber){
	DIO_init_pin(portName,pinNumber,IN);
	//we will use internal Vref = AVCC and signal ended input
	// and adlar justfied right
	ADMUX |=  1<<6;
	//we start ADCRA with 64 prescalar
	ADCSRA |= 1<<7 | 1<<2 | 1<<3;
}
uint16 ADC_read(uint8 channel){
	uint16 read;
	ADMUX |= channel &0x07;
	// start conversion 
	ADCSRA |= 1<<6;
	// wait for the end of the conversion
	while(READ_BIT(ADCSRA,4)==0);
	read = ADCL + (ADCH<<8);
	return read; 
}