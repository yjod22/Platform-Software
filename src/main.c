/*
*******************************************************************************
*                                                                             *
*			     Copyright (c)				      *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     main.c
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     16.0
* Author/Date: JSO / 2018-09-30
* Change:      Redefine the architecture
*******************************************************************************
* Version:     15.0
* Author/Date: JSO / 2018-09-30
* Change:      Declare I2c_Position in the I2cPosition.h file
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#include <stdio.h>
#include "stm32f4xx.h"
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

#include  <ucos_ii.h>
#include  <cpu.h>
#include  <lib_def.h>
#include  <lib_mem.h>
#include  <lib_str.h>
#include  <os_cpu.h>
#include  <app_cfg.h>

uint32 	temp[1];
uint32 	taskFlags;  // semafore register, can also be any other data type that fits your flags (1ul --> uint32_t or larger!)
uint32 	cntLedDelay;
uint32 	cntEXTI;
bool 	bPushButton;

#define HANDLE_MY_INTERRUPT_STUFF    (1ul<<0) // Define a flag for interrupt things.
#define  TASK_STK_SIZE                 512

static	OS_STK AppTaskStartStk[APP_CFG_TASK_START_STK_SIZE];
static  OS_STK	Task1_Stk[TASK_STK_SIZE];

static  void  AppTaskStart(void *p_arg);
void   Task1(void *data);

int main()
{
	CPU_INT08U  os_err;

	/* Init uC/OS-II. */
   	OSInit();                                               

	/* Create the start task. */
	os_err = OSTaskCreate((void (*)(void *)) AppTaskStart,  
                             (void          * ) 0,
                             (OS_STK        * )&AppTaskStartStk[APP_CFG_TASK_START_STK_SIZE - 1],
                             //(INT8U           ) APP_TASK_START_PRIO
                             (INT8U           ) 7
                             );

	OSTaskNameSet(7, (CPU_INT08U *)"Start Task", &os_err);

	OSStart();
	return (0);
}


/*
*********************************************************************************************************
*                                          STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Arguments   : p_arg   is the argument passed to 'AppTaskStart()' by 'OSTaskCreate()'.
*
* Returns     : none
*
* Notes       : 1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                  used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static  void  AppTaskStart (void *p_arg)
{
	CPU_INT08U  os_err;
	CPU_INT32U  r0;
	CPU_INT32U  r1;
	CPU_INT32U  r2;
	CPU_INT32U  r3;
	CPU_INT32U  r4;
	CPU_INT32U  r5;
	CPU_INT32U  r6;
	CPU_INT32U  r7;
	CPU_INT32U  r8;
	CPU_INT32U  r9;
	CPU_INT32U  r10;
	CPU_INT32U  r11;
	CPU_INT32U  r12;
	CPU_INT32U  cpu_clk_freq;
	CPU_INT32U  cnts;
	(void) p_arg;
	
	/* Initialize local variables. */
	r0  =  0u;
	r1  =  1u;
	r2  =  2u;
	r3  =  3u;
	r4  =  4u;
	r5  =  5u;
	r6  =  6u;
	r7  =  7u;
	r8  =  8u;
	r9  =  9u;
	r10 = 10u;
	r11 = 11u;
	r12 = 12u;

	/* Initialize the uC/CPU services */
	CPU_Init();                                                 
	
	RCC_ClocksTypeDef RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);
	
	/* Determine SysTick reference freq. */
	cpu_clk_freq = RCC_Clocks.HCLK_Frequency ;		
	
	/* Determine nbr SysTick increments. */
	#if (OS_VERSION >= 30000u)
		cnts  = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;       
	#else
		cnts  = cpu_clk_freq / (CPU_INT32U)OS_TICKS_PER_SEC;
	#endif
	
	/* Initialize the SysTick. */
	OS_CPU_SysTickInit(cnts);            							

	 /* Determine CPU capacity */
	#if (OS_TASK_STAT_EN > 0)
		OSStatInit();                                              
	#endif

	/* initialization */
	LED_Init();
	LLIO_Init(115200);
	TIMER2_Init();
	TIMER3_Init();
	TIMER5_Init();
	GPIO_Init_All();
	EXTI_Init_All();
	DMA2_Init();
	ADC1_Init();
	EHAL_ADC_Init();
	I2C3_Init();
	I2cPosition_Init();
	TIMER6_Init(); //2ms task
	TIMER7_Init(); //20ms task

    	LED_G_OFF();
    	LED_R_OFF();

    	os_err = OSTaskCreate(Task1,"20ms",&Task1_Stk[TASK_STK_SIZE - 1],5);
    	OSTaskNameSet(5, (CPU_INT08U *)"20ms", &os_err);

	/* Task body, always written as an infinite loop.       */
	while (DEF_TRUE) {                                          
		/* Check task context. */
		if ((r0  !=  0u) ||                                     
		    (r1  !=  1u) ||
		    (r2  !=  2u) ||
		    (r3  !=  3u) ||
		    (r4  !=  4u) ||
		    (r5  !=  5u) ||
		    (r6  !=  6u) ||
		    (r7  !=  7u) ||
		    (r8  !=  8u) ||
		    (r9  !=  9u) ||
		    (r10 != 10u) ||
		    (r11 != 11u) ||
		    (r12 != 12u)) {
		}
		/* Wait 10ms */
		OSTimeDlyHMSM(0, 0, 0, 10);                         
	}
}

void Task1(void *data)
{
	while(1)
	{
		/* Main function control period: 20ms*/
		EHAL_ProcMain();
		DRV_Inpp_ProcMain();
		DRV_Outp_ProcMain();

		OSTaskSuspend(5);
	}
}


