/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalCan_IN.h
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


#ifndef EHALCAN_IN_H_
#define EHALCAN_IN_H_

#include "EhalCan_CFG.h"
#include "system_macro.h"

static inline void EhalCan_IN_TxMessage(CanTxMsg* msg)
{
	CanTxMsg canTxMsg;
	canTxMsg.StdId = 0x111;
	canTxMsg.ExtId = 0;
	canTxMsg.IDE = CAN_Id_Standard;
	canTxMsg.RTR = CAN_RTR_Data;
	canTxMsg.DLC = 8;

	uint8_t canData[8];
	canData[0] = 0xFF;
	canData[1] = 0xFF;
	canData[2] = 0xFF;
	canData[3] = 0xFF;
	canData[4] = 0xFF;
	canData[5] = 0xFF;
	canData[6] = 0xFF;
	canData[7] = 0xFF;
	uint8_t valueToSet = 0x00;
	memcpy(canTxMsg.Data, &valueToSet, sizeof(canTxMsg.Data));
	for(int i=0; i<8; i++)
	{
		canTxMsg.Data[i] = canData[i];
	}

	memcpy(msg, &canTxMsg, sizeof(canTxMsg));
}

#endif /* EHALCAN_IN_H_ */
