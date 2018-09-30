/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Template/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    18-January-2013
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/*
*
*  Filename:     stm32f4xx_it.c
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "std_type.h"

#include "delay.h"
#include "OutpMotorCtl.h"
#include "EHAL_distance.h"
#include "EHAL_motor.h"
#include "ehal_adc.h"
#include "ehal.h"
#include "Inpp.h"
#include "ucos_ii.h"


/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint16_t IC2Value = 0;
__IO uint16_t DutyCycle = 0;
__IO uint32_t Frequency = 0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
__IO uint32_t TimmingDelay;


void SysTick_Handler(void)
{
/*  TimingDelay_Decrement(); */
    
	if(TimmingDelay != 0)
	{
		TimmingDelay--;
	}
	else
	{
		/* Do nothing */
	}
}

void OSTickISR(void)
{
	OSIntEnter();
	OSTimeTick();
	OSIntExit();

}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f40xx.s/startup_stm32f427x.s).                         */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

void EXTI0_IRQHandler(void)
{
  uint32 prim;
  prim = __get_PRIMASK();

  __disable_irq();

  static uint32 lastSec = 0;
  //uint32 curSec = cntSysTick;
  uint32 curSec = OSTime;
  
  /* Make sure that interrupt flag is set */
  if (EXTI_GetITStatus(EXTI_Line0) != RESET) 
  {
      /* Bounce would be ignored */
      if(curSec - lastSec > 20)
      {
          /* Do your stuff when PE0 is changed */
          //cntEXTI++;
    	  if (bPushButton != false)
		  {
    		  bPushButton = false;
		  }
    	  else
    	  {
    		  bPushButton = true;
    	  }
          
      }
    /* Clear interrupt flag */
    EXTI_ClearITPendingBit(EXTI_Line0);
  }

  lastSec = curSec;

  
  if(!prim)
  {
  	__enable_irq();
  }
    
}

void TIM5_IRQHandler(void)
{

  uint32 prim;
  prim = __get_PRIMASK();

  __disable_irq();
  
  RCC_ClocksTypeDef RCC_Clocks;
  RCC_GetClocksFreq(&RCC_Clocks);

  /* Clear TIM4 Capture compare interrupt pending bit */
  TIM_ClearITPendingBit(TIM5, TIM_IT_CC1);

  /* Get the Input Capture value */
  IC2Value = TIM_GetCapture1(TIM5);

  if(!prim)
  {
  	__enable_irq();
  }

}

void TIM6_DAC_IRQHandler(void)
{
  uint32 prim;
  prim = __get_PRIMASK();

  __disable_irq();
  
  RCC_ClocksTypeDef RCC_Clocks;
  RCC_GetClocksFreq(&RCC_Clocks);

  /* Clear TIM6 Capture compare interrupt pending bit */
  TIM_ClearITPendingBit(TIM6, TIM_IT_Update);

  /* Load ADC results from buffer every 2ms */
  EHAL_ADC_2ms();

  if(!prim)
  {
	 __enable_irq();
  }

}


void TIM7_IRQHandler(void)
{
  uint32 prim;
  prim = __get_PRIMASK();

  __disable_irq();

  RCC_ClocksTypeDef RCC_Clocks;
  RCC_GetClocksFreq(&RCC_Clocks);

  /* Clear TIM7 Capture compare interrupt pending bit */
  TIM_ClearITPendingBit(TIM7, TIM_IT_Update);

  cntLedDelay++;
  //taskFlags |= HANDLE_MY_INTERRUPT_STUFF;  // set the flag
  OSTaskResume(5);


  if(!prim)
  {
    __enable_irq();
  }

}



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
