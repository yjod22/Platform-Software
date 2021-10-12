/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ApplLed_IN.h
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
*/


#ifndef APPLLED_IN_H_
#define APPLLED_IN_H_

#include "ApplLed_CFG.h"

static inline void ApplLed_IN_Temperature(float *data)
{
	Rte_Read_Temperature(data);
}

static inline void ApplLed_IN_PsplyMode(uint8 *data)
{
	Rte_Read_PsplyMode(data);
}

#endif /* APPLLED_IN_H_ */
