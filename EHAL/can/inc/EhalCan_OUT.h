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

static inline void EhalCan_OUT_InitRcc(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);      \
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
}

static inline void EhalCan_OUT_InitGpio(void)
{
	GPIO_InitTypeDef GPIO_InitStructure_RX;
	GPIO_InitTypeDef GPIO_InitStructure_TX;

	// GPIO AF config for CAN1
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_CAN1);

	/* Configure CAN as alternate function*/
	GPIO_InitStructure_RX.GPIO_Pin   = GPIO_Pin_11;
	GPIO_InitStructure_RX.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure_RX.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure_RX.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure_RX.GPIO_Speed = GPIO_Speed_2MHz;

	/* Configure the GPIO for CAN RX*/
	GPIO_Init(GPIOA, &GPIO_InitStructure_RX);

	// GPIO AF config for CAN1
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource12, GPIO_AF_CAN1);

	/* Configure CAN as alternate function*/
	GPIO_InitStructure_TX.GPIO_Pin   = GPIO_Pin_12;
	GPIO_InitStructure_TX.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure_TX.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure_TX.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure_TX.GPIO_Speed = GPIO_Speed_2MHz;

	/* Configure the GPIO for CAN TX*/
	GPIO_Init(GPIOA, &GPIO_InitStructure_TX);
}


static inline void EhalCan_OUT_InitCan1(void)
{
	/* Enable clock */
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
	CAN_InitStruct.CAN_Mode = CAN_Mode_Normal;
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

	/* Configure Interrupt */
	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);

	/* Initialize CAN */
	CAN_Init(CAN1, &CAN_InitStruct);
}

static inline void EhalCan_OUT_InitNvic()
{
    NVIC_InitTypeDef NVIC_InitStructure;

    /* Configure the priority group */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

    /* Enable the CAN RX Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 6;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static inline void EhalCan_OUT_TxMessage(CanTxMsg* msg)
{
	CAN_Transmit(CAN1, msg);
}

#endif /* EHALCAN_OUT_H_ */
