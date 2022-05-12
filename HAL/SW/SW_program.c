/**************************************************************************/
/**************************************************************************/
/*******************		AUTHOR:  Ahmed Rafique		*******************/
/*******************		Layer:   HAL				*******************/
/*******************		SWC: 	 SW 				*******************/
/*******************		Version: 1.0.0				*******************/
/**************************************************************************/
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SW_interface.h"
#include <util/delay.h>

u8 SW_u8GetState(u8 Copy_u8Port,u8 Copy_u8Pin,u8 SelfLockingType,u8 PullType)
{
	u8 Local_u8ErrorState = 0;
	u8 SW_Pressed = 0;
	DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);
	if(SelfLockingType == SW_Temporary)
	{
		u8 Temp1 = 0;
		u8 Temp2 = 0;
		DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Temp1);
		_delay_ms(100);
		DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Temp2);
		if(Temp1 == Temp2)
		{
			SW_Pressed = 1;
			return SW_Pressed;
		}
		else
		{
			SW_Pressed = 0;
			return SW_Pressed;
		}

	}
	else if(SelfLockingType == SW_Permanent)
	{
		DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&SW_Pressed);
		return SW_Pressed;
	}
	else
	{
		Local_u8ErrorState = 1;
		return Local_u8ErrorState;
	}

}
