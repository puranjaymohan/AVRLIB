## AVRLIB
API Library for AVR Microcontrollers.

AVRLIB is a high level API library for interfacing LCDs, GPIO, USART etc. to the AVR series of Microcontrollers.
# Features of this library:

  - Written in C with good documentation and examples
  - Includes APIs for most peripherals like LCD, RTC, GPIO, UART, I2C etc.
  - Most of the funtions required by a peripheral have predefined APIs.
  - Supports the complete family of AVR Microcontrollers.

> Every API Provides a set of funtions to interface the peripheral.
> Every funtions is documented in the respective API's header file file
> Every API has a been used in example.c file which shows the usage of the funtions

# Programming the Microcontroller
This library comes with a Makefile which includes configurations and targets for programming the controller using AVRDUDE.

# Makefile
The Makefile has to be configured for using it properly.
all APIs that you wish to use need to be added to the makefile variable OBJ=$(LIB)"API NAME" without quotes. 
example:
```Makefile
#Define the AVR Microcontroller here                                                             
MCU=atmega32                                                                                            
#Define the name of your C file here                                                             
TARGET=example
```
# LICENCE
# GNU General Public License Version 3

