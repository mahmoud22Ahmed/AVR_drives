/*
 * RTC.c
 *
 * Created: 10/18/2022 11:03:38 PM
 *  Author: Mahmoud
 */ 
#include "RTC.h"


void RTC_intiRead(){
	I2C_int();
	I2C_Start();
	I2C_sendAddress(Device_Write_address,Write);
	I2C_Write(0x07);
	I2C_Write(0x00);
	I2C_Stop();
}
int IsItPM(char hour_)
{
	if(hour_ & (AMPM))
	return 1;
	else
	return 0;
}

void RTC_Read_Clock(uint8 *second,uint8 *minute,uint8 *hour)
{
	I2C_Start();/* Start I2C communication with RTC */
    I2C_sendAddress(Device_Write_address,Write);
	I2C_Write(0x00);	/* set the pointer to reg 0  */
	I2C_Stop();
     
	I2C_Start();/* Start I2C communication with RTC */
	I2C_sendAddress(Device_Read_address,Read);
	*second = I2C_Read_Ack();	/* Read second */
	*minute = I2C_Read_Ack();	/* Read minute */
	*hour = I2C_Read_Nack();		/* Read hour with Nack */
	I2C_Stop();			/* Stop i2C communication */
}

void RTC_Read_date(uint8 *day,uint8 *month,uint8 *year)
{
	I2C_Start();/* Start I2C communication with RTC */
	I2C_sendAddress(Device_Write_address,Write);
	I2C_Write(0x04);	/* set the pointer to reg 4  */
	I2C_Stop();
	
	I2C_Start();/* Start I2C communication with RTC */
	I2C_sendAddress(Device_Read_address,Read);
	*day = I2C_Read_Ack();	/* Read second */
	*month = I2C_Read_Ack();	/* Read minute */
	*year = I2C_Read_Nack();		/* Read hour with Nack */
	I2C_Stop();			/* Stop i2C communication */
}

void RTC_intiWrite(){
	I2C_int();
	I2C_Repeated_Start();
	I2C_sendAddress(Device_Write_address,Write);
	I2C_Write(0x07);
	I2C_Write(0x00);
	I2C_Stop();
}
void RTC_Clock_Write(uint8 _hour, uint8 _minute, uint8 _second, uint8 _AMPM)
{
	_hour |= _AMPM;
	I2C_Start();			/* Start I2C communication with RTC */
	I2C_sendAddress(Device_Write_address,Write); // send the address to write on RTC
	I2C_Write(0);								/* Write on 0 location for second value */
	I2C_Write(_second);							/* Write second value on 00 location */
	I2C_Write(_minute);							/* Write minute value on 01 location */
	I2C_Write(_hour);							/* Write hour value on 02 location */
	I2C_Stop();									/* Stop I2C communication */
}

void RTC_Calendar_Write(uint8 _day, uint8 _date, uint8 _month, uint8 _year)	/* function for calendar */
{
	I2C_Start(Device_Write_address);			/* Start I2C communication with RTC */
	I2C_sendAddress(Device_Write_address,Write);; // send the address to write on RTC
	I2C_Write(3);								/* Write on 3 location for day value */
	I2C_Write(_day);							/* Write day value on 03 location */
	I2C_Write(_date);							/* Write date value on 04 location */
	I2C_Write(_month);							/* Write month value on 05 location */
	I2C_Write(_year);							/* Write year value on 06 location */
	I2C_Stop();									/* Stop I2C communication */
}

