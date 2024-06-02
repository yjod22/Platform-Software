/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalDio.c
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
*/

#include "EhalDio_CFG.h"
#include "EhalDio_IN.h"
#include "EhalDio_OUT.h"
/*
 * DEFINITION OF LOCAL MACROS/DEFINES
 * */

/*
 * DEFINITION OF LOCAL TYPES
 * */

/*
 * DEFINITION OF LOCAL VARIABLES
 * */

static bool EhalDio_LedRed_b = false;
static bool EhalDio_LedGreen_b = false;

/*
 * DEFINITION OF LOCAL CONSTANTS
 * */

/*
 * DECLARATION OF LOCAL FUNCTIONS
 * */

/*
 * DEFINITION OF GLOBAL VARIABLES
 * */

/*
 * IMPLEMENTATION OF GLOBAL FUNCTIONS
 * */

void EhalDio_Init(void)
{
	EhalDio_OUT_InitRcc();
	EhalDio_OUT_InitGpio();

	EhalDio_OUT_LedRed_Off();
	EhalDio_OUT_LedGreen_Off();
}

void EhalDio_CalcOutput(void)
{
	EhalDio_IN_LedRed(&EhalDio_LedRed_b);
	EhalDio_IN_LedGreen(&EhalDio_LedGreen_b);

	if(EhalDio_LedRed_b != false)
	{
		EhalDio_OUT_LedRed_On();
	}
	else
	{
		EhalDio_OUT_LedRed_Off();
	}

	if(EhalDio_LedGreen_b != false)
	{
		EhalDio_OUT_LedGreen_On();
	}
	else
	{
		EhalDio_OUT_LedGreen_Off();
	}
}

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */
