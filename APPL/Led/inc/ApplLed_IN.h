#ifndef APPLLED_IN_H_
#define APPLLED_IN_H_

#include "ApplLed_CFG.h"

static inline void ApplLed_IN_Temperature(float* data) { Rte_Read_Temperature(data); }

static inline void ApplLed_IN_PsplyMode(uint8* data) { Rte_Read_PsplyMode(data); }

#endif /* APPLLED_IN_H_ */
