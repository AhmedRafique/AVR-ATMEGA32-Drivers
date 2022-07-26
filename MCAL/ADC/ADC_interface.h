/********************		Author: Ahmed Rafique	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20/07/2022		**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define		AREF_VREF_OFF							1
#define		AVCC									2
#define		RESERVED								3
#define		INTERNAL_2_56_V							4


#define		ADC_LEFT_ADJUST							1
#define		ADC_RIGHT_ADJUST						2


#define		DIV_BY_2								1
#define		DIV_BY_4								2
#define		DIV_BY_8								3
#define		DIV_BY_16								4
#define		DIV_BY_32								5
#define		DIV_BY_64								6
#define		DIV_BY_128								7


#define		FREE_RUNNING							0
#define		ANALOG_COMPARATOR						1
#define		EXTI_REQUEST_0							2
#define		TIMER_COUNTER_0_COMPARE_MATCH			3
#define		TIMER_COUNTER_0_OVERFLOW				4
#define		TIMER_COUNTER_0_COMPARE_MATCH_B			5
#define		TIMER_COUNTER_1_OVERFLOW				6
#define		TIMER_COUNTER_1_CAPTURE_EVENT			7


#define		ADC_8_BITS_RES							1
#define		ADC_10_BITS_RES							2

#define ENABLED										1
#define DISABLED									2

void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8* Copy_pu8Reading);

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8* Copy_pu8Reading, void(*Copy_pvNotificationFunc)(void));

#endif