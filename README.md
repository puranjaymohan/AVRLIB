# AVRLIB
API Library for AVR Microcontrollers.

AVRLIB is a high level API library for interfacing LCDs, GPIO, USART etc. to the AVR series of Microcontrollers.
## Features of this library:

  - Written in C, well documented and includes many examples.
  - Includes APIs for most peripherals like LCD, RTC, GPIO, UART, I2C etc.
  - Most of the funtions required by a peripheral have predefined APIs functions.
  - Supports the complete family of AVR Microcontrollers.

> Every API Provides a set of funtions to interface the peripheral.
> Every funtions is documented in the respective API's header file file.
> Every API has a API_example.c file which shows the usage of the funtions.

## Programming the Microcontroller
This library comes with a Makefile which includes configurations and targets for programming the controller using AVRDUDE. The microcontroller can be programmed via any other method if required.

## Makefile
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
## Using an API in your project
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

4. Add all names of all the APIs that you have used in your project in the Makefile in the OBJ variable using the following syntax
```Makefile
#add all the APIs you need using $(LIB)api1 $(LIB)api2 ... format.
#Don't remove the $(TARGET).o , just add all the required apis after $(TARGET).o. Examole for using LCD and GPIO api
OBJ=$(TARGET).o $(LIB)lcd.o  $(LIB)gpio.o
```
# LCD API 
This API provides functions to interface HD44780 LCD. This supports 16x2 and 20x4 LCDs, but support for other LCDs can be added easily.
## Configuring the API
Edit the lcd.h header file which can be found at src/include/lcd.h, in this file define the pins which you have used to connect you LCD to your microcontroller.
Change the file according to your connections, variables which need changes are given below.
```c
#ifndef LCD_H
/*Define the cpu frequency of your AVR microcontroller*/
#define F_CPU 16000000UL

/*LCD TYPES
 * define the lcd type with the options given below
 * 1 - 16 X 2
 * 2 - 20 X 4 */
#define LCDTYPE		1

/*PIN CONFIGURATIONS
 *define the pins conncted to the lcd
 *DATAPORT is the port connected to data pins
 *similarly define all connections*/
#define DATAPORT	PORTC
#define DATAPIN		PINC
#define DATADDR		DDRC
#define RS		PD3
#define RW		PD4
#define EN		PD7
#define CONPORT		PORTD
#define CONPIN		PIND
#define CONDDR		DDRD
```

## Functions Provided by LCD API
### 1. lcd_init()
This functions initilizes the LCD and sets up all the registers. It has to be called before using any other lcd api function.
It takes no parameters and also doesn't return anything.
Parameters - __Void__
Returns - __Void__
### 2. lcd_send_command(__unsigned char__ command)
This function can be called to send a command to the lcd in 8 bit format, for example 0x01 (clear screen).
Parameters - __unsigned char__ command 
Returns - __Void__
__Example:__
```c
unsigned char cmd = 0x01;
lcd_send_command(cmd);
```
### 3. lcd_send_data(__unsigned char__ data)
This function can be called to send data(single character) to the lcd in, for example 'P'.
Parameters - __unsigned char__ data 
Returns - __Void__
__Example:__
```c
unsigned char data = 'P';
lcd_send_command(data);
```
### 4. lcd_write_string(__char *__ string)
This function can be called to send a string to the lcd, for example "HELLO LCD".
It takes a character pointer to a string and return nothing.
Parameters - __char *__ command 
Returns - __Void__
__Example:__
```c
char *string = "HELLO LCD :D";
lcd_send_command(string);
```
### 5. lcd_set_cursor(__int__ row, __int__ column)
This function can be called to change the position of the cursor to any row and column of the LCD, for example 2,0 (second row, first column). It takes two integers as parameters for row and column, it assumes 0,0 as first row and first column.
Parameters - __int__ row, __int__  column 
Returns - __Void__
__Example:__
```c
int row = 2;
int col = 1;
lcd_set_cursor(row,col);
```
### 6. lcd_clrscr()
This function can be called to clear the screen and bring the cursor to home position (0,0).
Parameters - __void__
Returns - __Void__
__Example:__
```c
lcd_clrscr();
```
### 7. lcd_clrscr()
This function can be called to clear the screen and bring the cursor to home position (0,0).
Parameters - __void__
Returns - __Void__
__Example:__
```c
lcd_clrscr();
```
### 8. lcd_show_cursor_underline()
This function can be called to make the cursor appear as an underscore i.e. '_'.
Parameters - __void__
Returns - __Void__
__Example:__
```c
lcd_show_cursor_underline();
```
### 9. lcd_show_cursor_block()
This function can be called to make the cursor appear as a block or a box.
Parameters - __void__
Returns - __Void__
__Example:__
```c
lcd_show_cursor_block();
```
### 9. lcd_hide_cursor()
This function can be called to hide the cursor, any of the above two functions can be called to get back the cursor.
Parameters - __void__
Returns - __Void__
__Example:__
```c
lcd_hide_cursor();
```


### LICENCE
#### GNU General Public License Version 3

