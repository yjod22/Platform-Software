/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalCan.c
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     2016b04
* Author/Date: Junseok Oh / 2024-02-28
* Change:      Enable Can driver
*******************************************************************************
*/

#include "EhalCan_CFG.h"
#include "EhalCan_IN.h"
#include "EhalCan_OUT.h"

/*
 * DEFINITION OF LOCAL MACROS/DEFINES
 * */

/*
 * DEFINITION OF LOCAL TYPES
 * */

/*
 * DEFINITION OF LOCAL VARIABLES
 * */

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

void EhalCan_SendMessage(void)
{
	CanTxMsg txMsg;
	EhalCan_IN_TxMessage(&txMsg);
	EhalCan_OUT_TxMessage(&txMsg);
}

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */
