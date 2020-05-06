/**
* AVRLIB: I2D LCD API related functions definitions
*
* Copyright (C) 2019, PURANJAY MOHAN.
* This file is part of I2C LCD AVR LIBRARY
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

#include "i2c.h"
#include "i2c_lcd.h"
#include <avr/io.h>
#include <util/delay.h>


void i2c_lcd_send_command(unsigned char cmd)
{	unsigned int DATA;
	DATA = geti2c(cmd>>4);
	DATA &= ~(RS) & ~(RW);
	DATA |= (EN);
	i2c_write(DATA);
	_delay_us(1);
	DATA &= ~(RS) & ~(RW) & ~(EN);
	i2c_write(DATA);
	_delay_us(200);
	DATA = geti2c(cmd);
	DATA &= ~(RS) & ~(RW);
	DATA |= (EN);
	i2c_write(DATA);
	_delay_us(1);
	DATA &= ~(RS) & ~(RW) & ~(EN);
	i2c_write(DATA);
	_delay_ms(2);
	return;

}



void i2c_lcd_init(unsigned int addr)
{
	i2c_init();
	i2c_start(addr);
	_delay_ms(20);
	i2c_lcd_send_command(0x33);
	i2c_lcd_send_command(0x32);	/* Send for 4 bit initialization of LCD  */
	i2c_lcd_send_command(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	i2c_lcd_send_command(0x0c);	/* Display on cursor off */
	i2c_lcd_send_command(0x06);	/* Increment cursor (shift cursor to right) */
	i2c_lcd_send_command(0x01);	/* Clear display screen */
	return;
}

void i2c_lcd_send_data(unsigned char data)
{
	unsigned int DATA;
	DATA = geti2c(data>>4);
	DATA |= (RS);  /* RS=1, data reg. */
	DATA |= (EN);
	i2c_write(DATA);
	_delay_us(1);
	DATA &= ~ (EN);
	i2c_write(DATA);
	_delay_us(200);
	DATA = geti2c(data);  /* Sending lower nibble */
	DATA |= (EN);
	i2c_write(DATA);
	_delay_us(1);
	DATA &= ~ (EN);
	i2c_write(DATA);
	_delay_ms(2);
	return;
}

void i2c_lcd_write_string(char *string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		i2c_lcd_send_data(string[i]);
		_delay_ms(1);
		i++;
	}
	return;
}

void i2c_lcd_set_cursor(int row, int column)
{
	unsigned int address=0;
	switch(row)
	{
		case 0:
			address = 128+column;
			break;
		case 1:
			address = 192+column;
			break;
		case 2:
			address = 148+column;
			break;
		case 3:
			address = 212+column;
			break;

	}

	i2c_lcd_send_command(address);

	return;
}

void i2c_lcd_clrscr(void)
{
	i2c_lcd_send_command(CLRSCR);
	i2c_lcd_set_cursor(0,0);
	return;
}

void i2c_lcd_hide_cursor(void)
{
	i2c_lcd_send_command(0x0C);
	return;
}

void i2c_lcd_show_cursor_underline()
{
	i2c_lcd_send_command(0x0E);
	return;
}

void i2c_lcd_show_cursor_block()
{
	i2c_lcd_send_command(0x0F);
	return;
}
