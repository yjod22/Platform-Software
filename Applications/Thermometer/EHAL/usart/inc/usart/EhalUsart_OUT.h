#ifndef EHALDIO_OUT_H_
#define EHALDIO_OUT_H_

#include <EHAL/usart/inc/usart/EhalUsart_CFG.h>

static inline void EhalUsart_OUT_InitRcc(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
}

static inline void EhalUsart_OUT_InitGpio(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // GPIO AF config for UART1
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

    /* Configure USARTx_Tx/USARTx_Rx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    /* Configure the GPIOA*/
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

static inline void EhalUsart_OUT_InitUsart(void)
{
    USART_InitTypeDef USART_InitStructure;

    /* USARTx configuration ------------------------------------------------------*/
    USART_InitStructure.USART_BaudRate = 921600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    /* Configure the USART1 */
    USART_Init(USART1, &USART_InitStructure);

    /* Enable the USART1 */
    USART_Cmd(USART1, ENABLE);
}

static inline void EhalUsart_OUT_SendData(uint16_t data)
{
    USART_SendData(USART1, data);

    /* Wait until the byte has been transmitted */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == FALSE);
}

#endif /* EHALDIO_OUT_H_ */
