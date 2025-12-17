#include <Thermometer/std_type.h>
#include "FreeRTOS.h"
#include "queue.h"

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

float Rte_Temperature;

/*
 * IMPLEMENTATION OF GLOBAL FUNCTIONS
 * */

void Rte_Init() { Rte_Temperature = 0.0; }

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */
