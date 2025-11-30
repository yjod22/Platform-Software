#ifndef RTE_EHALADC_H_
#define RTE_EHALADC_H_

#include <CanAnalyzer/std_type.h>

extern uint32 Rte_Battery;

#define Rte_Write_Battery(data) (Rte_Battery = (data))

#endif /* RTE_EHALADC_H_ */
