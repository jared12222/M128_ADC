#include "ASA_Lib.h"
//#include <avr/eeprom.h>


void adc_ini(void) {

    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
    //DIDR0=1<<ADC0D;
    printf("\nini_done\n");
}

char adc_read(void) {

uint8_t    channel=channel&0x00;
    ADMUX|=channel;
    ADCSRA |= (1<<ADSC);
    while(!(ADCSRA & (1<<ADIF))) printf("---2\n");
    //printf("%d\n",ADC);
    return ADC;
}




int main (void) {

        ASA_M128_set();
        adc_ini();
        uint16_t  data=0;


        while(1) {
                data=adc_read();
                //printf("---1\n");
                //printf("data=%d\n",data[0]+data[1]);
                printf("data=%d\n",data);

        }
}
