#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <EHAL/ehal.h>
#include <RTE/Rte.h>
#include <rte/Rte_EhalI2c.h>
#include <Thermometer/std_type.h>
#include <Thermometer/system_macro.h>

#include "FreeRTOS.h"
#include "stm32f4xx.h"
#include "task.h"

#if USE_SEMIHOSTING_ENABLED
extern void initialise_monitor_handles();
#endif
void vInitTaskHandler(void* params);
void v50msTaskHandler(void* params);
void vApplicationIdleHook();
void vApplicationTickHook();

volatile uint32_t TimmingDelay = 0;
BaseType_t xHigherPriorityTaskWoken = pdFALSE;

int main(void)
{
#if USE_SEMIHOSTING_ENABLED
    initialise_monitor_handles();
    printf("Hello world example code by ARM semihosting \n");
#endif

    // Enable cycle counting (CYCCNT) in DWT_CTRL to get time stamp information of events
    DWT->CTRL |= (1 << 0);

    // HSI ON, HSE OFF, PLL OFF, system clock = 16Mhz, cpu_clock = 16Mhz
    RCC_DeInit();
    SystemCoreClockUpdate();

    // Start recording
    SEGGER_SYSVIEW_Conf();
    SEGGER_SYSVIEW_Start();

    // Create tasks
    xTaskCreate(vInitTaskHandler, "Init_Task", 500, NULL, 3, &xInitTaskHandle);
    xTaskCreate(v50msTaskHandler, "50ms_Task", 500, NULL, 1, &x50msTaskHandle);
    vTaskStartScheduler();

    for (;;)
        ;
}

void vInitTaskHandler(void* params)
{
    /* initialization */
    Rte_Init();
    EhalI2c_Init();
    EhalUsart_Init();

    // Suspend the task
    vTaskSuspend(xInitTaskHandle);
}

void v50msTaskHandler(void* params)
{
    while (1)
    {
        // Execute main functionalities
        EHAL_Main_InputProcess();
        EHAL_Main_OutputProcess();

        // Suspend the task
        vTaskSuspend(x50msTaskHandle);
    }
}

void vApplicationIdleHook()
{
    // Send the cpu to normal sleep
    __WFI();
}

void vApplicationTickHook()
{
    if (TimmingDelay != 0)
    {
        TimmingDelay--;
    }
}
