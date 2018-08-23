/*###############################################################
# AUTOR: ICKSON BARBOSA
# BIBLIOTECA SERIAL
#################################################################*/

#ifndef SERIAL_H_
#define SERIAL_H_

void Serial_Init(unsigned int baud);
void Serial_write(unsigned char data);
void Serial_writeFlush(unsigned char data);
unsigned char Serial_read(void);
void Serial_string(char s[]);

#endif 