/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ehal.h
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
* Version:     14.0
* Author/Date: JSO / 2018-09-29
* Change:      Initial version
*******************************************************************************
*/

#ifndef EHAL_H_
#define EHAL_H_

#include "std_type.h"
#include "EhalAdc.h"
#include "EhalI2c.h"
#include "EhalDio.h"
#include "EhalUsart.h"
#include "EhalCan.h"

extern void EHAL_Main_InputProcess(void);
extern void EHAL_Main_OutputProcess(void);


#endif /* EHAL_H_ */
