/*###############################################################
# AUTOR: ICKSON BARBOSA
# BIBLIOTECA SERIAL
#################################################################*/

#ifndef TIMERS_H_
#define TIMERS_H_

#ifndef F_CPU
#define F_CPU 16000000
#endif

void Timer1_Init(char type, int prescaler);
void Timer1_Disable(void);
void delay_ms(unsigned int tempo);

#endif 