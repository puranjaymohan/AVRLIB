/**
* AVRLIB: LCD API related functions definitions
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

static int bit4 = 0;

void lcd_send_command(unsigned char cmd)
{
	if (bit4==0){
		DATAPORT=cmd;
		_delay_ms(1);
		CONPORT &= ~(1<<RS) & ~(1<<RW);
		CONPORT |= (1<<EN);
		_delay_ms(1);
		CONPORT &= ~(1<<RS) & ~(1<<RW) & ~(1<<EN);
		return;
	}else if(bit4 == 1){
		DATAPORT = (cmd&0xF0) | (DATAPORT & 0x0F);
		_delay_ms(1);
		CONPORT &= ~(1<<RS) & ~(1<<RW);
		CONPORT |= (1<<EN);
		_delay_ms(1);
		CONPORT &= ~(1<<RS) & ~(1<<RW) & ~(1<<EN);

		_delay_ms(2);
		DATAPORT = (cmd << 4) | (DATAPORT & 0x0F);
		CONPORT &= ~(1<<RS) & ~(1<<RW);
		CONPORT |= (1<<EN);
		_delay_ms(1);
		CONPORT &= ~(1<<RS) & ~(1<<RW) & ~(1<<EN);
		_delay_ms(2);

		return;
	}
}



void lcd_init(unsigned int mode)
{
	_delay_ms(100);
	switch(mode){
		case 0:
			bit4=0;
			DATADDR=0xff;
			CONDDR |= (1<<RS)|(1<<EN)|(1<<RW);
			lcd_send_command(0x38);
			_delay_ms(1);
			lcd_send_command(0x01);
			_delay_ms(1);
			lcd_send_command(0x0E);
			_delay_ms(1);
			lcd_send_command(0x80);
			_delay_ms(1);
			break;
		case 1:
			bit4=1;
			DATADDR=0xf0 | DATADDR;
			CONDDR |= (1<<RS)|(1<<EN)|(1<<RW);
			lcd_send_command(0x02);
			_delay_ms(4);
			lcd_send_command(0x28);
			_delay_ms(1);
			lcd_send_command(0x01);
			_delay_ms(1);
			lcd_send_command(0x0c);
			_delay_ms(1);
			lcd_send_command(0x06);
			/*
			lcd_send_command(0x80);
			_delay_ms(1);
			lcd_send_command(0x00);
			lcd_send_command(0x80);
			_delay_ms(1);
			lcd_send_command(0x00);
			lcd_send_command(0x10);
			_delay_ms(1);
			lcd_send_command(0x00);
			lcd_send_command(0x60);
			*/
			_delay_ms(1);

			break;

	return;
	}
}

void lcd_send_data(unsigned char data)
{
	if(bit4 == 0){
		DATAPORT=data;
		CONPORT &= ~(1<<RW);
		CONPORT |= (1<<RS) | (1<<EN);
		_delay_ms(1);
		CONPORT &= ~(1<<RW) & ~(1<<EN);
		CONPORT |= (1<<RS);
		_delay_ms(1);
		return;
	}

	else if(bit4 == 1){
		DATAPORT = (data & 0xF0) | (DATAPORT & 0x0F) ;
		CONPORT &= ~(1<<RW);
		CONPORT |= (1<<RS) | (1<<EN);
		_delay_ms(1);
		CONPORT &= ~(1<<RW) & ~(1<<EN);
		CONPORT |= (1<<RS);
		_delay_ms(1);
		DATAPORT = (data << 4) | (DATAPORT & 0x0F);
		CONPORT &= ~(1<<RW);
		CONPORT |= (1<<RS) | (1<<EN);
		_delay_ms(1);
		CONPORT &= ~(1<<RW) & ~(1<<EN);
		CONPORT |= (1<<RS);
		_delay_ms(2);
		return;
	}
}

void lcd_write_string(char *string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		lcd_send_data(string[i]);
		_delay_ms(1);
		i++;
	}
	return;
}

void lcd_set_cursor(int row, int column)
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

	lcd_send_command(address);

	return;
}

void lcd_clrscr(void)
{
	lcd_send_command(CLRSCR);
	lcd_set_cursor(0,0);
	return;
}

void lcd_hide_cursor(void)
{
	lcd_send_command(0x0C);
	return;
}

void lcd_show_cursor_underline()
{
	lcd_send_command(0x0E);
	return;
}

void lcd_show_cursor_block()
{
	lcd_send_command(0x0F);
	return;
}
