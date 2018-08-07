#ifndef F_CPU
#define F_CPU 16000000UL // Frequencia de 16MHz
#endif


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "serial.h"

int main(void)
{
	Serial serial(9600);

	DDRB |= (1<<PB5);

	_delay_ms(1000);
	serial.writeFlush(0x01);

	while(1)
	{
		if(serial.read() == 0x01)
		{
			PORTB ^= (1<<PB5);
			_delay_ms(1000);
			serial.writeFlush(0x01);
			_delay_ms(10);
		}
	}
}