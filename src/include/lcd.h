/**
* AVRLIB: Header file for LCD API configurations and function prototypes
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



#ifndef LCD_H
/*Define the cpu frequency of your AVR microcontroller*/
#define F_CPU 16000000UL

/*LCD TYPES
 * define the lcd type with the options given below
 * 1 - 16 X 2
 * 2 - 20 X 4 */
#define LCDTYPE		2

/*PIN CONFIGURATIONS
 *define the pins conncted to the lcd
 *DATAPORT is the port connected to data pins
 *similarly define all connections*/
#define DATAPORT	PORTC
#define DATAPIN		PINC
#define DATADDR		DDRC
#define RS		PD3
#define RW		PD4
#define EN		PD7
#define CONPORT		PORTD
#define CONPIN		PIND
#define CONDDR		DDRD

/*COMMAND DEFINITIONS
 * Changes here are not required*/
#define CLRSCR		0x01
#define BIT8LINE2	0x38
#define CURSORVISIBLE	0x0E
#define GOTOHOME	0x80

/*FUNCTIONS PROVIDED BY THIS API*/

/*This function has to be called before using any other lcd functions*/
void lcd_init(void);

/*This function sends data to the lcd and displays it, it takes a character as a parameter*/
void lcd_send_data(unsigned char data);

/*This funtion sends commands to the lcd and takes a character as a parameter*/
void lcd_send_command(unsigned char cmd);

/*This funtion can be used to print strings on the LCD and it takes character pointer as a parameter*/
void lcd_write_string(char *string);

/*This funtion is used to set the position of the cursor on the LCD display
 * it takes two parameter which define the row and column of the final position of the cursor
 * so second row and fifth column is (1,4) because this functions counts from 0
 * home position is (0,0)*/
void lcd_set_cursor(int row, int column);

/*This funtion is used to clear the screen and erase everything written on the LCD*/
void lcd_clrscr(void);

/*This funtion shows the underline (underscore) cursor if the cursor is hidden*/
void lcd_show_cursor_underline(void);

/*This futions turns on the block blinking cursor*/
void lcd_show_cursor_block(void);

/*This funtion hides the cursor and only text remains on the LCD.
 * cursor can be brought back by calling lcd_show_cursor() function*/
void lcd_hide_cursor(void);
#endif
