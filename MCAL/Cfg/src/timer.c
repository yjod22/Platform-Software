/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     timer.c
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

#include <stdio.h>
#include <stddef.h>
#include "stm32f4xx.h"
#include "timer.h"
#include "delay.h"
#include "gpio.h"
#include "llio.h"

void TIMER2_Init(void)
{
    uint16_t PrescalerValue;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    /* TIM2 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		
	/* Compute the prescaler value */
	// timer base counter에 1MHz 입력.
	// TIMER2는 APB1에 연결되어 있다.
	// TIMER input clock은 APBx의 clock divider가 1인 경우 HCLK의 클럭이 그대로 쓰이고,
	//                                        1이 아닌 경우 HCLK의 클럭 /2가 사용된다.
	// 현재 소스 구성에서는 drv/system_stm32f4xx.c 파일의 SetSysClock()함수 내에서 APB1 clock은 HCLK /4로 설정하고 있다.
	SystemCoreClockUpdate();
	PrescalerValue = (uint16_t) (SystemCoreClock / 2 / TIMER_PRESCALER_FREQ) - 1;
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = TIMER_PRESCALER_FREQ / PWM_FREQ_BLDC - 1;   //1khz timer
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;    
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;    
	TIM_OCInitStructure.TIM_Pulse = DUTY_IDLE_BLDC;       // default 25% (1ms)    
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);    
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Disable);

	/* TIM2 enable counter */
	TIM_Cmd(TIM2, ENABLE);
}


void TIMER3_Init(void)
{
    uint16_t PrescalerValue;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    /* TIM3 clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	/* Compute the prescaler value */
	// timer base counter에 1MHz 입력.
	// TIMER3는 APB1에 연결되어 있다.
	// TIMER input clock은 APBx의 clock divider가 1인 경우 HCLK의 클럭이 그대로 쓰이고,
	//                                        1이 아닌 경우 HCLK의 클럭 /2가 사용된다.
	// 현재 소스 구성에서는 drv/system_stm32f4xx.c 파일의 SetSysClock()함수 내에서 APB1 clock은 HCLK /4로 설정하고 있다.
	SystemCoreClockUpdate();
	PrescalerValue = (uint16_t) (SystemCoreClock / 2 / TIMER_PRESCALER_FREQ) - 1;
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = TIMER_PRESCALER_FREQ / PWM_FREQ - 1;   //1khz timer
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;    
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;    
	TIM_OCInitStructure.TIM_Pulse = DUTY_IDLE;       // default 1%    
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);    
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Disable);

	/* TIM3 enable counter */
	TIM_Cmd(TIM3, ENABLE);
}


void TIMER5_Init(void)
{
	/* TIM5 configuration: PWM Input mode ------------------------
           The external signal is connected to TIM5 CH1 pin (PA.00), 
           The Rising edge is used as active edge,
           The TIM5 CCR2 is used to compute the frequency value 
           The TIM5 CCR1 is used to compute the duty cycle value
           ------------------------------------------------------------ */
	uint16_t PrescalerValue;
	TIM_ICInitTypeDef  TIM_ICInitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    /* TIM5 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);

    SystemCoreClockUpdate();
	PrescalerValue = (uint16_t) (SystemCoreClock / 2 / TIMER_PRESCALER_FREQ) - 1;
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = TIMER_PRESCALER_FREQ / PWM_FREQ - 1;   //1khz timer
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);

    TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStructure.TIM_ICFilter = 0x0;
	TIM_PWMIConfig(TIM5, &TIM_ICInitStructure);
	
	/* Select the TIM5 Input Trigger: TI1FP1 */
	TIM_SelectInputTrigger(TIM5, TIM_TS_TI1FP1);
	
	/* Select the slave Mode: Reset Mode */
	TIM_SelectSlaveMode(TIM5, TIM_SlaveMode_Reset);
	TIM_SelectMasterSlaveMode(TIM5,TIM_MasterSlaveMode_Enable);
	
	/* TIM enable counter */
	TIM_Cmd(TIM5, ENABLE);
	
	/* Enable the CC1 Interrupt Request */
	TIM_ITConfig(TIM5, TIM_IT_CC1,ENABLE);
	

    /* Enable the TIM5 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 15;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

}


void TIMER6_Init(void)
{
	/* TIM4 configuration: PWM Input mode ------------------------
           The external signal is connected to TIM4 CH1 pin (PB.06), 
           The Rising edge is used as active edge,
           The TIM4 CCR2 is used to compute the frequency value 
           The TIM4 CCR1 is used to compute the duty cycle value
           ------------------------------------------------------------ */
	uint16_t PrescalerValue;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    /* TIM6 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

    SystemCoreClockUpdate();
	PrescalerValue = (uint16_t) (SystemCoreClock / 2 / TIMER_PRESCALER_FREQ) - 1;
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = TIMER_PRESCALER_FREQ / TASK_2ms - 1;   //1khz timer
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
	
	/* TIM enable counter */
	TIM_Cmd(TIM6, ENABLE);
	
	/* Enable the CC1 Interrupt Request */
	TIM_ITConfig(TIM6, TIM_IT_Update,ENABLE);
	
    /* Enable the TIM6 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM6_DAC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

}


void TIMER7_Init(void)
{
	/* TIM4 configuration: PWM Input mode ------------------------
           The external signal is connected to TIM4 CH1 pin (PB.06), 
           The Rising edge is used as active edge,
           The TIM4 CCR2 is used to compute the frequency value 
           The TIM4 CCR1 is used to compute the duty cycle value
           ------------------------------------------------------------ */
	uint16_t PrescalerValue;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    /* TIM7 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);

    SystemCoreClockUpdate();
	PrescalerValue = (uint16_t) (SystemCoreClock / 2 / TIMER_PRESCALER_FREQ) - 1;
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = TIMER_PRESCALER_FREQ / TASK_20ms - 1;   //1khz timer
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);
	
	/* TIM enable counter */
	TIM_Cmd(TIM7, ENABLE);
	
	/* Enable the CC1 Interrupt Request */
	TIM_ITConfig(TIM7, TIM_IT_Update,ENABLE);

    /* Enable the TIM7 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 10;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

}
