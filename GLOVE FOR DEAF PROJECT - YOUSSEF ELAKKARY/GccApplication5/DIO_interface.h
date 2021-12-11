#ifndef				DIO_INTERFACE_H
#define				DIO_INTERFACE_H

/*					FOR ONE PIN										*/
/*			Determine Direction for one pin	(in/out)				*/
void	DIO_voidSetPinDirection(u8 PORTID , u8 PINID , u8 Direction);

/*			Determine (Output) High or Low for one pin	(1/0)		*/
void	DIO_voidSetPinValue(u8 PORTID , u8 PINID , u8 Value);

/*			Determine (Input) High or Low for one pin	(1/0)		*/
u8		DIO_u8GetPinValue(u8 PORTID , u8 PINID);

/*					FOR ONE PORT(8 pins)							*/
/*			Determine Direction for one port(8 PINS)	(in/out)	*/
void	DIO_voidSetPortDirection(u8 PORTID , u8 Direction);

/*			Determine (Output) High or Low for one PORT(8 PINS)	(1/0)*/
void	DIO_voidSetPortValue(u8 PORTID , u8 Value);

/*			Determine (Input) High or Low for one port	(1/0)		*/
u8      DIO_u8GetPortValue(u8 PORTID);

#define				PORTA			0
#define				PORTB			1
#define				PORTC			2
#define				PORTD			3

#define				PIN0			0
#define				PIN1			1
#define				PIN2			2
#define				PIN3			3
#define				PIN4			4
#define				PIN5			5
#define				PIN6			6
#define				PIN7			7

#define				INPUT			0
#define				OUTPUT			1

#define				LOW				0
#define				HIGH			1

#ifndef NULL
#define NULL ((char *)0)
#endif

#endif