#include <string.h>
#include <avr/io.h>
#include <util/delay.h>
#include <transmitter.h>
#include <rotaryEnc.h>

#define pinA_state ( PINC & (1<<PC5) )
#define pinB_state ( PINC & (1<<PC4) )

uint8_t counter;
uint8_t astate;
uint8_t alastState;
char msg[3];
/* char counterStr[3]; */

void ENC_Init(){
     counter = 60;
     alastState = pinA_state;
}

void goEnc(){
    astate = pinA_state;
    if ( astate != alastState ){
        /* if ( ( counter >= 69 ) | ( counter <= 49 ) )  counter = 60; */
        if ( pinB_state != astate ){
            /* counter++; */
            strcpy(msg,"k\n");
            /* USART_TransmitStr(msg); */
        }
        else{
            /* counter-- works for the first anticlockwise rotation,
             * but on the next tick =! fails and counter++ occurs,
             * and this goes on...weird...*/
            /* counter -= 3; */
            strcpy(msg,"j\n");
            /* USART_TransmitStr("acw\n"); */
        }

        /* itoa(counter,counterStr,10); */
        /* strcat(counterStr,"\n"); */
        /* USART_TransmitStr(counterStr); */
        USART_TransmitStr(msg);
        alastState = astate;

    }
}
