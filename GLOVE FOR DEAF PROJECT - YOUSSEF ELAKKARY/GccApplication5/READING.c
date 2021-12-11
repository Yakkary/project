#include "Std_Types.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "READING.h"
#include	<util/delay.h>


int u16Conversion_Val;
int u16Analog_Val[5]; 
//u16Analog_Val<1200 ==> flat   0-24%
//2500>u16Analog_Val>1200 ==> half bended  25-49%
//u16Analog_Val>2500  ==> Fully bended  50-100%

void READ_sensor(void)
{
	for (int i = 0 ; i<5 ; i++)
	{
		 ADC_channel(i);
		 u16Conversion_Val = ADC_u16ReadConversion(i);
		 u16Analog_Val[i]=((u16Conversion_Val*5000UL)/1024);
	}
	
	
	//ROCK AND ROLL
	if ((u16Analog_Val[0]>2500)&&(u16Analog_Val[1]<1200)&&(u16Analog_Val[2]>2500)&&(u16Analog_Val[3]>2500)&&(u16Analog_Val[4]<1200))
	{
		LCD_voidSendCMD8Bit(0X80);
		LCD_voidWriteString("Rock And Roll!");
		 LCD_voidSendCMD8Bit(0X01);
		
	}
	
	//I LOVE YOU
	if ((u16Analog_Val[0]<1200)&&(u16Analog_Val[1]<1200)&&(u16Analog_Val[2]>2500)&&(u16Analog_Val[3]>2500)&&(u16Analog_Val[4]<1200))
	{
		LCD_voidSendCMD8Bit(0X85);
		LCD_voidWriteString("I LOVE YOU!");
		 LCD_voidSendCMD8Bit(0X01);
		
	}

    //I REALLY LOVE YOU
	if ((u16Analog_Val[0]<1200)&&(u16Analog_Val[1]<1200)&&(u16Analog_Val[2]<1200)&&(u16Analog_Val[3]>2500)&&(u16Analog_Val[4]<1200))
	{
		LCD_voidSendCMD8Bit(0X80);
		LCD_voidWriteString("I REALLY LOVE");
		LCD_voidSendCMD8Bit(0XC5);
		LCD_voidWriteString(" YOU !");
		 LCD_voidSendCMD8Bit(0X01);
		
	}

    //I AM WATCHING YOU
	if ((u16Analog_Val[0]>2500)&&(u16Analog_Val[1]>1200 & u16Analog_Val[1]<2500)&&(u16Analog_Val[2]>1200 & u16Analog_Val[2]<2500)&&(u16Analog_Val[3]>2500)&&(u16Analog_Val[4]>2500))
	{
		LCD_voidSendCMD8Bit(0X80);
		LCD_voidWriteString("I'M WATCHING YOU !");
		 LCD_voidSendCMD8Bit(0X01);
		
	}	
	
	//HEY YOU!
	if ((u16Analog_Val[0]>2500)&&(u16Analog_Val[1]<1200)&&(u16Analog_Val[2]>2500)&&(u16Analog_Val[3]>2500)&&(u16Analog_Val[4]>2500))
	{
		LCD_voidSendCMD8Bit(0X85);
		LCD_voidWriteString("HEY YOU!");
		LCD_voidSendCMD8Bit(0X01);
	}
		
	//GOOD JOB!
	if ((u16Analog_Val[0]<1200)&&(u16Analog_Val[1]>2500)&&(u16Analog_Val[2]>2500)&&(u16Analog_Val[3]>2500)&&(u16Analog_Val[4]>2500))
	{
		LCD_voidSendCMD8Bit(0X85);
		LCD_voidWriteString("GOOD JOB!");
		 LCD_voidSendCMD8Bit(0X01);
		
	}
	
	 //I WISH YOU A HAPPY LIFE
	 if ((u16Analog_Val[0]<1200)&&(u16Analog_Val[1]<1200)&&(u16Analog_Val[2]<1200)&&(u16Analog_Val[3]<1200)&&(u16Analog_Val[4]<1200))
	 {
		 LCD_voidSendCMD8Bit(0X80);
		 LCD_voidWriteString("I WISH YOU");
		 LCD_voidSendCMD8Bit(0XC0);
		 LCD_voidWriteString("A HAPPY LIFE");
		 LCD_voidSendCMD8Bit(0X01);
		 
		 
	 }
	 
	}
