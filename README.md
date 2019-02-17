## AVRLIB
API Library for AVR Microcontrollers.

AVRLIB is a high level API library for interfacing LCDs, GPIO, USART etc. to the AVR series of Microcontrollers.
# Features of this library:

  - Written in C with good documentation and examples
  - Includes APIs for most peripherals like LCD, RTC, GPIO, UART, I2C etc.
  - Most of the funtions required by a peripheral have predefined APIs.
  - Supports the complete family of AVR Microcontrollers.

> Every API Provides a set of funtions to interface the peripheral.
> Every funtions is documented in the respective API's Readme file
> Every API has a example.c file which shows the usage of the funtions

# Programming the Microcontroller
Every API comes with a Makefile which includes configurations and targets for programming the controller using AVRDUDE.

# Makefile
The Makefile for every API has to be configured for using it properly.
example:
```Makefile
#Define the AVR Microcontroller here                                                             
MCU=atmega32                                                                                            
#Define the name of your C file here                                                             
TARGET=example
```
# LICENCE
# GNU General Public License Version 3

