/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     I2c.h
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

#ifndef I2C_H_
#define I2C_H_

#include "mcal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_i2c.h"

#define DRIVER_I2C_RECEIVER_MODE      1
#define DRIVER_I2C_TRANSMITTER_MODE   0
#define DRIVER_I2C_ACK_ENABLE         1
#define DRIVER_I2C_ACK_DISABLE        0

#define DRIVER_I2C_TIMEOUT		   	  100

extern __IO uint32_t TimmingDelay;

extern int16_t Driver_I2c_Start(I2C_TypeDef* I2Cx, uint8_t address, uint8_t direction, uint8_t ack);
extern void Driver_I2c_WriteData(I2C_TypeDef* I2Cx, uint8_t data);
extern uint8_t Driver_I2c_ReadAck(I2C_TypeDef* I2Cx);
extern uint8_t Driver_I2c_ReadNack(I2C_TypeDef* I2Cx); 

extern void Driver_I2c_ReadMulti(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t* data, uint16_t count);
extern uint8_t Driver_I2c_Read(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg);
extern void Driver_I2c_Write(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t data);
extern uint8_t Driver_I2c_Stop(I2C_TypeDef* I2Cx);
#endif /* I2C_H_ */
