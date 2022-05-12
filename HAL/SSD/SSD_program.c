/**************************************************************************/
/**************************************************************************/
/*******************		AUTHOR:  Ahmed Rafique		*******************/
/*******************		Layer:   HAL				*******************/
/*******************		SWC: 	 SSD				*******************/
/*******************		Version: 1.0.0				*******************/
/**************************************************************************/
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

u8 SSD_u8SetNumber(u8 Number,SSD_t* SSD)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPinDirection((SSD->EnablePort),(SSD->EnablePin),DIO_u8PIN_OUTPUT);

	DIO_u8SetPortDirection(SSD->EnablePort,DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(SSD->PORT,DIO_u8PORT_OUTPUT);
	if(SSD->COM_TYPE == SSD_COMANODE){
		DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_HIGH);
		DIO_u8SetPortValue(SSD->PORT,~Number);
	}
	else if(SSD->COM_TYPE == SSD_COMCATHODE)
	{
		DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_LOW);
		DIO_u8SetPortValue(SSD->PORT,Number);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 SSD_Enable(SSD_t* SSD)
{
	u8 Local_u8ErrorState = 0;
	if(SSD->COM_TYPE == SSD_COMANODE){
		DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_HIGH);

	}
	else if(SSD->COM_TYPE == SSD_COMCATHODE)
	{
		DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 SSD_Disable(SSD_t* SSD)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPortDirection(SSD->PORT,DIO_u8PIN_OUTPUT);
	if(SSD->COM_TYPE == SSD_COMANODE){
		DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_LOW);
	}
	else if(SSD->COM_TYPE == SSD_COMCATHODE)
	{
		DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}
