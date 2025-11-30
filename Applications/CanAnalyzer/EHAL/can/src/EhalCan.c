#include <can/EhalCan_CFG.h>
#include <can/EhalCan_IN.h>
#include <can/EhalCan_OUT.h>

/*
 * DEFINITION OF LOCAL MACROS/DEFINES
 * */

/*
 * DEFINITION OF LOCAL TYPES
 * */

/*
 * DEFINITION OF LOCAL VARIABLES
 * */

/*
 * DEFINITION OF LOCAL CONSTANTS
 * */

/*
 * DECLARATION OF LOCAL FUNCTIONS
 * */

/*
 * DEFINITION OF GLOBAL VARIABLES
 * */

/*
 * IMPLEMENTATION OF GLOBAL FUNCTIONS
 * */

void EhalCan_Init(void)
{
    EhalCan_OUT_InitRcc();
    EhalCan_OUT_InitGpio();
    EhalCan_OUT_InitCan1();
    EhalCan_OUT_InitNvic();
}

void EhalCan_SendMessage(void)
{
    CanTxMsg txMsg;
    EhalCan_IN_TxMessage(&txMsg);
    EhalCan_OUT_TxMessage(&txMsg);
}

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */
