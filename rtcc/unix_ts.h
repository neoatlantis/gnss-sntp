#ifndef _RTCC_UNIX_TS
#define _RTCC_UNIX_TS

#include "rtcc.h"

void _civil_from_days(int64_t z, uint16_t *y, uint8_t *m, uint8_t *d);


void unix_to_datetime(uint64_t ts, datetime_t *dt);



#endif