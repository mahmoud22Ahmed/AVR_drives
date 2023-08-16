/*
 * KEYPAD.c
 *
 * Created: 10/8/2022 4:43:07 PM
 *  Author: Mahmoud
 */ 
#include "KEYPAD.h"
uint8 keypadButton[16]={
	'7','8','9','/',
	'4','5','6','X',
	'1','2','3','-',
	'o','0','#','+'
};

uint8 rowPins[4],colPins[4],keypadPort;
void keypadInt(uint8 port,uint8 r1,uint8 r2,uint8 r3,uint8 r4,uint8 c1,uint8 c2,uint8 c3,uint8 c4){
	keypadPort = port;
	// assign row pins
	rowPins[0]=r1;
	rowPins[1]=r2;
	rowPins[2]=r3;
	rowPins[3]=r4;
	//assign columns pins
	colPins[0]=c1;
	colPins[1]=c2;
	colPins[2]=c3;
	colPins[3]=c4;
	//we intilize the rows as outputs pins
	DIO_init_pin(keypadPort,rowPins[0],OUT);
	DIO_init_pin(keypadPort,rowPins[1],OUT);
	DIO_init_pin(keypadPort,rowPins[2],OUT);
	DIO_init_pin(keypadPort,rowPins[3],OUT);

	
	//we intilize the colunms  as outputs pins
	DIO_init_pin(keypadPort,colPins[0],IN);
    DIO_init_pin(keypadPort,colPins[1],IN);
	DIO_init_pin(keypadPort,colPins[2],IN);
	DIO_init_pin(keypadPort,colPins[3],IN);
	//out 5V from row pins
	DIO_write_pin(keypadPort,rowPins[0],HIGH);
	DIO_write_pin(keypadPort,rowPins[1],HIGH);
	DIO_write_pin(keypadPort,rowPins[2],HIGH);
	DIO_write_pin(keypadPort,rowPins[3],HIGH);
}
uint8 getKey(){	
 uint8 index=16;
 while(index == 16){
	 index = row1();
	 if (index != 16)
	 {
		 break;
	 }
	 index = row2();
	 if (index != 16)
	 {
		 break;
	 }
	 index = row3();
	 if (index != 16)
	 {
		 break;
	 }
	  index = row4();
	 if (index != 16)
	 {
		 break;
	 }
 }	
 return keypadButton[index];
}

uint8 row1(){
	DIO_write_pin(keypadPort,rowPins[0],HIGH);
	DIO_write_pin(keypadPort,rowPins[1],LOW);
	DIO_write_pin(keypadPort,rowPins[2],LOW);
	DIO_write_pin(keypadPort,rowPins[3],LOW);
	if (DIO_read_pin(keypadPort,colPins[0]) == HIGH)
	{
	    while(DIO_read_pin(keypadPort,colPins[0]) == HIGH);
		return 0;
	}
	if (DIO_read_pin(keypadPort,colPins[1]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[2]) == HIGH);
		return 1;
	}
	if (DIO_read_pin(keypadPort,colPins[2]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[2]) == HIGH);
		return 2;
	}
	if (DIO_read_pin(keypadPort,colPins[3]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[3]) == HIGH);
		return 3;
	}
	else{
		Delay_ms(100);
		return 16;
	}
}

uint8 row2(){
	DIO_write_pin(keypadPort,rowPins[0],LOW);
	DIO_write_pin(keypadPort,rowPins[1],HIGH);
	DIO_write_pin(keypadPort,rowPins[2],LOW);
	DIO_write_pin(keypadPort,rowPins[3],LOW);
	if (DIO_read_pin(keypadPort,colPins[0]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[0]) == HIGH);
		return 4;
	}
	if (DIO_read_pin(keypadPort,colPins[1]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[1]) == HIGH);
		return 5;
	}
	if (DIO_read_pin(keypadPort,colPins[2]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[2]) == HIGH);
		return 6;
	}
	if (DIO_read_pin(keypadPort,colPins[3]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[3]) == HIGH);
		return 7;
	}
	else{
		Delay_ms(100);
		return 16;
	}
}

uint8 row3(){
	DIO_write_pin(keypadPort,rowPins[0],LOW);
	DIO_write_pin(keypadPort,rowPins[1],LOW);
	DIO_write_pin(keypadPort,rowPins[2],HIGH);
	DIO_write_pin(keypadPort,rowPins[3],LOW);
	if (DIO_read_pin(keypadPort,colPins[0]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[0]) == HIGH);
		return 8;
	}
	if (DIO_read_pin(keypadPort,colPins[1]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[1]) == HIGH);
		return 9;
	}
	if (DIO_read_pin(keypadPort,colPins[2]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[2]) == HIGH);
		return 10;
	}
	if (DIO_read_pin(keypadPort,colPins[3]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[3]) == HIGH);
		return 11;
	}
	else{
		Delay_ms(100);
		return 16;
	}
}


uint8 row4(){
	DIO_write_pin(keypadPort,rowPins[0],LOW);
	DIO_write_pin(keypadPort,rowPins[1],LOW);
	DIO_write_pin(keypadPort,rowPins[2],LOW);
	DIO_write_pin(keypadPort,rowPins[3],HIGH);
	if (DIO_read_pin(keypadPort,colPins[0]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[0]) == HIGH);
		return 12;
	}
	if (DIO_read_pin(keypadPort,colPins[1]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[1]) == HIGH);
		return 13;
	}
	if (DIO_read_pin(keypadPort,colPins[2]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[2]) == HIGH);
		return 14;
	}
	if (DIO_read_pin(keypadPort,colPins[3]) == HIGH)
	{
		while(DIO_read_pin(keypadPort,colPins[3]) == HIGH);
		return 15;
	}
	else{
		Delay_ms(100);
		return 16;
	}
}
