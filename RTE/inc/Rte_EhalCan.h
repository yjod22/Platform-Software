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
#include "FreeRTOS.h"
#include "queue.h"
#include "stm32f4xx_can.h"

#define QUEUE_LENGTH 100
#define QUEUE_ITEM_SIZE sizeof(Rte_CanRx_tst)

typedef struct
{
	uint16 msgCounter;
	CanRxMsg canRxMsg;
}Rte_CanRx_tst;

extern QueueHandle_t Rte_CanQueue;

#define Rte_Write_CanRxMsg(data, prio) (xQueueSendFromISR(Rte_CanQueue, &data, &prio))
#define Rte_Read_CanRxMsg(data) (xQueueReceive(Rte_CanQueue, data, 0))


#endif /* RTE_EHALCAN_H_ */
