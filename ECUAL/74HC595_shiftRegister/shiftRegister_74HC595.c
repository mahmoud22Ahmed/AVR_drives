/*
 * _74HC595c.c
 *
 * Created: 10/11/2022 10:19:50 PM
 *  Author: Mahmoud
 */ 
#include "shiftRegister_74HC595.h"
/*
MR in shift register is connected to +5V
OE is connected to ground
*/
/**
 * 1- Send one bit 
 * 2- send pulse to shift register clock pulse
 * 3- repeat the two previous steps until send one byte 
 * 4- send pulse to Storage register clock input.
*/

/********************************************************
 *          Initialize Shift Register                   *
 ********************************************************
 */
void Shift_Register_Init (void)
{
	DIO_init_pin(SHR_PORT,DS,OUT);
	DIO_init_pin(SHR_PORT,ST_CP,OUT);
	DIO_init_pin(SHR_PORT,SH_CP,OUT);
	return;
}

/********************************************************
 *      Set pins Value of Shift Register                *
 * ******************************************************
 */

void Shift_register_Send_data (uint8 data)
{
    DIO_write_pin(SHR_PORT,ST_CP,LOW);
    unsigned char arr[8];
    unsigned char i= 0;
    for (i=0 ; i<8 ; i++)
    {
       arr[i] = ( data & (1<<i))>>i;
    }
    for (i=8 ; i>=1 ; i--)
    {
    	if (arr[i-1] == 0) DIO_write_pin(SHR_PORT,DS,LOW);
   else if (arr[i-1] == 1) DIO_write_pin(SHR_PORT,DS,HIGH);
    	DIO_write_pin(SHR_PORT,SH_CP,HIGH);
       _delay_us(1);
	   DIO_write_pin(SHR_PORT,SH_CP,LOW);
    }
    DIO_write_pin(SHR_PORT,ST_CP,HIGH);
}