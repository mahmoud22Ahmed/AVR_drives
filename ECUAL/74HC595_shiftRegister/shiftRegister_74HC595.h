/*
 * _74HC595.h
 *
 * Created: 10/11/2022 10:20:04 PM
 *  Author: Mahmoud
 */ 


#ifndef SHIFTREGISTER_74HC595_H_
#define SHIFTREGISTER_74HC595_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER/TIMER.h"
#include <util/delay.h>
#define  F_CPU 8000000UL
#define SHR_PORT  PORT_C
#define SH_CP     PIN0    // Shift Register clock pulse
#define DS        PIN1    // Data Serial
#define ST_CP     PIN2    // Storage Register clock pulse

void Shift_Register_Init(void);
void Shift_register_Send_data (uint8 data);
#endif /* SHIFTREGISTER_74HC595_H_ */