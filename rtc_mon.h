#ifndef _RTC_MON
#define _RTC_MON

#include <xc.h>
#include <stdbool.h>
#include "../rtcc/rtcc.h"



typedef enum {
    RTC_MON_WAITING_UNIX_TP0 = 1,
    RTC_MON_WAITING_GPS_PPS0 = 2,

    RTC_MON_WAITING_UNIX_TP1 = 3,
    RTC_MON_WAITING_GPS_PPS1 = 4,

    RTC_MON_WAITING_UNIX_TP2 = 5,
    RTC_MON_WAITING_GPS_PPS2 = 6,

    RTC_MON_WAITING_RTCC_PPS = 7,

    

} RTC_MON_STATUS_t;




typedef struct {
    bool measuring_window;

    RTC_MON_STATUS_t    status;
    bool waiting_next_1pps;

    bool error_1pps_out_of_sync;
    bool error_unix_tp_noncontinuous;

    uint16_t unix_tp0;
    uint16_t unix_tp1;

} RTC_MON_CONTEXT_t;



void rtc_mon_init(void);
void rtc_mon_on_rtcc_interrupt(RTCC_READ_RESULT_t*);
void rtc_mon_on_next_1pps_timestamp(uint64_t timestamp);
void rtc_mon_on_1pps_interrupt(void);

#endif