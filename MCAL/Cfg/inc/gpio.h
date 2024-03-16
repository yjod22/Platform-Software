/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     gpio.h
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     2016b02
* Author/Date: Junseok Oh / 2021-10-12
* Change:      Apply AUTOSAR Architecture
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f4xx.h"
#include "mcal.h"

/* 
***DC motor drive ******************************************************
Port A. Pin 5
Timer 2. Channel 1
**********************************************************************
*/
#define GPIOA_5_INIT(X)                                             \
        do {                                                        \
            GPIO_InitTypeDef GPIO_InitStructure;                    \
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);   \
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_TIM2); \
            GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5;             \
            GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;           \
            GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;           \
            GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          \
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;       \
            GPIO_Init(GPIOA, &GPIO_InitStructure);                  \
        } while (0)

/*
***ADC for check Vtg source status**************************************
Port A. Pin 3
ADC1 Channel3
**********************************************************************
*/

#define GPIOA_3_INIT(X)      									 \
		do{															 \
			GPIO_InitTypeDef GPIO_InitStructure; 					 \
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	 \
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; 				 \
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 			 \
			GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 		 \
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			 \
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 		 \
			GPIO_Init(GPIOA, &GPIO_InitStructure); 					 \
	    } while(0)

/* 
***Ultrasonic wave sensor Trigger siganal***********************************
Port B. Pin 1
Timer 3. Channel 1
**********************************************************************
*/

#define GPIOB_1_INIT(X)                                             \
		do {														\
			GPIO_InitTypeDef GPIO_InitStructure;					\
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);   \
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_TIM3); \
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1; 			\
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;			\
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;		\
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			\
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		\
			GPIO_Init(GPIOB, &GPIO_InitStructure);					\
		} while (0)

/* 
***Ultrasonic wave sensor Echo signal**************************************
Port A. Pin 0
Timer 5. Channel 1
**********************************************************************
*/

#define GPIOA_0_INIT(X)                                                \
		do {														   \
			GPIO_InitTypeDef GPIO_InitStructure;					   \
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	   \
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM5);    \
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0; 			   \
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;			   \
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;		   \
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			   \
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		   \
			GPIO_Init(GPIOA, &GPIO_InitStructure);					   \
		} while (0)

/* 
***DC Motor Bit setting#0************************************************
Port E. Pin 0

**********************************************************************
*/

#define GPIOE_0_INIT(X)                                                 \
        do {                                                            \
            GPIO_InitTypeDef GPIO_InitStructure;                        \
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);       \
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);      \
            GPIO_PinAFConfig(GPIOE, GPIO_PinSource0, GPIO_AF_CAN1);     \
            GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;                 \
            GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;              \
            GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;           \
            GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              \
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           \
            GPIO_Init(GPIOE, &GPIO_InitStructure);                      \
        } while (0)
/* 
***DC Motor Bit setting#1************************************************
Port E. Pin 1

**********************************************************************
*/
#define GPIOE_1_INIT(X)                                                \
		do {												     	   \
			GPIO_InitTypeDef GPIO_InitStructure;			           \
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);	   \
			GPIO_PinAFConfig(GPIOE, GPIO_PinSource1, GPIO_AF_CAN2);    \
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1; 			   \
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;			   \
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;		   \
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			   \
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		   \
			GPIO_Init(GPIOE, &GPIO_InitStructure);					   \
			GPIO_ResetBits(GPIOE,GPIO_Pin_1); 												 \
		} while (0)



#define GPIOE_0_OFF(X)            GPIO_ResetBits(GPIOE,GPIO_Pin_0)
#define GPIOE_0_ON(X)             GPIO_SetBits(GPIOE,GPIO_Pin_0)
//#define LED_X_IS_ON(X)          !(LED_##X##_PORT->ODR & LED_##X##_PIN)
//#define LED_X_TOGGLE(X)         LED_##X##_PORT->ODR ^= LED_##X##_PIN



/* 
***MPU6050 Drive SCL setting************************************************
Port A. Pin 8

**********************************************************************
*/

#define GPIOA_8_INIT(X)                                                 \
        do {                                                            \
            GPIO_InitTypeDef GPIO_InitStructure;                        \
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);       \
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_I2C3);     \
            GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;                 \
            GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;              \
            GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;           \
            GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;              \
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;           \
            GPIO_Init(GPIOA, &GPIO_InitStructure);                      \
        } while (0)

		
/* 
***MPU6050 Drive SDA setting************************************************
Port C. Pin 9

**********************************************************************
*/

#define GPIOC_9_INIT(X)                                                 \
		do {															\
			GPIO_InitTypeDef GPIO_InitStructure;						\
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);		\
			GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_I2C3); 	\
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9; 				\
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;				\
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;			\
			GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;				\
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;			\
			GPIO_Init(GPIOC, &GPIO_InitStructure);						\
		} while (0)

/*
***CAN_RX setting************************************************
Port A. Pin 11

**********************************************************************
*/

#define GPIOA_11_INIT(X)                                                 \
        do {                                                            \
            GPIO_InitTypeDef GPIO_InitStructure;                        \
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);       \
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_CAN1);     \
            GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11;                 \
            GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;              \
            GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;           \
            GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              \
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;           \
            GPIO_Init(GPIOA, &GPIO_InitStructure);                      \
        } while (0)

/*
***CAN_TX setting************************************************
Port A. Pin 12

**********************************************************************
*/

#define GPIOA_12_INIT(X)                                                 \
        do {                                                            \
            GPIO_InitTypeDef GPIO_InitStructure;                        \
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);       \
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource12, GPIO_AF_CAN1);     \
            GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_12;                 \
            GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;              \
            GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;           \
            GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              \
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;           \
            GPIO_Init(GPIOA, &GPIO_InitStructure);                      \
        } while (0)

/*
***LED Red setting************************************************
Port A. Pin 15
**********************************************************************
*/

#define LED_R_INIT(X)                                                           \
        do {                                                                    \
            GPIO_InitTypeDef GPIO_InitStructure;                                \
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);                   \
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_CAN1);            \
            GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;                      \
            GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;                      \
            GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;                   \
            GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                      \
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                   \
            GPIO_Init(GPIOA, &GPIO_InitStructure);                     \
        } while (0)


/*
***LED Green setting************************************************
Port B. Pin 4
**********************************************************************
*/

#define LED_G_INIT(X)                                                           \
        do {                                                                    \
            GPIO_InitTypeDef GPIO_InitStructure;                                \
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);                   \
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_CAN1);             \
            GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_4;                      \
            GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;                      \
            GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;                   \
            GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                      \
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                   \
            GPIO_Init(GPIOB, &GPIO_InitStructure);                     \
        } while (0)

void GPIO_Init_All(void);

#endif /* GPIO_H_ */
