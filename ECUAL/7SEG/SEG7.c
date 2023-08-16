/*
 * _7SEG.c
 *
 * Created: 9/23/2022 2:54:16 PM
 *  Author: Mahmoud
 */ 
#include "SEG7.h"
uint8 hexCode[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; //P7:P0 // common cathode
void seg7_int(uint8 portName){
	DIO_init_port(portName,OUT);
}
void seg7_write(uint8 portName,uint8 value,uint8 type){ 
	switch(type){
	case CC:
	  DIO_write_port(portName,hexCode[value]);
	  break;
	case  CA:
	  DIO_write_port(portName,~hexCode[value]);
	  break;
	default:
	  break;
   }
}

