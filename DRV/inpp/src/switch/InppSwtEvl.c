/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     InppSwtEvl.c
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
#include "InppSwtEvl.h"

bool InppSwtEvl_bSwt;

uint32 InppSwtEvl_Get_bSwt()
{
	uint32 b;
	b = InppSwtEvl_bSwt;
	return b;
}

void InppSwtEvl_Set_bSwt(bool val)
{
	InppSwtEvl_bSwt = val;
}
void InppSwtEvl_Calc_SwtVal(void)
{
	InppSwtEvl_Set_bSwt(bPushButton);
    return;
}
