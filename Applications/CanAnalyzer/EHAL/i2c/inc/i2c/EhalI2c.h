#ifndef EHALI2C_H_
#define EHALI2C_H_

#include <CanAnalyzer/std_type.h>

extern void EhalI2c_Init(void);
extern void EhalI2c_Read_Accelerometer(void);
extern void EhalI2c_Read_Temperature(void);
extern void EhalI2c_Read_Gyroscope(void);
extern void EhalI2c_Read_All(void);

#endif /* EHALI2C_H_ */
