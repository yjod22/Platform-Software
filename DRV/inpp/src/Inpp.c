/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     Inpp.c
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

#include "Inpp.h"

void DRV_Inpp_ProcMain()
{
	InppBattEvl_Calc_BattVal();
	//InppDistanceEvl_Calc_DistanceVal();
	InppTempEvl_Calc_TempVal();
	InppSwtEvl_Calc_SwtVal();
}

