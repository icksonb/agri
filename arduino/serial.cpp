#include <avr/io.h>
#include "serial.h"

#ifndef F_CPU
#define F_CPU 16000000UL // Frequencia de 16MHz
#endif

Serial::Serial(unsigned int baud)
{
	unsigned int ubrr = 0;
	ubrr = F_CPU/16/baud-1;
	
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<TXEN0) | (1<<RXEN0);
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void Serial::write(unsigned char data)
{
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = data;
}

void Serial::writeFlush(unsigned char data)
{
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = data;	
	while(!(UCSR0A & (1<<RXC0)));
	char c = 0;
	c = UDR0;
}

unsigned char Serial::read(void)
{
    //while(!(UCSR0A) & (1<<RXC0));                  
    while(!(UCSR0A & (1<<RXC0)));
    return UDR0;                                   
}

void Serial::string(char s[])
{
	int i =0;
	while (s[i] != 0x00)
	{
		write(s[i]);
		i++;
	}
}
