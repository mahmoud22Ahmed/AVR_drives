/*
 * SPI.c
 *
 * Created: 10/27/2022 3:35:30 PM
 *  Author: Mahmoud
 */ 
#include "SPI.h"
// master functions
void SPI_Init_master()					/* SPI Initialize function */
{
	/* Make MOSI, SCK, SS  as Output pin   and MISO as input*/
	DIO_init_pin(SPI_PORT,MOSI,OUT);
	DIO_init_pin(SPI_PORT,SS,OUT);
	DIO_init_pin(SPI_PORT,SCLK,OUT);
	DIO_init_pin(SPI_PORT,MISO,IN);
    // make SS is high
	DIO_write_pin(SPI_PORT,SS,HIGH);
	
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	/* Enable SPI in master mode
						with Fosc/16 */
	SPSR &= ~(1<<SPI2X);			/* Disable speed doubler */
}

void SPI_Write_master(uint8 data)		/* SPI write data function */
{
	char flush_buffer;
	DIO_write_pin(SPI_PORT,SS,LOW);
	SPDR = data;			/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */
	flush_buffer = SPDR;		/* Flush received data */
	DIO_write_pin(SPI_PORT,SS,HIGH);
	/* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and then accessing SPDR hence flush buffer used here to access SPDR after SPSR read */
}

uint8 SPI_Read_master()				/* SPI read data function */
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	return(SPDR);			/* Return received data */
}

//slave functions
void SPI_Init_slave()					/* SPI Initialize function */
{
	/* Make MOSI, SCK, SS  as input pin   and MISO as output*/
	DIO_init_pin(SPI_PORT,MOSI,IN);
	DIO_init_pin(SPI_PORT,SS,IN);
	DIO_init_pin(SPI_PORT,SCLK,IN);
	DIO_init_pin(SPI_PORT,MISO,OUT);
    // make SS is high
	SPCR = (1<<SPE);	/* Enable SPI in slave mode */
}

uint8 SPI_Receive_slave()			/* SPI Receive data function */
{
	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	return(SPDR);			/* Return received data */
}

