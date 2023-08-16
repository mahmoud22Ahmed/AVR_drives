/*
 * EEPROM.c
 *
 * Created: 12/1/2022 10:25:05 PM
 *  Author: Mahmoud
 */ 
#include "EEPROM.h"
void eeprom_write(uint16 address,uint8 data){
	while(READ_BIT(EECR,EEWE) == 1);
	EEARL = address & 0xFF;
	EEARH = (address & 0x100)>>8;
	EEDR = data;
	EECR |= (1<<EEMWE);
	EECR |= (1<<EEWE);
}
uint8 eeprom_read(uint16 address){
	uint8 data;
	while(READ_BIT(EECR,EEWE) == 1);
	EEARL = address & 0xFF;
	EEARH = (address & 0x100)>>8;
	EECR |= (1<<EERE);
	data = EEDR;
	EECR |= (1<<EEWE);
	return data;
}