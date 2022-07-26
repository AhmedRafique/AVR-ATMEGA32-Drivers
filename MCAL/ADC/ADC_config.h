/********************		Author: Ahmed Rafique	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20/07/2022		**************/
/*****************************************************************/
/*****************************************************************/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*
OPTIONS:	1-	AREF_VREF_OFF
			2-	AVCC
			3-	RESERVED
			4-	INTERNAL_2_56_V
*/
#define ADC_VOLTAGE_REF				VREF_AVCC

/*
OPTIONS:	1-	ADC_LEFT_ADJUST
			2-	ADC_RIGHT_ADJUST
*/
#define ADC_ADJUSTMENT				ADC_LEFT_ADJUST

/*
OPTIONS:	1-	DIV_BY_2
			2-	DIV_BY_4
			3-	DIV_BY_8
			4-	DIV_BY_16
			5-	DIV_BY_32
			6-	DIV_BY_64
			7-	DIV_BY_128
*/
#define ADC_PRESCALER				DIV_BY_128

/*
OPTIONS:	1-	FREE_RUNNING
			2-	ANALOG_COMPARATOR
			3-	EXTI_REQUEST_0
			4-	TIMER_COUNTER_0_COMPARE_MATCH
			5-	TIMER_COUNTER_0_OVERFLOW
			6-	TIMER_COUNTER_0_COMPARE_MATCH_B
			7-	TIMER_COUNTER_1_OVERFLOW
			8-	TIMER_COUNTER_1_CAPTURE_EVENT
*/
#define ADC_AUTO_TRIGGER_SOURCE		FREE_RUNNING

/*
OPTIONS:	1-	ADC_8_BITS_RES
			2-	ADC_10_BITS_RES
*/
#define ADC_RESOLUTION					ADC_8_BITS_RES

/*
OPTIONS:	1-	ENABLED
			2-	DISABLED
*/
#define ADC_AUTO_TRIGGER_STATE			ENABLED



#define ADC_u32TimeOut					50000

#endif