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
    �⺻ delay.
    �� �Լ��� ����ǰ� ������ �� ���� 3 cycle �ð��� �ɸ���.
    compiler optimization�� ���� ���� �ʴ´�.
    system core clock�� ����Ǹ� instruction cache�� prefatch latency�� �޶����Ƿ� �� �Լ��� ���� �ð��� �޶��� �� �ִ�.
    ���� �ڵ��168MHz�� ����.
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
