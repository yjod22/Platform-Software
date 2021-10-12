/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalI2c_CFG.h
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

#ifndef EHALI2C_CFG_H_
#define EHALI2C_CFG_H_

#include "Rte_EhalI2c.h"
#include "stm32f4xx.h"
#include "std_type.h"
/*
 * DEFINITION OF GLOBAL MACROS/DEFINES
 * */
#define	MPU6050_I2C		I2C3

/* Default I2C address */
#define MPU6050_I2C_ADDR			0xD0

/* MPU6050 registers */
#define MPU6050_GYRO_CONFIG			0x1B
#define MPU6050_ACCEL_CONFIG		0x1C

#define MPU6050_ACCEL_XOUT_H		0x3B
#define MPU6050_ACCEL_XOUT_L		0x3C
#define MPU6050_ACCEL_YOUT_H		0x3D
#define MPU6050_ACCEL_YOUT_L		0x3E
#define MPU6050_ACCEL_ZOUT_H		0x3F
#define MPU6050_ACCEL_ZOUT_L		0x40
#define MPU6050_TEMP_OUT_H			0x41
#define MPU6050_TEMP_OUT_L			0x42
#define MPU6050_GYRO_XOUT_H			0x43
#define MPU6050_GYRO_XOUT_L			0x44
#define MPU6050_GYRO_YOUT_H			0x45
#define MPU6050_GYRO_YOUT_L			0x46
#define MPU6050_GYRO_ZOUT_H			0x47
#define MPU6050_GYRO_ZOUT_L			0x48

#define MPU6050_PWR_MGMT_1			0x6B


#endif /* EHALI2C_CFG_H_ */
