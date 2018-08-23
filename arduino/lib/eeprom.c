#include <avr/io.h>
#include "eeprom.h"

unsigned int memoria_eeprom = 0;
unsigned int memoria_flash = 0;

void EEPROM_write(unsigned int uiAddress, unsigned char ucData) 
{
	while(EECR & (1 << EEPE));
	EEAR = uiAddress;
	EEDR = ucData;
	EECR |= 1 << EEMPE;
	EECR |= 1 << EEPE;
}


unsigned char EEPROM_read(unsigned int uiAddress) 
{
    while (EECR & (1 << EEPE));
    EEAR = uiAddress;
    EECR |= (1 << EERE);
    return EEDR;
}

void EEPROM_memoria_eeprom_read(void)
{
	unsigned char memH = EEPROM_read(FIM_MEMORIA_EEPROM);
	unsigned char memL = EEPROM_read(FIM_MEMORIA_EEPROM+1);
	memoria_eeprom = (memH<<8) | memL;
}

void EEPROM_memoria_eeprom_write(void)
{
	unsigned char memH = (memoria_eeprom >> 8);
	unsigned char memL = (unsigned char) memoria_eeprom;
	EEPROM_write(FIM_MEMORIA_EEPROM, memH);
	EEPROM_write(FIM_MEMORIA_EEPROM+1, memL);
}

void EEPROM_memoria_flash_read(void)
{
	unsigned char memH = EEPROM_read(FIM_MEMORIA_FLASH);
	unsigned char memL = EEPROM_read(FIM_MEMORIA_FLASH+1);
	memoria_flash = (memH<<8) | memL;
}

void EEPROM_memoria_flash_write(void)
{
	unsigned char memH = (memoria_flash >> 8);
	unsigned char memL = (unsigned char) memoria_flash;
	EEPROM_write(FIM_MEMORIA_FLASH, memH);
	EEPROM_write(FIM_MEMORIA_FLASH+1, memL);
}

void EEPROM_init(void)
{
	EEPROM_memoria_eeprom_read();
	EEPROM_memoria_flash_read();
	ENDERECO_ESCRAVO = EEPROM_read(END_ESCRAVO);
}

void EEPROM_IntWrite(unsigned int value)
{
	// if(memoria_eeprom+1>1023) {}
	EEPROM_write(memoria_eeprom, (unsigned char) (value>>8));
	memoria_eeprom++;
	EEPROM_write(memoria_eeprom, (unsigned char) (value));
	memoria_eeprom++;
	EEPROM_memoria_eeprom_write();
}

void EEPROM_CharWrite(unsigned char value)
{
	// if(memoria_eeprom>1023) {}
	EEPROM_write(memoria_eeprom, (unsigned char) value);
	memoria_eeprom++;
	EEPROM_memoria_eeprom_write();
}