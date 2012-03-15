/**********************************************************
*Anthony Webb
*this is atesting program for both programing and compiling
**********************************************************/

#ifndef F_CPU 
   #define F_CPU 100000UL      
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

int main(void){
/*Init****************************************************/
    //enabling needed outputs on port b and c
    DDRB |= (1<<PB3);//OC0A - Right motor
    DDRD |= (1<<PD5);//OC1A - Lect motor
    //DDRC |= (1<<PC0);
    
    /*being used as imputs
    PA0 - ADC0 - Distance sensor input 
    */
    //init of pwm on OC0A
    TCCR0A|=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
    TCCR0B|=(1<<CS00);
    
    //init of pwm on OC1A
    TCCR1A|=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
    TCCR1B|=(1<<CS00);
    
    //adc set up
    ADCSRA |= (1<<ADATE)|(1<<ADEN)|(1<<ADSC);
    ADMUX |= (1<<ADLAR);





}
