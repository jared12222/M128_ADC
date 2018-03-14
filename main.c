#include ".\Lib\rev_STDIO.h"
#include ".\Lib\M128_ADC.h"
#include <inttypes.h>
#include <util\delay.h>
#include <stdio.h>

volatile uint8_t flag = 0;
volatile unsigned int data = 0;


void INT_test(void)
{
    flag ++;
    M128_ADC_get(100,2,(char*)&data);
}


int main(void) {
  char flag = 0,check;
  //char buff[2];
  unsigned int buff;
  rev_STDIO_set();

  check = M128_ADC_set(200,0xC0,6,0); //Set ADC Ref to AVCC
  check |= M128_ADC_set(200,0x1F,0,0); //Set ADC mux ADC0
  check |= M128_ADC_set(200,0x20,5,0); //Set ADC 10bits
  check |= M128_ADC_set(201,0x07,0,7); //Set ADC prescaler 128
  check |= M128_ADC_set(201,0x20,5,0); //Set Single conversion
  //check |= M128_ADC_set(202,0x0F,0,0); //Set ADC pins as input

  M128_ADC_isr(0,INT_test);
  //check |= M128_ADC_set(201,0x08,3,1); //Enable ADC Interrupt
  check |= M128_ADC_set(201,0x80,7,1); //Enable ADC
  printf("ADMUX : %.2X\r\n",ADMUX);
  printf("ADCSRA: %.2X\r\n",ADCSRA);
  if(check)
    printf("Debug point <3> check:%d\r\n",check);
  //sei();
  /*
  ADMUX=(1<<REFS0);
  ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
  ADMUX = 0b01000000;
  ADCSRA = 0b10000111;
  DDRF = 0x00;
  */
  printf("Set completed, Start!\r\n");
  while (1)
  {
    //-------------------------Check ADC interrupt
    //
    // check = M128_ADC_fpt(201,0x40,6,1); // Start conversion
    //
    // while(!flag);
    // printf("Success!\n");
    // printf("Result:%d %d\n",flag,data);

    //-------------------------Read after flag set to one

    check = M128_ADC_fpt(201,0x40,6,1); // Start conversion

    while(!flag)
    {
      check = M128_ADC_fgt(201,0x10,4,&flag);   // check ADC Interrupt flag
      if(check)
        printf("Debug point <1> check:%d\n",check);
    }
    //check = M128_ADC_get(100,2,buff);  //uint8_t buff[2]
    check = M128_ADC_get(100,2,&buff);   //unsigned int
    check = M128_ADC_fpt(201,0x10,4,1);   // Clear ADC Interrupt Flag
    if(check)
        printf("Debug point <2> check:%d\n",check);
    //printf("Re:%.1X%.2X\r",buff[1],buff[0]);  //uint8_t buff[2]
    printf("Re:%.3X\r",buff);    // unsigned int

    //----------------------------- Direct Register
    // ADCSRA = (((ADCSRA) & (~(0x40)))|(((1)<<6)&(0x40)));
    // ADCSRA |= (1<<ADSC);
    // while(!flag){
    //     flag = ((ADCSRA & 0x10) >> 4);
    //     if(check)
    //          printf("Debug point <1> check:%d\n",check);
    // }
    // //while(!(ADCSRA & (1<<ADIF)));
    //
    // printf("%.3X\r",ADC);
    // ADCSRA |= (1<<ADSC);
  }
}
