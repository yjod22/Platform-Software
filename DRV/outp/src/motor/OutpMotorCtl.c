/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     OutpMotorCtl.c
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


#include "OutpMotorCtl.h"
#include "ehal_motor.h"

void OutpMotorCtl_Calc_Motor(uint32 pulse)
{
	EHAL_Motor_Process(pulse);
    return;
}
