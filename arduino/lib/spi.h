/*###############################################################
# AUTOR: ICKSON BARBOSA
# BIBLIOTECA SPI
#################################################################*/

#ifndef SPI_H_
#define SPI_H_

#define MOSI PB3
#define MISO PB4
#define SCK PB5

void SPI_Init(char pinCS);
void SPI_disable(void);
void SPI_CSL(char pinCS);
void SPI_CSH(char pinCS);
void SPI_Transmit(char cData);
char SPI_Receive(void);
char SPI_Rcv(void);

#endif