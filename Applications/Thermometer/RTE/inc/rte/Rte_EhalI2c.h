#ifndef RTE_EHALI2C_H_
#define RTE_EHALI2C_H_

#include <Thermometer/std_type.h>

extern float Rte_Temperature;

#define Rte_Write_Temperature(data) (Rte_Temperature = (data))
#define Rte_Read_Temperature(data) (*(data) = Rte_Temperature)

#endif /* RTE_EHALI2C_H_ */
