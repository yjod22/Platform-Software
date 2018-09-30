/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     timer.h
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

#ifndef TIMER_H_
#define TIMER_H_


#include "led.h"
#include "mcal.h"

#define TIMER_PRESCALER_FREQ        1000000   // timer 입력 클력 1MHz
#define PWM_FREQ					(1000/60) // PWM 반복 주기 60ms = 1/60kHz
#define PWM_FREQ_BLDC				(1000/4)  // PWM 반복 주기 4ms = (1000/4)Hz		
#define TASK_2ms				    (1000/2)
#define TASK_20ms					(1000/20)
#define PWM_WIDTH                   (TIMER_PRESCALER_FREQ / PWM_FREQ)
#define PWM_WIDTH_BLDC				(TIMER_PRESCALER_FREQ / PWM_FREQ_BLDC)
//#define DUTY_IDLE                 (PWM_WIDTH / 100)     // 1% duty
#define DUTY_IDLE                   10     // 10us duty
#define DUTY_IDLE_DCMotor			PWM_WIDTH	   // 100% duty
#define DUTY_IDLE_BLDC				(PWM_WIDTH_BLDC/4) // 1ms duty (25% duty)

void TIMER2_Init(void);
void TIMER3_Init(void);
void TIMER5_Init(void);
void TIMER6_Init(void);
void TIMER7_Init(void);
#endif /* TIMER_H_ */



