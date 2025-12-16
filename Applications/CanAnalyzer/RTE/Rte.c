#include "FreeRTOS.h"
#include "queue.h"

#include <CanAnalyzer/std_type.h>
#include <rte/Rte_EhalCan.h>

#include "Rte.h"

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

QueueHandle_t Rte_CanQueue;

/*
 * IMPLEMENTATION OF GLOBAL FUNCTIONS
 * */

void Rte_Init() { Rte_CanQueue = xQueueCreate(QUEUE_LENGTH, QUEUE_ITEM_SIZE); }

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */
