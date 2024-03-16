/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     can.c
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     x.0
* Author/Date: JSO / 2024-01-21
* Change:      Initial version
*******************************************************************************
*/

#include <stdio.h>
#include <stddef.h>
#include "stm32f4xx.h"
#include "can.h"

void CAN1_Init(void)
{
	/* Enable clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

	/* Set values */
	/* http://www.bittiming.can-wiki.info/ */
	/* main.c*/
	/* system clock = 16Mhz */
	/* system_stm32f4xx.c */
    /* HCLK = SYSCLK / 1* = 16Mhz/
	/* PCLK1 = HCLK / 1 = 16Mhz*/
	CAN_InitTypeDef CAN_InitStruct;
	CAN_StructInit(&CAN_InitStruct);
	CAN_InitStruct.CAN_Prescaler = 2;
	CAN_InitStruct.CAN_Mode = CAN_Mode_LoopBack;
	CAN_InitStruct.CAN_SJW = CAN_SJW_1tq;
	CAN_InitStruct.CAN_BS1 = CAN_BS1_13tq;
	CAN_InitStruct.CAN_BS2 = CAN_BS2_2tq;

	CAN_FilterInitTypeDef CAN_FilterStruct;
	CAN_FilterStruct.CAN_FilterActivation = ENABLE;
	CAN_FilterStruct.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;
	CAN_FilterStruct.CAN_FilterIdHigh = 0x0000;
	CAN_FilterStruct.CAN_FilterIdLow = 0x0000;
	CAN_FilterStruct.CAN_FilterMaskIdHigh = 0x0000;
	CAN_FilterStruct.CAN_FilterMaskIdLow = 0x0000;
	CAN_FilterStruct.CAN_FilterMode = CAN_FilterMode_IdMask;
	CAN_FilterStruct.CAN_FilterNumber = 0;
	CAN_FilterStruct.CAN_FilterScale = CAN_FilterScale_32bit;

	/* Initialize Filter */
	CAN_FilterInit(&CAN_FilterStruct);

	/* Initialize CAN */
	CAN_Init(CAN1, &CAN_InitStruct);
}
