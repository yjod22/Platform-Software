/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalDio_OUT.h
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

#ifndef EHALDIO_OUT_H_
#define EHALDIO_OUT_H_

#include "EhalUsart_CFG.h"
#include "stm32f4xx_usart.h"

static inline void EhalUsart_OUT_SendData(uint16_t data)
{
	USART_SendData(USART1, data);
}

#endif /* EHALDIO_OUT_H_ */
