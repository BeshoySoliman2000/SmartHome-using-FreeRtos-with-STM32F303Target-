#include "Std_types.h"
#include "Bit_utils.h"

#include "GPIO.h"
#include "GPIO_prv.h"
#include "GPIO_cfg.h"

void GPIO_voidSetPinDir(u8 PORT, u8 PIN, u8 DIR)
{
	GPIOx[PORT]->MODER = ((GPIOx[PORT]->MODER & ~(0b11<<(PIN*2)))|(DIR<<(PIN*2)));

}
void GPIO_voidInputMode(u8 PORT, u8 PIN, u8 MODE)
{
	GPIOx[PORT]->PUPDR = ((GPIOx[PORT]->PUPDR & ~(0b11<<(PIN*2)))|(MODE<<(PIN*2)));

}
void GPIO_voidSetPinVal(u8 PORT, u8 PIN, u8 Val)
{
	switch(Val)
	{
		case GPIOx_High:
			SET_BIT(GPIOx[PORT]->ODR, PIN);
			break;
		case GPIOx_LOW:
			CLR_BIT(GPIOx[PORT]->ODR, PIN);
			break;
	}
}
void GPIO_voidGetPinVal(u8 PORT, u8 PIN, u8 *Val)
{
		*Val = GET_BIT(GPIOx[PORT]->IDR,PIN);
}
