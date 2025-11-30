#ifndef EHALUSART_H_
#define EHALUSART_H_

#include <CanAnalyzer/std_type.h>

extern void EhalUsart_Init(void);
extern void EhalUsart_SendTemperature(void);
extern void EhalUsart_SendCan(void);

#endif /* EHALUSART_H_ */
