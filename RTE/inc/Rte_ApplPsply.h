#ifndef RTE_APPLPSPLY_H_
#define RTE_APPLPSPLY_H_

#include "std_type.h"

extern uint32 Rte_Battery;
extern bool Rte_Switch;
extern uint8 Rte_PsplyMode;
extern bool Rte_PsplyOut;

#define Rte_Read_Battery(data) (*(data) = Rte_Battery)
#define Rte_Read_Switch(data) (*(data) = Rte_Switch)

#define Rte_Write_PsplyMode(data) (Rte_PsplyMode = (data))
#define Rte_Write_PsplyOut(data) (Rte_PsplyOut = (data))

#endif /* RTE_APPLPSPLY_H_ */
