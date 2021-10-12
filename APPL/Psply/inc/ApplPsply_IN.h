/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ApplPsply_IN.h
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

#include "ApplPsply_CFG.h"

#ifndef APPLPSPLY_IN_H_
#define APPLPSPLY_IN_H_

static inline void ApplPsply_IN_Battery(uint32 *data)
{
	Rte_Read_Battery(data);
}

static inline void ApplPsply_IN_Switch(bool *data)
{
	Rte_Read_Switch(data);
}


#endif /* APPLPSPLY_IN_H_ */
