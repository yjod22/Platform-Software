#include <CanAnalyzer/system_macro.h>

#include "ehal.h"
#include "stm32f4xx.h"

void EHAL_Main_OutputProcess(void)
{
    EhalUsart_SendCan();
}
