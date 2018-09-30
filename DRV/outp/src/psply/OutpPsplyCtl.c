/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     OutpPsplyCtl.c
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

#include "OutpPsplyCtl.h"

uint8 	OutpPsplyCtl_sPsplyMode;
bool 	OutpPsplyCtl_bPsplyOut;

uint8 OutpPsplyCtl_Get_sPsplyMode()
{
	uint8 u;
	u = OutpPsplyCtl_sPsplyMode;
	return u;
}

bool OutpPsplyCtl_Get_bPsplyOut()
{
	bool b;
	b = OutpPsplyCtl_bPsplyOut;
	return b;
}

void OutpPsplyCtl_Calc_Psply(void)
{
	uint8 	sMode;
	bool  	bOutMon;
	uint32 	uBattLoc;
	bool 	bSwtLoc;

	bOutMon = OutpPsplyCtl_bPsplyOut;
	sMode = OutpPsplyCtl_sPsplyMode;
	uBattLoc = InppBattEvl_Get_uBatt();
	bSwtLoc = InppSwtEvl_Get_bSwt();

	switch(sMode)
	{
		case PSPLY_INIT:
		{
			if (uBattLoc > BATT_THRESHOLD)
			{
				sMode = PSPLY_OP;
			}
			else
			{
				sMode = PSPLY_NONOP;
			}
			break;
		}

		case PSPLY_NONOP:
		{
			bOutMon = false;

			if(uBattLoc > BATT_THRESHOLD)
			{
				sMode = PSPLY_OP;
			}
			break;
		}

		case PSPLY_OP:
		{
			bOutMon = true;

			sMode = PSPLY_ACTIVE_OFF;
			break;
		}

		case PSPLY_ACTIVE_OFF:
		{
			if(uBattLoc > BATT_THRESHOLD)
			{
				if(bSwtLoc != false)
				{
					sMode = PSPLY_ACTIVE_ON;
				}
			}
			else
			{
				sMode = PSPLY_NONOP;
			}
			break;
		}

		case PSPLY_ACTIVE_ON:
		{
			if(uBattLoc > BATT_THRESHOLD)
			{
				if(bSwtLoc == false)
				{
					sMode = PSPLY_ACTIVE_OFF;
				}
			}
			else
			{
				sMode = PSPLY_NONOP;
			}
			break;
		}

	}

	 /* store the new status */
	OutpPsplyCtl_sPsplyMode = sMode;

	 /* set Output */
	OutpPsplyCtl_bPsplyOut = bOutMon;

}
