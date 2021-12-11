#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "DIO_private.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"

void ADC_voidinit()
{
	//VRef selection
#if  ADC_V_REF ==  ADC_AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif  ADC_V_REF ==  ADC_AREF
	CLR_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif  ADC_V_REF ==  ADC_INTERNAL_2_56
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#else
    #error "Wrong Choice Of ADC Voltage Reference"
	
#endif

	
	//ADC Channel selection
	#if    ADC_CHANNEL ==  ADC_CHANNEL_0
	CLR_BIT(ADC,0);
	CLR_BIT(ADC,1);
	CLR_BIT(ADC,2);
	CLR_BIT(ADC,3);
	CLR_BIT(ADC,4);
	#elif  ADC_CHANNEL ==  ADC_CHANNEL_1
	SET_BIT(ADC,0);
	CLR_BIT(ADC,1);
	CLR_BIT(ADC,2);
	CLR_BIT(ADC,3);
	CLR_BIT(ADC,4);
	#elif  ADC_CHANNEL ==  ADC_CHANNEL_2
	CLR_BIT(ADMUX,0);
	SET_BIT(ADMUX,1);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);
	#elif  ADC_CHANNEL ==  ADC_CHANNEL_3
	SET_BIT(ADMUX,0);
	SET_BIT(ADMUX,1);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);
	#elif  ADC_CHANNEL ==  ADC_CHANNEL_4
	CLR_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	SET_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);
	#elif  ADC_CHANNEL ==  ADC_CHANNEL_5
	SET_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	SET_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);
	#elif  ADC_CHANNEL ==  ADC_CHANNEL_6
	CLR_BIT(ADMUX,0);
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);
	#elif  ADC_CHANNEL ==  ADC_CHANNEL_7
	SET_BIT(ADMUX,0);
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);
	
	
	#else
	{
		#error "Wrong Choice Of ADC CHANNEL"
	}
	
	#endif
	

	
	/*Pre-Scaller Selection*/
		
#if  ADC_PRE_SCALLER ==  ADC_2
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif ADC_PRE_SCALLER ==  ADC_4
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif ADC_PRE_SCALLER ==  ADC_8
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif ADC_PRE_SCALLER ==  ADC_16
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif ADC_PRE_SCALLER ==  ADC_32
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif ADC_PRE_SCALLER ==  ADC_64
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif ADC_PRE_SCALLER ==  ADC_128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#else
	#error "Wrong Choice Of Prescaller"
		
#endif
	
	
}

u16 ADC_u16ReadConversion(u8 ChannelID)
{

// 1- start single conversion
  SET_BIT(ADCSRA,6);
  
  // 2- polling (wait till the event happens)
  while ((GET_BIT(ADCSRA,4)) == 0);	
  {
	  
  }
  
  //3- clear the conversion flag
SET_BIT(ADCSRA,4);

//4- READ THE CONVERSION VALUES 10BITS
return ADC;
}

void ADC_channel(int _channel){
	ADMUX = 0x00;
	ADMUX |= _channel;
}


int ADC_read() {
	while(!(ADCSRA & (1<<ADIF)));
	int data = ADCL;
	data |= (ADCH<<8);
	return data;
}


void  ADC_voidEnable(void)
{
	SET_BIT(ADCSRA,7);	
}

void  ADC_voidDisable(void)
{
	CLR_BIT(ADCSRA,7);
}