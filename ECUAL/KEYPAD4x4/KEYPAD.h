/*
 * KEYPAD.h
 *
 * Created: 10/8/2022 4:43:21 PM
 *  Author: Mahmoud
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER/TIMER.h"
void keypadInt(uint8 port,uint8 r1,uint8 r2,uint8 r3,uint8 r4,uint8 c1,uint8 c2,uint8 c3,uint8 c4);
uint8 row1();
uint8 row2();
uint8 row3();
uint8 row4();
uint8 getKey();
#endif /* KEYPAD_H_ */