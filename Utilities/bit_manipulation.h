/*
 * bit_munipulation.h
 *
 * Created: 9/7/2022 11:25:08 PM
 *  Author: Mahmoud
 */ 


#ifndef BIT_MUNIPULATION_H_
#define BIT_MUNIPULATION_H_
#define CLEAR_BIT(REG,NUM) REG&=~(1<<NUM)
#define SET_BIT(REG,NUM)   REG|=(1<<NUM)
#define TOGGLE_BIT(REG,NUM) REG^=(1<<NUM)
#define READ_BIT(REG,NUM)  ((REG&(1<<NUM))>>NUM)
#endif /* BIT_MUNIPULATION_H_ */