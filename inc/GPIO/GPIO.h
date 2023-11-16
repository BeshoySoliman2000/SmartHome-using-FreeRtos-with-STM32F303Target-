#ifndef GPIO_H_
#define GPIO_H_

#include "Std_types.h"
#include "Bit_utils.h"

#define OUTPUTdir	0b01
#define INPUTdir	0b00

#define INPUT_PULLUP		0b01
#define NO_PULLUPDOWN		0b00
#define INPUT_PULLDOWN	0b01

#define GPIOx_High		1
#define GPIOx_LOW			0

#define GPIOxA		0
#define GPIOxB		1
#define GPIOxC		2
#define GPIOxD		3
#define GPIOxE		4
#define GPIOxF		5
#define GPIOxG		6
#define GPIOxH		7

#define PINx0		0
#define PINx1		1
#define PINx2		2
#define PINx3		3
#define PINx4		4
#define PINx5		5
#define PINx6		6
#define PINx7		7
#define PINx8		8
#define PINx9		9
#define PINx10		10
#define PINx11		11
#define PINx12		12
#define PINx13		13
#define PINx14		14
#define PINx15		15

void GPIO_voidSetPinDir(u8 PORT, u8 PIN, u8 DIR);
void GPIO_voidInputMode(u8 PORT, u8 PIN, u8 MODE);
void GPIO_voidSetPinVal(u8 PORT, u8 PIN, u8 Val);
void GPIO_voidGetPinVal(u8 PORT, u8 PIN, u8 *Val);

#endif
