#include "ApplLed.h"
#include "ApplLed_CFG.h"
#include "ApplLed_IN.h"
#include "ApplLed_OUT.h"

void ApplLed_Calc_Led()
{
    float ApplLed_Temperature_f;
    uint8 ApplLed_PsplyMode_u8;

    ApplLed_IN_Temperature(&ApplLed_Temperature_f);
    ApplLed_IN_PsplyMode(&ApplLed_PsplyMode_u8);

    if (ApplLed_PsplyMode_u8 >= APPLLED_PSPLY_OP)
    {
        if (ApplLed_PsplyMode_u8 == APPLLED_PSPLY_ACTIVE_ON)
        {
            if (ApplLed_Temperature_f < 25)
            {
                ApplLed_OUT_LedRed_On();
                ApplLed_OUT_LedGreen_Off();
            }
            else
            {
                ApplLed_OUT_LedRed_Off();
                ApplLed_OUT_LedGreen_On();
            }
        }
        else
        {
            ApplLed_OUT_LedRed_Off();
            ApplLed_OUT_LedGreen_Off();
        }
    }
    else
    {
        ApplLed_OUT_LedRed_Off();
        ApplLed_OUT_LedGreen_Off();
    }
}
