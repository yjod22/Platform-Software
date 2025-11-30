#ifndef APPLPSPLY_CFG_H_
#define APPLPSPLY_CFG_H_

#include <rte/Rte_ApplPsply.h>

/***********************************************/
/* Psply control mode                          */
/***********************************************/
#define APPLPSPLY_PSPLY_INIT (0x00)
#define APPLPSPLY_PSPLY_NONOP (0x11)
#define APPLPSPLY_PSPLY_OP (0x22)
#define APPLPSPLY_PSPLY_ACTIVE_OFF (0x33)
#define APPLPSPLY_PSPLY_ACTIVE_ON (0x44)

#define BATT_THRESHOLD (30000)

#endif /* APPLPSPLY_CFG_H_ */
