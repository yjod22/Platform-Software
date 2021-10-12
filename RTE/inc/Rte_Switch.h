/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     Rte_Switch.h
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

#ifndef RTE_SWITCH_H_
#define RTE_SWITCH_H_

#include "std_type.h"

extern bool Rte_Switch;

#define Rte_Write_Switch(data)	(Rte_Switch = (data))


#endif /* RTE_SWITCH_H_ */
