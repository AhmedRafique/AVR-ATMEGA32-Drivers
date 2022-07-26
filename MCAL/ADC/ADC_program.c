/********************		Author: Ahmed Rafique	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20/07/2022		**************/
/*****************************************************************/
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_register.h"
#include "ADC_private.h"

u8 ADC_u8BusyState = ADC_State_Idle;
/*Global Pointer to function to call the function after ADC conversion is complete and reading*/
static u8* ADC_pu8Reading= NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;

void ADC_voidInit(void)
{
	/*Select Reference voltage*/
	#if(ADC_VOLTAGE_REF == VREF_AVCC)
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	#elif(ADC_VOLTAGE_REF == AREF_VREF_OFF)
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	#elif(ADC_VOLTAGE_REF == RESERVED)
	CLR_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);	
	#elif(ADC_VOLTAGE_REF == INTERNAL_2_56_V)
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
	#else
	#error "Wrong ADC_VOLTAGE_REF configuration option"
	#endif	
	/*Choose Adjustment*/
	#if(ADC_ADJUSTMENT == ADC_LEFT_ADJUST)
	SET_BIT(ADMUX,ADMUX_ADLAR);
	#elif(ADC_ADJUSTMENT == ADC_RIGHT_ADJUST)
	CLR_BIT(ADMUX,ADMUX_ADLAR);	
	#else
	#error "Wrong ADC_ADJUSTMENT configuration option"
	#endif	
	/*Set prescaler value*/
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_PRESCALER;
	/*Select trigger source*/
	#if(ADC_AUTO_TRIGGER_STATE == ENABLED)
	/*Enable Auto Trigger*/
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	SFIOR &= 0b00011111;
	SFIOR |= ADC_AUTO_TRIGGER_SOURCE;
	/*ADC Start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Enable ADC Interrupt*/
	SET_BIT(ADCSRA,ADCSRA_ADIE);
	#elif(ADC_AUTO_TRIGGER_STATE == DISABLED)
	/*Disable ADC Interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
	/*Disable ADC Auto Trigger*/
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
	#else
	#error "Wrong ADC_AUTO_TRIGGER_STATE configuration option"
	#endif

	/*Enable ADC peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8* Copy_pu8Reading)
{
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=OK;
	if(ADC_u8BusyState == ADC_State_Idle)
	{
	/*Make ADC busy in order to block it from being executed while being already busy*/
	ADC_u8BusyState = ADC_State_Busy;
	/*Clear the MUX bits in ADMUX register*/
	ADMUX &=0b11100000;
	/*Set the required channel into the MUX bits*/
	ADMUX |= Copy_u8Channel;
	/*Start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Polling (busy waiting) until the conversion complete flag is set or couter reaches timeout*/
	while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0)&&(Local_u32Counter < ADC_u32TimeOut))
	{
		Local_u32Counter++;
	}
	if(Local_u32Counter == ADC_u32TimeOut)
	{
		/*Loop is broken due to timeout*/
		Local_u8ErrorState = NOK;
	}
	else{
		/*Loop is broken because the flag is set*/
		/*Clear the conversion complete flag*/
		SET_BIT(ADCSRA,ADCSRA_ADIF);
		*Copy_pu8Reading = ADCH;
		/*Make ADC State Idle*/
		ADC_u8BusyState = ADC_State_Idle;
	}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC; //Define in STD_TYPES
	}
	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8* Copy_pu8Reading, void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(ADC_u8BusyState==ADC_State_Idle)
	{
	if((Copy_pu8Reading == NULL)|| (Copy_pvNotificationFunc == NULL))
	{
		Local_u8ErrorState = NULL_POINTER; //defined in STD_TYPES
	}
	else
	{
	/*Make ADC busy in order to block it from being executed while being already busy*/
	ADC_u8BusyState = ADC_State_Busy;
	/*Initialize the reading variable globally*/
	ADC_pu8Reading = Copy_pu8Reading;
	/*Initialize the callback function globally*/
	ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;
	/*Clear the MUX bits in ADMUX register*/
	ADMUX &=0b11100000;
	/*Set the required channel into the MUX bits*/
	ADMUX |= Copy_u8Channel;
	/*Start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Enable ADC Interrupt*/
	SET_BIT(ADCSRA,ADCSRA_ADIE);
	
	}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC; //Define in STD_TYPES
	}
	return Local_u8ErrorState;
}

void __vector_16 (void)	__attribute__((signal));
void __vector_16 (void)
{
	/*Read ADC result*/
	*ADC_pu8Reading = ADCH;
	/*Make ADC State Idle*/
	ADC_u8BusyState = ADC_State_Idle;
	/*Invoke the callback notification function*/
	ADC_pvCallBackNotificationFunc();
	/*Disable ADC conversion complete interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}
