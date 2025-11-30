#ifndef EHALDIO_IN_H_
#define EHALDIO_IN_H_

#include <dio/EhalDio_CFG.h>

static inline void EhalDio_IN_LedRed(bool* data) { Rte_Read_LedRed(data); }

static inline void EhalDio_IN_LedGreen(bool* data) { Rte_Read_LedGreen(data); }

#endif /* EHALDIO_IN_H_ */
