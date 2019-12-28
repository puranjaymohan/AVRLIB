####Makefile for LCD API####
###
# HD44780 LCD AVR LIBRARY: API related functions
#
# Copyright (C) 2019, PURANJAY MOHAN.
# This file is part of HD44780 LCD AVR LIBRARY
#
# HD44780 LCD AVR LIBRARY is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# HD44780 LCD AVR LIBRARY is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
###
###
CC=avr-gcc
OBJCOPY=avr-objcopy
INC=-Isrc/include
LIB=src/lib/
###

#Define the AVR Microcontroller here
MCU=atmega32
#Define the name of your C file here
TARGET=UART_example
#add all the APIs you need using $(LIB)api1 $(LIB)api2 ... format.
OBJ=$(TARGET).o $(LIB)lcd.o $(LIB)gpio.o $(LIB)uart.o


CFLAGS= -mmcu=$(MCU) -Os -Wall $(INC) 

DEPS=lcd.h

REMOVE=rm -f

PROG=usbasp

all: $(TARGET).hex
	$(REMOVE) $(TARGET).o $(TARGET).elf $(OBJ)
	echo "Done Comiling and Linking"

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -j .text -j .data $(TARGET).elf $(TARGET).hex

$(TARGET).elf: $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ)  --output $(TARGET).elf

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

src/lib/%.o: src/lib/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(REMOVE) $(TARGET).hex $(OBJ)

program: all
	avrdude -c $(PROG) -p $(MCU) -U flash:w:$(TARGET).hex
