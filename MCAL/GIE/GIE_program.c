/********************		Author: Ahmed Rafique	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: GIE				**************/
/********************		Version: 1.00			**************/
/********************		Date: 18-7-2022			**************/
/*****************************************************************/
/*****************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}