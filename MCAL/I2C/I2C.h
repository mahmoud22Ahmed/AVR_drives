/*
 * I2C.h
 *
 * Created: 10/4/2022 1:56:17 PM
 *  Author: Mahmoud
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "../../Utilities/registers.h"
#include "../DIO/DIO.h"
#include <math.h>
#define FCPU 8000000UL
#define SCL_CLK 50000UL

// intilize the bit rate
#define BITRATE(TWSR)	((FCPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

#define Read 1
#define Write 0
// TWCR bits
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC 3
#define TWEN 2
#define TWIE 0

// TWSR bits
#define TWPS0 0
#define TWPS1 1

// code for master modes
#define  startCondition 0x08
#define  startCondition_ACK 0x18
#define  startCondition_NACK 0x20
#define  startCondition_ACK_SR 0x40
#define  startCondition_NACK_SR 0x48
#define  dataTranmit_ACK 0x28
#define  dataTranmit_NACK 0x30

// master functions
void I2C_int();
void I2C_Start();
void I2C_sendAddress(uint8 address,uint8 dir);
void I2C_Repeated_Start();
void I2C_Write(uint8 data);	
uint8 I2C_Read_Ack();
uint8 I2C_Read_NAck(uint8 *carry);
void I2C_Stop();

// slave functions
void I2C_Slave_Init(uint8 slave_address);
void I2C_Slave_Listen();
uint8 I2C_Slave_Transmit(uint8 data);
uint8 I2C_Slave_Receive();
#endif /* I2C_H_ */