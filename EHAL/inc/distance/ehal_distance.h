/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ehal_distance.h
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     15.0
* Author/Date: JSO / 2018-09-30
* Change:      Define the variable in the header
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#ifndef EHAL_DISTANCE_H_
#define EHAL_DISTANCE_H_

#include "ehal.h"

static uint16 EHAL_uDistance;

extern uint16 EHAL_Get_uDistance();
extern void EHAL_Distance_CalcInput(void);

#endif /* EHAL_DISTANCE_H_ */
