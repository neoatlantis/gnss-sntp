#include <xc.h>
#include <stdbool.h>
#include "../rtcc/rtcc.h"
#include "../timer1/timer1.h"

#include "rtc_mon.h"


RTC_MON_CONTEXT_t      rtc_mon_status;

void rtc_mon_init(void){
    rtc_mon_status.status = RTC_MON_WAITING_UNIX_TP0;
    rtc_mon_status.measuring_window = false;

}


// On reception of a new 1pps interrupt

uint64_t next_unix_timestamp = 0;
uint16_t next_unix_timestamp_recv_at = 0;
uint16_t latest_1pps_recv_at = 0;

void rtc_mon_on_1pps_interrupt(void){
    if(!rtc_mon_status.measuring_window) return;

    latest_1pps_recv_at = timer1_read();

    if(!rtc_mon_status.waiting_next_1pps){
        rtc_mon_status.error_1pps_out_of_sync = true;
        return; // drop unexpected 1pps
    }

    rtc_mon_status.waiting_next_1pps = false;
    if(latest_1pps_recv_at - next_unix_timestamp_recv_at > TIMER1_TIME_1010ms){
        rtc_mon_status.error_1pps_out_of_sync = true;
        return;
    }

    rtc_mon_status.error_1pps_out_of_sync = false; // clear error
    rtc_mon_status.unix_tp0 = rtc_mon_status.unix_tp1;
    rtc_mon_status.unix_tp1 = next_unix_timestamp;

    rtc_mon_status.error_unix_tp_noncontinuous = (
        1 != rtc_mon_status.unix_tp1 - rtc_mon_status.unix_tp0
    );
}


// On reception of a new incoming UNIX timestamp...

void rtc_mon_on_next_1pps_timestamp(uint64_t timestamp){
    if(!rtc_mon_status.measuring_window) return;

    next_unix_timestamp = timestamp;
    next_unix_timestamp_recv_at = timer1_read();    
    rtc_mon_status.waiting_next_1pps = true;
}


// On RTCC local 1pps (not GPS)...

void rtc_mon_on_rtcc_interrupt(RTCC_READ_RESULT_t* rtcc){

    // Start new measuring window if not started

    if(!rtc_mon_status.measuring_window){
        timer1_start(); // restart timer1 from 0 at each RTCC 1pps interrupt
        rtc_mon_status.measuring_window = true;
        return;
    }

    // Stop measuring window after given period (10s)

    uint16_t timer1_now = timer1_read();

    if(timer1_now >= TIMER1_TIME_10000ms){
        timer1_stop();
        rtc_mon_status.measuring_window = false;
    }
    

}
