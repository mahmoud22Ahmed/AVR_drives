/*
 * DIO.h
 *
 * Created: 9/7/2022 11:33:59 PM
 *  Author: Mahmoud
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//Direction defines
#define IN 0
#define OUT 1

//Value defines
#define LOW 0
#define HIGH 1


void DIO_init_pin(uint8 portNumber, uint8 pinNumber, uint8 direction);// Initialize dio direction
void DIO_write_pin(uint8 portNumber, uint8 pinNumber, uint8 value); //write data to dio
void DIO_toggle_pin(uint8 portNumber, uint8 pinNumber); //toggle dio
uint8 DIO_read_pin(uint8 portNumber, uint8 pinNumber); //read dio

void DIO_init_port(uint8 portNumber,uint8 direction);// Initialize dio direction
void DIO_write_port(uint8 portNumber,uint8 value); //write data to dio


#endif /* DIO_H_ */