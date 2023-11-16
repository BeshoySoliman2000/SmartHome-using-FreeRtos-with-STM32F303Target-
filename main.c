#include "stm32f303xe.h"
#include "Std_types.h"
#include "Bit_utils.h"
#include "RCC.h"
#include "GPIO.h"
#include "LCD.h"
#include "KEYPAD_int.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

/* Define Tasks Priorities */
#define  LCD_priority (3)
#define  ButtonOn_PRIORITY (3)

void LCDTask_code(void*pvParamter) ;
void HomeIntro_code (void * pvParamter) ;

/*Create Task Handles Create */

xTaskHandle LCDTask1Hand = NULL;
xTaskHandle HomeTask2Hand = NULL;

u8 StoredPassArray[4] = {1,3,5,7};
u8 PassToCheckArray[4];

u8 globalIndex =0;
u8 PasswordFlag=0;
int main(void)
{

	RCC_voidEnablePeripheralClock(AHBx, IOPxB);
	RCC_voidEnablePeripheralClock(AHBx, IOPxC);
	
	xTaskCreate(LCDTask_code,(const signed char *)"Task1",85,NULL,LCD_priority,&LCDTask1Hand);
	xTaskCreate(HomeIntro_code,(const signed char *)"Task2",85,NULL,ButtonOn_PRIORITY,&HomeTask2Hand);


	/*start Scheduler */
	vTaskStartScheduler();
	while(1)
	{
	
	}
	/*Never Enter Here */
	return 0;
}
/*This Task Handles The Lcd Init and Showing Parameters*/
void LCDTask_code(void*pvParamter)
{
	LCD_voidInit();
	while(1)
	{
		LCD_voidSetCursorToX_y(0,0);
		if(PasswordFlag == 1)
		{
			LCD_voidWriteString("You've Succedded the Password");
			PasswordFlag = 3;
		}
		else if (PasswordFlag == 2)
		{
			LCD_voidWriteString("You're a theif you've entered the password 3 Times");
			PasswordFlag = 4;
		}
		vTaskDelay(100);
	}
}

/* This Function Handle The Password with Keypad and you can you use it inside
the Home with the keypad and other devices */
void HomeIntro_code (void * pvParamter)
{
	KEYPAD_voidInit();
	u8 KeypadRead;
	u8 FlagPassStatus = 0;
	u8 NumOfErrPasswordEntry =0;
	while(1)
	{
		if(PasswordFlag == 0)
		{
			if(NumOfErrPasswordEntry < 4)
			{
				KeypadRead = KEYPAD_voidGetKEYPADVal();
				if(KeypadRead != 0)
				{
					if(globalIndex < 4)
					{
						PassToCheckArray[globalIndex] = KeypadRead - '0';
						globalIndex++;
					}
					else
					{
						for(u8 i =0;i<4;i++)
						{
							if(PassToCheckArray[i] == StoredPassArray[i])
							{
								FlagPassStatus = 1;
							}
							else
							{
								FlagPassStatus = 0;
							}
						}
						if(FlagPassStatus == 0)
						{
							NumOfErrPasswordEntry++;
						}
						else
						{
							PasswordFlag = 1;
						}
					}
				}
			}
			else
			{
				PasswordFlag = 2;
			}
		}
		vTaskDelay(100);
	}
}
