/**********************************************************
*Anthony Webb
*this is a band based wall folowing algorithm
**********************************************************/

#ifndef F_CPU 
   #define F_CPU 1000000UL      
#endif 

#include <avr/io.h>
#include <util/delay.h>

//input the percent you want returns the 8 bit value of
//given percent
int percent_to_8bit(uint8_t percent){
    uint8_t duty;
    duty = percent * 2.55;
    return duty;
};

void delay_s(int sec){
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
PD7 - OC2A - Lect motor
PD6 - PUSH BUTTON
*/
/*Init****************************************************/
    DDRB |= (1<<PB0)|(1<<PB3);
    PORTB |= (1<<PB0);
    
    DDRD |= (1<<PD0)|(1<<PD1)|(1<<PD2)|(1<<PD3)|(1<<PD7);
    PORTD |= (1<<PD6);//ENABLING PULL UP    
    //init of pwm on OC0A
    TCCR0A|=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
    TCCR0B|=(1<<CS00);
    
    //init of pwm on OC1A
    TCCR2A|=(1<<WGM20)|(1<<WGM21)|(1<<COM2A1);
    TCCR2B|=(1<<CS20);
    
    //adc set up
    ADCSRA |= (1<<ADATE)|(1<<ADEN)|(1<<ADSC);
    ADMUX |= (1<<ADLAR)|(1<<REFS1)|(1<<REFS0);
    
/*setup**************************************************/
    int base;
    int i =1;
    PORTD |= (1<<PD1);
    while(i){
        if(!(PIND & (1<<PD6))){
            base = ADCH;
            PORTD &= ~(1<<PD1);
            PORTD |= (1<<PD0);
            delay_s(10);
            i = 0;
        }
    }

    int band = 10;
    while(1){
    current_distance = ADCH;
    samples++;
        PORTD &= ~((1<<PD1)|(1<<PD2)|(1<<PD3));
        
        if (ADCH > (base + band)){
            PORTD |= (1<<PD3);
            OCR0A = percent_to_8bit(30);
            OCR2A = percent_to_8bit(80);
        }else if(ADCH < (base - band)){
            //turning tword the wall
            PORTD |= (1<<PD1);
            OCR0A = percent_to_8bit(80);
            OCR2A = percent_to_8bit(30);
        }else {
            //go forward
            PORTD |= (1<<PD1)|(1<<PD3);
            OCR0A = percent_to_8bit(60);
            OCR2A = percent_to_8bit(60);
        }

        _delay_ms(500);   
    }
}
