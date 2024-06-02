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

static inline void EhalI2c_OUT_InitRcc(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C3, ENABLE);
}


static inline void EhalI2c_OUT_InitGpio(void)
{
	GPIO_InitTypeDef GPIO_InitStructure_SCL;
	GPIO_InitTypeDef GPIO_InitStructure_SDA;

	// GPIO AF config for I2C3
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_I2C3);

	/* Configure IC2 as alternate function*/
	GPIO_InitStructure_SCL.GPIO_Pin   = GPIO_Pin_8;
	GPIO_InitStructure_SCL.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure_SCL.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure_SCL.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure_SCL.GPIO_Speed = GPIO_Speed_25MHz;

	/* Configure the GPIO for SCL*/
	GPIO_Init(GPIOA, &GPIO_InitStructure_SCL);

	// GPIO AF config for I2C3
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_I2C3);

	/* Configure IC2 as alternate function*/
	GPIO_InitStructure_SDA.GPIO_Pin   = GPIO_Pin_9;
	GPIO_InitStructure_SDA.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure_SDA.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure_SDA.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure_SDA.GPIO_Speed = GPIO_Speed_25MHz;

	/* Configure the GPIO for SDA*/
	GPIO_Init(GPIOC, &GPIO_InitStructure_SDA);
}

static inline void EhalI2c_OUT_InitI2c(void)
{
	I2C_InitTypeDef I2C_InitStruct;

	/* Set values */
	I2C_InitStruct.I2C_ClockSpeed = 400000;
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStruct.I2C_OwnAddress1 = 0x00;
	I2C_InitStruct.I2C_Ack = I2C_Ack_Disable;
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;

	/* Disable I2C first */
	I2C_Cmd(I2C3, DISABLE);

	/* Configure the I2C3 */
	I2C_Init(I2C3, &I2C_InitStruct);

	/* Enable I2C */
	I2C_Cmd(I2C3, ENABLE);
}

static inline void EhalI2c_OUT_I2c_Write(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t data)
{
	Driver_I2c_Write(I2Cx, address, reg, data);
}

static inline void EhalI2c_OUT_Temperature(float data)
{
	Rte_Write_Temperature(data);
}

#endif /* EHALI2C_OUT_H_ */
