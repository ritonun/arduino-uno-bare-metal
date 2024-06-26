#include <avr/io.h>
#include "usart.h"
#include <util/setbaud.h>

void USART_Init(unsigned int ubrr) {
    // Init le baud rate
    UBRR0H = UBRRH_VALUE;   // valeur calcule par util/setbaud.h                   
    UBRR0L = UBRRL_VALUE;

    #if USE_2X
      UCSR0A |= (1 << U2X0);
    #else
      UCSR0A &= ~(1 << U2X0);
    #endif

    // activer le recepteur et transmitteur
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    // format de la frame (8bit , 1 stop bit, pas de parite)
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); 
}

void USART_tx_byte(uint8_t data) {
    // fonction blockante
    // transmet un byte
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = data;
}

uint8_t USART_rx_byte() {
    // fonction boquante
    // recoit un byte
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}

void USART_rx_str(uint8_t str[]) {
    // envoi une chaine de caractere byte par btye
    uint8_t i = 0;
    while(str[i] != '0') {
        USART_tx_byte(str[i]);
        i++;
    }
    USART_tx_byte(str[i]);
}
