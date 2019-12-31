/**
* AVRLIB: Header file for I2C API configurations and function prototypes
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

#ifndef _I2C_H_
#define _I2C_H_
#include "config.h"
#include "i2c_config.h"
#include <math.h>
//TWBR Calculation based on SCL_CLK
#define BITRATE(TWSR)   ((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

/*Functions Provided by UART API*/
/*This function sets the TWBR register for accoding to the i2c frequency*/
void i2c_init(void);

/*This functions creates the start condition on the bus*/
unsigned int i2c_start(unsigned int address);

/*This function creates the repeated start condition on the bus*/
unsigned int i2c_repeated_start(unsigned int address);

/*This funtion writes 8 bit data to the bus*/
unsigned int i2c_write(char data);

/*This funtion reads a byte from the bus and generates an ACK or a NACK signal*/
char i2c_read(unsigned int send_nack);

/*This funtions creates the stop condition on the bus*/
void i2c_stop(void);
#endif
