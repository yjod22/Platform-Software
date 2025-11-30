#include <psply/ApplPsply.h>
#include <psply/ApplPsply_CFG.h>
#include <psply/ApplPsply_IN.h>
#include <psply/ApplPsply_OUT.h>

/*
 * DEFINITION OF LOCAL MACROS/DEFINES
 * */

/*
 * DEFINITION OF LOCAL TYPES
 * */

/*
 * DEFINITION OF LOCAL VARIABLES
 * */

static uint8 ApplPsply_PsplyMode_u8;
static bool ApplPsply_PsplyOut_b;

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

void ApplPsply_Calc_Psply(void)
{
    uint32 battery_u32;
    bool switch_b;

    ApplPsply_IN_Battery(&battery_u32);
    ApplPsply_IN_Switch(&switch_b);

    switch (ApplPsply_PsplyMode_u8)
    {
    case APPLPSPLY_PSPLY_INIT:
    {
        if (battery_u32 > BATT_THRESHOLD)
        {
            ApplPsply_PsplyMode_u8 = APPLPSPLY_PSPLY_OP;
        }
        else
        {
            ApplPsply_PsplyMode_u8 = APPLPSPLY_PSPLY_NONOP;
        }
        break;
    }

    case APPLPSPLY_PSPLY_NONOP:
    {
        ApplPsply_PsplyOut_b = false;

        if (battery_u32 > BATT_THRESHOLD)
        {
            ApplPsply_PsplyMode_u8 = APPLPSPLY_PSPLY_OP;
        }
        break;
    }

    case APPLPSPLY_PSPLY_OP:
    {
        ApplPsply_PsplyOut_b = true;

        ApplPsply_PsplyMode_u8 = APPLPSPLY_PSPLY_ACTIVE_OFF;
        break;
    }

    case APPLPSPLY_PSPLY_ACTIVE_OFF:
    {
        if (battery_u32 > BATT_THRESHOLD)
        {
            if (switch_b != false)
            {
                ApplPsply_PsplyMode_u8 = APPLPSPLY_PSPLY_ACTIVE_ON;
            }
        }
        else
        {
            ApplPsply_PsplyMode_u8 = APPLPSPLY_PSPLY_NONOP;
        }
        break;
    }

    case APPLPSPLY_PSPLY_ACTIVE_ON:
    {
        if (battery_u32 > BATT_THRESHOLD)
        {
            if (switch_b == false)
            {
                ApplPsply_PsplyMode_u8 = APPLPSPLY_PSPLY_ACTIVE_OFF;
            }
        }
        else
        {
            ApplPsply_PsplyMode_u8 = APPLPSPLY_PSPLY_NONOP;
        }
        break;
    }
    }

    /* store the new status */
    ApplPsply_OUT_PsplyMode(ApplPsply_PsplyMode_u8);

    /* set Output */
    ApplPsply_OUT_PsplyOut(ApplPsply_PsplyOut_b);
}

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */
