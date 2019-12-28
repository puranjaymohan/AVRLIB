/**
* AVRLIB: Header file for UART API configurations and function prototypes
*
* Copyright (C) 2019, PURANJAY MOHAN.
* This file is part of AVRLIB
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



#ifndef __UART_H_
#define __UART_H__
#include "config.h"
#include "uart_config.h"
//Definitions for compatibility between atmega32 and atmega328p
#ifdef __MCU__ATMEGA328__
#define UBRRH UBRR0H
#define UBRRL UBRR0L
#define UDR UDR0

#define UCSRA UCSR0A
#define UDRE UDRE0
#define RXC RXC0

#define UCSRB UCSR0B
#define RXEN RXEN0
#define TXEN TXEN0
#define RXCIE RXCIE0

#define UCSRC UCSR0C
#define URSEL
#define UCSZ0 UCSZ00
#define UCSZ1 UCSZ01
#define URSEL
#define UCSRC_SELECT 0
#else
#define UCSRC_SELECT (1 << URSEL)
#endif
//end of compatibility definitions

#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

/*Functions Provided by UART API*/

/*This Functions initializes the uart register with the given baud rate and data frame specification, they can exclsively be editied at src/lib/uart.c 
 *This function has to be called before using any other API functions*/
void uart_init(void);

/*This fuctions reads the uart buffer and returns the data as an unsigned character*/
char uart_receive(void);

/*This function can be called to send data through UART as an unsigned character*/
void uart_send(char data);

/*This function can be called to send a string through the UART by providing the pointer to the string as the parameter.*/
void uart_send_string(char* StringPtr);

/*This function can be called to receive a string through the UART by providing the pointer to the place where the string has to be stored and also the length of the string.*/
void uart_receive_string(char* StringPtr, unsigned int len);

#endif
