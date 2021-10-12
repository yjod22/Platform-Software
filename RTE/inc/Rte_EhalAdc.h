/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     Rte_EhalAdc.h
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

#ifndef RTE_EHALADC_H_
#define RTE_EHALADC_H_

#include "std_type.h"

extern uint32 Rte_Battery;

#define Rte_Write_Battery(data) (Rte_Battery = (data))

#endif /* RTE_EHALADC_H_ */
