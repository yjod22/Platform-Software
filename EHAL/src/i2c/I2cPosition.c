/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     I2cPosition.c
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
* Change:      Delete the temporary variables
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#include "I2cPosition.h"

float I2cPosition_Get_uTemp()
{
	float u;
	u = I2c_Position_ptr->Temperature;

	return u;
}

void I2cPosition_Init(void)
{
	uint8_t temp;
	
	/* Format I2C address */
	I2c_Position_ptr->Address = MPU6050_I2C_ADDR;
	
	/* Wakeup MPU6050 */
	Driver_I2c_Write(MPU6050_I2C, I2c_Position_ptr->Address, MPU6050_PWR_MGMT_1, 0x00);

	/* Config accelerometer */
	temp = Driver_I2c_Read(MPU6050_I2C, I2c_Position_ptr->Address, MPU6050_ACCEL_CONFIG);
	temp = (temp & 0xE7) | (uint8_t)0x00 << 3;
	Driver_I2c_Write(MPU6050_I2C, I2c_Position_ptr->Address, MPU6050_ACCEL_CONFIG, temp);
	
	/* Config gyroscope */
	temp = Driver_I2c_Read(MPU6050_I2C, I2c_Position_ptr->Address, MPU6050_GYRO_CONFIG);
	temp = (temp & 0xE7) | (uint8_t)0x00 << 3;
	Driver_I2c_Write(MPU6050_I2C, I2c_Position_ptr->Address, MPU6050_GYRO_CONFIG, temp);
}

void I2cPosition_Read_Accelerometer(void)
{
	uint8_t data[6];
	Driver_I2c_ReadMulti(MPU6050_I2C,I2c_Position_ptr->Address,MPU6050_ACCEL_XOUT_H,data,6);

	/* Format accelerometer data */
	I2c_Position_ptr->Accelerometer_X = (int16_t)(data[0] << 8 | data[1]);	
	I2c_Position_ptr->Accelerometer_Y = (int16_t)(data[2] << 8 | data[3]);
	I2c_Position_ptr->Accelerometer_Z = (int16_t)(data[4] << 8 | data[5]);
}

void I2cPosition_Read_Temperature(void)
{	
	uint8_t data[2];
	int16_t temp;
	Driver_I2c_ReadMulti(MPU6050_I2C,I2c_Position_ptr->Address,MPU6050_TEMP_OUT_H,data,2);
	
	/* Format temperature */
	temp = (data[0] << 8 | data[1]);
	I2c_Position_ptr->Temperature = (float)((int16_t)temp / (float)340 + (float)36.53);
}

void I2cPosition_Read_Gyroscope(void)
{	
	uint8_t data[6];
	Driver_I2c_ReadMulti(MPU6050_I2C,I2c_Position_ptr->Address,MPU6050_GYRO_XOUT_H,data,6);
	
	/* Format gyroscope data */
	I2c_Position_ptr->Gyroscope_X = (int16_t)(data[0] << 8 | data[1]);
	I2c_Position_ptr->Gyroscope_Y = (int16_t)(data[2] << 8 | data[3]);
	I2c_Position_ptr->Gyroscope_Z = (int16_t)(data[4] << 8 | data[5]);
}

void I2cPosition_Read_All(void)
{	
	uint8_t data[14];
	int16_t temp;
	Driver_I2c_ReadMulti(MPU6050_I2C,I2c_Position_ptr->Address,MPU6050_ACCEL_XOUT_H,data,14);
	
	/* Format accelerometer data */
	I2c_Position_ptr->Accelerometer_X = (int16_t)(data[0] << 8 | data[1]);	
	I2c_Position_ptr->Accelerometer_Y = (int16_t)(data[2] << 8 | data[3]);
	I2c_Position_ptr->Accelerometer_Z = (int16_t)(data[4] << 8 | data[5]);

	/* Format temperature */
	temp = (data[6] << 8 | data[7]);
	I2c_Position_ptr->Temperature = (float)((float)((int16_t)temp) / (float)340.0 + (float)36.53);
	
	/* Format gyroscope data */
	I2c_Position_ptr->Gyroscope_X = (int16_t)(data[8] << 8 | data[9]);
	I2c_Position_ptr->Gyroscope_Y = (int16_t)(data[10] << 8 | data[11]);
	I2c_Position_ptr->Gyroscope_Z = (int16_t)(data[12] << 8 | data[13]);
}

