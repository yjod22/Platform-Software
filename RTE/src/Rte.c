/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     Rte.c
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

#include "std_type.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "Rte_EhalCan.h"

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

float Rte_Temperature;
uint32 Rte_Battery;
bool Rte_Switch;
uint8 Rte_PsplyMode;
bool Rte_PsplyOut;
bool Rte_LedRed;
bool Rte_LedGreen;
uint8 Rte_CanRxMsg[8];
QueueHandle_t Rte_CanQueue;

/*
 * IMPLEMENTATION OF GLOBAL FUNCTIONS
 * */

void Rte_Init()
{
	Rte_Temperature = 0.0;
	Rte_Battery = 0;
	Rte_Switch = false;
	Rte_PsplyMode = 0;
	Rte_PsplyOut = false;
	Rte_LedRed = false;
	Rte_LedGreen = false;
	for(int i=0; i<8; i++)
	{
		Rte_CanRxMsg[i] = 0;
	}
	Rte_CanQueue = xQueueCreate(QUEUE_LENGTH, QUEUE_ITEM_SIZE);
}

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */
