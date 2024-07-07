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

static inline void EhalUsart_IN_Temperature(float *data)
{
	Rte_Read_Temperature(data);
}

static inline bool EhalUsart_IN_Can(Rte_CanRx_tst *data)
{
	return Rte_Read_CanRxMsg(data);
}

#endif /* EHALUSART_IN_H_ */
