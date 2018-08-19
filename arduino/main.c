
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "serial.h"
#include "timers.h"
#include "adc.h"

int main(void)
{
	//Serial_Init(9600);

	DDRB |= (1<<PB5);
	delay_ms(1000);
	//Serial_writeFlush(0x01);

	while(1)
	{
		/*if(Serial_read() == 0x01)
		{
			PORTB ^= (1<<PB5);
			delay_ms(1000);
			Serial_writeFlush(0x01);
			delay_ms(1000);
		}*/
		/*if(ADC_Porcentagem(0) > (char) 50)
		//if(ADC_Read(0) > 256)
			PORTB |= (1<<PB5);
		else
			PORTB &= ~(1<<PB5);
		delay_ms(100);*/
		PORTB ^= (1<<PB5);
		delay_ms(1000);
	}
}