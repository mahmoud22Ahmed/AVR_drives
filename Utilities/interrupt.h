/*
 * interrupt.h
 *
 * Created: 9/7/2022 11:29:08 PM
 *  Author: Mahmoud
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "registers.h"

//Interrupt vectors
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2
#define EXT_INT_2 __vector_3
#define TIMER_1_OVROF __vector_10


//Enable interrupts
#define sei()  __asm__ __volatile__ ("sei" ::: "memory") // to enable the interrupt
#define cli()  __asm__ __volatile__ ("cli" ::: "memory") // to enable the interrupt
//MCUCR Pins
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2 6
//GICR Pins
#define INT1 7
#define INT0 6
#define INT2 5
 

//ISR macro
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)
#endif /* INTERRUPT_H_ */