/**********************************************************
*Anthony Webb
*AVR USART .h file
**********************************************************/

#include <cpu_clock.h>
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

void usart_init(int cpu);

int usart_read();

bool usart_write(string data);

