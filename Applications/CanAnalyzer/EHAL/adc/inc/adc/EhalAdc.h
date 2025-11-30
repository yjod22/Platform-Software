#ifndef EHALADC_H_
#define EHALADC_H_

#include <CanAnalyzer/std_type.h>

extern uint32 EhalAdc_Resultbuffer_au32[1];

void EhalAdc_Init(void);
void EhalAdc_5ms(void);
void EhalAdc_CalcInput(void);

#endif /* EHALADC_H_ */
