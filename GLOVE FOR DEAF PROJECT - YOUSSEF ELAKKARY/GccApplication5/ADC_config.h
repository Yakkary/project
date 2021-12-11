#ifndef   ADC_CONFIG_H
#define   ADC_CONFIG_H

/*THE ADC channel can be:     
1- ADV_AVCC
2- ADC_AREF
3-ADC_INTERNAL_2_56
*/
#define   ADC_V_REF    ADC_AVCC

/*THE ADC channel can be:
1- ADC_CHANNEL_0
2- ADC_CHANNEL_1
3- ADC_CHANNEL_2
4- ADC_CHANNEL_3
5- ADC_CHANNEL_4
6- ADC_CHANNEL_5
7- ADC_CHANNEL_6
8- ADC_CHANNEL_7
*/
//#define   ADC_CHANNEL     ADC_CHANNEL_1

/*THE ADC Prescaller can be:
1- ADC_2
2- ADC_4
3- ADC_8
4- ADC_16
5- ADC_32
6- ADC_64
7- ADC_128
*/
#define   ADC_PRE_SCALLER     ADC_128

#define   ADC_ADCSRA   *((volatile u8 *)0x26)
#define   ADC_ADCL     *((volatile u8 *)0x25)
#define   ADC_ADCH     *((volatile u8 *)0x24)

#endif