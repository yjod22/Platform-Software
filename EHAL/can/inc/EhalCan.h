/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalCan.h
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

#ifndef EHALCAN_H_
#define EHALCAN_H_

#include "std_type.h"

extern void EhalCan_Init(void);
extern void EhalCan_SendMessage(void);

#endif /* EHALCAN_H_ */
