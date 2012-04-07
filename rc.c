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
int percent_to_8bit(uint8_t percent){
    uint8_t duty;
    duty = percent * 2.55;
    return duty;
};


void delay_ms(uint16_t ms) {
        while ( ms )
        {
                _delay_ms(1);
                ms--;
        }
}

/*Main function*******************************************/
int main(void){
/*I/0
*/
/*Init****************************************************/
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);
//    DDRB |= (1<<PB0)|(1<<PB3);
//    PORTB |= (1<<PB0);
    DDRC |= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5)|(1<<PC6)|(1<<PC7);
    PORTC = 0x00;
//    DDRD |= (1<<PD0)|(1<<PD1)|(1<<PD2)|(1<<PD3)|(1<<PD7);
//    PORTD |= (1<<PD6);//ENABLING PULL UP    

    //init of pwm on OC0A
//    TCCR0A|=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
//    TCCR0B|=(1<<CS00);
    
    //init of pwm on OC1A
//    TCCR2A|=(1<<WGM20)|(1<<WGM21)|(1<<COM2A1);
//    TCCR2B|=(1<<CS20);
    
    //adc set up
//    ADCSRA |= (1<<ADATE)|(1<<ADEN)|(1<<ADSC);
//    ADMUX |= (1<<ADLAR)|(1<<REFS1)|(1<<REFS0);
    
/*setup**************************************************/
    while(1){
        PORTC &= ~(1<<PC3);
        delay_ms(1000);
        PORTC |= (1<<PC3);
        delay_ms(1000);
    }

}
