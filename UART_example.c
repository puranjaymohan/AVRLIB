
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>



int main(void){
	uart_init();    
 
	while(1){
		uart_send('Q');
		
		 
	}
 
	return 0;
}
 
