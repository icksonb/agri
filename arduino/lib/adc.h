/*###############################################################
# AUTOR: ICKSON BARBOSA
# BIBLIOTECA ADC
#################################################################*/

#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include "timers.h"

void ADC_Enable(void);
void ADC_Disable(void);
unsigned int ADC_Read(char pin);
char ADC_Porcentagem(char pin);

#endif