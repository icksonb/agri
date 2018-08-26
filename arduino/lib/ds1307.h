/*###############################################################
# AUTOR: ICKSON BARBOSA
# BIBLIOTECA DS1307
#################################################################*/

#ifndef I2C_H_
#define I2C_H_

#define SEG_POR_MIN         60
#define SEG_POR_HORA        3600
#define SEG_POR_DIA         86400
#define MES_POR_ANO	        12
#define ANO_EPOCA           1970
#define E_ANO_BISSEXTO(ano) ( (((ano)%4 == 0) && ((ano)%100 != 0)) || ((ano)%400 == 0) )

#define DS1307_WRITE 0b11010000
#define DS1307_READ  0b11010001
#define SET_24H		 0b01000000

#define REG_SEGUNDOS 0x00
#define REG_MINUTOS	 0x01
#define REG_HORAS	 0x02
#define REG_DIAS	 0x04
#define REG_MESES	 0x05
#define REG_ANOS	 0x06


static int dias_por_mes[2][MES_POR_ANO] = {
  { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

static int dias_por_ano[2] = {
  365, 366
};



void DS1307_init(void);
void DS1307_set1Hz(void);
unsigned long int DS1307_getTimestamp(void);
unsigned char DS1307_readRegister(unsigned char registerRead);
void DS1307_writeRegister(unsigned char registerWrite, unsigned char value);
void DS1307_set24(void);
unsigned long int timestamp(unsigned char seg, unsigned char min, unsigned char hrs, 
	unsigned char dia, unsigned char mes, unsigned int ano);

#endif