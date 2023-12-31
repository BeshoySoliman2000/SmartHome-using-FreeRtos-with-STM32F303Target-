#include "Std_types.h"
#include "Bit_utils.h"
#include "GPIO.h"
#include "KEYPAD_int.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_prv.h"
void KEYPAD_voidInit(void)
{
	
	GPIO_voidSetPinDir(KEYPAD_PORT, ROW0PIN, OUTPUTdir);
	GPIO_voidSetPinDir(KEYPAD_PORT, ROW1PIN, OUTPUTdir);
	GPIO_voidSetPinDir(KEYPAD_PORT, ROW2PIN, OUTPUTdir);
	GPIO_voidSetPinDir(KEYPAD_PORT, ROW3PIN, OUTPUTdir);
	
	GPIO_voidSetPinVal(KEYPAD_PORT, ROW0PIN, GPIOx_High);
	GPIO_voidSetPinVal(KEYPAD_PORT, ROW1PIN, GPIOx_High);
	GPIO_voidSetPinVal(KEYPAD_PORT, ROW2PIN, GPIOx_High);
	GPIO_voidSetPinVal(KEYPAD_PORT, ROW3PIN, GPIOx_High);
	
	
	/*PORT_enumSET_PINDirection(ROW0PIN, PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(ROW1PIN, PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(ROW2PIN, PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(ROW3PIN, PORT_u8PINDIR_OUTPUT);
	
	PORT_enumSET_PINMODE(ROW0PIN, PORT_u8PINMODE_OUTPUT_HIGH);
	PORT_enumSET_PINMODE(ROW1PIN, PORT_u8PINMODE_OUTPUT_HIGH);
	PORT_enumSET_PINMODE(ROW2PIN, PORT_u8PINMODE_OUTPUT_HIGH);
	PORT_enumSET_PINMODE(ROW3PIN, PORT_u8PINMODE_OUTPUT_HIGH);
	
	PORT_enumSET_PINDirection(COLOUMN0PIN, PORT_u8PINDIR_INPUT);
	PORT_enumSET_PINDirection(COLOUMN1PIN, PORT_u8PINDIR_INPUT);
	PORT_enumSET_PINDirection(COLOUMN2PIN, PORT_u8PINDIR_INPUT);
	PORT_enumSET_PINDirection(COLOUMN3PIN, PORT_u8PINDIR_INPUT);*/	
	
	GPIO_voidSetPinDir(KEYPAD_PORT, COLOUMN0PIN	, INPUTdir);
	GPIO_voidSetPinDir(KEYPAD_PORT, COLOUMN1PIN	, INPUTdir);
	GPIO_voidSetPinDir(KEYPAD_PORT, COLOUMN2PIN	, INPUTdir);
	GPIO_voidSetPinDir(KEYPAD_PORT, COLOUMN3PIN	, INPUTdir);
	
	GPIO_voidInputMode(KEYPAD_PORT, COLOUMN0PIN, INPUT_PULLUP);
	GPIO_voidInputMode(KEYPAD_PORT, COLOUMN1PIN, INPUT_PULLUP);
	GPIO_voidInputMode(KEYPAD_PORT, COLOUMN2PIN, INPUT_PULLUP);
	GPIO_voidInputMode(KEYPAD_PORT, COLOUMN3PIN, INPUT_PULLUP);
	
	/*PORT_enumSET_PINMODE(COLOUMN0PIN, PORT_u8PINMODE_INPUUT_PULLUP);
	PORT_enumSET_PINMODE(COLOUMN1PIN, PORT_u8PINMODE_INPUUT_PULLUP);
	PORT_enumSET_PINMODE(COLOUMN2PIN, PORT_u8PINMODE_INPUUT_PULLUP);
	PORT_enumSET_PINMODE(COLOUMN3PIN, PORT_u8PINMODE_INPUUT_PULLUP);*/

}
u8 KEYPAD_voidGetKEYPADVal(void)
{
	u8 KEYPAD_u8ColoumnVal;
	u8 KEYPAD_u8Flag = 0;
	for(u8 i=0;i<4;i++)
	{
		GPIO_voidSetPinVal(KEYPAD_PORT, KEYPAD_u8ROWSArray[i], GPIOx_LOW);
		for(int m=0;m<4;m++)
		{
			GPIO_voidGetPinVal(KEYPAD_PORT, KEYPAD_u8COLOUMNSSArray[m], &KEYPAD_u8ColoumnVal);
			while(KEYPAD_u8ColoumnVal == 0)
			{
				GPIO_voidGetPinVal(KEYPAD_PORT, KEYPAD_u8COLOUMNSSArray[m], &KEYPAD_u8ColoumnVal);
				KEYPAD_u8Flag = 1;
			}
			if(KEYPAD_u8Flag == 1 )
			{
				GPIO_voidSetPinVal(KEYPAD_PORT, KEYPAD_u8ROWSArray[i], GPIOx_High);
				return KEYPAD_u8arrayVals[i][m];
			}
		}
		GPIO_voidSetPinVal(KEYPAD_PORT, KEYPAD_u8ROWSArray[i], GPIOx_High);
	}
	return 0;
}
