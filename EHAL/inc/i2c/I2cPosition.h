/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     I2cPosition.h
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
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

#ifndef EHAL_I2C_H_
#define EHAL_I2C_H_

#include "ehal.h"
#include "I2cPosition_typedef.h"
#include "DriverI2c.h"
#include "stm32f4xx.h"


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


/**
 * @brief  Parameters for accelerometer range
 */
typedef enum {
	I2c_Position_Accelerometer_2G = 0x00, /*!< Range is +- 2G */
	I2c_Position_Accelerometer_4G = 0x01, /*!< Range is +- 4G */
	I2c_Position_Accelerometer_8G = 0x02, /*!< Range is +- 8G */
	I2c_Position_Accelerometer_16G = 0x03 /*!< Range is +- 16G */
} I2C_POSITION_ACCELEROMETER_t;

I2C_POSITION_t I2c_Position;
#define I2c_Position_ptr	((I2C_POSITION_t *)&I2c_Position)

extern float I2cPosition_Get_uTemp(void);
extern void I2cPosition_Init(void);
extern void I2cPosition_Read_Accelerometer(void);
extern void I2cPosition_Read_Temperature(void);
extern void I2cPosition_Read_Gyroscope(void);
extern void I2cPosition_Read_All(void);


#endif /* EHAL_I2C_H_ */
