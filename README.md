# AVR-ATMEGA32-Drivers
All drivers for ATMega32 Microcontroller written in C.

Drivers are splitted into 3 main layers

MCAL Layer ===> MCAL is a software module that directly accesses on-chip MCU peripheral modules and external devices that are mapped to memory,
and makes the upper software layer independent of the MCU.
HAL Layer ===>  A HAL is a hardware abstraction layer that defines a set of routines, protocols and tools for interacting with the hardware.
APP Layer ===>  Software layer for applications depending on HAL and MCAL layers.

There are also 2 important libraries till now

STD_TYPES.h ===> Userdefined types e.g. u8, u16, u32 ... etc. 
BIT_MATH.h ===>  For Setting, Clearing, Toggling and Getting the pins' values.
