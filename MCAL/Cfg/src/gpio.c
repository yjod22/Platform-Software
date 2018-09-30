/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     gpio.c
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

#include "stm32f4xx.h"
#include "gpio.h"
#include "delay.h"


void GPIO_Init_All(void)
{	
	GPIOA_0_INIT();
	GPIOA_3_INIT();
	GPIOB_1_INIT();
	GPIOA_5_INIT();
	GPIOE_0_INIT(); //Push button port
	GPIOE_1_INIT();
	GPIOA_8_INIT(); //MPU6050 drive (SCL)
	GPIOC_9_INIT(); //MPU6050 drive (SDA)
}

