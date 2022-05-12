/**************************************************************************/
/**************************************************************************/
/*******************		AUTHOR:  Ahmed Rafique		*******************/
/*******************		Layer:   HAL				*******************/
/*******************		SWC: 	 LED				*******************/
/*******************		Version: 1.0.0				*******************/
/**************************************************************************/
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_interface.h"

u8 LED_u8TurnOn(u8 Copy_u8Port,u8 Copy_u8Pin,u8 ConnType)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_OUTPUT);
	if(ConnType == LED_SINK)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);
	}
	else if(ConnType== LED_SOURCE)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 LED_u8TurnOff(u8 Copy_u8Port,u8 Copy_u8Pin,u8 ConnType)
{
	DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_OUTPUT);
	u8 Local_u8ErrorState = 0;
	if(ConnType == LED_SINK)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);
	}
	else if(ConnType== LED_SOURCE)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}
