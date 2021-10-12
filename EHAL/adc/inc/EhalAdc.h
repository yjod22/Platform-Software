/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalAdc.h
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
* Version:     16.0
* Author/Date: JSO / 2018-09-30
* Change:      Redefine the architecture
*******************************************************************************
* Version:     15.0
* Author/Date: JSO / 2018-09-30
* Change:      Define the objects in the header
*******************************************************************************
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#ifndef EHALADC_H_
#define EHALADC_H_

#include "std_type.h"

extern uint32 EhalAdc_Resultbuffer_au32[1];

void EhalAdc_Init(void);
void EhalAdc_5ms(void);
void EhalAdc_CalcInput(void);

#endif /* EHALADC_H_ */
