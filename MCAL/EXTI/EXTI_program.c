/********************		Author: Ahmed Rafique	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: EXTI				**************/
/********************		Version: 1.00			**************/
/********************		Date: 17/07/2022		**************/
/*****************************************************************/
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_register.h"
#include "EXTI_private.h"

/*Global Pointer to function to hold INT0 ISR address*/
void (*EXTI_pvINT0Func)(void) = NULL;
/*Global Pointer to function to hold INT1 ISR address*/
void (*EXTI_pvINT1Func)(void) = NULL;
/*Global Pointer to function to hold INT2 ISR address*/
void (*EXTI_pvINT2Func)(void) = NULL;

void EXTI_voidINT0Init(void)
{
	/*1- Check Sense Control*/
	#if INT0_SENSE == LOW_LEVEL
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	#elif	INT0_SENSE == ON_CHANGE
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);	
	#elif INT0_SENSE == FALLING_EDGE
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);	
	#elif INT0_SENSE == RISING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	#else
	#error "Wrong INT0_SENSE configuration option"
	#endif
	
	/*Check Peripheral Interrupt Enable (PIE) Inital State*/
	#if INT0_INITIAL_STATE == ENABLED
		SET_BIT(GICR,GICR_INT0);
	#elif INT0_INITIAL_STATE == DISABLED
		CLR_BIT(GICR,GICR_INT0);
	#else
	#error "Wrong INT0_INITIAL_STATE configuration option"
	#endif	
}

void EXTI_voidINT1Init(void)
{
	/*1- Check Sense Control*/
	#if INT1_SENSE == LOW_LEVEL
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
	#elif	INT1_SENSE == ON_CHANGE
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);	
	#elif INT1_SENSE == FALLING_EDGE
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);	
	#elif INT1_SENSE == RISING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	#else
	#error "Wrong INT1_SENSE configuration option"
	#endif
	
	/*Check Peripheral Interrupt Enable (PIE) Inital State*/
	#if INT1_INITIAL_STATE == ENABLED
		SET_BIT(GICR,GICR_INT1);
	#elif INT1_INITIAL_STATE == DISABLED
		CLR_BIT(GICR,GICR_INT1);
	#else
	#error "Wrong INT1_INITIAL_STATE configuration option"
	#endif	
}

void EXTI_voidINT2Init(void)
{
	/*1- Check Sense Control*/
	#if INT2_SENSE == FALLING_EDGE
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
	#elif INT2_SENSE == RISING_EDGE
		SET_BIT(MCUCSR,MCUCSR_ISC2);
	#else
	#error "Wrong INT2_SENSE configuration option"
	#endif
	
	/*Check Peripheral Interrupt Enable (PIE) Inital State*/
	#if INT2_INITIAL_STATE == ENABLED
		SET_BIT(GICR,GICR_INT2);
	#elif INT2_INITIAL_STATE == DISABLED
		CLR_BIT(GICR,GICR_INT2);
	#else
	#error "Wrong INT2_INITIAL_STATE configuration option"
	#endif	
}

u8 	 EXTI_u8INT0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);		
		break;
	case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);		
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;		
	default: Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 	 EXTI_u8INT1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);		
		break;
	case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);		
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;		
	default: Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 	 EXTI_u8INT1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
	case FALLING_EDGE:
		CLR_BIT(MCUCSR,MCUCSR_ISC2);	
		break;
	case RISING_EDGE:
		SET_BIT(MCUCSR,MCUCSR_ISC2);
		break;		
	default: Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INTEnable(u8 Copy_u8INT)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8INT)
	{
	case GICR_INT0:
		SET_BIT(GICR,GICR_INT0);
		break;
	case GICR_INT1:
		SET_BIT(GICR,GICR_INT1);
		break;
	case GICR_INT2:
		SET_BIT(GICR,GICR_INT2);
		break;			
	default: Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INTDisable(u8 Copy_u8INT)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8INT)
	{
	case GICR_INT0:
		CLR_BIT(GICR,GICR_INT0);
		break;
	case GICR_INT1:
		CLR_BIT(GICR,GICR_INT1);
		break;
	case GICR_INT2:
		CLR_BIT(GICR,GICR_INT2);
		break;			
	default: Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INT0SetCallBack(void(*Copy_pvINT0Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvINT0Func != NULL)
	{
		EXTI_pvINT0Func = Copy_pvINT0Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER; //Define it = 2 in STD_TYPES	
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INT1SetCallBack(void(*Copy_pvINT1Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvINT1Func != NULL)
	{
		EXTI_pvINT1Func = Copy_pvINT1Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER; //Define it = 2 in STD_TYPES	
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INT2SetCallBack(void(*Copy_pvINT2Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvINT2Func != NULL)
	{
		EXTI_pvINT2Func = Copy_pvINT2Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER; //Define it = 2 in STD_TYPES	
	}
	return Local_u8ErrorState;
}

/*ISR of INT0*/
void __vector_1(void)		__attribute__((signal));
void __vector_1(void)
{	
	if(EXTI_pvINT0Func != NULL)
	{
		EXTI_pvINT0Func();
	}
	else
	{
		/*Do Nothing*/
	}
}
/*ISR of INT1*/
void __vector_2(void)		__attribute__((signal));
void __vector_2(void)
{	
	if(EXTI_pvINT1Func != NULL)
	{
		EXTI_pvINT1Func();
	}
	else
	{
		/*Do Nothing*/
	}
}
/*ISR of INT2*/
void __vector_3(void)		__attribute__((signal));
void __vector_3(void)
{	
	if(EXTI_pvINT2Func != NULL)
	{
		EXTI_pvINT2Func();
	}
	else
	{
		/*Do Nothing*/
	}
}