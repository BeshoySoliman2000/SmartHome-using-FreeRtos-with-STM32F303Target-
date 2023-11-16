#ifndef GPIO_PRV_H_
#define GPIO_PRV_H_
#include "Std_types.h"
#include "Bit_utils.h"

typedef struct
{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
	u32 BRR;
}GPIO_t;

GPIO_t* GPIOx[8] = 
{
	((volatile GPIO_t*)0x48000000),
	((volatile GPIO_t*)0x48000400),
	((volatile GPIO_t*)0x48000800),
	((volatile GPIO_t*)0x48000C00),
	((volatile GPIO_t*)0x48001000),
	((volatile GPIO_t*)0x48001400),
	((volatile GPIO_t*)0x48001800),
	((volatile GPIO_t*)0x48001C00)
};

#endif