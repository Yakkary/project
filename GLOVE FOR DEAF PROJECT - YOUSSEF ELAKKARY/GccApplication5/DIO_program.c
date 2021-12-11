/*					Library Includes					*/
#include	"Std_Types.h"
#include	"Bit_Math.h"
/*					MCAL    Includes					*/
#include	"DIO_interface.h"
#include	"DIO_private.h"


/*					FOR ONE PIN										*/
/*			Determine Direction for one pin	(in/out)				*/
/*			DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);				*/
void	DIO_voidSetPinDirection(u8 PORTID , u8 PINID , u8 Direction)
{
	/*				Range Check										*/
	if( ( PORTID < 4 ) && ( PINID < 8 ) )
	{
		if( Direction == OUTPUT )
		{
			switch(PORTID)
			{
				case	PORTA	:	SET_BIT(DDRA_REG,PINID);	break;
				case	PORTB	:	SET_BIT(DDRB_REG,PINID);	break;
				case	PORTC	:	SET_BIT(DDRC_REG,PINID);	break;
				case	PORTD	:	SET_BIT(DDRD_REG,PINID);	break;
			}
		}
		else if(Direction == INPUT)
		{
			switch(PORTID)
			{
				case	PORTA	:	CLR_BIT(DDRA_REG,PINID);	break;
				case	PORTB	:	CLR_BIT(DDRB_REG,PINID);	break;
				case	PORTC	:	CLR_BIT(DDRC_REG,PINID);	break;
				case	PORTD	:	CLR_BIT(DDRD_REG,PINID);	break;
			}			
		}
		else{	/*		Do Nothing		*/	}
	}
	else{	/*		Do Nothing		*/	}
}

/*			Determine (Output) High or Low for one pin	(1/0)		*/
/*			DIO_voidSetPinValue(PORTC,PIN7,HIGH);					*/
void	DIO_voidSetPinValue(u8 PORTID , u8 PINID , u8 Value)
{
	/*				Range Check										*/
	if( ( PORTID < 4 ) && ( PINID < 8 ) )
	{
		if( Value == HIGH )
		{
			switch(PORTID)
			{
				case	PORTA	:	SET_BIT(PORTA_REG,PINID);	break;
				case	PORTB	:	SET_BIT(PORTB_REG,PINID);	break;
				case	PORTC	:	SET_BIT(PORTC_REG,PINID);	break;
				case	PORTD	:	SET_BIT(PORTD_REG,PINID);	break;
			}
		}
		else if(Value == LOW)
		{
			switch(PORTID)
			{
				case	PORTA	:	CLR_BIT(PORTA_REG,PINID);	break;
				case	PORTB	:	CLR_BIT(PORTB_REG,PINID);	break;
				case	PORTC	:	CLR_BIT(PORTC_REG,PINID);	break;
				case	PORTD	:	CLR_BIT(PORTD_REG,PINID);	break;
			}			
		}
		else{	/*		Do Nothing		*/	}
	}
	else{	/*		Do Nothing		*/	}	
}

/*			Determine (Input) High or Low for one pin	(1/0)		*/
u8		DIO_u8GetPinValue(u8 PORTID , u8 PINID)
{
	u8 Local_Val = 0xFF;
/*				Range Check										*/
	if( ( PORTID < 4 ) && ( PINID < 8 ) )
	{	
			switch(PORTID)
			{
				case	PORTA	:	Local_Val	=	GET_BIT(PINA_REG,PINID);	break;
				case	PORTB	:	Local_Val	=	GET_BIT(PINB_REG,PINID);	break;
				case	PORTC	:	Local_Val	=	GET_BIT(PINC_REG,PINID);	break;
				case	PORTD	:	Local_Val	=	GET_BIT(PIND_REG,PINID);	break;
			}	
	}
	else{	/*		Do Nothing		*/	}	
	return Local_Val;
}

u8 DIO_u8GetPortValue(u8 PORTID)
{
	u8 Local_Val = 0xFF;
	/*				Range Check										*/
	if(  PORTID < 4  )
	{
		switch(PORTID)
		{
			case	PORTA	:  Local_Val  =	PORTA_REG;		break;
			case	PORTB	:  Local_Val  = PORTB_REG;		break;
			case	PORTC	:  Local_Val  = PORTC_REG;		break;
			case	PORTD	:  Local_Val  = PORTD_REG;		break;
		}
	}
	
	else{	/*		Do Nothing		*/	}
	return Local_Val;
}


/*					FOR ONE PORT(8 pins)								*/
/*			Determine Direction for one port(8 PINS)	(in/out)		*/
/*			DIO_voidSetPortDirection(PORTA , 8)		0b0000 1000;		*/
/*			DIO_voidSetPortDirection(PORTB , 0x0F)		0b0000 1111;	*/
/*			DIO_voidSetPortDirection(PORTB , OUTPUT)		0b1111 1111;*/
void	DIO_voidSetPortDirection(u8 PORTID , u8 Direction)
{
	/*				Range Check										*/
	if(  PORTID < 4  )
	{
		if( Direction == OUTPUT )
		{
			switch(PORTID)
			{
				case	PORTA	:	DDRA_REG	=	0xFF;	break;
				case	PORTB	:	DDRB_REG	=	0xFF;	break;
				case	PORTC	:	DDRC_REG	=	0xFF;	break;
				case	PORTD	:	DDRD_REG	=	0xFF;	break;
			}
		}
		else if(Direction == INPUT)
		{
			switch(PORTID)
			{
				case	PORTA	:	DDRA_REG	=	0x00;	break;
				case	PORTB	:	DDRB_REG	=	0x00;	break;
				case	PORTC	:	DDRC_REG	=	0x00;	break;
				case	PORTD	:	DDRD_REG	=	0x00;	break;
			}			
		}
		else
		{
			switch(PORTID)
			{
				case	PORTA	:	DDRA_REG	=	Direction;	break;
				case	PORTB	:	DDRB_REG	=	Direction;	break;
				case	PORTC	:	DDRC_REG	=	Direction;	break;
				case	PORTD	:	DDRD_REG	=	Direction;	break;
			}				
		}
	}
	else{	/*		Do Nothing		*/	}
	
}
/*			Determine (Output) High or Low for one PORT(8 PINS)	(1/0)*/
void	DIO_voidSetPortValue(u8 PORTID , u8 Value)
{
	/*				Range Check										*/
	if(  PORTID < 4  )
	{
		if( Value == HIGH )
		{
			switch(PORTID)
			{
				case	PORTA	:	PORTA_REG	=	0xFF;	break;
				case	PORTB	:	PORTB_REG	=	0xFF;	break;
				case	PORTC	:	PORTC_REG	=	0xFF;	break;
				case	PORTD	:	PORTD_REG	=	0xFF;	break;
			}
		}
		else if(Value == LOW)
		{
			switch(PORTID)
			{
				case	PORTA	:	PORTA_REG	=	0x00;	break;
				case	PORTB	:	PORTB_REG	=	0x00;	break;
				case	PORTC	:	PORTC_REG	=	0x00;	break;
				case	PORTD	:	PORTD_REG	=	0x00;	break;
			}			
		}
		else
		{
			switch(PORTID)
			{
				case	PORTA	:	PORTA_REG	=	Value;	break;
				case	PORTB	:	PORTB_REG	=	Value;	break;
				case	PORTC	:	PORTC_REG	=	Value;	break;
				case	PORTD	:	PORTD_REG	=	Value;	break;
			}				
		}
	}
	else{	/*		Do Nothing		*/	}	
}

//map library
long map(long Q, long in_min, long in_max, long out_min, long out_max)
 {
	return (Q - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}