/**
* AVRLIB: Example source code for using the SPI API
*
* Copyright (C) 2019, PURANJAY MOHAN.
* This file is part of SPI AVR LIBRARY
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

#include "spi.h"
#include "i2c_lcd.h"
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	unsigned int data = 0x51, datar;
	spi_init();
	i2c_lcd_init(DEFADDR);
	while(1){
		datar = spi_transmit_recieve(data);
		i2c_lcd_send_data((char)datar);
	}
	return 0;
}