/*
 * TIMER.h
 *
 * Created: 9/7/2022 11:41:27 PM
 *  Author: Mahmoud
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../Utilities/registers.h"
#include <avr/io.h>
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/interrupt.h"
#include "../DIO/DIO.h"
// input capture bits on TCCR1B
#define ICNC1 7
#define ICES1 6
void Delay_ms(uint32 value);
void Delay_us(uint32 value);
void PWM(uint32 duty_cycle);
uint32 pulseWidth();
#endif /* TIMER_H_ */