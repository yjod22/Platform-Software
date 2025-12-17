#ifndef EHAL_H_
#define EHAL_H_

#include <i2c/EhalI2c.h>
#include <Thermometer/std_type.h>
#include <usart/EhalUsart.h>

extern void EHAL_Main_InputProcess(void);
extern void EHAL_Main_OutputProcess(void);

#endif /* EHAL_H_ */
