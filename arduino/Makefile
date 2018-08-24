############################# Makefile ##########################
# AUTOR: ICKSON BARBOSA
# TCC - AGRICULTURA
#################################################################

COMPILAR = avr-g++ -g -O3 -mmcu=atmega328p -c 

cleanObj:
	rm -rf *.o

all: clean compilar comp hex gravar

compilar: clean serial timers adc spi avr_mmcp i2c ds1307 comp hex cleanObj

serial:
	$(COMPILAR) lib/serial.c

timers:
	$(COMPILAR) lib/timers.c

adc:
	$(COMPILAR) lib/adc.c

spi:
	$(COMPILAR) lib/spi.c

eeprom:
	$(COMPILAR) lib/eeprom.c

avr_mmcp:
	$(COMPILAR) lib/avr_mmcp.c

i2c:
	$(COMPILAR) lib/i2c.c

ds1307:
	$(COMPILAR) lib/ds1307.c

comp:
	$(COMPILAR) main.c && avr-g++ -g -mmcu=atmega328p -o main.elf *.o

hex:
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

gravar:
	avrdude -p m328p -c arduino -P /dev/ttyUSB0 -b 57600 -U flash:w:main.hex

cleanpart:
	rm -rf *.elf *.hex

clean:
	rm -rf *.o *.elf *.hex

