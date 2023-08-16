/*
 * RTC.h
 *
 * Created: 10/18/2022 11:03:52 PM
 *  Author: Mahmoud
 */ 


#ifndef RTC_H_
#define RTC_H_
#include "../../MCAL/I2C/I2C.h"
#include "../../Utilities/types.h"

#define Device_Write_address  0xD0	/* Define RTC DS1307 slave write address */
#define Device_Read_address	  0xD1	/* Make LSB bit high of slave address for read */
#define TimeFormat12		0x40	/* Define 12 hour format */
#define AMPM 0x20 


void RTC_intiRead();
void RTC_intiWrite();
int IsItPM(char hour_);
void RTC_Read_Clock(uint8 *second,uint8 *minute,uint8 *hour);
void RTC_Read_date(uint8 *day,uint8 *month,uint8 *year);
void RTC_Clock_Write(uint8 _hour, uint8 _minute, uint8 _second, uint8 _AMPM);
void RTC_Calendar_Write(uint8 _day, uint8 _date, uint8 _month, uint8 _year);
#endif /* RTC_H_ */