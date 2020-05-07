/**
* AVRLIB: Header file for SPI API configurations and function prototypes
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

#ifndef _SPI_H_
#define _SPI_H_
#include "config.h"
#include "spi_config.h"
#include <math.h>

/*Functions Provided by UART API*/
/*This function initializes the SPI and sets the registers according to given data*/
void spi_init(void);

/*This functions send and recieves one byte of data on the SPI bus*/
unsigned int spi_transmit_recieve(unsigned int data);

#endif
