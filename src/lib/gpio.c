#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>
void gpio_set_mode_output(char port, unsigned int gpio)
{
	switch(port)
	{
		#ifndef __MCU__ATMEGA328__
		case 'A':
			DDRA |= (1<<gpio);
			break;
		#endif	
		case 'B':
			DDRB |= (1<<gpio);
			break;
		case 'C':
			DDRC |= (1<<gpio);
			break;
		case 'D':
			DDRD |= (1<<gpio);
			break;
	/*	case 'E':
			DDRE |= (1<<gpio);
			break;
		case 'F':
			DDRF |= (1<<gpio);
			break;
	*/
	}
	return;
}


void gpio_set_mode_input(char port, unsigned int gpio, unsigned int pull)
{
	switch(port)
	{	
		#ifndef __MCU__ATMEGA328__
		case 'A':
			DDRA &= ~(1<<gpio);
			PORTA |= (pull<<gpio);
			break;
		#endif	
		case 'B':
			DDRB &= ~(1<<gpio);
			PORTB |= (pull<<gpio);
			break;
		case 'C':
			DDRC &= ~(1<<gpio);
			PORTC |= (pull<<gpio);
			break;
		case 'D':
			DDRD &= ~(1<<gpio);
			PORTD |= (pull<<gpio);
			break;
	/*	case 'E':
			DDRE &= ~(1<<gpio);
			PORTE |= (pull<<gpio);
			break;
		case 'F':
			DDRF &= ~(1<<gpio);
			PORTF |= (pull<<gpio);
			break;
	*/
	}
	return;
}


void gpio_set_high(char port, unsigned int gpio)
{
	gpio_set_mode_output(port,gpio);
	switch(port)
	{
		#ifndef __MCU__ATMEGA328__
		case 'A':
			PORTA |= (1<<gpio);
			break;
		#endif	
		case 'B':
			PORTB |= (1<<gpio);
			break;
		case 'C':
			PORTC |= (1<<gpio);
			break;
		case 'D':
			PORTD |= (1<<gpio);
			break;
	/*	case 'E':
			PORTE |= (1<<gpio);
			break;
		case 'F':
			PORTF |= (1<<gpio);
			break;
	*/		
	}
	return;
}	

void gpio_set_low(char port, unsigned int gpio)
{
	gpio_set_mode_output(port,gpio);
	switch(port)
	{
		#ifndef __MCU__ATMEGA328__
		case 'A':
			PORTA &= ~(1<<gpio);
			break;
		#endif	
		case 'B':
			PORTB &= ~(1<<gpio);
			break;
		case 'C':
			PORTC &= ~(1<<gpio);
			break;
		case 'D':
			PORTD &= ~(1<<gpio);
			break;
	/*	case 'E':
			PORTE &= ~(1<<gpio);
			break;
		case 'F':
			PORTF &= ~(1<<gpio);
			break;
	*/
	}
	return;
}

unsigned int gpio_read_pin(char port_, unsigned int gpio)
{
	unsigned int value=0;
	char port;
	gpio_set_mode_input(port_, gpio, 1);
	switch(port_)
	{
		#ifndef __MCU__ATMEGA328__
		case 'A':
			port = PINA;
			port &= (1<<gpio);
			value = port>>gpio;
			break;
		#endif	
		case 'B':
			port = PINB;
			port &= (1<<gpio);
			value = port>>gpio;
			break;
		case 'C':
			port = PINC;
			port &= (1<<gpio);
			value = port>>gpio;
			break;
		case 'D':
			port = PIND;
			port &= (1<<gpio);
			value = port>>gpio;
			break;;
	/*	case 'E':
			port = PINE;
			port &= (1<<gpio);
			value = port>>gpio;
			break;
		case 'F':
			port = PINF;
			port &= (1<<gpio);
			value = port>>gpio;
			break;
	*/
	}
	return value;
}
