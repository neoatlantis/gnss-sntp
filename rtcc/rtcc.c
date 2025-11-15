#include "../interrupts/interrupts.h"
#include "rtcc.h"
#include "./unix_ts.h"

void __attribute__((optimize("O0"))) rtcc_unlock(void){
    // Suspend interrupts
    interrupts_general_disable;

    // critical sequence

    SYSKEY = 0xaa996655; // write first unlock key to SYSKEY
    SYSKEY = 0x556699aa; // write second unlock key to SYSKEY
    RTCCONSET = 0x8; // set RTCWREN in RTCCONSET
    
    // re-enable interrupts
    interrupts_general_enable;

    // re-enable the DMA controller
}

void rtcc_lock(void){
    RTCCONCLR = 0x8; // clear RTCWREN
}

/* Enable the function of RTCC */
void rtcc_enable_func(void){
    rtcc_unlock();
    RTCCONSET = (1 << 15);
    rtcc_lock();
}


void rtcc_read(RTCC_READ_RESULT_t *result){
    RTCC_RTCDATE_t rtcdate;
    RTCC_RTCTIME_t rtctime;

    rtcdate.value = RTCDATE;
    rtctime.value = RTCTIME;
    result->clock_is_running = rtcc_is_running;

    result->datetime.year    = 2000+rtcdate.YEAR01+rtcdate.YEAR10*10;
    result->datetime.month   = rtcdate.MONTH01+rtcdate.MONTH10*10;
    result->datetime.day     = rtcdate.DAY01+rtcdate.DAY10*10;
    result->datetime.weekday = rtcdate.WDAY01;

    result->datetime.hour    = rtctime.HR01+rtctime.HR10*10;
    result->datetime.min     = rtctime.MIN01+rtctime.MIN10*10;
    result->datetime.sec     = rtctime.SEC01+rtctime.SEC10*10;
}

void rtcc_write_prepare(datetime_t *datetime, RTCC_WRITE_DATA_t *data){
    //unix_to_datetime(unix_ts, &datetime);
    
    uint16_t rtcyear = datetime->year - 2000;
    _SPLIT10(rtcyear, data->rtcdate.YEAR10, data->rtcdate.YEAR01);
    _SPLIT10(datetime->month, data->rtcdate.MONTH10, data->rtcdate.MONTH01);
    _SPLIT10(datetime->day, data->rtcdate.DAY10, data->rtcdate.DAY01);
    data->rtcdate.WDAY01 = datetime->weekday;

    _SPLIT10(datetime->hour, data->rtctime.HR10, data->rtctime.HR01);
    _SPLIT10(datetime->min, data->rtctime.MIN10, data->rtctime.MIN01);
    _SPLIT10(datetime->sec, data->rtctime.SEC10, data->rtctime.SEC01);
}

void rtcc_write(RTCC_WRITE_DATA_t *data){
    rtcc_unlock();
    RTCTIME = data->rtctime.value; // write time ASAP
    RTCDATE = data->rtcdate.value;
    rtcc_lock();
}
