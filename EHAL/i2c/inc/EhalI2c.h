/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalI2c.h
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
* Version:     16.0
* Author/Date: JSO / 2018-09-30
* Change:      Redefine the architecture
*******************************************************************************
* Version:     15.0
* Author/Date: JSO / 2018-09-30
* Change:      Move out the typedef into the typedef-header
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#ifndef EHALI2C_H_
#define EHALI2C_H_

#include "std_type.h"

extern void EhalI2c_Init(void);
extern void EhalI2c_Read_Accelerometer(void);
extern void EhalI2c_Read_Temperature(void);
extern void EhalI2c_Read_Gyroscope(void);
extern void EhalI2c_Read_All(void);

#endif /* EHALI2C_H_ */
