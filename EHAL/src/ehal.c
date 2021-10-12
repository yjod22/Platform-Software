/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ehal.c
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     2016b02
* Author/Date: Junseok Oh / 2021-10-12
* Change:      Apply AUTOSAR Architecture
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#include "ehal.h"

void EHAL_Main_InputProcess(void)
{
	EhalAdc_CalcInput();
	EhalI2c_Read_Accelerometer();
	EhalI2c_Read_Temperature();
	EhalI2c_Read_Gyroscope();
}

void EHAL_Main_OutputProcess(void)
{
	EhalDio_CalcOutput();
}
