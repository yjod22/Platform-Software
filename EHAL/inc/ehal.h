#ifndef EHAL_H_
#define EHAL_H_

#include "EhalAdc.h"
#include "EhalCan.h"
#include "EhalDio.h"
#include "EhalExti.h"
#include "EhalI2c.h"
#include "EhalUsart.h"
#include "std_type.h"

extern void EHAL_Main_InputProcess(void);
extern void EHAL_Main_OutputProcess(void);

#endif /* EHAL_H_ */
