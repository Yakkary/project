/*
 * GccApplication5.c
 *
 * Created: 12/11/2021 2:55:15 PM
 * Author : Youssef El Akkary 
 */ 

#include <avr/io.h>
#include "Std_Types.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "LCD_interface.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "READING.h"
#include	<util/delay.h>





int main(void)
{
	  ADC_voidinit();
	ADC_voidEnable();
	ADC_u16ReadConversion(1);
DIO_voidSetPortDirection(PORTD,OUTPUT);
DIO_voidSetPortDirection(PORTC,OUTPUT);
DIO_voidSetPortDirection(PORTA,INPUT);

	LCD_voidInit8Bit();
	
  
    while (1) 
    {
			
			READ_sensor();
			 
			
    }
	
}

