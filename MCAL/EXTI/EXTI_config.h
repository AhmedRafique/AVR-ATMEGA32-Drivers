/********************		Author: Ahmed Rafique	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: EXTI				**************/
/********************		Version: 1.00			**************/
/********************		Date: 17/07/2022		**************/
/*****************************************************************/
/*****************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*OPTIONS:
			1- LOW_LEVEL
			2- ON_CHANGE
			3- FALLING_EDGE
			4- RISING_EDGE*/
#define INT0_SENSE		FALLING_EDGE

/*OPTIONS:
			1- ENABLED
			2- DISABLED*/
#define INT0_INITIAL_STATE	ENABLED

/*OPTIONS:
			1- LOW_LEVEL
			2- ON_CHANGE
			3- FALLING_EDGE
			4- RISING_EDGE*/
#define INT1_SENSE		FALLING_EDGE

/*OPTIONS:
			1- ENABLED
			2- DISABLED*/
#define INT1_INITIAL_STATE	ENABLED

/*OPTIONS:
			3- FALLING_EDGE
			4- RISING_EDGE*/
#define INT2_SENSE		FALLING_EDGE

/*OPTIONS:
			1- ENABLED
			2- DISABLED*/
#define INT2_INITIAL_STATE	ENABLED


#endif