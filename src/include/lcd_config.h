#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

/*LCD TYPES
 * define the lcd type with the options given below
 * 1 - 16 X 2
 * 2 - 20 X 4 */
#define LCDTYPE		2

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

#endif
