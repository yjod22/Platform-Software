/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     InppDistanceEvl.h
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

#ifndef INPP_DISTANCE_EVL_H_
#define INPP_DISTANCE_EVL_H_

#include "drv.h"
#include "ehal_distance.h"

extern uint16 InppDistanceEvl_Get_uDistance();
extern void InppDistanceEvl_Set_uDistance(uint16 val);

extern void InppDistanceEvl_Calc_DistanceVal(void);

#endif
