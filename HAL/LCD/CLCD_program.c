/**************************************************************************/
/**************************************************************************/
/*******************		AUTHOR:  Ahmed Rafique		*******************/
/*******************		Layer:   HAL				*******************/
/*******************		SWC: 	 CLCD				*******************/
/*******************		Version: 1.0.0				*******************/
/**************************************************************************/
/**************************************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include <util/delay.h>

void CLCD_u8SendCommand(u8 Copy_u8Command)
{
	/*RS = 0 -> Command Signal*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);
	/*RW = 0 -> write Signal*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	/*Set Control to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);
	/*Set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
}
void CLCD_u8SendData(u8 Copy_u8Data)
{
	/*RS = 1 -> Data Signal*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);
	/*RW = 0 -> write Signal*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	/*Set Data to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);
	/*Set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
}
void CLCD_VoidInit(void)
{
	/*Wait for more than 30ms*/
	_delay_ms(40);
	/*Function set command: 2 lines, 5*8 Font size*/
	CLCD_u8SendCommand(0b00111000);
	/*Display on off control: display enable, no cursor, no blink cursor*/
	CLCD_u8SendCommand(0b00001100);
	/*Clear Display*/
	CLCD_u8SendCommand(1);
}
void CLCD_u8SendString(const char* Copy_pcString)
{
	u8 i = 0;
	while(Copy_pcString[i] != '\0')
	{
		CLCD_u8SendData(Copy_pcString[i]);
		i++;
	}
}
void CLCD_u8GoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos == 0)
	{
		/*Location is at first line*/
		Local_u8Address = Copy_u8YPos;
	}
	else if(Copy_u8XPos == 1)
	{
		/*Location is at second line*/
		Local_u8Address = Copy_u8YPos + 0x40;
	}
	/*Set bit no. 7 for Set DDRAM Address command then send the command*/
	CLCD_u8SendCommand(Local_u8Address + 128);
}
void CLCD_u8WriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 i;
	/*Calculate the CGRAM address whose each block is 8 bytes*/
	u8 Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
	/*Send CGRAM address command to LCD, with setting bit 6, and clearing bit 7*/
	CLCD_u8SendCommand(Local_u8CGRAMAddress + 64);
	for(i=0;i<8;i++)
	{
		/*Writing the pattern into CGRAM*/
		CLCD_u8SendData(Copy_pu8Pattern[i]);
	}
	/*Go back to DDRAM to display the pattern*/
	CLCD_u8GoToXY(Copy_u8XPos, Copy_u8YPos);
	/*Display the pattern written in the CGRAM*/
	CLCD_u8SendData(Copy_u8PatternNumber);
}
void CLCD_u32WriteNumber(u32 Copy_u32Number)
{
	u8 Local_u8NextDigit,i=0,j,Arr[8];

	while(Copy_u32Number > 0)
	{
		Local_u8NextDigit = Copy_u32Number % 10;
		Copy_u32Number = Copy_u32Number / 10;
		Arr[i] = Local_u8NextDigit;
		i++;
	}
	for(j=0;j<i;j++)
	{
		CLCD_u8SendData(Arr[i-j-1]+48);
	}
}
