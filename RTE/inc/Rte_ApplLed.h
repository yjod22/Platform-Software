/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     Rte_ApplLed.h
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

#ifndef RTE_APPLLED_H_
#define RTE_APPLLED_H_

#include "std_type.h"

extern float Rte_Temperature;
extern uint8 Rte_PsplyMode;
extern bool Rte_LedRed;
extern bool Rte_LedGreen;

#define Rte_Read_Temperature(data) (*(data) = Rte_Temperature)
#define Rte_Read_PsplyMode(data) (*(data) = Rte_PsplyMode)

#define Rte_Write_LedRed(data) (Rte_LedRed = data)
#define Rte_Write_LedGreen(data) (Rte_LedGreen = data)

#endif /* RTE_APPLLED_H_ */
