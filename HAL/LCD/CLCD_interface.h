/**************************************************************************/
/**************************************************************************/
/*******************		AUTHOR:  Ahmed Rafique		*******************/
/*******************		Layer:   HAL				*******************/
/*******************		SWC: 	 CLCD				*******************/
/*******************		Version: 1.0.0				*******************/
/**************************************************************************/
/**************************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_u8SendCommand(u8 Copy_u8Command);
void CLCD_u8SendData(u8 Copy_u8Data);
void CLCD_VoidInit(void);
void CLCD_u8SendString(const char* Copy_pcString);
void CLCD_u8GoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_u8WriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_u32WriteNumber(u32 Copy_u32Number);
#endif
