#ifndef EHALCAN_CFG_H_
#define EHALCAN_CFG_H_

#include "Rte_EhalCan.h"
#include "std_type.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#define EHAL_CAN_TIMEOUT 2

extern __IO uint32_t TimmingDelay;

#endif /* EHALCAN_CFG_H_ */
