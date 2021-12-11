
#ifndef   ADC_PRIVATE_H
#define   ADC_PRIVATE_H

#define   ADMUX    *((volatile u8 *)0x27)
#define   ADCSRA   *((volatile u8 *)0x26)
#define   ADCH     *((volatile u8 *)0x25)
#define   ADCL     *((volatile u8 *)0x24)

#define   ADC      *((volatile u16 *)0x24)

#define   ADC_AVCC            0
#define   ADC_AREF            1
#define   ADC_INTERNAL_2_56   2

#define   ADC_CHANNEL_0       0
#define   ADC_CHANNEL_1       1
#define   ADC_CHANNEL_2       2
#define   ADC_CHANNEL_3       3 
#define   ADC_CHANNEL_4       4
#define   ADC_CHANNEL_5       5
#define   ADC_CHANNEL_6       6
#define   ADC_CHANNEL_7       7


#define  ADC_2                1
#define  ADC_4                2
#define  ADC_8                3
#define  ADC_16               4
#define  ADC_32               5
#define  ADC_64               6
#define  ADC_128              7


#endif