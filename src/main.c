#include <avr/io.h>
#include <util/delay.h>

#include "usart.h"
#include "dht.h"

int main(void) {
    uint8_t data;

    DDRB |= (1 << PB5);
    PORTB |= (1 << PB5);

    while(1) {
        PORTB = 0x00;
        _delay_ms(1000);
        PORTB |= (1 << PB5);
        _delay_ms(1000);
    }

    return 0;
}