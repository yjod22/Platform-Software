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

#include "EhalDio_CFG.h"
#include "stm32f4xx_gpio.h"

static inline void EhalDio_OUT_LedRed_On(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_15);
}

static inline void EhalDio_OUT_LedRed_Off(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_15);
}

static inline void EhalDio_OUT_LedGreen_On(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_4);
}

static inline void EhalDio_OUT_LedGreen_Off(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_4);
}


#endif /* EHALDIO_OUT_H_ */
