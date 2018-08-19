#include <avr/io.h>
#include <avr/interrupt.h>
#include "timers.h"

#define NORMAL 1
#define CTC 2

/*############################ Makefile ##########################
# AUTOR: ICKSON BARBOSA
# BIBLIOTECA TIMERS
#################################################################*/

void Timer1_Init(char type, int prescaler)
{
	switch(type)
	{
		case NORMAL:
			TCCR1A &= ~((1<<WGM11) | (1<<WGM10));
			TCCR1B &= ~((1<<WGM13) | (1<<WGM12));
			break;

		case CTC:
			TCCR1A &= ~((1<<WGM11) | (1<<WGM10));
			TCCR1B &= ~((1<<WGM13) | (1<<WGM12));
			TCCR1B |= (1<<WGM12);
			break;
	}

	switch(prescaler)
	{
		case 0:
			TCCR1B &= ~((1<<CS10) | (1<<CS11) | (1<<CS12));
			break;
		case 1:
			TCCR1B &= ~((1<<CS10) | (1<<CS11) | (1<<CS12));
			TCCR1B |= (1<<CS10);
			break;
		case 8:
			TCCR1B &= ~((1<<CS10) | (1<<CS11) | (1<<CS12));
			TCCR1B |= (1<<CS11);
			break;
		case 64:
			TCCR1B &= ~((1<<CS10) | (1<<CS11) | (1<<CS12));
			TCCR1B |= ((1<<CS10) | (1<<CS11));
			break;
		case 256:
			TCCR1B &= ~((1<<CS10) | (1<<CS11) | (1<<CS12));
			TCCR1B |= (1<<CS12);
			break;
		case 1024:
			TCCR1B &= ~((1<<CS10) | (1<<CS11) | (1<<CS12));
			TCCR1B |= ((1<<CS12) | (1<<CS10));
			break;
	}
}

void Timer1_Disable(void)
{
	Timer1_Init(NORMAL, 0);
}

void delay_ms(unsigned int tempo)
{
	Timer1_Disable();
	unsigned int comp = 0;
	switch(F_CPU)
	{
		case 16000000:
			comp = 16;
			Timer1_Init(NORMAL, 1024);
			break;
		
	}

	int i = 0;
	for (i=0; i<tempo; i++)
	{
		while(TCNT1 < comp);
		TCNT1 = 0;
	}
	Timer1_Disable();
}
