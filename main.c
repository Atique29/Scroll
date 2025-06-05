#include <avr/io.h>
#include <util/delay.h>
#include <transmitter.h>
#include <rotaryEnc.h>

#define F_CPU 2000000UL
#define BAUD 9600UL

int main(void) {

    /* initialize pullup on input pin pc5 */
    PORTC |= ( 1<<PC5 ) | ( 1<<PC4 );

    USART_Init(BAUD,F_CPU);
    ENC_Init();

    char *yah = "lets get this thing going\n";
    USART_TransmitStr(yah);

    while (1) {
      goEnc();
    }
  return 0;
}

  /* DDRB |= 0b00000011; */
/*     PORTB = 0b00000011; */
/*     _delay_ms(5000); */
/*     PORTB = 0b00000000; */
    /* _delay_ms(2000); */

    /* unsigned char serialCharacter = USART_Receive(); */
    /* if (bit_is_clear(PINC,PC5)){ */
    /*     USART_Transmit('A'); */
    /*     USART_Transmit('\n'); */
    /* } */
    /* _delay_ms(50); */
    /* if (bit_is_clear(PINC,PC4)){ */
    /*     USART_Transmit('B'); */
    /*     USART_Transmit('\n'); */
    /* } */
