#ifndef EHALUSART_IN_H_
#define EHALUSART_IN_H_

#include <EHAL/usart/inc/usart/EhalUsart_CFG.h>

static inline void EhalUsart_IN_Temperature(float* data) { Rte_Read_Temperature(data); }

#endif /* EHALUSART_IN_H_ */
