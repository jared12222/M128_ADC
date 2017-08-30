#ifndef __M128_ADC_H__
#define __M128_ADC_H__

#include <avr\io.h>
#include <avr\interrupt.h>
#include <stdlib.h>

/**
    \ingroup M128_ADC
    set M128 ADC register
*/
char M128_ADC_set(char LSByte, char Mask, char Shift, char Data);
/**
    \ingroup M128_ADC
    get M128 ADC result
*/
char M128_ADC_get(char LSByte, char Bytes, void *Data_p);
/**
    \ingroup M128_ADC
    put M128 ADC flag
*/
char M128_ADC_fpt(char LSByte,char Mask,char Shift,char Data);
/**
    \ingroup M128_ADC
    get M128 ADC result
*/
char M128_ADC_fgt(char LSByte,char Mask,char Shift,char *Data_p);
/**
    \ingroup M128_ADC
    register function into ADC interrupt
*/
char M128_ADC_isr(char Number, void (*function)(void));

#endif
