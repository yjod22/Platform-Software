/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalI2c.c
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
* Change:      Delete the temporary variables
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#include <EhalI2c_CFG.h>
#include <EhalI2c_IN.h>
#include <EhalI2c_OUT.h>

/*
 * DEFINITION OF LOCAL MACROS/DEFINES
 * */

/*
 * DEFINITION OF LOCAL TYPES
 * */
typedef struct {
	/* Private */
	uint8_t Address_u8;         /*!< I2C address of device. Only for private use */
	float Gyro_Mult_f;         /*!< Gyroscope corrector from raw data to "degrees/s". Only for private use */
	float Acce_Mult_f;         /*!< Accelerometer corrector from raw data to "g". Only for private use */
	/* Public */
	int16_t Accelerometer_X_i16; /*!< Accelerometer value X axis */
	int16_t Accelerometer_Y_i16; /*!< Accelerometer value Y axis */
	int16_t Accelerometer_Z_i16; /*!< Accelerometer value Z axis */
	int16_t Gyroscope_X_i16;     /*!< Gyroscope value X axis */
	int16_t Gyroscope_Y_i16;     /*!< Gyroscope value Y axis */
	int16_t Gyroscope_Z_i16;     /*!< Gyroscope value Z axis */
	float Temperature_f;       /*!< Temperature in degrees */
} EhalI2c_Position_tst;

/*
 * DEFINITION OF LOCAL VARIABLES
 * */
static EhalI2c_Position_tst EhalI2c_Position_st;

/*
 * DEFINITION OF LOCAL CONSTANTS
 * */

/*
 * DECLARATION OF LOCAL FUNCTIONS
 * */

/*
 * DEFINITION OF GLOBAL VARIABLES
 * */

/*
 * IMPLEMENTATION OF GLOBAL FUNCTIONS
 * */

void EhalI2c_Init(void)
{
	uint8_t temp;
	
	/* Format I2C address */
	EhalI2c_Position_st.Address_u8 = MPU6050_I2C_ADDR;
	
	/* Wakeup MPU6050 */
	EhalI2c_OUT_I2c_Write(MPU6050_I2C, EhalI2c_Position_st.Address_u8, MPU6050_PWR_MGMT_1, 0x00);

	/* Config accelerometer */
	EhalI2c_IN_I2c_Read(MPU6050_I2C, EhalI2c_Position_st.Address_u8, MPU6050_ACCEL_CONFIG, &temp);
	temp = (temp & 0xE7) | (uint8_t)0x00 << 3;
	EhalI2c_OUT_I2c_Write(MPU6050_I2C, EhalI2c_Position_st.Address_u8, MPU6050_ACCEL_CONFIG, temp);
	
	/* Config gyroscope */
	EhalI2c_IN_I2c_Read(MPU6050_I2C, EhalI2c_Position_st.Address_u8, MPU6050_GYRO_CONFIG, &temp);
	temp = (temp & 0xE7) | (uint8_t)0x00 << 3;
	EhalI2c_OUT_I2c_Write(MPU6050_I2C, EhalI2c_Position_st.Address_u8, MPU6050_GYRO_CONFIG, temp);
}

void EhalI2c_Read_Accelerometer(void)
{
	uint8_t data[6];
	EhalI2c_IN_I2c_ReadMulti(MPU6050_I2C, EhalI2c_Position_st.Address_u8, MPU6050_ACCEL_XOUT_H, data, 6);

	/* Format accelerometer data */
	EhalI2c_Position_st.Accelerometer_X_i16 = (int16_t)(data[0] << 8 | data[1]);
	EhalI2c_Position_st.Accelerometer_Y_i16 = (int16_t)(data[2] << 8 | data[3]);
	EhalI2c_Position_st.Accelerometer_Z_i16 = (int16_t)(data[4] << 8 | data[5]);
}

void EhalI2c_Read_Temperature(void)
{	
	uint8_t data[2];
	int16_t temp;
	EhalI2c_IN_I2c_ReadMulti(MPU6050_I2C, EhalI2c_Position_st.Address_u8, MPU6050_TEMP_OUT_H, data, 2);
	
	/* Format temperature */
	temp = (data[0] << 8 | data[1]);
	EhalI2c_Position_st.Temperature_f = (float)((int16_t)temp / (float)340 + (float)36.53);

	EhalI2c_OUT_Temperature(EhalI2c_Position_st.Temperature_f);
}

void EhalI2c_Read_Gyroscope(void)
{	
	uint8_t data[6];
	EhalI2c_IN_I2c_ReadMulti(MPU6050_I2C, EhalI2c_Position_st.Address_u8, MPU6050_GYRO_XOUT_H, data, 6);
	
	/* Format gyroscope data */
	EhalI2c_Position_st.Gyroscope_X_i16 = (int16_t)(data[0] << 8 | data[1]);
	EhalI2c_Position_st.Gyroscope_Y_i16 = (int16_t)(data[2] << 8 | data[3]);
	EhalI2c_Position_st.Gyroscope_Z_i16 = (int16_t)(data[4] << 8 | data[5]);
}

void EhalI2c_Read_All(void)
{	
	uint8_t data[14];
	int16_t temp;
	EhalI2c_IN_I2c_ReadMulti(MPU6050_I2C, EhalI2c_Position_st.Address_u8, MPU6050_ACCEL_XOUT_H, data, 14);
	
	/* Format accelerometer data */
	EhalI2c_Position_st.Accelerometer_X_i16 = (int16_t)(data[0] << 8 | data[1]);
	EhalI2c_Position_st.Accelerometer_Y_i16 = (int16_t)(data[2] << 8 | data[3]);
	EhalI2c_Position_st.Accelerometer_Z_i16 = (int16_t)(data[4] << 8 | data[5]);

	/* Format temperature */
	temp = (data[6] << 8 | data[7]);
	EhalI2c_Position_st.Temperature_f = (float)((float)((int16_t)temp) / (float)340.0 + (float)36.53);
	
	/* Format gyroscope data */
	EhalI2c_Position_st.Gyroscope_X_i16 = (int16_t)(data[8] << 8 | data[9]);
	EhalI2c_Position_st.Gyroscope_Y_i16 = (int16_t)(data[10] << 8 | data[11]);
	EhalI2c_Position_st.Gyroscope_Z_i16 = (int16_t)(data[12] << 8 | data[13]);
}

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */
