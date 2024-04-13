/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalAdc.c
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
#include "EhalAdc_CFG.h"
#include "EhalAdc_OUT.h"

/*
 * DEFINITION OF LOCAL MACROS/DEFINES
 * */

/*
 * DEFINITION OF LOCAL TYPES
 * */

typedef struct {
   uint32 Sum_u32;
   uint8  Num_u8;
   uint8  NumMax_u8;
   uint8  Idx_u8;
   bool   FiltOn_b;
} EhalAdc_BattFir_tst;


typedef struct {
   EhalAdc_BattFir_tst 	*EhalAdc_BattFir_pst;
   real32      		Factor_r32;
   uint32      		*Result_pu32;
   uint32      		*Data_pu32;
   uint8       		NumLimit_u8;
} EhalAdc_BattDscr_tst;

/*
 * DEFINITION OF LOCAL VARIABLES
 * */

EhalAdc_BattFir_tst EhalAdc_BattFir_st;
uint32 EhalAdc_Batt_u32;
static uint32 EhalAdc_BattDat_au32[10];

static const EhalAdc_BattDscr_tst EhalAdc_BattDscr_st=
{
   &EhalAdc_BattFir_st,
   ADC_FACTOR,
   &EhalAdc_Batt_u32,
   &EhalAdc_BattDat_au32[0],
   sizeof(EhalAdc_BattDat_au32)/sizeof(EhalAdc_BattDat_au32[0]),
};

/*
 * DEFINITION OF LOCAL CONSTANTS
 * */

/*
 * DECLARATION OF LOCAL FUNCTIONS
 * */

static void EhalAdc_FIR_Clear(const EhalAdc_BattDscr_tst *p);
static void EhalAdc_FIR_Input(const EhalAdc_BattDscr_tst *p, uint16 in);
static void EhalAdc_FIR_Calc(const EhalAdc_BattDscr_tst *p);

/*
 * DEFINITION OF GLOBAL VARIABLES
 * */

uint32 EhalAdc_Resultbuffer_au32[1];

/*
 * IMPLEMENTATION OF GLOBAL FUNCTIONS
 * */

void EhalAdc_Init(void)
{
	EhalAdc_OUT_InitRcc();
	EhalAdc_OUT_InitGpio();
	EhalAdc_OUT_InitDma();
	EhalAdc_OUT_InitAdc();
	EhalAdc_FIR_Clear(&EhalAdc_BattDscr_st);
}

void EhalAdc_5ms(void)
{
	EhalAdc_FIR_Input(&EhalAdc_BattDscr_st, EhalAdc_Resultbuffer_au32[0]);
}

void EhalAdc_CalcInput(void)
{
	EhalAdc_FIR_Calc(&EhalAdc_BattDscr_st);
	EhalAdc_OUT_Battery(*(EhalAdc_BattDscr_st.Result_pu32));
}

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */

static void EhalAdc_FIR_Clear(const EhalAdc_BattDscr_tst *p)
{
   EhalAdc_BattFir_tst *BattFir_pst = p->EhalAdc_BattFir_pst;

   BattFir_pst->Sum_u32 = 0;
   BattFir_pst->Num_u8 = 0;
   BattFir_pst->NumMax_u8 = p->NumLimit_u8;
   BattFir_pst->Idx_u8 = 0;
   BattFir_pst->FiltOn_b = ADC_FILT_ON;

   return;
}

static void EhalAdc_FIR_Input(const EhalAdc_BattDscr_tst *p, uint16 in)
{
   EhalAdc_BattFir_tst *BattFir_pst = p->EhalAdc_BattFir_pst;
   uint i;

   /* Filter is not active */
   if (BattFir_pst->FiltOn_b < ADC_FILT_ON)
   {
	   i=0;
       p->Data_pu32[i] = in;
       BattFir_pst->Sum_u32 += in;
       i++;
       BattFir_pst->Idx_u8=i;
       BattFir_pst->Num_u8=i;
   }

   /* Filter is active */
   else
   {
      i=BattFir_pst->Idx_u8;

      /* Start to fill the buffer*/
     if (BattFir_pst->Num_u8 < BattFir_pst->NumMax_u8)
     {
      p->Data_pu32[i] = in;
      BattFir_pst->Sum_u32 += in;

      i++;
      BattFir_pst->Idx_u8 = i;
      BattFir_pst->Num_u8 =i;
      }

      /* update the oldest value in the buffer  */
      else
      {
         if (i>=BattFir_pst->NumMax_u8)
         {
            i=0;
         }
         BattFir_pst->Sum_u32 += in - p->Data_pu32[i];
         p->Data_pu32[i] = in;

         i++;
         BattFir_pst->Idx_u8 = i;
     }
   }

   return;
}

static void EhalAdc_FIR_Calc(const EhalAdc_BattDscr_tst *p)
{

	volatile EhalAdc_BattFir_tst *BattFir_pst=p->EhalAdc_BattFir_pst;
	uint i;
	sint32 s;
	real32 f1;

	i = BattFir_pst->Num_u8;

    if (i >0)
    {
	  s=(sint32)BattFir_pst->Sum_u32;

	  f1=((((real32)s * p->Factor_r32) / (real32)((sint)i)) + 0.5f);

	  *p->Result_pu32=(uint32) f1;
    }

   return;
}
