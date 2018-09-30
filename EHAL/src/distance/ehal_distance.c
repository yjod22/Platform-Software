/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ehal_distance.c
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     16.0
* Author/Date: JSO / 2018-09-30
* Change:      Redefine the architecture
*******************************************************************************
* Version:     15.0
* Author/Date: JSO / 2018-09-30
* Change:      Define the objects in the header
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/
#include "ehal_distance.h"
#include "DriverPwm.h"


uint16 EHAL_Get_uDistance()
{
	uint16 u;
	u = EHAL_uDistance;

	return u;
}

void EHAL_Distance_CalcInput(void)
{
	uint16 factor;
	factor = 17;
	//EHAL_uDistance = factor*EHAL_uDistance_Flt;
	EHAL_uDistance = factor*Driver_Pwm_Get_uInputCapture();
	return;
}
