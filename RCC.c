#include "Std_types.h"
#include "Bit_utils.h"

#include "RCC.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"

void RCC_voidEnablePeripheralClock(u8 Copy_u8PerphBus, u8 Copy_u8Peripheral)
{
	//RCCp->AHBENR = 0;
	switch(Copy_u8PerphBus)
	{
		case AHBx:
			SET_BITBAND(RCCp->AHBENR, Copy_u8Peripheral);
//		SET_BIT(RCCp->AHBENR, Copy_u8Peripheral);
			break;
		case APB1x:
			SET_BITBAND(RCCp->APB1ENR, Copy_u8Peripheral);
			break;
		case APB2x:
			SET_BITBAND(RCCp->APB2ENR, Copy_u8Peripheral);
			break;
	}
}
void RCC_voidDisablePeripheralClock(u8 Copy_u8PerphBus, u8 Copy_u8Peripheral)
{
	switch(Copy_u8PerphBus)
	{
		case AHBx:
			CLR_BITBAND(RCCp->AHBENR, Copy_u8Peripheral);
			break;
		case APB1x:
			CLR_BITBAND(RCCp->APB1ENR, Copy_u8Peripheral);
			break;
		case APB2x:
			CLR_BITBAND(RCCp->APB2ENR, Copy_u8Peripheral);
			break;
	}
}

