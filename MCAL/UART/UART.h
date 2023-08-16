/*
 * UART.h
 *
 * Created: 9/19/2022 9:36:00 PM
 *  Author: Mahmoud
 */ 


#ifndef UART_H_
#define UART_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../DIO/DIO.h"
void UART_int(uint16 baud_rate);
void UART_trans_char(char c);
void UART_trans_string(char *str);
char UART_recieve_char();
#endif /* UART_H_ */