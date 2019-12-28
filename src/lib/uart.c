/**
* AVRLIB: UART API related functions definitions
*
* Copyright (C) 2019, PURANJAY MOHAN.
* This file is part of UART API LIBRARY
*
* AVRLIB is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* AVRLIB is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
**/

#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>

void uart_init(void)
{
	UBRRH = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRRL = (uint8_t)(BAUD_PRESCALLER);
	UCSRB |= (1<<RXEN)|(1<<TXEN);
	UCSRC |= (1<<UCSZ0)|(1<<UCSZ1)| UCSRC_SELECT;
}

char uart_receive(void)
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

void uart_send(char data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
	return;
}

void uart_send_string(char* StringPtr)
{
	while(*StringPtr != 0x00)
	{
		uart_send(*StringPtr);
		StringPtr++;
	}
	return;
}

void uart_receive_string(char* StringPtr, unsigned int len)
{
	int i=0;
	for(i; i<len; i++){
		*StringPtr = uart_receive();
		StringPtr++;
	}
	*StringPtr = '\0';
	StringPtr -= len;
}

