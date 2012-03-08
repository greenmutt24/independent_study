/**********************************************************
*Anthony Webb
*this is atesting program for both programing and compiling
**********************************************************/

#ifndef F_CPU 
   #define F_CPU 100000UL      
#endif 

#include <avr/io.h>
#include <util/delay.h>

int main(void){
    

    DDRB = 0xff;
    DDRC = 0xff;

    while(1){
        PORTB = 0x01;
        _delay_ms(500);
        PORTB = 0x00;
        PORTC = 0X01;
        _delay_ms(500);
        PORTC = 0x00;
    }
    return 0;
}

