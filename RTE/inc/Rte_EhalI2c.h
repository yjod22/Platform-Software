#ifndef RTE_EHALI2C_H_
#define RTE_EHALI2C_H_

#include "std_type.h"

extern float Rte_Temperature;

#define Rte_Write_Temperature(data) (Rte_Temperature = (data))

#endif /* RTE_EHALI2C_H_ */
