/*
 * SPI.h
 *
 * Created: 10/27/2022 3:35:41 PM
 *  Author: Mahmoud
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "../../Utilities/registers.h"
#include "../../MCAL/DIO/DIO.h"
//SPCR bits
#define SPIE 7
#define SPE  6
#define DORD  5
#define MSTR  4
#define CPOL  3
#define CPHA  2
#define SPR1  1
#define SPR0  0

//SPSR bits
#define SPIF  7
#define WCOL  6
#define SPI2X  0

// SPI PINS
#define SPI_PORT  PORT_B
#define SS        PIN4
#define MOSI      PIN5
#define MISO      PIN6
#define SCLK      PIN7

void SPI_Init_master();
void SPI_Write_master(uint8 data);
uint8 SPI_Read_master();
void SPI_Init_slave();
uint8 SPI_Receive_slave();

#endif /* SPI_H_ */