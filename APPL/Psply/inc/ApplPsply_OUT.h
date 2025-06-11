#ifndef APPLPSPLY_OUT_H_
#define APPLPSPLY_OUT_H_

#include "ApplPsply_CFG.h"

static inline void ApplPsply_OUT_PsplyMode(uint8 data) { Rte_Write_PsplyMode(data); }

static inline void ApplPsply_OUT_PsplyOut(bool data) { Rte_Write_PsplyOut(data); }

#endif /* APPLPSPLY_OUT_H_ */
