/**********************************************************
*Anthony Webb
*this is atesting program for both programing and compiling
**********************************************************/

#ifndef F_CPU 
   #define F_CPU 1000000UL      
#endif 

#include <avr/io.h>
#include <util/delay.h>

//input the percent you want returns the 8 bit value of
//given percent
int pwm(uint8_t percent){
    uint8_t duty;
    duty = percent * 2.55;
    return duty;
};

void _delay_s(int sec){
    for(int i; i< sec;i++){
        _delay_ms(1000);
    }
}

/*Main function*******************************************/
int main(void){
/*I/0
PA0 - ADC0 - Distance sensor input

PB0 - Distance sensor control
PB3 - OC0A - Right motor

    
PD0 - green led
PD1 - yellow led
PD2 - red led
PD3 - blue led
PD5 - OC1A - Lect motor
PD7 - PUSH BUTTON
*/
/*Init****************************************************/
    DDRB |= (1<<PB0)|(1<<PB3);
    
    DDRD |= (1<<PD0)|(1<<PD1)|(1<<PD2)|(1<<PD3)|(1<<PD5);
    PORTD |= (1<<PD7);//ENABLING PULL UP    
    //init of pwm on OC0A
    TCCR0A|=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
    TCCR0B|=(1<<CS00);
    
    //init of pwm on OC1A
    TCCR1A|=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
    TCCR1B|=(1<<CS00);
    
    //adc set up
    ADCSRA |= (1<<ADATE)|(1<<ADEN)|(1<<ADSC);
    ADMUX |= (1<<ADLAR);
    
/*setup**************************************************/
    int base;
    int i =1;
    PORTD |= (1<<PD1);
    while(i){
        if(!(PIND & (1<<PD7))){
            base = ADCH;
            PORTD &= ~(1<<PD1);
            PORTD |= (1<<PD0);
            _delay_s(2);
            i = 0;
        }
    }

    while(1){
        _delay_ms(1000);
    }
}
