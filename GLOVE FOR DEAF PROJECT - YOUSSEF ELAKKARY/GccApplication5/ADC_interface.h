#ifndef   ADC_INTERFACE_H
#define   ADC_INTERFACE_H

void ADC_voidinit(void);
u16 ADC_u16ReadConversion(u8 ChannelID);
void  ADC_voidEnable(void);
void  ADC_voidDisable(void);

#define   ADC_CHANNEL_0       0
#define   ADC_CHANNEL_1       1
#define   ADC_CHANNEL_2       2
#define   ADC_CHANNEL_3       3
#define   ADC_CHANNEL_4       4
#define   ADC_CHANNEL_5       5
#define   ADC_CHANNEL_6       6
#define   ADC_CHANNEL_7       7


//* ADCSRA */
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0



#endif