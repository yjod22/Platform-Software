/**
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

#include "led.h"
#include "llio.h"
#include "timer.h"
#include "adc.h"
#include "dma.h"
#include "delay.h"
#include "gpio.h"
#include "inpp.h"
#include "outp.h"
#include "OutpMotorCtl.h"
#include "EHAL_distance.h"
#include "EHAL_motor.h"
#include "EHAL_adc.h"
#include "i2c.h"
#include "I2cPosition.h"
#include "exti.h"

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
	GPIO_Init_All();
#if DC_MOTOR_USED
	TIMER2_Init(); // DC motor drive
#endif
#if ULTRASONIC_WAVE_SENSOR_USED
	TIMER3_Init(); // Ultrasonic wave sensor trigger signal
	TIMER5_Init(); // Ultrasonic wave sensor echo signal
#endif
#if USART_USED
	LLIO_Init(115200); // USART setting
#endif
#if MPU6050_USED
	I2C3_Init();
	I2cPosition_Init();
#endif
#if PUSH_BUTTON_PE0_USED
	EXTI_Init_All();
#endif
	DMA2_Init();
	ADC1_Init();
	EHAL_ADC_Init();

	LED_Init();
	LED_G_OFF();
	LED_R_OFF();

	// Suspend the task
	vTaskSuspend(xInitTaskHandle);
}

void v5msTaskHandler(void *params)
{
#if configUSER_DEFINED_SYSTICK_HANDLER
	while(1)
	{
		/* Load ADC results from buffer every 5ms */
		EHAL_ADC_5ms();

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
		EHAL_ADC_5ms();
	}
#endif
}

void v50msTaskHandler(void *params)
{
#if configUSER_DEFINED_SYSTICK_HANDLER
	while(1)
	{
		// Execute main functionalities
		EHAL_ProcMain();
		DRV_Inpp_ProcMain();
		DRV_Outp_ProcMain();

		// Suspend the task
		vTaskSuspend(x50msTaskHandle);
	}

#else
	const TickType_t xFrequency = 50;
	while(1)
	{
		vTaskDelayUntil(&x50msTaskLastWakeTime, xFrequency);

		// Execute main functionalities
		EHAL_ProcMain();
		DRV_Inpp_ProcMain();
		DRV_Outp_ProcMain();
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

