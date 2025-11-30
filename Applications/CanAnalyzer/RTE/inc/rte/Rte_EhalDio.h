#ifndef RTE_EHALDIO_H_
#define RTE_EHALDIO_H_

#include <CanAnalyzer/std_type.h>

extern bool Rte_LedRed;
extern bool Rte_LedGreen;

#define Rte_Read_LedRed(data) (*(data) = Rte_LedRed)
#define Rte_Read_LedGreen(data) (*(data) = Rte_LedGreen)

#endif /* RTE_EHALDIO_H_ */
