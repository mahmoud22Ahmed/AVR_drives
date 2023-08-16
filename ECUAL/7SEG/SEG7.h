/*
 * _7SEG.h
 *
 * Created: 9/23/2022 2:54:32 PM
 *  Author: Mahmoud
 */ 


#ifndef SEG7_H_
#define SEG7_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../Utilities/types.h"
//uint8 hexCode[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; 
#define CC 0
#define CA 1
void seg7_int(uint8 portName);
void seg7_write(uint8 portName,uint8 value,uint8 type);
#endif /* 7SEG_H_ */