/**********************************************************
*Anthony Webb
*AVR USART .h file
**********************************************************/

#include "cpu_clock.h"
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define BAUD_RATE 4800
#define UBBR_VALUE ((F_CPU / (BAUD_RATE * 16UL)) - 1)

void usart_init();

char usart_read();

void usart_write(char data);

