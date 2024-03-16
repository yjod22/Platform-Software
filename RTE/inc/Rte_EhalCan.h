/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     Rte_EhalCan.h
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     2016b03
* Author/Date: Junseok Oh / 2024-03-16
* Change:      enable CAN Rx functionality
*******************************************************************************
*/

#ifndef RTE_EHALCAN_H_
#define RTE_EHALCAN_H_

#include "std_type.h"

extern uint8 Rte_CanRxMsg[8];

#define Rte_Write_CanRxMsg(data) (memcpy(Rte_CanRxMsg, data, sizeof(data)))

#endif /* RTE_EHALCAN_H_ */
