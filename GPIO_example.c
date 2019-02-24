/**
* AVRLIB: Example source code for using the GPIO API
*
* Copyright (C) 2019, PURANJAY MOHAN.
* This file is part of HD44780 LCD AVR LIBRARY
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

#define __MCU__ATMEGA328__
#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>

int main()
{	
	for (;;)
	{
		gpio_set_high('D',6); //writing a one to PORTD pin 6
		_delay_ms(1000);      //delay of one second	
		gpio_set_low('D',6);  //writing a zero to PORTD pin 6
		_delay_ms(1000);      //delay of one second
	}	
	return 0;
}




