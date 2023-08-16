/*
 * LED.h
 *
 * Created: 9/7/2022 11:36:58 PM
 *  Author: Mahmoud
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"
void LED_init(uint8 ledPort,uint8 ledPin);
void LED_on(uint8 ledPort,uint8 ledPin);
void LED_off(uint8 ledPort,uint8 ledPin);
void LED_toggle(uint8 ledPort,uint8 ledPin);
#endif /* LED_H_ */