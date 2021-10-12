/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ApplPsply_CFG.h
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


#ifndef APPLPSPLY_CFG_H_
#define APPLPSPLY_CFG_H_

#include "Rte_ApplPsply.h"

/***********************************************/
/* Psply control mode                          */
/***********************************************/
#define APPLPSPLY_PSPLY_INIT         (0x00)
#define APPLPSPLY_PSPLY_NONOP        (0x11)
#define APPLPSPLY_PSPLY_OP           (0x22)
#define APPLPSPLY_PSPLY_ACTIVE_OFF   (0x33)
#define APPLPSPLY_PSPLY_ACTIVE_ON    (0x44)

#define BATT_THRESHOLD	(30000)

#endif /* APPLPSPLY_CFG_H_ */
