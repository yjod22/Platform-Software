/*
 * EhalExti.c
 *
 *  Created on: 2024. 3. 31.
 *      Author: yjod2
 */

#include "EhalExti_CFG.h"
#include "EhalExti_OUT.h"
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

void EhalExti_Init(void)
{
	EhalExti_OUT_InitRcc();
	EhalExti_OUT_InitGpio();
	EhalExti_OUT_InitExti();
	EhalExti_OUT_InitNvic();
}

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */
