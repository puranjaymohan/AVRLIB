/**
* AVRLIB: Example source code for using the LCD HD44780 API
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

#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>

int main()
{	
	lcd_init(); //initialize the LCD

	lcd_write_string("HELLO"); //lcd_write_string() prints strings on the LCD 
	
	lcd_show_cursor_block(); //lcd_show_cursor_block() turns the cursor to a blinking block
	
	lcd_set_cursor(1,0); //lcd_set_cursor() sets the postion of the cursor at (row,column)

	lcd_write_string("HD44780 LCD API FOR");
	lcd_set_cursor(2,0);
	lcd_write_string("AVR MICROCONTROLLERS");	
	lcd_set_cursor(3,0);
	lcd_write_string("BY PURANJAY MOHAN");
	_delay_ms(5000);
	
	lcd_clrscr(); //lcd_clrscr() clears the screen
	
	lcd_hide_cursor(); //lcd_hide_cursor() hides the cursor from the dislay
	_delay_ms(1000);
	lcd_show_cursor_underline(); //lcd_show_cursor_underline() shows the cursor as an underscore
	return 0;
}





