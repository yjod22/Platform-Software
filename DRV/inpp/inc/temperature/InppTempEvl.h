/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     InppTempEvl.h
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

#ifndef INPP_IFC_TEMPERATURE_H_
#define INPP_IFC_TEMPERATURE_H_

#include "drv.h"
#include "I2cPosition.h"

extern float InppTempEvl_Get_fTemp(void);
extern void InppTempEvl_Set_fTemp(float val);

extern void InppTempEvl_Calc_TempVal();

#endif
