#define F_CPU 16000000UL
#include	"Std_Types.h"
//#include	"Bit_Math.h"*/

#include	"Dio_interface.h"
#include	"LCD_interface.h"
#include "DIO_private.h"

#include	<util/delay.h>

void	LCD_voidInit8Bit(void)
{
	/*		Delay 35 msec 	*/
	_delay_ms(35);
	/*		Function Set	font = 5*7	, N = 2 Lines of Display	*/
	LCD_voidSendCMD8Bit(0b00111000);
	_delay_ms(1);
	/*		Function Set	D = Display ON	, Cursor Off			*/
	LCD_voidSendCMD8Bit(0b00001100);
	_delay_ms(1);
	/*		Clear Display											*/
	LCD_voidSendCMD8Bit(0b00000001);
	_delay_ms(2);
	/*		Entery Mode	Cursor Increases and shift off	 			*/
	LCD_voidSendCMD8Bit(0b00000110);
	
	
}
void	LCD_voidWriteChar8Bit(u8	Data)
{
	/*				RS = 1 to write Data					*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,HIGH);
	/*				RW = 0 To write							*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
		/*				Send 8 Bit Data							*/
	DIO_voidSetPortValue(LCD_DATA_PORT,Data);
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);	
}
void	LCD_voidSendCMD8Bit(u8	CMD)
{
	/*				RS = 0 to write CMD						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,LOW);
	/*				RW = 0 To write							*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);	
		/*				En = Latch								*/
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
		_delay_ms(5);
		/*				Send 8 Bit CMD							*/
    DIO_voidSetPortValue(LCD_DATA_PORT,CMD);
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);	
}

void    LCD_voidWriteString(u8 *str)
{
	if (str != 0)
	{
		while (*str != '\0')
		{
			LCD_voidWriteChar8Bit(*str);
			str++;
		}
		
	}
}
void LCD_voidGotoXY(u8 line, u8 position)
{
	if (line == 1)
	{
		LCD_voidSendCMD8Bit((0x80+position));
	}
	else if (line == 2)
	{
		LCD_voidSendCMD8Bit((0xC0+position));
	}
}

//4bits


void LCD_voidInit4Bit(void)
{
	LCD_voidSendCMD4Bit(0x33);
	LCD_voidSendCMD4Bit(0x32);
	LCD_voidSendCMD4Bit(0x28);
	LCD_voidSendCMD4Bit(0x0C);
	LCD_voidSendCMD4Bit(0x01);
	LCD_voidSendCMD4Bit(0x06);
	LCD_voidSendCMD4Bit(0x02);
	
}

void	LCD_voidWriteChar4Bit(u8	Data)
{
	u8 Local_Port = DIO_u8GetPortValue( LCD_DATA_PORT);
	u8 Local_Temp = 0;
	/*				RS = 1 to write Data					*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,HIGH);
	/*				RW = 0 To write							*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	/*	 Send 4 Bit Data	MSB (most significant bit D4 : D7)		*/
	Local_Temp = (Data & 0xF0)|(Local_Port & 0X0F);
	DIO_voidSetPortValue(LCD_DATA_PORT,Local_Temp);
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
	
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	/*	 Send 4 Bit Data	LSB (Least significant bit D0 : D3)		*/
	Local_Temp = (Data << 4)|(Local_Port & 0X0F);
	DIO_voidSetPortValue(LCD_DATA_PORT,Local_Temp);
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
}

void	LCD_voidSendCMD4Bit(u8	CMD)
{
	u8 Local_Port = DIO_u8GetPortValue( LCD_DATA_PORT);
	u8 Local_Temp = 0;
	/*				RS = 0 to write CMD						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,LOW);
	/*				RW = 0 To write							*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	/*				Send 4 Bit Data MSB (D4 ; D7)							*/
	Local_Temp=(CMD & 0xF0)|(Local_Port & 0x0F);
	DIO_voidSetPortValue(LCD_DATA_PORT,Local_Temp);
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	/*Send 4 Bit Data LSB (D4 ; D7)							*/
	Local_Temp=(CMD << 4)|(Local_Port & 0x0F);
	DIO_voidSetPortValue(LCD_DATA_PORT,Local_Temp);
	/*				En = Latch								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
}
