#include <CanAnalyzer/system_macro.h>

#include "ehal.h"
#include "stm32f4xx.h"

void EHAL_Main_InputProcess(void)
{
    EhalAdc_CalcInput();
#if MPU6050_USED
    EhalI2c_Read_Accelerometer();
    EhalI2c_Read_Temperature();
    EhalI2c_Read_Gyroscope();
#endif
}

void EHAL_Main_OutputProcess(void)
{
    EhalDio_CalcOutput();
#if USART_USED
#    if CAN_ANALYZER_MODE
    EhalUsart_SendCan();
#    else
    EhalUsart_SendTemperature();
#    endif
#endif
#if CAN_TX_USED
    EhalCan_SendMessage();
#endif
}
