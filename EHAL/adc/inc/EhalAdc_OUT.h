/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalAdc_OUT.h
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

#ifndef EHALADC_OUT_H_
#define EHALADC_OUT_H_

#include "EhalAdc_CFG.h"

static inline void EhalAdc_OUT_Battery(uint32 data)
{
	Rte_Write_Battery(data);
}

#endif /* EHALADC_OUT_H_ */
