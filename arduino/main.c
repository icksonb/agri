
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/boot.h>
#include <stdio.h>
#include <string.h>
#include "lib/serial.h"
#include "lib/timers.h"
#include "lib/adc.h"
#include "lib/spi.h"
#include "sdcard/diskio.h"


char ENDERECO_ESCRAVO = 0;


int main(void)
{

	uint8_t ram_buffer[SPM_PAGESIZE];
	unsigned char c;

	Serial_Init(9600);

	DDRB |= (1<<PB5);
	delay_us(2000);
	//Serial_writeFlush(0x01);
	Serial_string("Iniciou...\r\n");

	int i = 0;
	char buffer[50];
	BYTE values[128];
	BYTE values2[128];

	if(!disk_initialize())
	{
		//Serial_string("Dados da flash: \r\n");
		disk_readp(values, (DWORD) 1, 0, 128);
		for(i=0; i<128; i++)
		{
			sprintf(buffer, "%d\r\n", values[i]);
			Serial_string(buffer);
		}

		for(i=0; i<128; i++)
			values2[i] = i;

		/*sprintf(buffer, "Escrita: %d\r\n", ));
		Serial_string(buffer);

		sprintf(buffer, "Escrita: %d\r\n", disk_readp(values, (DWORD) 1, 0, 128));
		Serial_string(buffer);
		*/
		//Serial_string("Dados da flash: \r\n");
		disk_writep(0, (DWORD) 1);
		disk_writep(values2, (DWORD) 128);
		disk_writep(0,0);
		
		disk_readp(values, (DWORD) 1, 0, 128);
		for(i=0; i<128; i++)
		{
			sprintf(buffer, "%d\r\n", values[i]);
			Serial_string(buffer);	
		}

	}
	else
	{
		Serial_string("Erro ao iniciar disco...\r\n");
	}
	delay_ms(100); // wait for sending all text via serial
	

	
	

	/*for (i=0;i<SPM_PAGESIZE;i++) 
	{
		if (i % 2 == 0) 
		{ // we must write WORDs
	    	w = i;
		} 
		else 
		{
	    	w += (ram_buffer[i] << 8);
			optiboot_page_fill((optiboot_addr_t)(void*) i+144,w);
		}
	}
	*/
	Serial_string("Gravado...");

	while(1)
	{
		delay_us(2000);
	}
}