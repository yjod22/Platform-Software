/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ehal_position.c
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
* Change:      Delete the temporary variables
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#include "ehal_position.h"


void EHAL_Position_CalcInput()
{
	I2cPosition_Read_Accelerometer();
	I2cPosition_Read_Temperature();
	I2cPosition_Read_Gyroscope();
}
