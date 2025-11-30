#ifndef DRIVERI2C_H_
#define DRIVERI2C_H_

#include "stm32f4xx.h"

#define DRIVER_I2C_RECEIVER_MODE 1
#define DRIVER_I2C_TRANSMITTER_MODE 0
#define DRIVER_I2C_ACK_ENABLE 1
#define DRIVER_I2C_ACK_DISABLE 0

#define DRIVER_I2C_TIMEOUT 2

extern __IO uint32_t TimmingDelay;

extern void Driver_I2c_ReadMulti(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t* data, uint16_t count);
extern uint8_t Driver_I2c_Read(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg);
extern void Driver_I2c_Write(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t data);
#endif /* DRIVERI2C_H_ */
