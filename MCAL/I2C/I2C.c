/*
 * I2C.c
 *
 * Created: 10/4/2022 1:56:06 PM
 *  Author: Mahmoud
 */ 
#include "I2C.h"
// we work on 8MHZ
// master functions
void I2C_int(){
	TWBR = BITRATE(TWSR=0x00);
}

void I2C_Start()/* I2C start function */
{
	uint8 status;		/* Declare variable */
	TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT); /* Enable TWI, generate START */
	while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	status=TWSR&0xF8;		/* Read TWI status register */
	while(status!=startCondition){		/* Check weather START transmitted or not? */
	 status=TWSR&0xF8;		/* Read TWI status register */
	}
}
void I2C_sendAddress(uint8 address,uint8 dir){
	DIO_init_port(PORT_A,OUT);
	DIO_init_pin(PORT_B,PIN6,OUT);
	uint8 status;
	if (dir == Read)
	{
		
		TWDR= address ;		// Write SLA+W in TWI data register
		TWCR=(1<<TWEN)|(1<<TWINT);	// Enable TWI & clear interrupt flag
		while(!(TWCR&(1<<TWINT)));	// Wait until TWI finish its current job
		status=TWSR&0xF8;		// Read TWI status register
		DIO_init_port(PORT_A,OUT);
		DIO_write_port(PORT_A,status);
		/*while((status != startCondition_ACK_SR)&&(status != startCondition_NACK_SR)){
			status=TWSR&0xF8;		// Read TWI status register
			DIO_write_port(PORT_A,status);
		}*/
	}
	
	else if (dir == Write)
	{
		TWDR= address + Write ;		// Write SLA+W in TWI data register
		TWCR=(1<<TWEN)|(1<<TWINT);	// Enable TWI & clear interrupt flag
		while(!(TWCR&(1<<TWINT)));	// Wait until TWI finish its current job
		status=TWSR&0xF8;		// Read TWI status register
		DIO_init_port(PORT_A,OUT);
		DIO_write_port(PORT_A,status);
		/*while((status != startCondition_ACK)&&(status != startCondition_NACK)){
			status=TWSR&0xF8;		// Read TWI status register
			DIO_write_port(PORT_A,status);
		}*/
	}
	
}
void I2C_Repeated_Start() /* I2C repeated start function */
{
	uint8 status;		/* Declare variable */
	TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);/* Enable TWI, generate start */
	while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	/*TWDR=address ;		// Write SLA+R in TWI data register 
	TWCR=(1<<TWEN)|(1<<TWINT);	// Enable TWI and clear interrupt flag 
	while(!(TWCR&(1<<TWINT)));	// Wait until TWI finish its current job
	*/ 
	status=TWSR&0xF8;		/* Read TWI status register */
	/*while(status != startCondition_ACK_SR){		// Check for SLA+R transmitted &ack received 
	status=TWSR&0xF8;			// Return 1 to indicate ack received 
	}*/
}

void I2C_Write(uint8 data)	/* I2C write function */
{
	uint8 status;		/* Declare variable */
	TWDR=data;			/* Copy data in TWI data register */
	TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI and clear interrupt flag */
	while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	status=TWSR&0xF8;		/* Read TWI status register */
	/*while(status != dataTranmit_ACK){ // Check for data transmitted &ack received 
		status=TWSR&0xF8;		// Read TWI status register 
	}*/		
}

uint8 I2C_Read_Ack()		/* I2C read ack function */
{
	DIO_init_port(PORT_A,OUT);
	uint8 status;
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA); /* Enable TWI, generation of ack */
	while((TWCR&(1<<TWINT)) == 0);	/* Wait until TWI finish its current job */
	status=TWSR&0xF8;
	DIO_write_port(PORT_A,status);
	while(status != 0x50){
		status=TWSR&0xF8;
		DIO_write_port(PORT_A,status);
	}
	return TWDR;			/* Return received data */
}

uint8 I2C_Read_Nack(){		/* I2C read nack function */
	
	DIO_init_port(PORT_A,OUT);
	uint8 status;
	TWCR = (1<<TWEN)|(1<<TWINT);	/* Enable TWI and clear interrupt flag */
	while( (TWCR&(1<<TWINT)) == 0);	/* Wait until TWI finish its current job */
	status=TWSR&0xF8;	
	DIO_write_port(PORT_A,status);
	while(status != 0x58){
		status=TWSR&0xF8;	
		DIO_write_port(PORT_A,status);
	}
	return TWDR;		/* Return received data */
}

void I2C_Stop()			/* I2C stop function */
{
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);/* Enable TWI, generate stop */
	while(TWCR&(1<<TWSTO));	/* Wait until stop condition execution */
}

//slave functions
void I2C_Slave_Init(uint8 slave_address)
{
	TWAR=slave_address;		/* Assign Address in TWI address register */
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);/* Enable TWI, Enable ack generation */
}

void I2C_Slave_Listen()
{
	while(1)
	{
		uint8 status;			/* Declare variable */
		while(!(TWCR&(1<<TWINT)));	/* Wait to be addressed */
		status=TWSR&0xF8;		/* Read TWI status register */
		while(status!=0x60){
			   status=TWSR&0xF8;		/* Read TWI status register */
		}	// Own SLA+W received &ack returned 
		break;
	}
}

uint8 I2C_Slave_Transmit(uint8 data)
{
	uint8 status;
	TWDR=data;			/* Write data to TWDR to be transmitted */
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);/* Enable TWI & clear interrupt flag */
	while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	status=TWSR&0xF8;		/* Read TWI status register */
	if(status==0xA0)		/* Check for STOP/REPEATED START received */
	{
		TWCR|=(1<<TWINT);	/* Clear interrupt flag & return -1 */
		return 1;
	}
	if(status==0xB8)		/* Check for data transmitted &ack received */
	return 0;			/* If yes then return 0 */
	if(status==0xC0)		/* Check for data transmitted &nack received */
	{
		TWCR|=(1<<TWINT);	/* Clear interrupt flag & return -2 */
		return 2;
	}
	if(status==0xC8)		/* Last byte transmitted with ack received */
	return 3;			/* If yes then return -3 */
	else			/* else return -4 */
	return 4;
}

uint8 I2C_Slave_Receive()
{
	uint8 status;		/* Declare variable */
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);/* Enable TWI & generation of ack */
	while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	status=TWSR&0xF8;		/* Read TWI status register */
	while(status!=0x80){// Check for data received &ack returned
	   status=TWSR&0xF8;		/* Read TWI status register */
	}
	return TWDR;		// If yes then return received data 
}
