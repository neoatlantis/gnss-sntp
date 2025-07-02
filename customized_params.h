
#ifndef _CUSTOMIZED_PARAMS_H    /* Guard against multiple inclusion */
#define _CUSTOMIZED_PARAMS_H

#include "nic/nic.h"

#define SNTP_LOCAL_IP      192, 168, 117, 1
#define SNTP_LOCAL_PORT    123
#define SNTP_BCAST_IP      192, 168, 117, 255
#define SNTP_BCAST_PORT    123

const NICIPv4Address IPdest = { 192, 168, 117, 255 };
const NICIPv4Address IPsrc  = { 192, 168, 117, 1 };

#endif