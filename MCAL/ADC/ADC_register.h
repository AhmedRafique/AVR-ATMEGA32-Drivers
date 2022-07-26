/********************		Author: Ahmed Rafique	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 17/07/2022		**************/
/*****************************************************************/
/*****************************************************************/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX			*((volatile u8*)0x27)

/*ADMUX ADC multiplexer selection register*/
#define ADMUX_REFS1		7		/*REFS1 & REFS0 to determine the reference voltage*/
#define ADMUX_REFS0		6
#define ADMUX_ADLAR		5		/*For left adjustment*/
#define ADMUX_MUX4		4		/*MUX pins to choose the mode of the ADC*/
#define ADMUX_MUX3		3	
#define ADMUX_MUX2		2	
#define ADMUX_MUX1		1	
#define ADMUX_MUX0		0


#define ADCSRA			*((volatile u8*)0x26)

/*ADCSRA ADC control and status register A*/
#define ADCSRA_ADEN		7		/*ADC Enable*/	
#define ADCSRA_ADSC		6		/*ADC Start conversion*/
#define ADCSRA_ADATE	5		/*ADC Auto Trigger Enable (to enable for interrupt to trigger ADC)*/
#define ADCSRA_ADIF		4		/*ADC Interrupt Flag (Logical 1 when ADC finishes conversion)*/
#define ADCSRA_ADIE		3		/*ADC Interrupt Enable (When is set and I bit in SREG is set ==> ADIF = 1 => Generate Interrupt)*/
#define ADCSRA_ADPS2	2		/*This and below for determining prescaler value*/
#define ADCSRA_ADPS1	1
#define ADCSRA_ADPS0	0

#define ADC_Register    *((volatile u16*)0x24)				/*ADC 16-bit Data Register*/
#define ADCH       		*((volatile u8*)0x25)				/*ADC Data High Register*/
#define ADCL        	*((volatile u8*)0x24)				/*ADC Data LOW Register*/



/*SFIOR Special function IO register*/
#define SFIOR			*((volatile u8*)0x50)
#define SFIOR_ADTS2		7		/*ADC select Auto trigger source related to ADCSRA_ADATE*/
#define SFIOR_ADTS1     6	
#define SFIOR_ADTS0	    5

#endif
