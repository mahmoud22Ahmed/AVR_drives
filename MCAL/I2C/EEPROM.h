/*
 * EEPROM.h
 *
 * Created: 12/1/2022 10:25:18 PM
 *  Author: Mahmoud
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
// EECR bits
#define EERIE 3
#define EEMWE 2
#define EEWE  1
#define EERE  0
void eeprom_write(uint16 address,uint8 data);
uint8 eeprom_read(uint16 address);





#endif /* EEPROM_H_ */