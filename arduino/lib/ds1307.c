#include "i2c.h"
#include "serial.h"
#include <stdio.h>
#include "ds1307.h"

void DS1307_init(void)
{
	i2c_init();
}

void DS1307_set24(void)
{
	DS1307_writeRegister(REG_HORAS, SET_24H);
}

unsigned long int DS1307_getTimestamp(void)
{
	char buffer[100];

	/*unsigned char segundo = DS1307_readRegister(REG_SEGUNDOS); 
	unsigned char minuto = DS1307_readRegister(REG_MINUTOS);
	unsigned char hora = DS1307_readRegister(REG_HORAS);
	unsigned char dia = DS1307_readRegister(REG_DIAS);
	unsigned char mes = DS1307_readRegister(REG_MESES);
	unsigned int ano = DS1307_readRegister(REG_ANOS);*/
	
	i2c_stop();

	i2c_start(DS1307_WRITE);
	i2c_write(0x00);
	//i2c_stop();
	i2c_start(DS1307_READ);

	unsigned char segundo = i2c_read_ack();
	unsigned char minuto = i2c_read_ack();
	unsigned char hora = i2c_read_ack();
	unsigned char semana = i2c_read_ack();
	unsigned char dia = i2c_read_ack();
	unsigned char mes = i2c_read_ack();
	unsigned char ano = i2c_read_nack();
	i2c_stop();

	segundo = ((segundo>>4) & 0x07)*10 + (segundo & 0x0F);
	minuto = ((minuto>>4)*10) + (minuto & 0x0F);
	hora = (((hora>>4) & 0x03)* 10 + (hora & 0x0F));
	dia = (((dia>>4) & 0x03)* 10 + (dia & 0x0F));
	mes = (((mes>>4) & 0x01)* 10 + (mes & 0x0F));
	unsigned int anos = 2000 + (((ano>>4))* 10 + (ano & 0x0F));	

	sprintf(buffer, "%d/%d/%d %d:%d:%d\r\n", dia, mes, anos, hora, minuto, segundo);
	Serial_string(buffer);

	return timestamp(segundo, minuto, hora, dia, mes, anos);
}

unsigned char DS1307_readRegister(unsigned char registerRead)
{
	unsigned char valor = 0;
	i2c_stop();

	i2c_start(DS1307_WRITE);
	i2c_write(registerRead);
	i2c_stop();
	i2c_start(DS1307_READ);
	valor = i2c_read_nack();
	i2c_stop();

	return valor;
}

void DS1307_writeRegister(unsigned char registerWrite, unsigned char value)
{
	i2c_stop();

	i2c_start(DS1307_WRITE);
	i2c_write(registerWrite);
	i2c_write(value);
	i2c_stop();

}


void DS1307_set1Hz(void)
{
	DS1307_writeRegister(0x07, 0x10);
}

unsigned long int timestamp(unsigned char seg, unsigned char min, unsigned char hrs, unsigned char dia, unsigned char mes, unsigned int ano)
{
  unsigned long int ts = 0;

  unsigned char anos = 0;
  unsigned char ano_bissexto = 0;
  for( unsigned int y_k = ANO_EPOCA; y_k<ano; y_k++ )
  {
    if( E_ANO_BISSEXTO( y_k ) )
    {
      ano_bissexto++;
    } else {
      anos++;
    }
  }
  ts += (unsigned long int) ( (anos*dias_por_ano[0]) + (ano_bissexto*dias_por_ano[1]) ) * SEG_POR_DIA;

  
  unsigned char ano_posicao = (E_ANO_BISSEXTO( ano )) ? 1 : 0;
  for( unsigned char mo_k = 0; mo_k<(mes-1); mo_k++ )
  { 
    ts += (unsigned long int) (dias_por_mes[ ano_posicao ][ mo_k ] * SEG_POR_DIA);
  }
  
  ts += (unsigned long int) ((dia-1) * SEG_POR_DIA); 

  ts += (unsigned long int) ( ((unsigned long int) hrs) *  ((unsigned long int) SEG_POR_HORA));
  ts += (unsigned long int) (min * SEG_POR_MIN);
  ts += (unsigned long int) seg;

  return ts;
}
