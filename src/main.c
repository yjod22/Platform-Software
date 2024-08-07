/**
  ******************************************************************************
  * @file    main.c
  * @author  M.Sc Junseok Oh
  * @version 2016b01
  * @date    17-April-2020
  * @brief   Implement main functionalities based on FreeRTOS.
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "system_macro.h"
#include "std_type.h"
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Rte.h"
#include "Rte_Switch.h"
#include "Rte_EhalCan.h"
#include "appl.h"
#include "ehal.h"

#if USE_SEMIHOSTING_ENABLED
extern void initialise_monitor_handles();
#endif
void vInitTaskHandler(void *params);
void v5msTaskHandler(void *params);
void v50msTaskHandler(void *params);
#if configUSE_TICK_HOOK
void vApplicationTickHook();
#endif
#if PUSH_BUTTON_PE0_USED
void Delay_Ms(uint32_t parDelayMs);
void Delay_Ms_FromISR(uint32_t parDelayMs);
#endif

TaskHandle_t x5msTaskHandle = NULL;
TaskHandle_t x50msTaskHandle = NULL;
TaskHandle_t xInitTaskHandle = NULL;

uint8_t buttonStatus = NOT_PRESSED;
char charUserMsg[250];
volatile uint32_t TimmingDelay;
#if PUSH_BUTTON_PE0_USED
volatile bool 	bPushButton;
#endif
#if configUSER_DEFINED_SYSTICK_HANDLER
uint32_t ulCntInitTask;
uint32_t ulCnt5msTask;
uint32_t ulCnt50msTask;
#else
TickType_t x5msTaskLastWakeTime;
TickType_t x50msTaskLastWakeTime;
#endif
Rte_CanRx_tst canRx;
BaseType_t xHigherPriorityTaskWoken = pdFALSE;

int main(void)
{
#if USE_SEMIHOSTING_ENABLED
	initialise_monitor_handles();
	printf("Hello world example code by ARM semihosting \n");
#endif

	// Enable cycle counting (CYCCNT) in DWT_CTRL to get time stamp information of events
	DWT->CTRL |= (1<<0);

	// HSI ON, HSE OFF, PLL OFF, system clock = 16Mhz, cpu_clock = 16Mhz
	RCC_DeInit();
	SystemCoreClockUpdate();

	// Start recording
	SEGGER_SYSVIEW_Conf();
	SEGGER_SYSVIEW_Start();

#if configUSER_DEFINED_SYSTICK_HANDLER
	// Initialize task relevant variables
	ulCntInitTask = 1;
	ulCnt5msTask = configCOUNTER_5MS_TASK;
	ulCnt50msTask = configCOUNTER_50MS_TASK;
#endif
	canRx.msgCounter = 0;

	xTaskCreate(vInitTaskHandler,
				"Init_Task",
				500,
				NULL,
				3,
				&xInitTaskHandle);

	xTaskCreate(v5msTaskHandler,
				"5ms_Task",
				500,
				NULL,
				2,
				&x5msTaskHandle);

	xTaskCreate(v50msTaskHandler,
				"50ms_Task",
				500,
				NULL,
				1,
				&x50msTaskHandle);

	vTaskStartScheduler();

	for(;;);
}

void vInitTaskHandler(void *params)
{
	/* initialization */
	Rte_Init();
#if CAN_TX_USED || CAN_RX_USED
	EhalCan_Init();
#endif
#if USART_USED
	EhalUsart_Init();
#endif
#if MPU6050_USED
	EhalI2c_Init();
#endif
#if PUSH_BUTTON_PE0_USED
	EhalExti_Init();
#endif
	EhalAdc_Init();
	EhalDio_Init();

	// Suspend the task
	vTaskSuspend(xInitTaskHandle);
}

void v5msTaskHandler(void *params)
{
#if configUSER_DEFINED_SYSTICK_HANDLER
	while(1)
	{
		/* Load ADC results from buffer every 5ms */
		EhalAdc_5ms();

		// Suspend the task
		vTaskSuspend(x5msTaskHandle);
	}

#else
	const TickType_t xFrequency = 5;
	x5msTaskLastWakeTime = xTaskGetTickCount();
	x50msTaskLastWakeTime = x5msTaskLastWakeTime;
	while(1)
	{
		vTaskDelayUntil(&x5msTaskLastWakeTime, xFrequency);

		/* Load ADC results from buffer every 5ms */
		EhalAdc_5ms();
	}
#endif
}

void v50msTaskHandler(void *params)
{
#if configUSER_DEFINED_SYSTICK_HANDLER
	while(1)
	{
		// Execute main functionalities
		EHAL_Main_InputProcess();
		APPL_Main_Process();
		EHAL_Main_OutputProcess();

		// Suspend the task
		vTaskSuspend(x50msTaskHandle);
	}

#else
	const TickType_t xFrequency = 50;
	while(1)
	{
		vTaskDelayUntil(&x50msTaskLastWakeTime, xFrequency);

		// Execute main functionalities
		EHAL_Main_InputProcess();
		APPL_Main_Process();
		EHAL_Main_OutputProcess();
	}
#endif
}

#if configUSE_IDLE_HOOK
void vApplicationIdleHook()
{
	// Send the cpu to normal sleep
	__WFI();
}
#endif

#if configUSE_TICK_HOOK
void vApplicationTickHook()
{
	if(TimmingDelay != 0)
	{
		TimmingDelay--;
	}
}
#endif

#if PUSH_BUTTON_PE0_USED
void EXTI0_IRQHandler(void)
{
  	traceISR_ENTER();
	// 1. Clear the interrupt pending bit of the EXTI line
	EXTI_ClearITPendingBit(EXTI_Line0);

	// 2. Toggle the status variable
	Delay_Ms(2);
	bPushButton ^= 1;
	Rte_Write_Switch(bPushButton);
	traceISR_EXIT();
}

void Delay_Ms(uint32_t parDelayMs)
{
	// Convert Mili Seconds to Tick
	uint32_t delayTick = (parDelayMs / 1000) * configTICK_RATE_HZ;

	// Stamp tick value from FreeRTOS
	uint32_t stampTick = xTaskGetTickCount();

	// Loop until it reaches the target time
	while(xTaskGetTickCount() - stampTick < delayTick);
}

void Delay_Ms_FromISR(uint32_t parDelayMs)
{
	// Convert Mili Seconds to Tick
	uint32_t delayTick = (parDelayMs / 1000) * configTICK_RATE_HZ;

	// Stamp tick value from FreeRTOS
	uint32_t stampTick = xTaskGetTickCountFromISR();

	// Loop until it reaches the target time
	while(xTaskGetTickCountFromISR() - stampTick < delayTick);
}
#endif

#if CAN_RX_USED
void CAN1_RX0_IRQHandler(void)
{
  	traceISR_ENTER();
  	CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);
  	CAN_Receive(CAN1, CAN_FIFO0, &(canRx.canRxMsg));
  	canRx.msgCounter++;
  	Rte_Write_CanRxMsg(canRx, xHigherPriorityTaskWoken);
  	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	traceISR_EXIT();
}
#endif

