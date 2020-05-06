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

#ifndef I2C_LCD_H
#define I2C_LCD_H
#include "config.h"
/*Data Word Definition for PCF8574*/
/*DB7 DB6 DB5 DB4 P3 EN RW RS*/
/*P7  P6  P5  P4  P3 P2 P1 P0*/

#define RS (1<<0)
#define RW (1<<1)
#define EN (1<<2)
#define geti2c(data) (data << 4)

/*DEFAULT ADDRESS*/
#define DEFADDR 0x40
/*COMMAND DEFINITIONS*/

#define CLRSCR		0x01
#define BIT8LINE2	0x38
#define CURSORVISIBLE	0x0E
#define GOTOHOME	0x80

/*FUNCTIONS PROVIDED BY THIS API*/

/*This function has to be called before using any other lcd functions.
 * It initializes the LCD in 4bit or 8bit modes.
 * mode = 0 --> 8 bit mode
 * mode = 1 --> 4 bit mode*/
void i2c_lcd_init(unsigned int addr);

/*This function sends data to the lcd and displays it, it takes a character as a parameter*/
void i2c_lcd_send_data(unsigned char data);

/*This funtion sends commands to the lcd and takes a character as a parameter*/
void i2c_lcd_send_command(unsigned char cmd);

/*This funtion can be used to print strings on the LCD and it takes character pointer as a parameter*/
void i2c_lcd_write_string(char *string);

/*This funtion is used to set the position of the cursor on the LCD display
 * it takes two parameter which define the row and column of the final position of the cursor
 * so second row and fifth column is (1,4) because this functions counts from 0
 * home position is (0,0)*/
void i2c_lcd_set_cursor(int row, int column);

/*This funtion is used to clear the screen and erase everything written on the LCD*/
void i2c_lcd_clrscr(void);

/*This funtion shows the underline (underscore) cursor if the cursor is hidden*/
void i2c_lcd_show_cursor_underline(void);

/*This futions turns on the block blinking cursor*/
void i2c_lcd_show_cursor_block(void);

/*This funtion hides the cursor and only text remains on the LCD.
 * cursor can be brought back by calling lcd_show_cursor() function*/
void i2c_lcd_hide_cursor(void);
#endif
