#ifndef APPLPSPLY_IN_H_
#define APPLPSPLY_IN_H_

#include "ApplPsply_CFG.h"

static inline void ApplPsply_IN_Battery(uint32* data) { Rte_Read_Battery(data); }

static inline void ApplPsply_IN_Switch(bool* data) { Rte_Read_Switch(data); }

#endif /* APPLPSPLY_IN_H_ */
