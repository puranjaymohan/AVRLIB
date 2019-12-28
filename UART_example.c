#include <stdlib.h>
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>

unsigned int i;
char c, *d;
unsigned int len = 5;
int main(void){
	uart_init();
	d=(char *)malloc(sizeof(char)*len);
	uart_send_string("hello UART\n\r");
	_delay_ms(10);
	uart_send_string("please send a character\n\r");
	c=uart_receive();
	uart_send_string("Recieved Char : ");
	uart_send(c);
	uart_send_string("\n\r");

	uart_send_string("please enter a string\n\r");
	uart_receive_string(d,len);
	uart_send_string(d);
	uart_send_string("\n\r");
	return 0;
}

