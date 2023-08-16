/*
 * LCD16X2.c
 *
 * Created: 9/17/2022 4:51:52 PM
 *  Author: Mahmoud
 */ 
#include "LCD16X2.h"
uint8 dataPort,controlPort,RS,RW,EA;//8bit pins
uint8 d4,d5,d6,d7; // data pins for 4 bits mode
// 8bit mode 
void LCD_int_8bit(uint8 dataPort_carry,uint8 controlPort_carry,uint8 RS_carry,uint8 RW_carry,uint8 EA_carry){
	dataPort = dataPort_carry;
	controlPort =controlPort_carry;
	RS = RS_carry;
	RW = RW_carry;
	EA = EA_carry;
	DIO_init_port(dataPort,OUT);  /* Make LCD data port direction as o/p */
	DIO_init_pin(controlPort,RS,OUT);
	DIO_init_pin(controlPort,RW,OUT);
	DIO_init_pin(controlPort,EA,OUT);
	Delay_ms(20); /* LCD Power ON delay always >15ms */
	LCD_8_bit_sendCommand(0x38); /* Initialization of 16X2 LCD in 8bit mode */
	LCD_8_bit_sendCommand(0x0E); /* Display ON Cursor blinking */
	LCD_8_bit_sendCommand(0x06); /* Auto Increment cursor */
	LCD_8_bit_sendCommand(0x01); /* clear display */
	LCD_8_bit_sendCommand(0x80); /* cursor at home position */
}
void LCD_8_bit_sendCommand(uint8 cmnd){
	DIO_write_port(dataPort,cmnd);
	DIO_write_pin(controlPort,RS,LOW); /* RS=0 command register */
    DIO_write_pin(controlPort,RW,LOW); /* RW=0 Write operation */
	DIO_write_pin(controlPort,EA,HIGH); /* Enable pulse */
	Delay_ms(1);
    DIO_write_pin(controlPort,EA,LOW);
	Delay_ms(3);
}
void LCD_8_bit_sendChar (uint8 char_data)
{
	DIO_write_port(dataPort,char_data);
	DIO_write_pin(controlPort,RS,HIGH); /* RS=1 data register */
	DIO_write_pin(controlPort,RW,LOW); /* RW=0 Write operation */
	DIO_write_pin(controlPort,EA,HIGH); /* Enable pulse */
	Delay_ms(1);
	DIO_write_pin(controlPort,EA,LOW);
	Delay_ms(3);
}
void LCD_8_bit_sendString (char *str)
{
	uint16 i;
	for(i=0;str[i]!=0;i++) /* send each char of string till the NULL */
	{
		LCD_8_bit_sendChar(str[i]); /* call LCD data write */
	}
}
void LCD_8_bit_clear(){
	LCD_8_bit_sendCommand(0x01); //clear the display
	Delay_ms(2);
	LCD_8_bit_sendCommand(0x80); /* cursor at home position */
}
void LCD_8_bit_setCursur(uint8 raw,uint8 column){
	uint8 position;
	if (raw == 0)// first line
	{
		position = 0x80 + column;
		LCD_8_bit_sendCommand(position);
	}
	else if (raw == 1)// second line
	{
		position = 0xC0 + column;
		LCD_8_bit_sendCommand(position);
	}
}

// 4bit
void LCD_4_bit_init (uint8 dataPort_carry,uint8 controlPort_carry,uint8 RS_carry,uint8 RW_carry,uint8 EA_carry) /* LCD Initialize function */
{
	dataPort = dataPort_carry;
	controlPort =controlPort_carry;
	RS = RS_carry;
	RW = RW_carry;
	EA = EA_carry;
	DIO_init_port(dataPort,OUT);
	DIO_init_pin(controlPort,RS,OUT);
	DIO_init_pin(controlPort,RW,OUT);
	DIO_init_pin(controlPort,EA,OUT);
	Delay_ms(20); /* LCD Power ON delay always >15ms */
	LCD_4_bit_sendCommand(0x02); /* Send for 4 bit initialization of LCD */
	LCD_4_bit_sendCommand(0x28); /* 2 line, 5*7 matrix in 4-bit mode */
	LCD_4_bit_sendCommand(0x0c); /* Display on cursor OFF -if we want to blank cursor we send 0E */
	LCD_4_bit_sendCommand(0x06); /* Increment cursor (shift cursor to right) */
	LCD_4_bit_sendCommand(0x01); /* Clear display screen */
	LCD_4_bit_sendCommand(0x80); /* cursor at home position */
}

void LCD_4_bit_sendCommand( uint8 cmnd )
{
	DIO_write_port(dataPort,(cmnd & 0xF0));/* Sending upper nibble */
	DIO_write_pin(controlPort,RS,LOW); /* RS=0, command reg. */
	DIO_write_pin(controlPort,RW,LOW);
	DIO_write_pin(controlPort,EA,HIGH); /* Enable pulse */
	Delay_ms(1);
	DIO_write_pin(controlPort,EA,LOW);
	Delay_ms(3);
    DIO_write_port(dataPort,(cmnd << 4));/* Sending lower nibble */
	DIO_write_pin(controlPort,EA,HIGH); /* Enable pulse */
	Delay_ms(1);
	DIO_write_pin(controlPort,EA,LOW);
	Delay_ms(3);
}

void LCD_4_bit_sendChar( uint8 data )
{
	DIO_write_port(dataPort,(data & 0xF0));/* Sending upper nibble */
	DIO_write_pin(controlPort,RS,HIGH); /* RS=1, data reg. */
	DIO_write_pin(controlPort,RW,LOW); 
	DIO_write_pin(controlPort,EA,HIGH); /* Enable pulse */
	Delay_ms(1);
	DIO_write_pin(controlPort,EA,LOW);
	Delay_ms(3);
	DIO_write_port(dataPort,(data << 4)); /* Sending lower nibble */
	DIO_write_pin(controlPort,EA,HIGH); /* Enable pulse */
	Delay_ms(1);
	DIO_write_pin(controlPort,EA,LOW);
	Delay_ms(3);
}

void LCD_4_bit_sendString (char *str)
{
	uint16 i;
	for(i=0;str[i]!=0;i++) /* send each char of string till the NULL */
	{
		LCD_4_bit_sendChar(str[i]); /* call LCD data write */
	}
}
void LCD_4_bit_clear(){
	LCD_4_bit_sendCommand(0x01); //clear the display
	Delay_ms(2);
	LCD_4_bit_sendCommand(0x80); /* cursor at home position */
}
void LCD_4_bit_setCursur(uint8 raw,uint8 column){
	uint8 position;
	if (raw == 0)// first line
	{
		position = 0x80 + column;
		LCD_4_bit_sendCommand(position);
	}
	else if (raw == 1)// second line
	{
		position = 0xC0 + column;
		LCD_4_bit_sendCommand(position);
	}
}