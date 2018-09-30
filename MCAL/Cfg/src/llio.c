/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     llio.c
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
//#include <yfuns.h>
#include "llio.h"


#define FEATURE_LLIO_UART


#define RCC_AHB1Periph_GPIO_USART       RCC_AHB1Periph_GPIOA

#define GPIO_USART                      GPIOA

#define GPIO_USART_Rx_Pin               GPIO_Pin_10
#define GPIO_USART_Rx_PinSource         GPIO_PinSource10
#define GPIO_USART_Tx_Pin               GPIO_Pin_9
#define GPIO_USART_Tx_PinSource         GPIO_PinSource9
#define GPIO_AF_USART                   GPIO_AF_USART1

#define RCC_APB2Periph_USART            RCC_APB2Periph_USART1
#define UARTn                           USART1


void LLIO_Init(unsigned long baudrate)
{
#ifdef FEATURE_LLIO_UART
    USART_InitTypeDef USART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable GPIOA clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIO_USART, ENABLE);

    /* Enable UARTn clocks */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART, ENABLE);

    // UART configuration ...

    // GPIO AF config for UART1
    GPIO_PinAFConfig(GPIOA, GPIO_USART_Tx_PinSource, GPIO_AF_USART);
    GPIO_PinAFConfig(GPIOA, GPIO_USART_Rx_PinSource, GPIO_AF_USART);


    /* Configure USARTx_Tx/USARTx_Rx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin   = GPIO_USART_Tx_Pin | GPIO_USART_Rx_Pin;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIO_USART, &GPIO_InitStructure);


    /* USARTx configuration ------------------------------------------------------*/
    USART_InitStructure.USART_BaudRate   = baudrate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits   = USART_StopBits_1;
    USART_InitStructure.USART_Parity     = USART_Parity_No ;
    USART_InitStructure.USART_HardwareFlowControl
                                         = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode       = USART_Mode_Rx | USART_Mode_Tx;

    /* Configure the USARTx */
    USART_Init(UARTn, &USART_InitStructure);

    /* Enable the UARTn */
    USART_Cmd(UARTn, ENABLE);
#endif
}


#ifdef FEATURE_LLIO_UART

#else
#pragma module_name = "?__write"
size_t __write(int handle, const unsigned char * buffer, size_t size)
{
    return 0;
}
size_t __read(int handle, unsigned char * buffer, size_t size)
{
    return 0;
}
#endif


