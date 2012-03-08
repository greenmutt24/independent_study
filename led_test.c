/**********************************************************
*Anthony Webb
*this is atesting program for both programing and compiling
**********************************************************/

#ifndef F_CPU 
   #define F_CPU 10000000UL      
#endif 

#include <avr/io.h>
#include <util/delay.h>

int main(void){
    
    InitTimer();

    DDRB = 0xff;
    DDRC = 0xff;

    PORTB = 0x01;

    _delay_ms(500);

    PORTB = 0x00;
    
    return 0;
}

