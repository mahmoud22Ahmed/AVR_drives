
#include "DIO.h"
void DIO_init_pin(uint8 portNumber, uint8 pinNumber, uint8 direction)
{
	switch(portNumber){
		case PORT_A:
			if(direction == IN){
				CLEAR_BIT(DDRA,pinNumber);
			}
			else if (direction == OUT){
				SET_BIT(DDRA,pinNumber);
			}
			else{
				//error handling
			}
			break;
		case PORT_B:
			if(direction == IN){
				CLEAR_BIT(DDRB,pinNumber);
			}
			else if (direction == OUT){
				SET_BIT(DDRB,pinNumber);
			}
			else{
				//error handling
			}
			break;
		case PORT_C:
			if(direction == IN){
				CLEAR_BIT(DDRC,pinNumber);
			}
			else if (direction == OUT){
				SET_BIT(DDRC,pinNumber);
			}
			else{
				//error handling
			}
			break;
		case PORT_D:
			if(direction == IN){
				CLEAR_BIT(DDRD,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRD,pinNumber);
			}
			else{
				//error handling
			}
			break;
	}
}
void DIO_write_pin(uint8 portNumber, uint8 pinNumber, uint8 value)
{
	switch(portNumber){
		case PORT_A:
			if(value == LOW){
				//PORTA &= ~(1<<pinNumber); //write 0
				CLEAR_BIT(PORTA,pinNumber);
			}
			else if (value == HIGH){
				//PORTA |= (1<<pinNumber); //write 1
				SET_BIT(PORTA,pinNumber);
			}
			else{
				//error handling
			}
		break;
		case PORT_B:
			if(value == LOW){
				//PORT_B &= ~(1<<pinNumber); //write 0
				CLEAR_BIT(PORTB,pinNumber);
			}else if (value == HIGH){
				//PORT_B |= (1<<pinNumber); //write 1
				SET_BIT(PORTB,pinNumber);
			}
			else{
				//error handling
			}
		break;
		case PORT_C:
			if(value == LOW){
				//PORT_C &= ~(1<<pinNumber); //write 0
				CLEAR_BIT(PORTC,pinNumber);
			}else if (value == HIGH){
				//PORT_C |= (1<<pinNumber); //write 1
				SET_BIT(PORTC,pinNumber);
			}
			else{
				//error handling
			}
		break;
		case PORT_D:
			if(value == LOW){
				//PORT_D &= ~(1<<pinNumber); //write 0
				CLEAR_BIT(PORTD,pinNumber);
			}else if (value == HIGH){
				//PORT_D |= (1<<pinNumber); //write 1
				SET_BIT(PORTD,pinNumber);
			}
			else{
				//error handling
			}
		break;
	}
}
void DIO_toggle_pin(uint8 portNumber, uint8 pinNumber)
{
	switch(portNumber){
		case PORT_A:
			//PORTA ^= (1<<pinNumber);
			TOGGLE_BIT(PORTA,pinNumber);
		break;
		case PORT_B:
			//PORT_B ^= (1<<pinNumber);
			TOGGLE_BIT(PORTB,pinNumber);
		break;
		case PORT_C:
			//PORT_C ^= (1<<pinNumber);
			TOGGLE_BIT(PORTC,pinNumber);
		break;
		case PORT_D:
			//PORTD ^= (1<<pinNumber);
			TOGGLE_BIT(PORTD,pinNumber);
		break;
	}
}
uint8 DIO_read_pin(uint8 portNumber, uint8 pinNumber)
{
	switch(portNumber){
		case PORT_A:
			
			return READ_BIT(PINA,pinNumber);;
		break;
		case PORT_B:
			return READ_BIT(PINB,pinNumber);;
		break;
		case PORT_C:
			return READ_BIT(PINC,pinNumber);;
		break;
		case PORT_D:
			return READ_BIT(PIND,pinNumber);;
		break;
	}
}
// port funcations
void DIO_init_port(uint8 portNumber, uint8 direction)
{
	switch(portNumber){
		case PORT_A:
		if(direction == IN){
			DDRA =0x00;
		}
		else if (direction == OUT){
			DDRA=0xFF;
		}
		else{
			//error handling
		}
		break;
		case PORT_B:
		if(direction == IN){
			DDRB =0x00;
		}
		else if (direction == OUT){
			DDRB =0xFF;
		}
		else{
			//error handling
		}
		break;
		case PORT_C:
		if(direction == IN){
			DDRC =0x00;
		}
		else if (direction == OUT){
			DDRC =0xFF;
		}
		else{
			//error handling
		}
		break;
		case PORT_D:
		if(direction == IN){
			DDRD =0x00;
		}
		else if (direction == OUT){
			DDRD =0xFF;
		}
		else{
			//error handling
		}
		break;
	}
}

void DIO_write_port(uint8 portNumber, uint8 value)
{
	switch(portNumber){
		case PORT_A:
			PORTA = value;
		break;
		case PORT_B:
		    PORTB = value;
		break;
		case PORT_C:
		    PORTC = value;
		break;
		case PORT_D:
		    PORTD = value;
		break;
	}
}