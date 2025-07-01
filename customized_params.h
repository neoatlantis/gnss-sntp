
#ifndef _CUSTOMIZED_PARAMS_H    /* Guard against multiple inclusion */
#define _CUSTOMIZED_PARAMS_H

#include "nic/nic.h"

#define SLOT1_LOCAL_IP      192, 168, 144, 1
#define SLOT1_LOCAL_PORT    53

#define SLOT2_LOCAL_IP      192, 168, 2, 144
#define SLOT2_GATEWAY_IP    192, 168, 2, 1

const NICIPv4Address IPdest = { 8, 8, 8, 8 };
const NICIPv4Address IPsrc  = { 192, 168, 144, 2 };

#endif