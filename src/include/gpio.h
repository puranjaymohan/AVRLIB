/**
* AVRLIB: Header file for GPIO API configurations and function prototypes
*
* Copyright (C) 2019, PURANJAY MOHAN.
* This file is part of AVRLIB
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
#ifndef GPIO_H
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#define GPIO_H


void gpio_set_mode_output(char port, unsigned int gpio);
void gpio_set_mode_input(char port, unsigned int gpio, unsigned int pull);
void gpio_set_low(char port, unsigned int gpio);
void gpio_set_high(char port, unsigned int gpio);
unsigned int gpio_read_pin(char port_, unsigned int gpio);
#endif
