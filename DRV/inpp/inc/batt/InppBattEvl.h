/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     InppBattEvl.h
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
#ifndef INPP_BATT_EVL_H_
#define INPP_BATT_EVL_H_

#include "drv.h"
#include "ehal_adc.h"

extern uint32 InppBattEvl_Get_uBatt(void);
extern void InppBatEvl_Set_uBatt(uint32 val);

extern void InppBattEvl_Calc_BattVal();

#endif
