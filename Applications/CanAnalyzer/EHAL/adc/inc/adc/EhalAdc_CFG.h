#ifndef EHALADC_CFG_H_
#define EHALADC_CFG_H_

#include <CanAnalyzer/std_type.h>
#include <RTE/Rte_EhalAdc.h>

#include "stm32f4xx_adc.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#define ADC_FACTOR (40 / 3)
#define ADC_FILT_ON (2)

#endif /* EHALADC_CFG_H_ */
