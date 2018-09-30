/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     InppBattEvl.c
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
#include "InppBattEvl.h"

uint32 InppBattEvl_uBatt;

uint32 InppBattEvl_Get_uBatt()
{
	uint32 u;
	u = InppBattEvl_uBatt;
	return u;
}

void InppBatEvl_Set_uBatt(uint32 val)
{
	InppBattEvl_uBatt = val;
}

void InppBattEvl_Calc_BattVal(void)
{
	InppBatEvl_Set_uBatt(EHAL_Get_uBatt());
    return;
}
