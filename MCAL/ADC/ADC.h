/*
 * ADC.h
 *
 * Created: 9/14/2022 5:08:38 PM
 *  Author: Mahmoud
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "../DIO/DIO.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"
#define channel_0 0
#define channel_1 1
#define channel_2 2
#define channel_3 3
#define channel_4 4
#define channel_5 5
#define channel_6 6
#define channel_7 7
void ADC_int(uint8 portName,uint8 pinNumber);
uint16 ADC_read(uint8 channel);
#endif /* ADC_H_ */