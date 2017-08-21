//Author    : BORAY
//Last Edit : BORAY 2017/08/21
#include "M128_ADC.h"

//Internal Definitions
#define cal_msk_sht(source,msk,sht,data) (((source) & (~(msk)))|(((data)<<sht)&(msk)))
#define ADC_ISR_arr_max 20 //Max_function_ADC
#define ADC_number 1 //M128_ADC_num
#define initial {NULL}

//Global variable
char ADC_num[ADC_ISR_arr_max] = {0};
volatile unsigned char ADC_ISR_counter = 0;

void (*ADC_ISR_func[ADC_ISR_arr_max])(void) = initial;

//Function
char M128_ADC_set(char LSByte, char Mask, char Shift, char Data)
{
  switch(LSByte)
  {
    // ADMUX
    case 200:
      ADMUX = cal_msk_sht(ADMUX,Mask,Shift,Data);
      break;
    // ADCSRA
    case 201:
      ADCSRA = cal_msk_sht(ADCSRA,Mask,Shift,Data);
      break;
    // DDRF
    case 202:
      if(DDRF & (~cal_msk_sht(ADMUX,Mask,Shift,Data)))
      {
        DDRF = cal_msk_sht(ADMUX,Mask,Shift,Data);
        return 2;
      }
      DDRF = cal_msk_sht(ADMUX,Mask,Shift,Data);
      break;
    default:
      return 1;
      break;
  }
  return 0;
}

char M128_ADC_get(char LSByte, char Bytes, void *Data_p)
{
  volatile uint8_t *reg[2] = {&ADCL,&ADCH};
  int i;
  if(((LSByte == 100) && (Bytes > 2)) || ((LSByte == 101) && (Bytes > 1)))  //Bytes must not exceeds 2/1 when Read LSByte 100/101
    return 1;
  for(i = 0;i < Bytes; i++)
  {
    *((char*)Data_p + i) = *reg[LSByte-100+i];
  }
  if(((ADMUX & 0x20) && (Bytes != 2)) || ((!(ADMUX & 0x20)) && (Bytes != 1))) // IF ADLAR of ADMUX =1/0, then Bytes maybe 2/1
    return 2;
  return 0;
}

char M128_ADC_fpt(char LSByte,char Mask,char Shift,char Data)
{
  if(LSByte != 201)
    return 1;
  ADCSRA = cal_msk_sht(ADCSRA,Mask,Shift,Data);
  return 0;
}

char M128_ADC_fgt(char LSByte,char Mask,char Shift,char *Data_p)
{
  if(LSByte != 201)
    return 1;
  *Data_p = ((ADCSRA & Mask) >> Shift);
  return 0;
}

char M128_ADC_isr(char Number, void (*function)(void))
{
  if((ADC_ISR_counter >= ADC_ISR_arr_max) || (Number >= ADC_number))
      return 1;
  else
  {
    ADC_ISR_func[ADC_ISR_counter] = function;
    ADC_num [ADC_ISR_counter] = Number;
  }
  ADC_ISR_counter++;

  return 0;
}
//------------------------ADC Interrupt------------------

volatile char i;
ISR(ADC_vect)
{
  for(i = 0;i <= ADC_ISR_counter;i++)
  {
    if((ADC_ISR_func[(int)i]!=0) && (ADC_num[(int)i] == 0))
      ADC_ISR_func[(int)i]();
  }
}
