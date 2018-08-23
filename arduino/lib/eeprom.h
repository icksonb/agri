/*###############################################################
# AUTOR: ICKSON BARBOSA
# BIBLIOTECA EEPROM
#################################################################*/

/*
| TIMESTAMP | UMIDADE DO SOLO (%) + ESTADO | UMIDADE AMBIENTE(%) + ? | TEMPERATURA (% * 20º) |
|	4 BYTES |	1 BYTE  - 7b + 1b 	  	   | 	1 BYTE - 7b + 1b     | 	1 BYTE               |
*/

#ifndef EEPROM_H_
#define EEPROM_H_

#define END_ESCRAVO			0
#define FIM_MEMORIA_EEPROM	1
#define FIM_MEMORIA_FLASH	3

#include <avr/io.h>

extern char ENDERECO_ESCRAVO;

void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);
void EEPROM_init(void);
void EEPROM_IntWrite(unsigned int value);
void EEPROM_CharWrite(unsigned char value);
//void EEPROM_char()

#endif