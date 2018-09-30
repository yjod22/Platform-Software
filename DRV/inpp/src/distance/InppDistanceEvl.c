/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     InppDistanceEvl.c
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
#include "InppDistanceEvl.h"

uint16 InppDistanceEvl_uDistance;

uint16 InppDistanceEvl_Get_uDistance()
{
	uint16 u;
	u = InppDistanceEvl_uDistance;
	return u;
}

void InppDistanceEvl_Set_uDistance(uint16 val)
{
	InppDistanceEvl_uDistance = val;
}

void InppDistanceEvl_Calc_DistanceVal(void)
{
	InppDistanceEvl_Set_uDistance(EHAL_Get_uDistance());
    return;
}
