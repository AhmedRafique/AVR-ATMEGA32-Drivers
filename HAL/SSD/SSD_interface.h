/**************************************************************************/
/**************************************************************************/
/*******************		AUTHOR:  Ahmed Rafique		*******************/
/*******************		Layer:   HAL				*******************/
/*******************		SWC: 	 SSD				*******************/
/*******************		Version: 1.0.0				*******************/
/**************************************************************************/
/**************************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_NUM0 			0b00111111
#define SSD_NUM1			0b00000110
#define SSD_NUM2			0b01011011
#define SSD_NUM3			0b01001111
#define SSD_NUM4			0b01100110
#define SSD_NUM5			0b01101101
#define SSD_NUM6			0b01111101
#define SSD_NUM7			0b00000111
#define SSD_NUM8			0b01111111
#define SSD_NUM9			0b01101111

#define SSD_COMANODE		0
#define SSD_COMCATHODE		1

typedef struct{
	u8 COM_TYPE;
	u8 PORT;
	u8 EnablePort;
	u8 EnablePin;
}SSD_t;

u8 SSD_u8SetNumber(u8 Number,SSD_t* SSD);

u8 SSD_Enable(SSD_t* SSD);

u8 SSD_Disable(SSD_t* SSD);

#endif
