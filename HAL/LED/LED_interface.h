/**************************************************************************/
/**************************************************************************/
/*******************		AUTHOR:  Ahmed Rafique		*******************/
/*******************		Layer:   HAL				*******************/
/*******************		SWC: 	 LED				*******************/
/*******************		Version: 1.0.0				*******************/
/**************************************************************************/
/**************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_SINK 		0
#define LED_SOURCE	 	1


u8 LED_u8TurnOn(u8 Copy_u8Port,u8 Copy_u8Pin,u8 ConnType);

u8 LED_u8TurnOff(u8 Copy_u8Port,u8 Copy_u8Pin,u8 ConnType);

#endif