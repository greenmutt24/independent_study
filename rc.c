/**********************************************************
*Anthony Webb
*this is atesting program for both programing and compiling
**********************************************************/

#include "cpu_clock.h"
#include "usart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define THRESHOLD 650

unsigned char read_byte;

//input the percent you want returns the 8 bit value of
//given percent
int percent_to_8bit(uint8_t percent){
    uint8_t duty;
    duty = percent * 2.55;
    return duty;
};


void delay_s(uint16_t s) {
        int ms  = s * 1000;
        while ( ms )
        {
                _delay_ms(1);
                ms--;
        }
}

/*usart interupt*******************************************/
ISR(USART0_RX_vect){
    read_byte = usart_read();
    
}

/*Main function*******************************************/
int main(void){
/*I/0*/
/*Init****************************************************/
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);

    DDRB |= (1<<PB3);
//    PORTB |= (1<<PB0);
    DDRC |= (1<<PC0)|(1<<PC1)|(1<<PC3)|(1<<PC4);
    DDRD |= (1<<PD7);
//    PORTD |= (1<<PD6);//ENABLING PULL UP    

    //init of pwm on OC0A
//    TCCR0A|=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
//    TCCR0B|=(1<<CS00);
    
    //init of pwm on OC1A
//    TCCR2A|=(1<<WGM20)|(1<<WGM21)|(1<<COM2A1);
//    TCCR2B|=(1<<CS20);
    
    //adc set up
    ADCSRA |= (1<<ADATE)|(1<<ADEN)|(1<<ADSC);
    //ADMUX |= (1<<ADLAR)|(1<<REFS1)|(1<<REFS0);
    
    ADMUX |= (1<<REFS1)|(1<<REFS0);
    
/*setup**************************************************/
    
    usart_init();
    uint16_t adc_full = 0;
    sei();

    //enabling right and left motor turing on green light
    PORTC |= (1<< PC0)|(1<<PC1)|(1<<PC3);

    while(1){
        /*adc_full = 0; 
        adc_full = ( ((uint16_t)(ADCH) << 8)|ADCL);
        if( adc_full > THRESHOLD ) {
            //wall_avoid();
            PORTC |= (1 << PC3);
        }else {
            PORTC &= (0<< PC3);
        }*/
        _delay_ms(500);
        if(read_byte == 'w'){
            //forward
            //left motor forward
            PORTB &= ~(1<< PB3);//1A
            PORTC |= (1<< PC2);//2A
            //right motor forward
            PORTD &= ~(1<< PD7);//3A
            PORTC |= (1<< PC6);//4A

        }else if(read_byte == 'a'){
            //left
            //left motor back
            PORTB |= (1<< PB3);//1A
            PORTC &= ~(1<< PC2);//2A
            //right motor forward
            PORTD &= ~(1<< PD7);//3A
            PORTC |= (1<< PC6);//4A

        }else if(read_byte == 's'){
            //back
            //left motor back
            PORTB |= (1<< PB3);//1A
            PORTC &= ~(1<< PC2);//2A
            //right motor back
            PORTD |= (1<< PD7);//3A
            PORTC &= ~(1<< PC6);//4A

        }else if(read_byte == 'd'){
            //right
            //left motor forward
            PORTB &= ~(1<< PB3);//1A
            PORTC |= (1<< PC2);//2A
            //right motor back
            PORTD |= (1<< PD7);//3A
            PORTC &= ~(1<< PC6);//4A

        }else if(read_byte == 'r'){
            //stop
            //left motor forward
            PORTB &= ~(1<< PB3);//1A
            PORTC &= ~(1<< PC2);//2A
            //right motor forward
            PORTD &= ~(1<< PD7);//3A
            PORTC &= ~(1<< PC6);//4A

        }
        //while ((UCSR0A & (1 << RXC0)) == 0) {};
        
        //read_byte = UDR0;
        //while ((UCSR0A & (1 << UDRE0)) == 0) {};
        //UDR0 = read_byte;
        //usart_write(read_byte);
    //do what usart wants
    
    }

}
