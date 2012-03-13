/**********************************************************
*Anthony Webb
*this is atesting program for both programing and compiling
**********************************************************/

#ifndef F_CPU 
   #define F_CPU 100000UL      
#endif 

#include <avr/io.h>
#include <util/delay.h>

int pwm(uint8_t percent){
    uint8_t duty;
    duty = percent * 2.55;
    return duty;
};

int main(void){
    
    //turning port b and c into all outputs
    DDRB = 0xff;
    DDRC = 0xff;

    //init of pwm
    TCCR0A|=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
    TCCR0B|=(1<<CS00);
      
    uint8_t brightness = 0;
    while(1){
        
        OCR0A = pwm(brightness++);
        brightness++;
        if(brightness > 100){
            brightness = 0;
            PORTC|=(1<<PC0);
            _delay_ms(1000);
            PORTC=(0<<PC0);
        }
        
        _delay_ms(2000);

        //PORTB |= (1<<PB0);
        //_delay_ms(1000);
        //PORTB = 0x00;
        //PORTC |=(1<<PC0);
        //_delay_ms(1000);
        //PORTC = 0x00;
    }
    return 0;
}

