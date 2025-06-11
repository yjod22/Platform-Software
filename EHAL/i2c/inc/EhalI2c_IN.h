#ifndef EHALI2C_IN_H_
#define EHALI2C_IN_H_

#include "EhalI2c_CFG.h"

static inline void EhalI2c_IN_I2c_Read(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t* data)
{
    *data = Driver_I2c_Read(I2Cx, address, reg);
}

static inline void
EhalI2c_IN_I2c_ReadMulti(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t* data, uint16_t count)
{
    Driver_I2c_ReadMulti(I2Cx, address, reg, data, count);
}

#endif /* EHALI2C_IN_H_ */
