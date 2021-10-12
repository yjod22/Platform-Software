/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalDio_IN.h
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

#ifndef EHALDIO_IN_H_
#define EHALDIO_IN_H_

#include "EhalDio_CFG.h"

static inline void EhalDio_IN_LedRed(bool *data)
{
	Rte_Read_LedRed(data);
}

static inline void EhalDio_IN_LedGreen(bool *data)
{
	Rte_Read_LedGreen(data);
}

#endif /* EHALDIO_IN_H_ */
