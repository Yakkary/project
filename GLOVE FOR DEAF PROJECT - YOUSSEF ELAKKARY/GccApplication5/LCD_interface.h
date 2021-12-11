#ifndef			LCD_INTERFACE_H
#define			LCD_INTERFACE_H

#define			LCD_CONTROL_PORT			PORTC
#define			LCD_RS						PIN0
#define			LCD_RW						PIN1
#define			LCD_EN						PIN2

#define			LCD_DATA_PORT				PORTD

//8bits
void	LCD_voidInit8Bit(void);
void	LCD_voidWriteChar8Bit(u8	Data);
void	LCD_voidSendCMD8Bit(u8	CMD);

//4bits 
void	LCD_voidInit4Bit(void);
void	LCD_voidWriteChar4Bit(u8	Data);
void	LCD_voidSendCMD4Bit(u8	CMD);

void    LCD_voidWriteString(u8 *str);
void    LCD_voidGotoXY(u8 line,u8 position);

#endif