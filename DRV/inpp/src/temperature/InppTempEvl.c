/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     InppTempEvl.c
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
#include "InppTempEvl.h"

float InppTempEvl_uTemp;

float InppTempEvl_Get_fTemp()
{
	float f;
	f = InppTempEvl_uTemp;
	return f;
}

void InppTempEvl_Set_fTemp(float val)
{
	InppTempEvl_uTemp = val;
}

void InppTempEvl_Calc_TempVal(void)
{
	InppTempEvl_Set_fTemp(I2cPosition_Get_uTemp());
    return;
}
