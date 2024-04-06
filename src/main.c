#include <avr/io.h>
#include <util/delay.h>

#include "usart.h"

int main(void) {
    uint8_t data;

    DDRB |= (1 << PB5);
    PORTB |= (1 << PB5);
    USART_Init(MYUBRR);

    while(1) {
        uint8_t str[] = {'h', 'e', 'l', 'l', 'o', '0'};
        USART_rx_str(str);
        _delay_ms(1000);
    }

    return 0;
}