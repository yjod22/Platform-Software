/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalUsart_IN.h
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
* Author/Date: Junseok Oh / 2023-11-03
* Change:      Enable Usart driver
*******************************************************************************
*/


#ifndef EHALUSART_IN_H_
#define EHALUSART_IN_H_

#include "EhalUsart_CFG.h"
#include "stm32f4xx_usart.h"

static inline void EhalUsart_IN_Temperature(float *data)
{
	Rte_Read_Temperature(data);
}

static inline bool EhalUsart_IN_FlagStatus_TxEmpty(void)
{
	return USART_GetFlagStatus(USART1, USART_FLAG_TXE);
}

#endif /* EHALUSART_IN_H_ */
