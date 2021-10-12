/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalI2c_OUT.h
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

#ifndef EHALI2C_OUT_H_
#define EHALI2C_OUT_H_

#include "EhalI2c_CFG.h"
#include "DriverI2c.h"

static inline void EhalI2c_OUT_I2c_Write(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t data)
{
	Driver_I2c_Write(I2Cx, address, reg, data);
}

static inline void EhalI2c_OUT_Temperature(float data)
{
	Rte_Write_Temperature(data);
}

#endif /* EHALI2C_OUT_H_ */
