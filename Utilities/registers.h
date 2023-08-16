/*
 * register.h
 *
 * Created: 9/7/2022 11:26:26 PM
 *  Author: Mahmoud
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_
#include "types.h"
//PINS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



//* DIO REGISTERS

//PortA registers
#define PORTA (*(volatile uint8*)(0x3B))
#define DDRA (*(volatile uint8*)(0x3A))
#define PINA (*(volatile uint8*)(0x39))

//PortB registers
#define PORTB (*(volatile uint8*)(0x38))
#define DDRB (*(volatile uint8*)(0x37))
#define PINB (*(volatile uint8*)(0x36))

//PortC registers
#define PORTC (*(volatile uint8*)(0x35))
#define DDRC (*(volatile uint8*)(0x34))
#define PINC (*(volatile uint8*)(0x33))

//PortD registers
#define PORTD (*(volatile uint8*)(0x32))
#define DDRD (*(volatile uint8*)(0x31))
#define PIND (*(volatile uint8*)(0x30))

//* Timer1 REGISTERS

#define TCCR1A (*(volatile uint8*)(0x4F))
#define TCCR1B (*(volatile uint8*)(0x4E))
#define TCNT1H (*(volatile uint8*)(0x4D))
#define TCNT1L (*(volatile uint8*)(0x4C))
#define OCR1AH (*(volatile uint8*)(0x4B))
#define OCR1AL (*(volatile uint8*)(0x4A))
#define OCR1BH (*(volatile uint8*)(0x49))
#define OCR1BL (*(volatile uint8*)(0x48))
#define ICR1H  (*(volatile uint8*)(0x47))
#define ICR1L  (*(volatile uint8*)(0x46))

//* Timer0 REGISTERS

#define TCCR0 (*(volatile uint8*)(0x53))
#define TCNT0 (*(volatile uint8*)(0x52))
#define OCR0 (*(volatile uint8*)(0x5C))
#define TIFR (*(volatile uint8*)(0x58))
#define TIMSK (*(volatile uint8*)(0x59))


//* Interrupt REGISTERS

#define SREG (*(volatile uint8*)(0x5F))
#define GICR (*(volatile uint8*)(0x5B))
#define MCUCR (*(volatile uint8*)(0x55))
#define MCUCSR (*(volatile uint8*)(0x54))

// ADC REGISTERS
#define ADMUX (*(volatile uint8*)(0x27))
#define ADCL (*(volatile uint8*)(0x24))
#define ADCH (*(volatile uint8*)(0x25))
#define SFIOR (*(volatile uint8*)(0x50))
#define ADCSRA (*(volatile uint8*)(0x26))

// UART REGISTERS
#define UDR (*(volatile uint8*)(0x2C))
#define UCSRA (*(volatile uint8*)(0x2B))
#define UCSRB (*(volatile uint8*)(0x2A))
#define UCSRC (*(volatile uint8*)(0x40))
#define UBRRL (*(volatile uint8*)(0x29))
#define UBRRH (*(volatile uint8*)(0x40))


// I2C REGISTERS
#define TWDR (*(volatile uint8*)(0x23))
#define TWAR (*(volatile uint8*)(0x22))
#define TWSR (*(volatile uint8*)(0x21))
#define TWBR (*(volatile uint8*)(0x20))
#define TWCR (*(volatile uint8*)(0x56))

// SPI REGISTERS
#define SPDR (*(volatile uint8*)(0x2F))
#define SPSR (*(volatile uint8*)(0x2E))
#define SPCR (*(volatile uint8*)(0x2D))

// INTERNAL EEPROM REGISTERS
#define EEARH (*(volatile uint8*)(0x3F))
#define EEARL (*(volatile uint8*)(0x3E))
#define EEDR (*(volatile uint8*)(0x3D))
#define EECR (*(volatile uint8*)(0x3C))

#endif /* REGISTER_H_ */