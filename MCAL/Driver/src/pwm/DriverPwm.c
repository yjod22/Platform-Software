/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     pwm.c
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
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#include <stdio.h>
#include <stddef.h>
#include "stm32f4xx.h"
#include "DriverPwm.h"

uint16 Driver_Pwm_Get_uInputCapture(void)
{
 uint16 Pwm_uInputCapture;
 Pwm_uInputCapture = (uint16)(TIM_GetCapture2(TIM5));
 return Pwm_uInputCapture;
}

void Driver_Pwm_Set_uPulse(uint32 uPulse)
{
	TIM_SetCompare1(TIM2, uPulse);
	return;
}

