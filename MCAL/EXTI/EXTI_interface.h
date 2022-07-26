/********************		Author: Ahmed Rafique	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: EXTI				**************/
/********************		Version: 1.00			**************/
/********************		Date: 17/07/2022		**************/
/*****************************************************************/
/*****************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL		1
#define ON_CHANGE		2
#define FALLING_EDGE	3
#define RISING_EDGE		4

#define ENABLED			1
#define DISABLED		2

void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT2Init(void);

/* A function to set the required sense control of INT0 using postbuild configuration
Input: Copy_u8Sense, options are:1 LOW_LEVEL		
                                 2 ON_CHANGE	
                                 3 FALLING_EDGE
                                 4 RISING_EDGE
Output: Error Status of type u8 */								  
u8 	 EXTI_u8INT0SetSenseControl(u8 Copy_u8Sense);
/* A function to set the required sense control of INT1 using postbuild configuration
Input: Copy_u8Sense, options are:1 LOW_LEVEL		
                                 2 ON_CHANGE	
                                 3 FALLING_EDGE
                                 4 RISING_EDGE
Output: Error Status of type u8 */
u8 	 EXTI_u8INT1SetSenseControl(u8 Copy_u8Sense);
/* A function to set the required sense control of INT2 using postbuild configuration
Input: Copy_u8Sense, options are:3 FALLING_EDGE
                                 4 RISING_EDGE
Output: Error Status of type u8 */
u8 	 EXTI_u8INT2SetSenseControl(u8 Copy_u8Sense);

/*A function to Enable a specific interrupt
Input: Interrupt number
Output: Error status of type u8*/
u8 EXTI_u8INTEnable(u8 Copy_u8INT);
/*A function to Disable a specific interrupt
Input: Interrupt number
Output: Error status of type u8*/
u8 EXTI_u8INTDisable(u8 Copy_u8INT);

u8 EXTI_u8INT0SetCallBack(void(*Copy_pvINT0Func)(void));

#endif