#include <CanAnalyzer/system_macro.h>

#include "ehal.h"
#include "stm32f4xx.h"

void EHAL_Main_InputProcess(void) { EhalI2c_Read_Temperature(); }
void EHAL_Main_OutputProcess(void) { EhalUsart_SendTemperature(); }
