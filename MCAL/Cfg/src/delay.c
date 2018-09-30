/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     delay.c
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

/*
    기본 delay.
    이 함수는 수행되고 리턴할 때 까지 3 cycle 시간이 걸린다.
    compiler optimization에 영향 받지 않는다.
    system core clock이 변경되면 instruction cache의 prefatch latency가 달라지므로 이 함수의 수행 시간이 달라질 수 있다.
    현재 코드는168MHz용 구성.
*/

void delay_us_10(int us_10)
{
	int i;
	int cycle;
	cycle = 125 * us_10;

	for (i=0;i<cycle;i++)
	{
		asm volatile("NOP");
	}
}
