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
	CAN_InitTypeDef CAN_InitStruct;

	/* Enable clock */
//	RCC->APB1ENR |= RCC_APB1ENR_CAN1EN;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

	/* main.c*/
	/* system clock = 16Mhz */

	/* system_stm32f4xx.c */
    /* HCLK = SYSCLK / 1* = 16Mhz/
	/* PCLK1 = HCLK / 1 = 16Mhz*/
	/* Set values */
	/* http://www.bittiming.can-wiki.info/ */
	CAN_StructInit(&CAN_InitStruct);
	CAN_InitStruct.CAN_Prescaler = 2;
	CAN_InitStruct.CAN_Mode = CAN_Mode_LoopBack;
	CAN_InitStruct.CAN_SJW = CAN_SJW_1tq;
	CAN_InitStruct.CAN_BS1 = CAN_BS1_13tq;
	CAN_InitStruct.CAN_BS2 = CAN_BS2_2tq;

	/* Disable CAN first */
//	I2C3->CR1 &= ~I2C_CR1_PE;

	/* Initialize I2C */
	CAN_Init(CAN1, &CAN_InitStruct);

	/* Enable CAN */
//	I2C3->CR1 |= I2C_CR1_PE;
}
