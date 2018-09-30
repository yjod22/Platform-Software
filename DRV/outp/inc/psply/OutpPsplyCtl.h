/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     OutpPsplyCtl.h
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

#ifndef OUTPPSPLYCTL_H_
#define OUTPPSPLYCTL_H_

#include "drv.h"
#include "InppBattEvl.h"
#include "InppSwtEvl.h"

/***********************************************/
/* Psply control mode                          */
/***********************************************/
#define PSPLY_INIT         (0x00)
#define PSPLY_NONOP        (0x11)
#define PSPLY_OP           (0x22)
#define PSPLY_ACTIVE_OFF   (0x33)
#define PSPLY_ACTIVE_ON    (0x44)

#define BATT_THRESHOLD	(30000)

extern uint8 OutpPsplyCtl_Get_sPsplyMode();
extern bool OutpPsplyCtl_Get_bPsplyOut();
extern void OutpPsplyCtl_Calc_Psply(void);

#endif /* OUTPPSPLYCTL_H_ */
