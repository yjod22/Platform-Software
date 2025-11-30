#ifndef EHALDIO_OUT_H_
#define EHALDIO_OUT_H_

#include <dio/EhalDio_CFG.h>

static inline void EhalDio_OUT_InitRcc(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
}

static inline void EhalDio_OUT_InitGpio(void)
{
    GPIO_InitTypeDef GPIO_InitStructure_LedRed;
    GPIO_InitTypeDef GPIO_InitStructure_LedGreen;

    // GPIO AF config for CAN1?
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_CAN1);

    GPIO_InitStructure_LedRed.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure_LedRed.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure_LedRed.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure_LedRed.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure_LedRed.GPIO_Speed = GPIO_Speed_50MHz;

    // GPIO AF config for CAN1?
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_CAN1);

    GPIO_InitStructure_LedGreen.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure_LedGreen.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure_LedGreen.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure_LedGreen.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure_LedGreen.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOA, &GPIO_InitStructure_LedRed);
    GPIO_Init(GPIOB, &GPIO_InitStructure_LedGreen);
}

static inline void EhalDio_OUT_LedRed_On(void) { GPIO_ResetBits(GPIOA, GPIO_Pin_15); }

static inline void EhalDio_OUT_LedRed_Off(void) { GPIO_SetBits(GPIOA, GPIO_Pin_15); }

static inline void EhalDio_OUT_LedGreen_On(void) { GPIO_ResetBits(GPIOB, GPIO_Pin_4); }

static inline void EhalDio_OUT_LedGreen_Off(void) { GPIO_SetBits(GPIOB, GPIO_Pin_4); }

#endif /* EHALDIO_OUT_H_ */
