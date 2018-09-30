/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     ehal_adc.c
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
#include "ehal_adc.h"

uint32 EHAL_Get_uBatt()
{
	uint32 u;
	u = EHAL_uBatt;

	return u;
}

void EHAL_ADC_Init(void)
{
	EHAL_ADC_FIR_Clear(&EHAL_uBattDscr);
}

void EHAL_ADC_2ms(void)
{
	EHAL_ADC_FIR_Input(&EHAL_uBattDscr, Adc_Resultbuffer[0]);
}

void EHAL_ADC_CalcInput(void)
{
	EHAL_ADC_FIR_Calc(&EHAL_uBattDscr);
}

void EHAL_ADC_FIR_Clear(const EHAL_Batt_Dscr_t *p)
{
   uint8 i8=p->num_limit;
   EHAL_Batt_FIR_t *pBattFilter_s=p->battFilter_s;

   i8=10;
   pBattFilter_s->num=0;
   pBattFilter_s->sum=0;
   pBattFilter_s->idx=0;
   pBattFilter_s->num_max=i8;
   pBattFilter_s->sFiltOn = 2;

   return;
}

void EHAL_ADC_FIR_Input(const EHAL_Batt_Dscr_t *p,uint16 in)
{
   EHAL_Batt_FIR_t *pBattFilter_s=p->battFilter_s;
   uint i;

   /* Filter is not active */
   if (pBattFilter_s->sFiltOn < ADC_FILT_ON)
   {
	   i=0;
       p->data_p[i] = in;
       pBattFilter_s->sum += in;
       i++;
       pBattFilter_s->idx=i;
       pBattFilter_s->num=i;
   }

   /* Filter is active */
   else
   {
      i=pBattFilter_s->idx;

      /* Start to fill the buffer*/
     if (pBattFilter_s->num < pBattFilter_s->num_max)
     {
      p->data_p[i] = in;
      pBattFilter_s->sum += in;

      i++;
      pBattFilter_s->idx = i;
      pBattFilter_s->num =i;
      }

      /* update the oldest value in the buffer  */
      else
      {
         if (i>=pBattFilter_s->num_max)
         {
            i=0;
         }
         pBattFilter_s->sum += in - p->data_p[i];
         p->data_p[i] = in;

         i++;
         pBattFilter_s->idx = i;
     }
   }

   return;
}

void EHAL_ADC_FIR_Calc(const EHAL_Batt_Dscr_t *p)
{

	volatile EHAL_Batt_FIR_t *pBattFilter_s=p->battFilter_s;
	uint i;
	sint32 s;
	real32 f1;

	i = pBattFilter_s->num;

    if (i >0)
    {
	  s=(sint32)pBattFilter_s->sum;

	  f1=((((real32)s * p->factor) / (real32)((sint)i)) + 0.5f);

	  *p->result_p=(uint32) f1;
    }

   return;
}
