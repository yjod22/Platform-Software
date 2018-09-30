/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     i2c.c
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

#include <stdio.h>
#include <stddef.h>
#include "stm32f4xx.h"
#include "i2c.h"


void I2C3_Init(void)
{
	I2C_InitTypeDef I2C_InitStruct;

	/* Enable clock */
	RCC->APB1ENR |= RCC_APB1ENR_I2C3EN;
	
	/* Check clock, set the lowest clock your devices support on the same I2C but */
	//if (clockSpeed < TM_I2C_INT_Clocks[2]) {
		//TM_I2C_INT_Clocks[2] = clockSpeed;
	//}
	
	/* Set values */
	I2C_InitStruct.I2C_ClockSpeed = 400000;
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStruct.I2C_OwnAddress1 = 0x00;
	I2C_InitStruct.I2C_Ack = I2C_Ack_Disable;
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
	
	
	/* Disable I2C first */
	I2C3->CR1 &= ~I2C_CR1_PE;
	
	/* Initialize I2C */
	I2C_Init(I2C3, &I2C_InitStruct);
	
	/* Enable I2C */
	I2C3->CR1 |= I2C_CR1_PE;

}

