/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalCan_CFG.h
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

#ifndef EHALCAN_CFG_H_
#define EHALCAN_CFG_H_

#include "Rte_EhalCan.h"
#include "std_type.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_can.h"

#define EHAL_CAN_TIMEOUT 2

extern __IO uint32_t TimmingDelay;

#endif /* EHALCAN_CFG_H_ */
