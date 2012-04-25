/**********************************************************
*Anthony Webb
*AVR USART .c file
**********************************************************/
#include "usart.h"

void usart_init(){
    //set baud rate
    UBRR0H = (unsigned char)(UBBR_VALUE >> 8);
    UBRR0L = (unsigned char)UBBR_VALUE;
    
    //enabling receiver
    UCSR0B = (1 << RXEN0);

    // Set gram format: 8 data, 2 stop bit
    UCSR0C = (1 << USBS0)|(3 << UCSZ00);

};

unsigned char usart_read(){

    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1 << RXC0)) ){};

    /* Put data into buffer, sends the data */
    return UDR0;

};

void usart_write(unsigned int data){

    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1 << UDRE0)) ){};

    /* Put data into buffer, sends the data */
    UDR0 = data;


};

