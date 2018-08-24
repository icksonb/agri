/*###############################################################
# AUTOR: ICKSON BARBOSA
# BIBLIOTECA DS1307
#################################################################*/

#ifndef I2C_H_
#define I2C_H_

#define DS1307_WRITE 0b11010000
#define DS1307_READ  0b11010001

#define SECONDS 0x00

void DS1307_init(void);
unsigned char DS1307_getSeconds(void);

#endif