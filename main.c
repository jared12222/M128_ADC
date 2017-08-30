#include "ASA_Lib.h"
#include ".\Lib\M128_ADC.h"

int main(int argc, char const *argv[]) {
  char flag = 0,check;
  unsigned int buff;
  ASA_M128_set();
  check = M128_ADC_set(200,0xC0,6,3); //Set ADC internal 2.56V reference
  check |= M128_ADC_set(200,0x1F,0,0x1F); //Set ADC mux GND
  check |= M128_ADC_set(200,0x20,5,0); //Set ADC 10bits
  check |= M128_ADC_set(201,0x07,0,6); //Set ADC prescaler 64
  check |= M128_ADC_set(201,0x20,5,0); //Set Single conversion
  check |= M128_ADC_set(202,0x0F,0,0); //Set ADC pins as input
  check |= M128_ADC_set(201,0x80,7,1); //Enable ADC
  if(check)
    printf("check:%d\n",check);
  printf("Set completed, Start!\n");
  while (1)
  {
    check = M128_ADC_fpt(201,0x40,6,1); // Start conversion
    printf("Start Convert\n");
    if(check)
      printf("check:%d\n",check);
    while(!flag)
    {
      check = M128_ADC_fgt(201,0x10,4,&flag);
      if(check)
        printf("check:%d\n",check);
    }
    check = M128_ADC_get(100,2,&buff);
    if(check)
      printf("check:%d\n",check);
    printf("Re:%X\n",buff);
  }
}
