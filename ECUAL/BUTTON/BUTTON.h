/*
 * BUTTON.h
 *
 * Created: 9/7/2022 11:38:52 PM
 *  Author: Mahmoud
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL//DIO/DIO.h"


//initialize
void BUTTON_init(uint8 buttonPort,uint8 buttonPin);

uint8 BUTTON_read(uint8 buttonPort,uint8 buttonPin);

#endif /* BUTTON_H_ */