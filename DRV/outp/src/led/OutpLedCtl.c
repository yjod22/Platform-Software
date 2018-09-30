/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     OutpLedCtl.c
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/
#include "OutpLedCtl.h"

void OutpLedCtl_Calc_Led()
{
	if( OutpPsplyCtl_Get_sPsplyMode() >= PSPLY_OP)
	{
		if( OutpPsplyCtl_Get_sPsplyMode() == PSPLY_ACTIVE_ON)
		{
			if( InppTempEvl_Get_fTemp() < 20)
			{
				LED_R_ON();
				LED_G_OFF();
			}
			else
			{
				LED_R_OFF();
				LED_G_ON();
			}
		}
		else
		{
			LED_R_OFF();
			LED_G_OFF();
		}
	}
	else
	{
		LED_R_OFF();
		LED_G_OFF();
	}
}
