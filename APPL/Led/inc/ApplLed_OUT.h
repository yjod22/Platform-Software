/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ApplLed_OUT.h
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

#ifndef APPLLED_OUT_H_
#define APPLLED_OUT_H_

#include "ApplLed_CFG.h"

static inline void ApplLed_OUT_LedRed_On(void)
{
	Rte_Write_LedRed(true);
}

static inline void ApplLed_OUT_LedRed_Off(void)
{
	Rte_Write_LedRed(false);
}

static inline void ApplLed_OUT_LedGreen_On(void)
{
	Rte_Write_LedGreen(true);
}

static inline void ApplLed_OUT_LedGreen_Off(void)
{
	Rte_Write_LedGreen(false);
}
#endif /* APPLLED_OUT_H_ */
