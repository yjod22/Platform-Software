/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ehal_adc.h
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
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

#ifndef EHAL_ADC_H_
#define EHAL_ADC_H_

#include "ehal.h"
#include "ehal_adc_typedef.h"

#define ADC_FACTOR (40/3)
#define ADC_FILT_ON (2)
uint32 Adc_Resultbuffer[1];
EHAL_Batt_FIR_t EHAL_uBattFlt;
uint32 EHAL_uBatt;
static uint32 EHAL_uBattDat[10];
const uint8 EHAL_numAdcFir_C;

static const EHAL_Batt_Dscr_t EHAL_uBattDscr=
{
   &EHAL_uBattFlt,
   ADC_FACTOR,
   &EHAL_uBatt,
   &EHAL_uBattDat[0],
   &EHAL_numAdcFir_C,
   sizeof(EHAL_uBattDat)/sizeof(EHAL_uBattDat[0]),
};

uint32 EHAL_Get_uBatt(void);
void EHAL_ADC_Init(void);
void EHAL_ADC_2ms(void);
void EHAL_ADC_CalcInput(void);

void EHAL_ADC_FIR_Clear(const EHAL_Batt_Dscr_t *p);
void EHAL_ADC_FIR_Input(const EHAL_Batt_Dscr_t *p, uint16 in);
void EHAL_ADC_FIR_Calc(const EHAL_Batt_Dscr_t *p);


#endif /* EHAL_ADC_H_ */
