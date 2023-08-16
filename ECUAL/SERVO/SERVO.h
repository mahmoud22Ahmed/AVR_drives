/*
 * SERVO.h
 *
 * Created: 9/22/2022 5:22:57 PM
 *  Author: Mahmoud
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include "../../Utilities/registers.h"
#include "../../MCAL/DIO/DIO.h"
#include <avr/io.h>
void servo_int_A();
void servo_write_A(uint16 degree);
#endif /* SERVO_H_ */