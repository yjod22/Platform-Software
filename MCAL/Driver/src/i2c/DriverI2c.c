/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     I2c.c
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
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#include "DriverI2c.h"

//static uint32_t Driver_I2c_Timeout;
int16_t Driver_I2c_Start(I2C_TypeDef* I2Cx, uint8_t address, uint8_t direction, uint8_t ack)
{
	/* Generate I2C start pulse */
	I2Cx->CR1 |= I2C_CR1_START;
	
	/* Wait till I2C is busy */
	//Driver_I2c_Timeout = DRIVER_I2C_TIMEOUT;
	TimmingDelay = DRIVER_I2C_TIMEOUT;
	while (!(I2Cx->SR1 & I2C_SR1_SB)) {
		/*
		if (--Driver_I2c_Timeout == 0x00) {
			return 1;
		}
		*/
		if(TimmingDelay == 0x00)
		{
			return 1;
		}
	}

	/* Enable ack if we select it */
	if (ack) {
		I2Cx->CR1 |= I2C_CR1_ACK;
	}

	
	/* Send write/read bit */
	if (direction == DRIVER_I2C_TRANSMITTER_MODE) {
		/* Send address with zero last bit */
		I2Cx->DR = address & ~I2C_OAR1_ADD0;
		
		/* Wait till finished */
		//Driver_I2c_Timeout = DRIVER_I2C_TIMEOUT;
		TimmingDelay = DRIVER_I2C_TIMEOUT;
		while (!(I2Cx->SR1 & I2C_SR1_ADDR)) {
			if (TimmingDelay == 0x00) {
				return 1;
			}
		}
	}
	if (direction == DRIVER_I2C_RECEIVER_MODE) {
		/* Send address with 1 last bit */
		I2Cx->DR = address | I2C_OAR1_ADD0;
		
		/* Wait till finished */
		TimmingDelay = DRIVER_I2C_TIMEOUT;
		while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED)) {
			if (TimmingDelay == 0x00) {
				return 1;
			}
		}
	}
	
	/* Read status register to clear ADDR flag */
	I2Cx->SR2;
	
	/* Return 0, everything ok */
	return 0;
}

void Driver_I2c_WriteData(I2C_TypeDef* I2Cx, uint8_t data) {
	/* Wait till I2C is not busy anymore */
	TimmingDelay = DRIVER_I2C_TIMEOUT;
	while (!(I2Cx->SR1 & I2C_SR1_TXE) && TimmingDelay) {
		/* Do nothing */
	}
	
	/* Send I2C data */
	I2Cx->DR = data;
}


uint8_t Driver_I2c_ReadAck(I2C_TypeDef* I2Cx)
{
	uint8_t data;
	
	/* Enable ACK */
	I2Cx->CR1 |= I2C_CR1_ACK;
	
	/* Wait till not received */
	TimmingDelay = DRIVER_I2C_TIMEOUT;
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED)) {
		if (TimmingDelay == 0x00) {
			return 1;
		}
	}
	
	/* Read data */
	data = I2Cx->DR;
	
	/* Return data */
	return data;
}

uint8_t Driver_I2c_ReadNack(I2C_TypeDef* I2Cx) 
{
	uint8_t data;
	
	/* Disable ACK */
	I2Cx->CR1 &= ~I2C_CR1_ACK;
	
	/* Generate stop */
	I2Cx->CR1 |= I2C_CR1_STOP;
	
	/* Wait till received */
	TimmingDelay = DRIVER_I2C_TIMEOUT;
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED)) {
		if (TimmingDelay == 0x00) {
			return 1;
		}
	}

	/* Read data */
	data = I2Cx->DR;
	
	/* Return data */
	return data;
}


void Driver_I2c_ReadMulti(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t* data, uint16_t count)
{
	uint8_t i;
	Driver_I2c_Start(I2Cx, address, DRIVER_I2C_TRANSMITTER_MODE, DRIVER_I2C_ACK_ENABLE);
	Driver_I2c_WriteData(I2Cx, reg);
	Driver_I2c_Start(I2Cx, address, DRIVER_I2C_RECEIVER_MODE, DRIVER_I2C_ACK_ENABLE);
	
	for (i = 0; i < count; i++) {
		if (i == (count - 1)) {
			/* Last byte */
			data[i] = Driver_I2c_ReadNack(I2Cx);
		} else {
			data[i] = Driver_I2c_ReadAck(I2Cx);
		}
	}
}

uint8_t Driver_I2c_Read(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg) {
	uint8_t received_data;
	Driver_I2c_Start(I2Cx, address, DRIVER_I2C_TRANSMITTER_MODE, DRIVER_I2C_ACK_DISABLE);
	Driver_I2c_WriteData(I2Cx, reg);
	Driver_I2c_Stop(I2Cx);
	Driver_I2c_Start(I2Cx, address, DRIVER_I2C_RECEIVER_MODE, DRIVER_I2C_ACK_DISABLE);
	received_data = Driver_I2c_ReadNack(I2Cx);
	return received_data;
}

void Driver_I2c_Write(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t data)
{
	Driver_I2c_Start(I2Cx, address, DRIVER_I2C_TRANSMITTER_MODE, DRIVER_I2C_ACK_DISABLE);
	Driver_I2c_WriteData(I2Cx, reg);
	Driver_I2c_WriteData(I2Cx, data);
	Driver_I2c_Stop(I2Cx);
}

uint8_t Driver_I2c_Stop(I2C_TypeDef* I2Cx) {
	/* Wait till transmitter not empty */
	TimmingDelay = DRIVER_I2C_TIMEOUT;
	while (((!(I2Cx->SR1 & I2C_SR1_TXE)) || (!(I2Cx->SR1 & I2C_SR1_BTF)))) {
		if (TimmingDelay == 0x00) {
			return 1;
		}
	}
	
	/* Generate stop */
	I2Cx->CR1 |= I2C_CR1_STOP;
	
	/* Return 0, everything ok */
	return 0;
}


