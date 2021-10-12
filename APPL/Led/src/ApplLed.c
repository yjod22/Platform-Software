/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ApplLed.c
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     2016b02
* Author/Date: Junseok Oh / 2021-10-12
* Change:      Apply AUTOSAR Architecture
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#include "ApplLed.h"
#include "ApplLed_CFG.h"
#include "ApplLed_IN.h"
#include "ApplLed_OUT.h"

void ApplLed_Calc_Led()
{
	float ApplLed_Temperature_f;
	uint8 ApplLed_PsplyMode_u8;

	ApplLed_IN_Temperature(&ApplLed_Temperature_f);
	ApplLed_IN_PsplyMode(&ApplLed_PsplyMode_u8);

	if( ApplLed_PsplyMode_u8 >= APPLLED_PSPLY_OP)
	{
		if( ApplLed_PsplyMode_u8 == APPLLED_PSPLY_ACTIVE_ON)
		{
			if( ApplLed_Temperature_f < 25)
			{
				ApplLed_OUT_LedRed_On();
				ApplLed_OUT_LedGreen_Off();
			}
			else
			{
				ApplLed_OUT_LedRed_Off();
				ApplLed_OUT_LedGreen_On();
			}
		}
		else
		{
			ApplLed_OUT_LedRed_Off();
			ApplLed_OUT_LedGreen_Off();
		}
	}
	else
	{
		ApplLed_OUT_LedRed_Off();
		ApplLed_OUT_LedGreen_Off();
	}
}
