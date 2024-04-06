#ifndef USART_H
#define USART_H

#define FOSC 16000000           // cpu frequency
#define BAUD 9600             // baud rate
#define MYUBRR FOSC/16/BAUD-1   // UBBR register value (see atmga328p documentation)

void USART_Init(unsigned int ubrr);

void USART_tx_byte(uint8_t data);
uint8_t USART_rx_byte();

void USART_rx_str(uint8_t str[]);

#endif