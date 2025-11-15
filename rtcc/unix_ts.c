#include "unix_ts.h"
#include "rtcc.h"


void _civil_from_days(int64_t z, uint16_t *y, uint8_t *m, uint8_t *d){
    z += 719468;  

    int64_t era = (z >= 0 ? z : z - 146096) / 146097;
    uint64_t doe = (uint64_t)(z - era * 146097);               // [0, 146096]
    uint64_t yoe = (doe - doe/1460 + doe/36524 - doe/146096) / 365; // [0,399]
    uint64_t y1  = (uint64_t)yoe + era * 400;
    uint64_t doy = doe - (365*yoe + yoe/4 - yoe/100);          // [0,365]
    uint64_t mp  = (5*doy + 2) / 153;                          // [0,11]

    uint64_t d1  = doy - (153*mp + 2)/5 + 1;
    uint64_t m1  = mp + (mp < 10 ? 3 : -9);
    uint64_t y2  = y1 + (m1 <= 2);

    *y = (uint16_t)y2;
    *m = (uint8_t)m1;
    *d = (uint8_t)d1;
}


void unix_to_datetime(uint64_t ts, datetime_t *dt){
    uint32_t secs = ts % 86400;
    int64_t  days = ts / 86400;

    dt->hour = secs / 3600;
    secs %= 3600;
    dt->minute = secs / 60;
    dt->second = secs % 60;

    dt->weekday = (days + 4) % 7; // 0 for Sunday

    _civil_from_days(days, &dt->year, &dt->month, &dt->day);
}
