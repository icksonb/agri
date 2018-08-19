############################# Makefile ##########################
# AUTOR: ICKSON BARBOSA
# TCC - AGRICULTURA
#################################################################

COMPILAR = avr-g++ -g -Os -mmcu=atmega328p -c 

all: clean compilar comp hex gravar

compilar: clean serial timers adc comp hex

serial:
	$(COMPILAR) serial.c

timers:
	$(COMPILAR) timers.c

adc:
	$(COMPILAR) adc.c

comp:
	$(COMPILAR) main.c && avr-g++ -g -mmcu=atmega328p -o main.elf serial.o timers.o adc.o main.o

hex:
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

gravar:
	avrdude -p m328p -c arduino -P /dev/ttyUSB0 -b 57600 -U flash:w:main.hex

cleanpart:
	rm -rf *.elf *.hex

clean:
	rm -rf *.o *.elf *.hex