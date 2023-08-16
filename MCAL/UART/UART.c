/*
 * UART.c
 *
 * Created: 9/19/2022 9:35:47 PM
 *  Author: Mahmoud
 */ 
// we working on 8MHZ XTAL
#include "UART.h"

void UART_int(uint16 baud_rate){
	// we work normal speed
	UCSRA |=0<<2;//U2X
	switch(baud_rate){
		case 2400:
			   UBRRL = 0xFF & 207;
			   UBRRH = (207)>>8;
		  break;
		case 4800:
			  UBRRL = 0xFF & 103;
			  UBRRH = (103)>>8;
		  break;
		case 9600:
			  UBRRL = 51;
			  UBRRH = (51)>>8;
		  break;
		case 14400:
			  UBRRL = 0xFF & 34;
			  UBRRH = (34)>>8;
		  break;
		default:
		 break;
	}
	//enable transmiting and recieving 
	UCSRB |= 1<<4 | 1<<3;
	// we work sync and no parity and one stop bit and 8 bit UART 
	UCSRC |= 1<<7 | 1<<2 | 1<<1 ;
}
void UART_trans_char(char c){
	//wait for the buffer be empty
	//wait for the buffer be empty
	while(!READ_BIT(UCSRA,5));
	UDR = c;
}
char UART_recieve_char(){
	//wait for the buffer be empty
	//wait for recieving the data
	while(!READ_BIT(UCSRA,7));
	return UDR;
}
void UART_trans_string(char *str){
	uint16 i;
	for (i=0;str[i]!=0;i++)
	{
		UART_trans_char(str[i]);
	}
}
