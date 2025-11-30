#ifndef EHALUSART_IN_H_
#define EHALUSART_IN_H_

#include <EHAL/usart/inc/usart/EhalUsart_CFG.h>

static inline void EhalUsart_IN_Temperature(float* data) { Rte_Read_Temperature(data); }

static inline bool EhalUsart_IN_Can(Rte_CanRx_tst* data) { return Rte_Read_CanRxMsg(data); }

#endif /* EHALUSART_IN_H_ */
