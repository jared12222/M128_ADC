/*===============ASA Series Library===============*/

/*****ReleaseDate*****/
//2018/--/--

/*****Feature*****/

/*===Supported Module===*/
//ASA M128
//ASA 7S00
//ASA ACC00
//ASA ADC00
//ASA DAC00
//ASA DIO00
//ASA GR00
//ASA JS00
//ASA KB00
//ASA PWM00
//ASA PWM01
//ASA RF00
//ASA RTC00
//ASA SDC00
//ASA STP00
//ASA THM00
//ASA THM01


/*================================================*/

#ifndef __ASA_H__
#define __ASA_H__

#include <avr\io.h>
#include <avr\interrupt.h>
#include <stdio.h>
#include <util\delay.h>

#define M128_AllINT_enable sei()
#define M128_AllINT_disable cli()

/**M128**/
char ASA_M128_set(void);
char DIO_fpt(char LSByte, char Mask, char shift, char Data);
char DIO_fgt(char LSByte, char Mask, char shift, char *Data_p);
char ISR_reg(char IRQ,void (*Fun_p)(void));
char TIM_set(char LSByte, char Mask, char Shift, char Data);
char EXT_set(char LSByte, char Mask, char Shift, char Data);
char HMI_Transceiver_put(char Bytes, void *Data_p);
char HMI_Transceiver_get(char Bytes, void *Data_p);
char HMI_Structure_put(char *FormatString, char Bytes, void *Data_p);
char HMI_Structure_get(char *FormatString, char Bytes, void *Data_p);


char M128_AComp_set(char LSByte, char Mask, char Shift, char Data);
char M128_AComp_fpt(char LSByte, char Mask, char Shift, char Data);
char M128_AComp_fgt(char LSByte, char Mask, char Shift, void *Data_p);
char M128_Acomp_isr(char Number, void (*function)(void));

char M128_ADC_set(char LSByte, char Mask, char Shift, char Data);
char M128_ADC_get(char LSByte, char Bytes, void *Data_p);
char M128_ADC_fpt(char LSByte,char Mask,char Shift,char Data);
char M128_ADC_fgt(char LSByte,char Mask,char Shift,char *Data_p);
char M128_ADC_isr(char Number, void (*function)(void));

char M128_DIO_set(char LSByte, char Mask, char Shift, char Data);
char M128_DIO_put(char LSByte, char Bytes, void *Data_p);
char M128_DIO_get(char LSByte, char Bytes, void *Data_p);
char M128_DIO_fpt(char LSByte, char Mask, char Shift, char Data);
char M128_DIO_fgt(char LSByte, char Mask, char Shift, void *Data_p);

char M128_EXT_set(char LSByte, char Mask, char Shift, char Data);
char M128_EXT_fpt(char LSByte, char Mask, char Shift, char Data);
char M128_EXT_fgt(char LSByte, char Mask, char Shift, void *Data_p);
char M128_EXT_isr(char Number, void (*function)(void));

char M128_HMI_set(char LSBytes, char Mask, char shift, char Data);
char M128_HMI_put(char Bytes, char Type, void *Data_p);
char M128_HMI_get(char Bytes, void *Data_p);
char M128_HMI_Form_put(char *FormatString, char Bytes, void *Data_p);
char M128_HMI_Form_get(char *FormatString, char Bytes, void *Data_p);

char M128_PWM_set(char LSByte, char Mask, char Shift, char Data);
char M128_PWM_fpt( char LSByte, char Mask,  char Shift, char Data);
char M128_PWM_put(char LSByte, char Bytes, void *Data_p);
char M128_PWM_fgt( char LSByte, char Mask,  char Shift, void *Data_p);
char M128_PWM_isr(char number,char cycle,char phase, void (*function)(void));

char M128_SPI_set(char LSByte,char Mask,char Shift,char Data);
char M128_SPI_put(char LSByte,char Bytes,char *Data_p);
char M128_SPI_get(char LSByte,char Bytes,char *Data_p);
char M128_SPI_fpt(char LSByte,char Mask,char Shift,char Data);
char M128_SPI_fgt(char LSByte,char Mask,char Shift,char *Data_p);
char M128_SPI_swap(char Data);
char M128_SPI_trm(char OneReg,char RegAdd,char Bytes,void *Data_p);
char M128_SPI_rec(char OneReg,char RegAdd,char Bytes,void *Data_p);
char M128_SPI_frc(char OneReg,char RegAdd,char Mask,char Shift,char *Data_p);
char M128_SPI_ftm(char OneReg,char RegAdd,char Mask,char Shift,char *Data_p);

char M128_TIM_set(char Lsbyte, char Mask, char Shift, char Data);
char M128_TIM_put(char LSbyte, char Bytes, void *Data_p);
char M128_TIM_get(char LSByte, char Bytes, void *Data_p);
char M128_TIM_fpt(char Lsbyte, char Mask, char Shift, char Data);
char M128_TIM_isr(char Number,char Cycle,char Phase, void (*function)(void));
char M128_TIM_isr_remove(char Number,  void (*function)(void));

char M128_TWI_set(char LSByte, char Mask,  char shift,char Data);
char M128_TWI_put(char LSByte, char Bytes, char *Data_p);
char M128_TWI_get(char LSByte, char Bytes, char *Data_p);
char M128_TWI_fpt( char LSByte, char Mask,  char shift, char Data);
char M128_TWI_fgt( char LSByte, char Mask,  char shift,  char *Data_p);
char M128_TWIM_trm(char OneReg, char TWIID, char RegAdd, char Bytes, void *Data_p);
char M128_TWIM_rec(char OneReg, char TWIID, char RegAdd, char Bytes, void *Data_p);
char M128_TWIM_ftm(char SLA,char OneReg, char RegAdd, char Mask, char shift, void *Data_p);
char M128_TWIM_frc(char SLA,char OneReg, char RegAdd, char Mask, char shift, char *Data_p);

char M128_UART_set( char LSbyte, char Mask, char Shift, void* Data_p);
char M128_UART_put( char LSbyte, char Bytes, void *Data_p);
char M128_UART_get( char LSbyte, char Bytes, void *Data_p);
char M128_UARTM_trm(char OneSLA, char OneReg, char UARTID, char RegAdd, char Bytes, void *Data_p);
char M128_UARTM_rec(char OneSLA, char OneReg, char UARTID, char RegAdd, char Bytes, void *Data_p);
char M128_UARTM_ftm(char OneSLA, char OneReg, char UARTID, char RegAdd, char Mask,  char shift, char* Data_p);
char M128_UARTM_frc(char OneSLA, char OneReg, char UARTID, char RegAdd, char Mask,  char shift, char* Data_p);

/**7S00**/
char ASA_7S00_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_7S00_put(char ASA_ID, char LSByte, char Bytes, void *Data_p);
char ASA_7S00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**ACC00**/
char ASA_ACC00_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_ACC00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**ADC00**/
char ASA_ADC00_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_ADC00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);
 
/**DAC00**/
char ASA_DAC00_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_DAC00_put(char ASA_ID, char LSByte, char Bytes, void *Data_p);
char ASA_DAC00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**DIO00**/
char ASA_DIO00_put(char ASA_ID, char LSByte, char Bytes, void* Data_p);
char ASA_DIO00_get(char ASA_ID, char LSByte, char Bytes, void* Data_p);
char ASA_DIO00_fpt(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_DIO00_fgt(char ASA_ID, char LSByte, char Mask, char shift, void *Data_p);

/**GR00**/
char ASA_GR00_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_GR00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**JS00**/
char ASA_JS00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**KB00**/
char ASA_KB00_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_KB00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**PWM00**/
char ASA_PWM00_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_PWM00_put(char ASA_ID, char LSByte, char Bytes, void *Data_p);
char ASA_PWM00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**PWM01**/
char ASA_PWM01_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_PWM01_put(char ASA_ID, char LSByte, char Bytes, void *Data_p);
char ASA_PWM01_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**RF00**/
char ASA_RF00_put(char ASA_ID,char LSByte,char Bytes,void *Data_p);
char ASA_RF00_get(char ASA_ID,char LSByte,char Bytes,void *Data_p);

/**RTC00**/
char ASA_RTC00_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_RTC00_put(char ASA_ID, char LSByte, char Bytes, void *Data_p);
char ASA_RTC00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**SDC00**/
char ASA_SDC00_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_SDC00_put(char ASA_ID, char LSByte, char Bytes, void *Data_p);
char ASA_SDC00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**STP00**/
char ASA_STP00_put(char ASA_ID, char LSByte,char Bytes,void  *Data_p);

/**THM00**/
char ASA_THM00_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_THM00_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

/**THM01**/
char ASA_THM01_set(char ASA_ID, char LSByte, char Mask, char shift, char Data);
char ASA_THM01_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

#endif
