/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ApplPsply_OUT.h
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

#ifndef APPLPSPLY_OUT_H_
#define APPLPSPLY_OUT_H_

#include "ApplPsply_CFG.h"

static inline void ApplPsply_OUT_PsplyMode(uint8 data)
{
	Rte_Write_PsplyMode(data);
}

static inline void ApplPsply_OUT_PsplyOut(bool data)
{
	Rte_Write_PsplyOut(data);
}


#endif /* APPLPSPLY_OUT_H_ */
