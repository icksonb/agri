#include "i2c.h"
#include "ds1307.h"

unsigned char segundo = 0;
unsigned char minuto = 0;
unsigned char hora = 0;
unsigned char semana = 0;
unsigned char dia = 0;
unsigned char mes = 0;
unsigned char ano = 0;

void DS1307_init(void)
{
	i2c_init();
}

unsigned char DS1307_getSeconds(void)
{
	i2c_stop();

	i2c_start(DS1307_WRITE);
	i2c_write(SECONDS);
	i2c_stop();

	i2c_start(DS1307_READ);
	segundo = i2c_read_ack();
	minuto = i2c_read_ack();
	hora = i2c_read_ack();
	semana = i2c_read_ack();
	dia = i2c_read_ack();
	mes = i2c_read_ack();
	ano = i2c_read_nack();
	i2c_stop();

	return (((segundo>>4) & 0x07)* 10 + (segundo & 0x0F));
}