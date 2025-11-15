#ifndef _RTCC_RTCC
#define _RTCC_RTCC

#include <xc.h>
#include <stdbool.h>

typedef union {
    uint32_t value;
    struct {
        unsigned :8;
        unsigned SEC01:4;
        unsigned SEC10:4;
        unsigned MIN01:4;
        unsigned MIN10:4;
        unsigned HR01:4;
        unsigned HR10:4;
    };
} RTCC_RTCTIME_t;


typedef union {
    uint32_t value;
    struct {
        unsigned WDAY01:3;
        unsigned :5;
        unsigned DAY01:4;
        unsigned DAY10:2;
        unsigned :2;
        unsigned MONTH01:4;
        unsigned MONTH10:1;
        unsigned :3;
        unsigned YEAR01:4;
        unsigned YEAR10:4;
    };
} RTCC_RTCDATE_t;


typedef struct {
    uint16_t year;
    uint8_t month;   // 1-12
    uint8_t day;     // 1-31
    uint8_t hour;    // 0-23
    uint8_t min;     // 0-59
    uint8_t sec;     // 0-59
    uint8_t weekday; // 0=Sunday, 1=Mon...6=Sat
} datetime_t;


typedef struct {
    datetime_t datetime;
    bool clock_is_running;
} RTCC_READ_RESULT_t;


typedef struct {
    RTCC_RTCDATE_t rtcdate;
    RTCC_RTCTIME_t rtctime;
} RTCC_WRITE_DATA_t;

void rtcc_init(void);

void rtcc_unlock(void);
void rtcc_lock(void);
void rtcc_enable_func(void);
void rtcc_disable_func(void);
void rtcc_read(RTCC_READ_RESULT_t*);
void rtcc_write_prepare(datetime_t *datetime, RTCC_WRITE_DATA_t *data);
void rtcc_write(RTCC_WRITE_DATA_t*);

#define rtcc_is_running (RTCCONbits.RTCCLKON)

#define _SPLIT10(v, tens, units) \
    tens = (v) / 10;            \
    units = (v) % 10




#endif