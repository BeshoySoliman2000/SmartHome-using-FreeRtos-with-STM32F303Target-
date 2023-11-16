#ifndef KEYPAD_PRV_H
#define	KEYPAD_PRV_H

#include "Std_types.h"
#include "Bit_utils.h"

#include "KEYPAD_int.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_prv.h"

u8 KEYPAD_u8ROWSArray[4]      = {ROW0PIN,ROW1PIN,ROW2PIN,ROW3PIN};
u8 KEYPAD_u8COLOUMNSSArray[4] = {COLOUMN0PIN,COLOUMN1PIN,COLOUMN2PIN,COLOUMN3PIN};

u8 KEYPAD_u8arrayVals[4][4] =
{
	{'7','8','9','*'},
	{'4','5','6','/'},
	{'1','2','3','+'},
	{'.','0','=','-'}
};

#endif