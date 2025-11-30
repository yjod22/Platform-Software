#ifndef RTE_SWITCH_H_
#define RTE_SWITCH_H_

#include <CanAnalyzer/std_type.h>

extern bool Rte_Switch;

#define Rte_Write_Switch(data) (Rte_Switch = (data))

#endif /* RTE_SWITCH_H_ */
