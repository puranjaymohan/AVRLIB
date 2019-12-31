/**
* AVRLIB: Example source code for using the I2C API
*
* Copyright (C) 2019, PURANJAY MOHAN.
* This file is part of I2C AVR LIBRARY
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
#include "gpio.h"
#include "i2c.h"
#include <avr/io.h>
#include <util/delay.h>


int main()
{
	gpio_set_mode_output('D',6);

	unsigned int address=0x7E, i=0;
	i2c_init();
	i2c_start(address);
	for(i=0; i<5; i++){
	i2c_write(0x00);
	_delay_ms(1000);
	i2c_write(0xFF);
	_delay_ms(1000);
	}
	i2c_stop();
	return 0;
}



