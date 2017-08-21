#ifndef __M128_ADC_H__
#define __M128_ADC_H__

#include <avr\io.h>
#include <avr\interrupt.h>
#include <stdlib.h>

char M128_ADC_set(char LSByte, char Mask, char Shift, char Data);
char M128_ADC_get(char LSByte, char Bytes, void *Data_p);
char M128_ADC_fpt(char LSByte,char Mask,char Shift,char Data);
char M128_ADC_fgt(char LSByte,char Mask,char Shift,char *Data_p);
char M128_ADC_isr(char Number, void (*function)(void));

#endif
