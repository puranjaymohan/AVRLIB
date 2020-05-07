/**
* AVRLIB: SPI API related functions definitions
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
#include <avr/io.h>
#include <util/delay.h>

void spi_init(void)
{
	SPI_DDR &= ~((1<<SPI_MISO)); //input
	SPI_DDR |= ((1<<SPI_MOSI) | (1<<SPI_SS) | (1<<SPI_SCK)); //output
	SPI_PORT |= (1<<SPI_MISO);
	SPCR = ((1<<SPE)|               // SPI Enable
            (0<<SPIE)|              // SPI Interupt Enable
            (0<<DORD)|              // Data Order (0:MSB first / 1:LSB first)
            (1<<MSTR)|              // Master/Slave select
            (1<<SPR1)|(1<<SPR0)|    // SPI Clock Rate
            (0<<CPOL)|              // Clock Polarity (0:SCK low / 1:SCK hi when idle)
            (0<<CPHA));             // Clock Phase (0:leading / 1:trailing edge sampling)

	    SPSR = (0<<SPI2X); // Double SPI Speed Bit
}

unsigned int spi_transmit_recieve(unsigned int data)
{
	SPDR = data;
	while((SPSR & (1<<SPIF)) == 0);
	return SPDR;
}


