/*
 * EhalExti_OUT.h
 *
 *  Created on: 2024. 4. 13.
 *      Author: yjod2
 */

#ifndef EHALEXTI_OUT_H_
#define EHALEXTI_OUT_H_

#include "EhalExti_CFG.h"

static inline void EhalExti_OUT_InitRcc()
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
}

static inline void EhalExti_OUT_InitGpio()
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

static inline void EhalExti_OUT_InitExti()
{
    /* Tell system that you will use PE0 for EXTI_Line0 */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource0);

    EXTI_InitTypeDef EXTI_InitStruct;

    EXTI_InitStruct.EXTI_Line = EXTI_Line0;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;

    EXTI_Init(&EXTI_InitStruct);
}

static inline void EhalExti_OUT_InitNvic()
{
    NVIC_InitTypeDef NVIC_InitStructure;

    /* Enable the Externel Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

#endif /* EHALEXTI_OUT_H_ */
