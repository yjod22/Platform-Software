/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     InppSwtEvl.h
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

#ifndef INPP_SWT_EVL_H_
#define INPP_SWT_EVL_H_

#include "drv.h"

extern bool bPushButton;

extern uint32 InppSwtEvl_Get_bSwt(void);
extern void InppSwtEvl_Set_bSwt(bool val);

extern void InppSwtEvl_Calc_SwtVal();

#endif /* INPPIFCSWITCH_H_ */
