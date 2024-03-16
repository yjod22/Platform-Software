/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalCan_OUT.h
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     2016b04
* Author/Date: Junseok Oh / 2024-02-28
* Change:      Enable Can driver
*******************************************************************************
*/

#ifndef EHALCAN_OUT_H_
#define EHALCAN_OUT_H_

#include "EhalCan_CFG.h"
#include "stm32f4xx_can.h"

static inline void EhalCan_OUT_TxMessage(CanTxMsg* msg)
{
	CAN_Transmit(CAN1, msg);
}

#endif /* EHALCAN_OUT_H_ */
