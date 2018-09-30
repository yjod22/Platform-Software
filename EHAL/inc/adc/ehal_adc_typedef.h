/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ehal_adc_typedef.h
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
* Change:      Initial version
*******************************************************************************
*/

#ifndef EHAL_ADC_TYPEDEF_H_
#define EHAL_ADC_TYPEDEF_H_


typedef struct {
   uint32 sum;
   uint8  num;
   uint8  num_max;
   uint8  idx;
   bool   sFiltOn;
} EHAL_Batt_FIR_t;


typedef struct {
   EHAL_Batt_FIR_t 	*battFilter_s;
   real32      		factor;
   uint32      		*result_p;
   uint32      		*data_p;
   const uint8 		*num_p;
   uint8       		num_limit;
} EHAL_Batt_Dscr_t;


#endif /* EHAL_ADC_TYPEDEF_H_ */
