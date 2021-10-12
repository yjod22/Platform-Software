/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     Rte_EhalDio.h
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

#ifndef RTE_EHALDIO_H_
#define RTE_EHALDIO_H_

#include "std_type.h"

extern bool Rte_LedRed;
extern bool Rte_LedGreen;

#define Rte_Read_LedRed(data) (*(data) = Rte_LedRed)
#define Rte_Read_LedGreen(data) (*(data) = Rte_LedGreen)

#endif /* RTE_EHALDIO_H_ */
