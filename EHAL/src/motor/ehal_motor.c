/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ehal_motor.c
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

#include "ehal_motor.h"
#include "timer.h"
#include "DriverPwm.h"

void EHAL_Motor_Process(uint32 pulse)
{
	//pulse = PWM_WIDTH * pulse / 100;
	pulse = PWM_WIDTH_BLDC * pulse / 100;	
	Driver_Pwm_Set_uPulse(pulse);
	return;
}
