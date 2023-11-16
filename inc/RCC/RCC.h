#ifndef RCC_H_
#define RCC_H_

#include "Std_types.h"
#include "Bit_utils.h"

#define AHBx			0

#define IOPxH		16
#define IOPxA		17
#define IOPxB		18
#define IOPxC		19
#define IOPxD		20
#define IOPxE		21
#define IOPxF		22
#define IOPxG		23

#define ADC12		28
#define ADC34		29



#define APB1x		1

#define TIM2		0
#define TIM3		1
#define TIM4		3

#define USART2		17
#define USART3		18
#define USART4		19
#define USART5		20

#define APB2x		2

#define TIM1		11
#define SPI1		12	
#define TIM8		13
#define USART1		14
#define SPI4		15



void RCC_voidEnablePeripheralClock(u8 Copy_u8PerphBus, u8 Copy_u8Peripheral);
void RCC_voidDisablePeripheralClock(u8 Copy_u8PerphBus, u8 Copy_u8Peripheral);
#endif

