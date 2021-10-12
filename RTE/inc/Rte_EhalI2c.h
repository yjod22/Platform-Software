/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     Rte_EhalI2c.h
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

#ifndef RTE_EHALI2C_H_
#define RTE_EHALI2C_H_

#include "std_type.h"

extern float Rte_Temperature;

#define Rte_Write_Temperature(data) (Rte_Temperature = (data))



#endif /* RTE_EHALI2C_H_ */
