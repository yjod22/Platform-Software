/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     i2c.h
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#ifndef I2C_H_
#define I2C_H_


#include "mcal.h"


/* Default I2C clock */
//#ifndef MPU6050_I2C_CLOCK
//#define MPU6050_I2C_CLOCK	400000
//#endif


void I2C3_Init(void);

#endif /* I2C_H_ */
