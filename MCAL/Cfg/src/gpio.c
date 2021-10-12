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
#include "system_macro.h"
#include "gpio.h"
#include "delay.h"


void GPIO_Init_All(void)
{	
#if DC_MOTOR_USED
	GPIOA_5_INIT(); //DC motor drive
	GPIOE_1_INIT(); //DC Motor Bit setting#1
#endif
#if ULTRASONIC_WAVE_SENSOR_USED
	GPIOA_0_INIT(); //Ultrasonic wave sensor Echo signal
	GPIOB_1_INIT(); //Ultrasonic wave sensor Trigger signal
#endif
#if MPU6050_USED
	GPIOA_8_INIT(); //MPU6050 drive (SCL)
	GPIOC_9_INIT(); //MPU6050 drive (SDA)
#endif
#if	PUSH_BUTTON_PE0_USED
	GPIOE_0_INIT(); //Push button port
#endif
	GPIOA_3_INIT(); //ADC for check Vtg source status

	LED_R_INIT();
	LED_G_INIT();
}

