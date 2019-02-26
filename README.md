## AVRLIB
API Library for AVR Microcontrollers.

AVRLIB is a high level API library for interfacing LCDs, GPIO, USART etc. to the AVR series of Microcontrollers.
# Features of this library:

  - Written in C with good documentation and examples.
  - Includes APIs for most peripherals like LCD, RTC, GPIO, UART, I2C etc.
  - Most of the funtions required by a peripheral have predefined APIs functions.
  - Supports the complete family of AVR Microcontrollers.

> Every API Provides a set of funtions to interface the peripheral.
> Every funtions is documented in the respective API's header file file.
> Every API has a API_example.c file which shows the usage of the funtions.

# Programming the Microcontroller
This library comes with a Makefile which includes configurations and targets for programming the controller using AVRDUDE. The microcontroller can be programmed via any other way if required.

# Makefile
The Makefile has to be configured for using it properly.
all APIs that you wish to use need to be added to the makefile variable OBJ=$(LIB)"API NAME" without quotes. 
example:
```Makefile
#Define the AVR Microcontroller here                                                             
MCU=atmega32                                                                                            
#Define the name of your C file here                                                             
TARGET=example
#add all the APIs you need using $(LIB)api1 $(LIB)api2 ... format.
OBJ=$(TARGET).o $(LIB)lcd.o
```
# Using an API in your project
1. define the microcontroller you are using in the Makefile using the MCU variable.
```Makefile
#Define the AVR Microcontroller here                                                             
MCU=atmega32
```
2. include the API in your project by adding #include "API.h" to the top of your source file. Add a definition about your microcontroller before including the above file.
```c
#define __MCU__ATMEGA32__
#include "gpio.h"
```

3. Read the API.h file for configuration and function documentation and use the funtions in your project.

4.Add all names of all the APIs that you have used in your project in the Makefile in the OBJ variable using the following syntax
```Makefile
#add all the APIs you need using $(LIB)api1 $(LIB)api2 ... format.
#Don't remove the $(TARGET).o , just add all the required apis after $(TARGET).o. Examole for using LCD and GPIO api
OBJ=$(TARGET).o $(LIB)lcd.o  $(LIB)gpio.o
```
# LICENCE
# GNU General Public License Version 3

