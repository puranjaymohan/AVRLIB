/**
* AVRLIB: I2C API related functions definitions
*
* Copyright (C) 2019, PURANJAY MOHAN.
* This file is part of I2C API LIBRARY
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
#include <avr/io.h>
#include <util/delay.h>
#include <util/twi.h>

void i2c_init(void)
{
	TWBR=BITRATE(TWSR=0x00);
}

unsigned int i2c_start(unsigned int address)
{
	unsigned int status;
	TWCR = (1<<TWSTA) | (1<<TWEN) | (1<<TWINT);
	while(!(TWCR&(1<<TWINT)));
	status = TWSR & 0xF8;

	if (status != TW_START)
	return 3;

	TWDR = address;
	TWCR = (1<<TWEN) | (1<<TWINT);
	while(!(TWCR&(1<<TWINT)));
	status = TWSR & 0xF8;
	if ((status == TW_MR_SLA_ACK) || (status == TW_MT_SLA_ACK))
	return 0;
	if ((status == TW_MR_SLA_NACK) || (status == TW_MT_SLA_NACK))
	return 1;

	return 2;
}

unsigned int i2c_repeated_start(unsigned int address)
{
	unsigned int status;
	TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWSTA);
	while(!(TWCR&(1<<TWINT)));
	status = TWSR & 0xF8;
	if (status != TW_REP_START)
	return 3;

	TWDR = address;
	TWCR = (1<<TWEN) | (1<<TWINT);
	while(!(TWCR&(1<<TWINT)));
	status = TWSR & 0xF8;
	if ((status == TW_MR_SLA_ACK) || (status == TW_MT_SLA_ACK))
	return 0;
	if ((status == TW_MR_SLA_NACK) || (status == TW_MT_SLA_NACK))
	return 1;

	return 2;
}

unsigned int i2c_write(char data)
{
	unsigned int status;
	TWDR = data;
	TWCR = (1<<TWEN) | (1<<TWINT);
	while(!(TWCR&(1<<TWINT)));
	status = TWSR & 0xF8;
	if (status == TW_MT_DATA_ACK)
	return 0;
	if (status == TW_MT_DATA_NACK)
	return 1;

	return 2;
}

char i2c_read(unsigned int send_nack)
{
	char TWCR_buff = (1<<TWEN) | (1<<TWINT);
	if(send_nack == 0)
	TWCR_buff |= (1<<TWEA);

	TWCR = TWCR_buff;
	while(!(TWCR&(1<<TWINT)));
	return TWDR;
}

void i2c_stop(void)
{
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
	while(TWCR & (1<<TWSTO));
}
