# AVRLIB
Hardware Abstraction Library for AVR Microcontrollers.

AVRLIB is a high level Hardware Abstarction API library for interfacing LCDs, GPIO, USART etc. to the AVR series of Microcontrollers.

##### Table of Contents

[Features](#features)

[How to Program](#program)

[Makefile](#makefile)

[How to use the API in your project](#howtouse)

[LCD API](#lcdapi)

[GPIO API](#gpioapi)

[UART API](#uartapi)

[License](#license)

<a name="features"/>
## Features of this library:

  - Written in C, well documented and includes many examples.
  - Includes APIs for most peripherals like LCD, RTC, GPIO, UART, I2C etc.
  - Most of the funtions required by a peripheral have predefined APIs functions.
  - Supports the complete family of AVR Microcontrollers.

> Every API Provides a set of funtions to interface the peripheral.
> Every funtions is documented in the respective API's header file file.
> Every API has a API_example.c file which shows the usage of the funtions.

<a name="program"/>
## Programming the Microcontroller
This library comes with a Makefile which includes configurations and targets for programming the controller using AVRDUDE. The microcontroller can be programmed via any other method if required.

<a name="makefile"/>
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

<a name="howtouse"/>
## Using an API in your project
1. define the microcontroller you are using in the Makefile using the MCU variable.
```Makefile
#Define the AVR Microcontroller here                                                             
MCU=atmega32
```
2. include the API in your project by adding #include "API.h" to the top of your source file.
```c
#include "gpio.h"
```

3. Read the API.h file for configuration and function documentation and use the funtions in your project.

4. Add all names of all the APIs that you have used in your project in the Makefile in the OBJ variable using the following syntax
```Makefile
#add all the APIs you need using $(LIB)api1 $(LIB)api2 ... format.
#Don't remove the $(TARGET).o , just add all the required apis after $(TARGET).o. Examole for using LCD and GPIO api
OBJ=$(TARGET).o $(LIB)lcd.o  $(LIB)gpio.o
```
5. Edit the config.h file present in src/include/ and add details about the cpu frequency and target microcontroller
```Makefile
#define __MCU__ATMEGA32__
#define F_CPU 16000000UL
```

<a name="lcdapi"/>
# LCD API 
This API provides functions to interface HD44780 LCD in both 4 and 8 bit mode. This only supports 16x2 and 20x4 LCDs, but support for other LCDs can be added easily.
## Configuring the API
Edit the lcd_config.h header file which can be found at src/include/, in this file define the pins which you have used to connect you LCD to your microcontroller.
Change the file according to your connections, variables which need changes are given below.
```c
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
It takes mode as the parameter and doesn't return anything.
mode = 0 --> 8 bit mode.
mode = 1 --. 4 bit mode.

Parameters - __unsigned int__ mode

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
### 10. lcd_hide_cursor()
This function can be called to hide the cursor, any of the above two functions can be called to get back the cursor.

Parameters - __void__

Returns - __Void__

__Example:__
```c
lcd_hide_cursor();
```

<a name="gpioapi"/>
# GPIO API
This API provides functions to interface GPIOs. It provides functions for easy usage of gpios, the functions are similar to arduino's pinMode and digitalWrite functions.
## Configuring the API
Edit the config.h header file which can be found at src/include/, in this file define the crystal frequency and the mcu name. This API doesn't requires any other configurations
## Functions Provided by GPIO API
### 1. gpio_set_mode_output(__char__ port, __unsigned int__ gpio)
This function initializes the given gpio of the given port as an output.
It takes Port name and pin as parameters, doesn't return anything.

Parameters - __char__ port, __unsigned int__ gpio

Returns - __Void__

__Example:__
```c
gpio_set_mode_output('B',5); // Initializing pin 5 of port B as an output
```
### 2. gpio_set_mode_input(__char__ port, __unsigned int__ gpio, __unsigned int__ pull);
This function sets the gpio of given port as an input.
It takes Port name, pin, and pull(0 or 1) as parameters, doesn't return anything.

Parameters - __char__ port, __unsigned int__ gpio, __unsigned int__ pull

Returns - __Void__

__Example:__
```c
gpio_set_mode_input('B',5,1); // Initializing pin 5 of port B as an input with internal pull-up
gpio_set_mode_input('B',0,0); // Initializing pin 0 of port B as an input with internal pull-down
```
### 3. gpio_set_low(__char__ port, __unsigned int__ gpio);
This function writes a 0 to the given pin of the given port.

Parameters - __char__ port, __unsigned int__ gpio 

Returns - __Void__

__Example:__
```c
gpio_set_low('B',3); //Writing a 0 to pin 3 of Port B
```
### 4. gpio_set_high(__char__ port, __unsigned int__ gpio);
This function writes a 1 to the given pin of the given port.

Parameters - __char__ port, __unsigned int__ gpio 

Returns - __Void__

__Example:__
```c
gpio_set_high('A',3); //Writing a 1 to pin 3 of Port B
```
### 5. unsigned int gpio_read_pin(__char__ port, __unsigned int__ gpio);
This function reads the pin of given port and returns the value as an int(0 or 1)

Parameters - __char__ port, __unsigned int__ gpio 

Returns - __unsigned int__ value

__Example:__
```c
unsigned int value;
value = gpio_read_pin("C", 3); //reading the value of pin 3 of Port C and stroing it in value.
```

<a name="uartapi"/>
# UART API
This API provides functions to interface the UART peripheral of the microcontroller. 
## Configuring the API
Edit the uart_config.h header file which can be found at src/include/, in this file define the baud rate for the uart communication. This API doesn't requires any other configurations
## Functions Provided by UART API
### 1. uart_init(__void__)
This Functions initializes the uart register with the given baud rate and data frame specification, they can exclusively be edited in src/lib/uart.c
This function has to be called before using any other API functions

Parameters - __Void__

Returns - __Void__

__Example:__
```c
uart_init(); // Initializing uart with baud rate given in uart_config.h
```
### 2. char uart_receive(__void__);
This function reads the uart buffer and returns the data as an unsigned character.

Parameters - __Void__

Returns - __char__

__Example:__
```c
char data;
data = uart_receive();
```
### 3. uart_send(__char__ data);
This function can be called to send data through UART as an unsigned character(one byte).

Parameters - __char__ data 

Returns - __Void__

__Example:__
```c
uart_send('P');
```
### 4. uart_send_string(__char*__ StringPtr);
This function can be called to send a string through the UART by providing the pointer to the string as the parameter.

Parameters - __char*__ ptr 

Returns - __Void__

__Example:__
```c
char string[] = "Hello";
uart_send_string(string);
```
### 5. uart_receive_string(__char*__ StringPtr, __unsigned int__ len);
This function can be called to receive a string through the UART by providing the pointer to the place where the string has to be stored and also the length of the string.

Parameters - __char*__ ptr 

Returns - __Void__

__Example:__
```c
unsigned int len = 5;
char string[5];
uart_receive_string(string, len);
```
<a name="license"/>
### LICENCE
#### GNU General Public License Version 3
