/*
 * LCD16X2.h
 *
 * Created: 9/17/2022 4:52:07 PM
 *  Author: Mahmoud
 */ 


#ifndef LCD16X2_H_
#define LCD16X2_H_
#include "../../MCAL/TIMER/TIMER.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"
#include <util/delay.h>
#define F_CPU 8000000UL
void LCD_int_8bit(uint8 dataPort,uint8 controlPort,uint8 RS,uint8 RW,uint8 EA);
void LCD_8_bit_sendCommand(uint8 cmnd);
void LCD_8_bit_sendChar (uint8 char_data);
void LCD_8_bit_sendString (char *str);
void LCD_8_bit_clear();
void LCD_8_bit_setCursur(uint8 raw,uint8 column);

//4bit mode
void LCD_4_bit_init (uint8 dataPort_carry,uint8 controlPort_carry,uint8 RS_carry,uint8 RW_carry,uint8 EA_carry);
void LCD_4_bit_sendCommand( uint8 cmnd );
void LCD_4_bit_sendChar( uint8 data );
void LCD_4_bit_sendString (char *str);
void LCD_4_bit_clear();
void LCD_4_bit_setCursur(uint8 raw,uint8 column);
#endif /* LCD16X2_H_ */