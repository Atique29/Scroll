#include <avr/io.h>
#include <util/delay.h>

void USART_Init( long unsigned int baud, long unsigned int f_cpu){
    unsigned int ubrr = f_cpu/16/baud - 1 ;
    UBRRH = (unsigned char) (ubrr>>8);
    UBRRL = (unsigned char) ubrr;
    UCSRB = (1<<RXEN) | (1<<TXEN);
    /* 8 bit data, 2 stop bit */
    /* UCSRC = (1<<URSEL) | (1<<USBS)|(3<<UCSZ0); */
    /* 8 bit data, 1 stop bit */
    UCSRC = (1<<URSEL)|(3<<UCSZ0);
}

void USART_Transmit(unsigned char data){
    while (!( UCSRA & (1<<UDRE)))
        ;
    UDR = data;
}

unsigned char USART_Receive(void){
    while (!(UCSRA & (1<<RXC)))
        ;
    return UDR;
}

void USART_TransmitStr( char *str ){
    uint8_t i = 0;
    while(str[i]){
        USART_Transmit(str[i]);
        i++;
    }
}
