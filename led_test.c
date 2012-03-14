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
/*Init****************************************************/
    //enabling needed outputs on port b and c
    DDRB |= (1<<PB3);//oc9a
    DDRC |= (1<<PC0);

    //init of pwm on oc0a
    TCCR0A|=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
    TCCR0B|=(1<<CS00);
    
    //adc set up
    ADCSRA |= (1<<ADATE)|(1<<ADEN)|(1<<ADSC);
    ADMUX |= (1<<ADLAR);
    
/*End Init************************************************/
    uint8_t brightness = 0;
    while(1){
        OCR0A = ADCH;

        /*ROTATING BRIGHTNESS
        OCR0A = pwm(brightness++);
        brightness++;
        if(brightness > 100){
            brightness = 0;
            PORTC|=(1<<PC0);
            _delay_ms(1000);
            PORTC=(0<<PC0);
        }
        
        _delay_ms(2000);
        */


        /*SWITHING LIGHTS
        PORTB |= (1<<PB0);
        _delay_ms(1000);
        PORTB = 0x00;
        PORTC |=(1<<PC0);
        _delay_ms(1000);
        PORTC = 0x00;*/
    }
    return 0;
}

