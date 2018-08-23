#include <avr/io.h>
#include "spi.h"

void SPI_Init(char pinCS)
{
	//DEFINE OS PINOS DE SAÍDA
	DDRB |= (1<<MOSI) | (1<<SCK) | (1<<pinCS);
   //DDRB &= ~(1<<MISO);
   //PORTB |= (1<<MISO);
   //SPI ENABLE, MASTER, FOSC/16
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0);
}

void SPI_disable(void)
{
	SPCR &= ~(1<<SPE);
}

void SPI_CSL(char pinCS)
{
	PORTB &= ~(1<<pinCS);
}

void SPI_CSH(char pinCS)
{
	PORTB |= (1<<pinCS);
}

void SPI_Transmit(char cData)
{
   /* Inicia transmissão */
   SPDR = cData;
   /* Aguarda finalizar transmissão */
   while(!(SPSR & (1<<SPIF)));
}

char SPI_Receive(void)
{
   /* Espera a recepção */
   while(!(SPSR & (1<<SPIF)));
   /* Retorna o dado lido */
   return SPDR;
}

char SPI_Rcv(void)
{
   SPI_Transmit(0xFF);
   return SPI_Receive();
}