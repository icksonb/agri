
#include "adc.h"

void ADC_Enable(void)
{
	//Habilita ADC com o clock de 125 kHz (16MHz de fonte)
	ADMUX |= (1<<REFS0); //Referência o GND
	ADCSRA |= ( (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));
}

void ADC_Disable(void)
{
	//Disabilita ADC
	ADCSRA &= ~((1<<ADEN));
}

unsigned int ADC_Read(char pin)
{
	ADC_Enable();
	//char tmp = ;
	ADMUX =  (ADMUX & 0xf0) | pin;
	ADCSRA |= (1<<ADSC);
	while ( !(ADCSRA & (1<<ADSC) ));
	unsigned int valor = 0;
	valor = ADCL;
	valor |= (ADCH << 8);
	//ADC_Disable();
	return valor;
}

char ADC_Porcentagem(char pin)
{
	long int bruto = (long int) (ADC_Read(pin) * ((unsigned int)(100)) );
	bruto = bruto/((int) 1023);
	return (char) bruto;
}